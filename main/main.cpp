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



    if (inputName == "")
    {
        if (argc != 1 && h == false)
        {
            cout << endl;
            cout << "Please provide the needed files!" << endl;
            help();
        }
    }
    else {
        if (operation == 1)
        {
            if (keyName == "" || outputName == "")
            {
                cout << endl;
                cout << "Please provide the needed files!" << endl;
                help();
                exit(0);
            }
            string key = readFile(keyName);
            string input = readFile(inputName);
            string output = encrypting(prepareKey(key, input), input);
            writeFile(outputName, output);
            cout << "Encrypted!" << endl;
        }
        else if (operation == 2)
        {
            if (keyName == "" || outputName == "")
            {
                cout << endl;
                cout << "Please provide the needed files!" << endl;
                help();
                exit(0);
            }
            string key = readFile(keyName);
            string input = readFile(inputName);
            string output = decrypting(prepareKey(key, input), input);
            writeFile(outputName, output);
            cout << "Decrypted!" << endl;
        }
        else if (operation == 3)
        {
            

        }
        else if (operation == 0)
        {
            cout << "Please provide a correct flag!";
            help();
        }
    }

	return 0;
}