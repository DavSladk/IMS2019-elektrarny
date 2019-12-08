/**
 * VUT FIT IMS project
 * Uhlíková stopa v energetice a teplárenství
 * @author xsladk08 David Sladký
 * @author xandrl09 Ondřej Andrla
 */

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <cmath>
#include "simlib.h"



using namespace std;


int years = 0; /// doba trvání simulace
int builded_coal = 0; ///počet postavených uhelných elektráren
int wind = 0; /// počet plánovaných větrných elektráren


long long int money = 0;
unsigned int elektricity = 0;
unsigned int emissions = 0;


void bad_args()
{
    cout << "Parametry byly špatně zadány" <<endl;

    exit(1);
}



void  parse_params(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt (argc, argv, "ybw")) != -1)
    {
        switch (opt)
        {
            case 'y':
                if (argv[optind] != nullptr ) {
                    years = strtol(argv[optind],nullptr,0);
                }
                else{
                    bad_args();
                }
                break;
            case 'b':
                if (argv[optind] != nullptr ) {
                    builded_coal = strtol(argv[optind],nullptr,0);
                }
                else{
                    bad_args();
                }
                break;
            case 'w':
                if (argv[optind] != nullptr ) {
                    wind = strtol(argv[optind],nullptr,0);
                }
                else{
                    bad_args();
                }
                break;
            default:
                bad_args();
        }
    }

}


int coal_power_plant()
{
    double d_time_to_live = Uniform(1, 50);
    int time_to_live = (int)round(d_time_to_live);
    cout << time_to_live << endl << endl;
    int el = 0;
    for(int i = 0; i < time_to_live; i++)
    {
        if(i == years - 1)
        {
            break;
        }

        long double d_e = Uniform(1404 , 1604);
        unsigned int e = (int)round(d_e);
        cout << e << endl;
        el = el + e;
        cout << el << endl;

    }
    cout << endl;
    return el;
}


void coal_work() {

    for(int i = 0; i < builded_coal; i++)
    {
        unsigned int el = coal_power_plant();
        cout << elektricity << endl;
        elektricity = elektricity + el;

        cout << elektricity << endl;
    }
    cout << endl;
    cout << elektricity << endl;

    // long double d_money = (int)round(d_money);
    money = elektricity * Uniform(400, 500);


    double d_emissions = elektricity * Uniform(760, 900);
    emissions = emissions + (int)round(d_emissions);



}


int wind_power_plant(int time_to_end)
{
    double d_time_to_live = Uniform(18, 25);
    int time_to_live = (int)round(d_time_to_live);
    cout << time_to_live << endl << endl;
    int el = 0;
    for(int i = 0; i < time_to_live; i++)
    {
        if(i == time_to_end - 1)
        {
            break;
        }

        double d_e = Normal(70, 1);/// 10 elektraren
        unsigned int e = (int)round(d_e);
        el = el + e;
        cout << el << endl;

        money = money - 40000;
    }
    cout << endl;
    return el;
}


void wind_work() {

    for(int i = 0; i < years; i++)
    {
        if(i == wind )
        {
            break;
        }

        unsigned int el = wind_power_plant(years - i);
        cout << elektricity << endl;
        elektricity = elektricity + el;


        cout << elektricity << endl;
    }
    cout << endl;
    cout << elektricity << endl;


    double d_money = elektricity * Uniform(1100, 1300);
    money = money + (int)round(d_money);

    money = money - Uniform(1050000, 1200000) * wind;

    double d_emissions = elektricity * Uniform(10, 20);
    emissions = (int)round(d_emissions);

}


int main(int argc, char *argv[]) {
    parse_params(argc, argv);
    RandomSeed(time(NULL));
    coal_work();
    wind_work();

    cout << "celkové množství vyprodukované elektřiny = " << elektricity << "GWh" << endl;
    cout << "celkov zisk = " << money  << " tisíc Kč" << endl;
    cout << "celkové množství CO2 = " << emissions  << "kg" << endl;
    return 0;
}