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


//Funcion z
std::vector <int> zfunc(std::string pattern, std::string pattern2){
    int pattern_length = pattern.length();
    int key_length = pattern2.length()-1;
    std::vector <int> result(key_length);
    std::vector <int> Zfunc(pattern_length);
    int i = 1;
    int j = 0;
    int count=0;

    Zfunc[0] = 0;

    while (i < pattern_length){
        if (pattern[i] == pattern[j]){
            count++;
            i++;
            j++;
        }

            

        else{
            i=i-count;
            Zfunc[i] = count;
            j = 0;
            
            count=0;
            i++;
        }
    }
    return Zfunc;

}

//position in function z
std::vector <int> position(std::vector <int> pattern, std::string pattern2){
    int pattern_length = pattern.size();
    int key_length = pattern2.length()-1;
    int original=0;
    std::vector <int> result(key_length);
    std::vector <int> final(key_length);
    int i,j;
    for (i=0; i<pattern_length; i++){
        if(pattern[i]==key_length){
            i=i+key_length-1;
            for(j=0; j<key_length; j++){
                original=i-key_length-1;
                result[j]=original;
                i--;
            }
            
            reverse(result.begin(), result.end());
            return result;
        }
    }
   return result; 
}

//Manacher 
std::string palindrome(std::string texto)
{
    int i = 1;                        // Iterador
    int counter = 0;                  // Contador
    int text_length = texto.length(); // Tamanho do texto
    int distancia = 1;                // Distancia entre los palindromos

    std::vector<int> Lstring(text_length); // Vetor com o tamanho do texto
    Lstring[0] = 0;

    int palLength = 0; // palindromo maximo
    int palCenter = 0; // centro de palindromo maximo

    while (i < text_length)
    {
        if (texto[i - distancia] == texto[i + distancia])
        {

            while (texto[i - distancia] == texto[i + distancia])
            {
                if (texto[i - distancia] <= 0 || texto[i + distancia] < text_length)
                {
                    break;
                }
                distancia++;
                counter++;
            }

            distancia = 1;
            Lstring[i] = counter;
            counter = 0;

            //Ir checando donde esta el palindromo 
            if (Lstring[i] > palLength) {
                palLength = Lstring[i];
                palCenter = i;
            }
            i++;
        }
        else
        {
            i++;
            counter = 0;
            Lstring[i] = counter;
        }
    }


    //Poner palindromo en una variable
    std::string longestPalindrome;
    
    // Extract the characters for the longest palindrome
    if (palLength > 0) {
        int startIndex = palCenter - palLength;
        int endIndex = palCenter + palLength;
        
        for (int j = startIndex; j <= endIndex; j++) {
            if (texto[j] != '$') {
                longestPalindrome += texto[j];
            }
        }
    }
    
    return longestPalindrome;
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
    std::string test = readTxt("test.txt");
    std::string virus1 = readTxt("mcode1.txt");
    std::string virus2 = readTxt("mcode2.txt");
    std::string virus3 = readTxt("mcode3.txt");

    int option;
    while(option!=4){
        std::cout << "Seleccione una opción: " << std::endl;
        std::cout << "1. Función 1 (KMP)" << std::endl;
        std::cout << "2. Función 2 (Encontrar palindromo más grande)" << std::endl;
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
        else if (option == 2)
        {
            std::cout << "Transmisión 1 " << std::endl;
            std::string string = "";
            //std::cout <<test.length()<< std::endl;
            for (int i = 0; i < test.length(); i++)
            {
                string = string + "$" + test[i];
            }
            string = string + "$";
            std::cout<<"String: "<<string<<std::endl;
            std::string result = palindrome(string);
            std::cout<<"Palindromo encontrado: "<<result<<std::endl;   
            //Encontrar donde se encuentra el palindromo
            std::string pattern = result+"$";
            std::string pattern_test = pattern+test;
            std::cout<<"Pattern: "<<pattern_test<<std::endl;

            std::vector <int> vector_test1 = zfunc(pattern_test, pattern);
            std::vector <int> vector_test2 = position(vector_test1, pattern);
            std::cout<<""<< std::endl;
            std::cout<<"Positions: "<< std::endl;
            for (int i = 0; i < vector_test2.size(); i++){
                std::cout << vector_test2[i] << " ";
            }
             std::cout<<""<< std::endl;

             std::cout << "Transmisión 2 " << std::endl;
            std::string string2 = "";
            //std::cout <<test.length()<< std::endl;
            for (int i = 0; i < text2.length(); i++)
            {
                string2 = string2 + "$" + text2[i];
            }
            string2 = string2 + "$";
            std::cout<<"String2: "<<string2<<std::endl;
            std::string result2 = palindrome(string2);
            std::cout<<"Palindromo encontrado: "<<result2<<std::endl;   
            //Encontrar donde se encuentra el palindromo
            std::string pattern2 = result2+"$";
            std::string pattern_test2 = pattern2+text2;
            std::cout<<"Pattern: "<<pattern_test2<<std::endl;

            std::vector <int> vector1 = zfunc(pattern_test2, pattern2);
            std::vector <int> vector2 = position(vector1, pattern);
            std::cout<<"Z Pattern: "<< std::endl;
            for (int i = 0; i < vector1.size(); i++){
                std::cout << vector1[i] << " ";
            }
            std::cout<<""<< std::endl;
            std::cout<<"Positions: "<< std::endl;
            for (int i = 0; i < vector2.size(); i++){
                std::cout << vector2[i] << " ";
            }
             std::cout<<""<< std::endl;



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
