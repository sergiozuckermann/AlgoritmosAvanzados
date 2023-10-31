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
    std::cout << "codigo1" << text1 << endl;
    std::cout <<"codigo2" << text2 << endl;
    std::cout << "virus1" << virus1 << endl;
    std::cout <<"virus2" << virus2 << endl;
    std::cout <<"virus3" << virus3 << endl;

    // std::cout << "Ingrese una opcion: " << endl;
    // std::cout << "1. Opción 1" << endl;
    // std::cout << "2. Opción 2" << endl;
    // std::cout << "3. Salir" << endl;

    // int opcion;
    // cin >> opcion;

    // if (opcion == 1) {
    //     //Insertar la función que pide
    // }
    // else if (opcion == 2) {
    //     //Insertar la función que pide
    // }
    // else if (opcion == 3) {
    //     std::cout << "Adios" << endl;
    // }
    // else {
    //     std::cout << "Invalido" << endl;
    //     main();
    // }
     return 0;
}