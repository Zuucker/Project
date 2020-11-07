#pragma once
#include <iostream>
#include <array>
#include <string>
#include <fstream>



using namespace std;

extern array<array<char, 26>, 26> matryca;/**This makes sure the header file understands the global variable "matryca"*/

/**
* The function fills the a matrix with consecutive letters starting with "a" for the first row, then with "b" for the second row ... with "z" for the last row until "z" and then fills the rest from "a" again so that every line has 26 elements.
* @param mat the char matrix to be filled
*/
void fill(array<array<char, 26>, 26>& mat) {

    int k = 0;
    char nast = 'a';
    for (int i = 0; i < 26; i++)
    {
        for (char j = nast; k < 26; j++)
        {
            mat[i][k] = j;
            if (j == 'z')
            {
                j = '`';
            }
            k++;
        }
        k = 0;

        nast++;
    }
}

/**
* The function reads and returns the content of a file.
* @param fName the name of the file
* @return string the content of the file
*/
string readFile(string fName)
{
    string tmp1, tmp2;
    ifstream file(fName);

    if (file)
    {
        while (!file.eof())
        {
            getline(file, tmp1);
            tmp2 += tmp1;
            tmp2 += " ";
        }
        file.close();
    }
    else
    {
        cout << "File " << fName << " not found!";
        exit(0);
    }
    return tmp2;
}

/**
* The function writes a string text to a file.
* @param fName the name of the file
* @param content the text that should be written into a file
*/
void writeFile(string fName, string content)
{
    string tmp1, tmp2;
    ofstream file(fName);

    if (file)
    {
        file << content;
        file.close();
    }
    else
    {
        cout << "error";
    }
}

/**
* The function makes sure the key is long enough to be used and returns the key.
* @param key the content of the key
* @param input the content of the text to be encrypted(to match it's lenght)
* @return string with the prepared key
*/
string prepareKey(string key, string input)
{
    string fKey;
    int k = 0;

    for (unsigned int i = 0; i < input.length(); i++)//-1
    {
        if (input[i] == ' ')
        {
            fKey += " ";
        }
        else {
            fKey += key[k];
            k++;
        }


        if (k == key.length() - 1)
        {
            k = 0;
        }
    }

    return fKey;
}

/**
* The function returns the index of the collumn in which the letter is found in the first row.
* @param letter the letter to be found
* @return int with the index of the collumn
*/
int col(char letter)//pionowe
{
    for (int i = 0; i < 26; i++)
    {
        if (letter == matryca[i][0])
        {
            return i;
        }
    }
    return 0;
}

/**
* The function returns the index of the row in which the letter is found int the first collumn.
* @param letter the letter to be found
* @return int with the index of the row
*/
int row(char letter)
{
    for (int i = 0; i < 26; i++)
    {
        if (letter == matryca[0][i])
        {
            return i;
        }
    }
    return 0;
}

/**
* The function returns the index of the row in which the letter was found in a collumn.
* @param letter the letter to be found
* @return int with the index of the row
*/
int letterInCollumn(char letter, int col)
{
    int pos;
    for (int i = 0; i < 26; i++)
    {
        if (matryca[i][col] == letter)
        {
            pos = i;
        }
    }
    return pos;
}

/**
* The function encrypts the given text using the prepared key.
* @param the prepared key
* @param text to be encrypted
* @return string with the encrypted text
*/
string encrypting(string key, string input)
{
    string encryptet;
    for (unsigned int i = 0; i < input.length() - 1; i++)
    {
        if (input[i] != ' ' || key[i] != ' ')
        {
            int c = col(input[i]);
            int r = row(key[i]);

            encryptet += matryca[c][r];
        }
        else {
            encryptet += ' ';
        }

    }
    encryptet += ' ';
    return encryptet;
}

/**
* The function decrypts the given text using the prepared key.
* @param key the prepared key
* @param input text to be decrypted
* @return string with the decrypted text
*/
string decrypting(string key, string input)
{
    string decrypted;
    for (unsigned int i = 0; i < input.length() - 1; i++)
    {
        if (input[i] != ' ' || key[i] != ' ')
        {
            int c = col(key[i]);
            int r = letterInCollumn(input[i], c);

            decrypted += matryca[0][r];
        }
        else {
            decrypted += ' ';
        }

    }
    decrypted += ' ';
    return decrypted;
}

/**
* The function displays the proper way the program is supposed to be used.
*/
void help()
{
    cout << endl;
    cout << "#######################################" << endl;
    cout << "Displaying help:" << endl;
    cout << "This program is used to encrypt and decrypt a text with the Vigenere method." << endl;
    cout << "It can be also used to break the ciphered text without the key." << endl;

    cout << "To encrypt use: " << endl;
    cout << "main.exe --en -i input-file.txt -o output-file.txt -k key.txt" << endl << endl;

    cout << "To decrypt use: " << endl;
    cout << "main.exe --de -i input-file.txt -o output-file.txt -k key.txt" << endl << endl;

    cout << "To break ciphered text witout a key use: " << endl;
    cout << "main.exe --br -i input-file.txt" << endl << endl;

    cout << "#######################################" << endl;


}