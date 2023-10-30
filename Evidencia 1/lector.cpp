#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readTxt()
{
    string mensaje;
    std::cout << "Ingrese el mensaje o el nombre del archivo de texto: ";
    cin >> mensaje;

    for (char & c : mensaje)
    {
        c = tolower(c);
    }

    if (mensaje.find(".txt") != string::npos)
    {
        ifstream file(mensaje);
        if (file)
        {
            string contenido((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
            std::cout << "File content:" << endl;
            std::cout << contenido << endl;
        }
        else
        {
            std::cout << "Archivo no encontrado." << endl;
        }
    }
    else
    {
        std::cout << "No es un archivo de texto (.txt), ingresó un mensaje directamente." << endl;
    }
}

int main()
{
    readTxt();
    std::cout << "Ingrese una opcion: " << endl;
    std::cout << "1. Opción 1" << endl;
    std::cout << "2. Opción 2" << endl;
    std::cout << "3. Salir" << endl;

    int opcion;
    cin >> opcion;

    if (opcion == 1) {
        //Insertar la función que pide
    }
    else if (opcion == 2) {
        //Insertar la función que pide
    }
    else if (opcion == 3) {
        std::cout << "Adios" << endl;
    }
    else {
        std::cout << "Invalido" << endl;
        main();
    }
    return 0;
}