#pragma once
#include <iostream>
#include <array>
#include <string>
#include <fstream>



using namespace std;

extern array<array<char, 26>, 26> matryca;

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

string decoding(string key, string input)
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