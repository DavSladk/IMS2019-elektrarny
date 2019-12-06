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

unsigned int years = 0;
unsigned int wind = 0;
unsigned int coal = 0;
unsigned int builded_coal = 0;

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

int main(int argc, char *argv[])
{
    parse_params(argc, argv);
    return 0;
}