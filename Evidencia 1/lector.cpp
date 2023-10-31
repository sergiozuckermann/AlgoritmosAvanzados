#include <iostream>
#include <fstream>
#include <string>

using namespace std;

std::string readTxt(std::string mensaje)
{
    std::string texto;
    ifstream file(mensaje);
    texto = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return texto;
}

int main()
{

    std::string text1=readTxt("transmission1.txt");
    std::string text2=readTxt("transmission2.txt");
    std::string virus1=readTxt("mcode1.txt");
    std::string virus2=readTxt("mcode2.txt");
    std::string virus3=readTxt("mcode3.txt");
    int opcion;
    while(opcion!=4){
        std::cout << "Ingrese una opcion: " << endl;
        std::cout << "1. Opción 1" << endl;
        std::cout << "2. Opción 2" << endl;
        std::cout << "3. Función 3" << endl;
        std::cout << "4. Salir" << endl;

        cin >> opcion;

         if (opcion == 1) {

         }
         else if (opcion == 2) {

         }
         else if (opcion == 3) {
            
         }
        else if (opcion == 4) {
           std::cout << "Adios" << endl;
         }
         else {
            std::cout << "Invalido" << endl;
        }
    } 
     return 0;
}