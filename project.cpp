#include "project.h"
using namespace std;

void _help()
{
    cout << "Usage: ./project [options] [value]"
         << "\n"
         << "Options:" << endl
         << "\t-h, --help\t\tShow this help message" << endl
         << "\t-b2d --bin2dec\t\tConvert binary to decimal" << endl
         << "\t-d2c --dec2bin\t\tConvert decimal to binary" << endl
         << endl;
}

void dec2bin(int number)
{
    int bin_arr[32], i = {0};

    while (number > 0)
    {
        bin_arr[i] = number % 2;
        number /= 2;
        i++;
    }

    string out;
    for (int k = i - 1; k >= 0; k--)
    {
        cout << bin_arr[k];
    }

    cout << "\n";
}

void bin2dec(int number)
{
}

void _run(int argc, char **argv)
{
    if (argc > 2)
    {
        string param = argv[1];
        int value = stoi(argv[2]);
        if (param == "-h" || param == "--help")
        {
            _help();
        }
        else if (param == "-d2c" || param == "--dec2bin")
        {
            dec2bin(value);
        }
        else if (param == "-c2d" || param == "--bin2dec")
        {
            bin2dec(value);
        }
        else
        {
            throw 1;
        }
    }
    else
    {
        _help();
    }
}