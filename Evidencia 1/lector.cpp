#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

std::string readTxt(std::string mensaje)
{
    std::string texto;
    std::ifstream file(mensaje);
    std::string line;
    
    while (std::getline(file, line))
    {
        texto += line;
    }
    return texto;
}

void funcion1(const std::string& mainString, const std::string& pattern)
{
    bool result=false;
    int mainString_length = mainString.length();
    int key_length = pattern.length();

    std::vector<int> prefixVector(key_length);

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
                result=true;
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

    if(result){
    std::cout << "Virus encontrado en el archivo de transmision"<< std::endl;
    }
    else{
        std::cout << "Archivo de transmision limpio"<< std::endl;
    }

}

void funcion3(const std::string& pattern, const std::string& pattern2)
{
    int pattern_length = pattern.length();
    int key_length = pattern2.length();

    std::vector <int> prefixVector(pattern_length);
    int i = 1;
    int j = 0;
    

    prefixVector[0] = 0;

    while (i < pattern_length){
        if (pattern[i] == pattern2[j]){
            prefixVector[i] = j + 1;
            i++;
            j++;
        }
        else if (j == 0){
            prefixVector[i] = 0;
            i++;
        }
        else{
            j = prefixVector[j - 1];
        }
    }

    
    int maxElement = prefixVector[0];
    for (i = 1; i < pattern_length; ++i) {
        if (prefixVector[i] > maxElement) {
            maxElement = prefixVector[i]; 
        }
    }
    std::vector <int> result(maxElement);

    for (i=0; i<pattern_length; i++){
        if(prefixVector[i]==maxElement){
            i=i-maxElement+1;
            for(j=0; j<maxElement; j++){
                result[j]=i;
                i++;
            }
        }
        else{
            i++;
        }
    }


    std::cout << "Most common substring in: ";
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
    while(option!=4){
        std::cout << "Seleccione una opción: " << std::endl;
        std::cout << "1. Función 1 (KMP)" << std::endl;
        std::cout << "3. Funcion 3 (KMP)" << std::endl;
        std::cout << "4. salir" << std::endl;
        cin>>option;
        if (option == 1)
        {
            std::cout << "Transmisión 1|Virus 1: " << std::endl;
            funcion1(text1, virus1);
            std::cout << "Transmisión 1|Virus 2: " << std::endl;
            funcion1(text1, virus2);
            std::cout << "Transmisión 1|Virus 3: " << std::endl;
            funcion1(text1, virus3);
            std::cout << "Transmisión 2|Virus 1: " << std::endl;
            funcion1(text2, virus1);
            std::cout << "Transmisión 2|Virus 2: " << std::endl;
            funcion1(text2, virus2);
            std::cout << "Transmisión 2|Virus 3: " << std::endl;
            funcion1(text2, virus3);
        }
        else if (option == 3)
        {
            std::cout << "Patron en comun entre dos transmisiones" << std::endl;
            std::cout << "Posiciones en comun transmission1" << std::endl;
            funcion3(text1,text2);
            std::cout << "Posiciones en comun transmission2" << std::endl;
            funcion3(text2,text1);
        }
        else if (option == 4)
        {
            std::cout << "Adios" << std::endl;
        }
        else
        {
            std::cout << "Opción no válida" << std::endl;
        }
    } 
    return 0;
}
