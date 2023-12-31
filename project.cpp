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
    int lastValue = {0}, dec = {0}, base = {1};

    while (number)
    {
        lastValue = number % 10;
        number /= 10;
        dec += lastValue * base;
        base *= 2;
    }

    cout << dec;
    cout << "\n";
}

bool arg_valid(char *arg)
{
    // Validate if are number
    bool valid = true;
    for (int i = 0; i < strlen(arg); i++)
    {
        if (!isdigit(arg[i]))
        {
            valid = false;
            break;
        }
    }

    return valid;
}

void _run(int argc, char **argv)
{
    if (argc > 2)
    {

        if (!arg_valid(argv[2]))
        {
            cout << "Invalid input, need me number!"
                 << "\n";
            return;
        };

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
        else if (param == "-b2d" || param == "--bin2dec")
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