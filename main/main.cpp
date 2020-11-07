#include <iostream>
#include <array>

#include "header.h"
using namespace std;

array<array<char, 26>, 26> matryca;

int main(int argc, char* argv[])
{
	fill(matryca);
	string inputName, outputName, keyName;
    int operation = 0;
    bool h = false;


    if (argc == 1)
    {
        help();
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            if (string(argv[i]) == "--en")
            {
                operation = 1;
            }
            else if (string(argv[i]) == "--de")
            {
                operation = 2;
            }
            else if (string(argv[i]) == "-h")
            {
                cout << "help!" << endl;
                h = true;
            }
            else if (string(argv[i]) == "--br")
            {
                operation = 3;
            }

            if (string(argv[i]) == "-i")
            {
                inputName = argv[i + 1];
            }
            if (string(argv[i]) == "-o")
            {
                outputName = argv[i + 1];
            }
            if (string(argv[i]) == "-k")
            {
                keyName = argv[i + 1];
            }
        }
    }

	return 0;
}