/**
 * VUT FIT IMS project
 * Uhlíková stopa v energetice a teplárenství
 * @author xsladk08 David Sladký
 * @author xandrl09 Ondřej Andrla
 */

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

unsigned int build_cost = 0; // money cost of building a wind turbine -w
unsigned int build_co2 = 0; // CO_2 generated to build wind turbine -c
unsigned int electricity_production = 0;

void bad_args()
{
    cout << "Parametry byly špatně zadány" << endl;

    exit(1);
}

void  parse_params(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt (argc, argv, "ywstc")) != -1)
    {
        switch (opt)
        {
            case 'w':
                if (argv[optind] != nullptr ) {
                    build_cost = strtol(argv[optind],nullptr,0);
                }
                else{
                    bad_args();
                }
                break;
            case 'c':
                if (argv[optind] != nullptr ) {
                    build_co2 = strtol(argv[optind],nullptr,0);
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

int main(int argc, char *argv[])
{
    parse_params(argc, argv);
    return 0;
}