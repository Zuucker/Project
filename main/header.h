#pragma once
#include <iostream>
#include <array>


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