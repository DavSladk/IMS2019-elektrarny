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

//class elektrarna

unsigned int years = 0; /// doba trvání simulace
unsigned int wind = 0; /// počet plánovaných větrných elektráren
unsigned int coal = 0; /// počet plánovaných uhelných elektráren
unsigned int builded_coal = 0; ///počet postavených uhelných elektráren

void bad_args()
{
    cout << "Parametry byly špatně zadány" <<endl;

    exit(1);
}

void print_help()
{

}

void  parse_params(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt (argc, argv, "ywbc")) != -1)
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
            case 'w':
                if (argv[optind] != nullptr ) {
                    wind = strtol(argv[optind],nullptr,0);
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
            case 'c':
                if (argv[optind] != nullptr ) {
                    coal = strtol(argv[optind],nullptr,0);
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


int power_plant()
{
    double d_time_to_live = Uniform(1, 50);
    int time_to_live = (int)round(d_time_to_live);
    cout << time_to_live << endl << endl;
    int el = 0;
    for(int i = 0; i < time_to_live; i++)
    {

        double d_e = Exponential(1504);
        cout << d_e << endl;
        unsigned int e = (int)round(d_e);
        cout << e << endl;
        el = el + e;
        cout << el << endl;
        //el += 1504000;
        if(i == years - 1)
        {
            break;
        }
    }
    cout << endl;
    return el;
}


int main(int argc, char *argv[]) {
    parse_params(argc, argv);

    unsigned int elektricity = 0;
    long int money = 0;
    unsigned int emissions = 0;
    //int months = 12 * years;

    for(int i = 0; i < builded_coal; i++)
    {
        unsigned int el = power_plant();
        cout << elektricity << endl;
        elektricity = elektricity + el;

        cout << elektricity << endl;
    }
    cout << endl;
    cout << elektricity << endl;

    //money += elektricity * 450;
    double d_money = elektricity * Normal(450, 100);
    money = (int)round(d_money);

    //emissions += elektricity * 820;
    double d_emissions = elektricity * Uniform(760, 900);
    emissions = (int)round(d_emissions);



    cout << "celkové množství vyprodukované elektřiny = " << elektricity  << "MWh" << endl;
    cout << "celkov zisk = " << money / 1000 << "milionu Kč" << endl;
    cout << "celkové množství CO2 = " << emissions /1000 << "tun" << endl;

    return 0;
}