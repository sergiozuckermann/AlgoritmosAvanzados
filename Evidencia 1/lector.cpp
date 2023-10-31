#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

std::string readTxt(std::string mensaje)
{
    std::string texto;
    ifstream file(mensaje);
    texto = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return texto;
}

void prefix_pattern(const std::string& mainString, const std::string& pattern)
{
    int mainString_length = mainString.length();
    int key_length = pattern.length();

    std::vector<int> prefixVector(key_length);
    std::vector<int> result;

    int i = 1;
    int j = 0;

    prefixVector[0] = 0;

    // Build the prefix vector
    while (i < key_length)
    {
        if (pattern[i] == pattern[j])
        {
            prefixVector[i] = j + 1;
            j++;
            i++;
        }
        else if (j == 0)
        {
            prefixVector[i] = 0;
            i++;
        }
        else
        {
            j = prefixVector[j - 1];
        }
    }

    i = 0; // Reset i for matching

    // Search for the pattern in the mainString
    while (i < mainString_length)
    {
        if (mainString[i] == pattern[j])
        {
            i++;
            j++;

            if (j == key_length)
            {
                // Pattern found, add the starting position to the result
                result.push_back(i - key_length);
                j = prefixVector[key_length - 1];
            }
        }
        else
        {
            if (j != 0)
                j = prefixVector[j - 1];
            else
                i++;
        }
    }

    std::cout << "Pattern found in positions: ";
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::string text1 = readTxt("transmission1.txt");
    std::string text2 = readTxt("transmission2.txt");
    std::string virus1 = readTxt("mcode1.txt");
    std::string virus2 = readTxt("mcode2.txt");
    std::string virus3 = readTxt("mcode3.txt");

    int option;
    std::cout << "Seleccione una opción: " << std::endl;
    std::cout << "1. KMP" << std::endl;
/*
    std::cout << "codigo1: " << text1 << endl;
    std::cout << "codigo2: " << text2 << endl;
    std::cout << "virus1: " << virus1 << endl;
    std::cout << "virus2: " << virus2 << endl;
    std::cout << "virus3: " << virus3 << endl;
*/
    if (option == 1)
    {
        prefix_pattern(text1, virus1);
        prefix_pattern(text1, virus2);
        prefix_pattern(text1, virus3);

        prefix_pattern(text2, virus1);
        prefix_pattern(text2, virus2);
        prefix_pattern(text2, virus3);
    }
    else
    {
        std::cout << "Opción no válida" << std::endl;
    }

    return 0;
}
