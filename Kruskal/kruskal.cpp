#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
using namespace std;

std::set<std::set<int>> mergeSubsets(std::set<std::set<int>> inputSets) // Función de unión

{
    // Esta función se utiliza de la misma manera en la que se utiliza en la teoría de conjuntos
    std::set<std::set<int>> mergedSets;

    for (const std::set<int> &subset : inputSets)
    {
        bool merged = false;                    // Por default se establece que no están mergeados
        std::set<std::set<int>> subsetsToMerge; // Siguiente en la lista a mergear

        /*Inicia el mergeador 3000*/
        for (const std::set<int> &mergedSubset : mergedSets)
        {
            for (int element : subset)
            {
                if (mergedSubset.count(element)) // Si exite como opción a mergear (tiene elementos en común) se va a formar
                {
                    subsetsToMerge.insert(mergedSubset);
                    break;
                }
            }
        }

        if (!subsetsToMerge.empty()) // Si subsetsToMerge no está vacío, se va a hacer la unión
        {
            std::set<int> mergedSubset = subset; // End game
            for (const std::set<int> &sub : subsetsToMerge)
            // sub funciona como un temporal para comparar
            {
                /*mini mergeador*/
                mergedSubset.insert(sub.begin(), sub.end());
                mergedSets.erase(sub);
                /*mini mergeador*/
            }
            mergedSets.insert(mergedSubset);
            merged = true;
        }

        if (!merged) // Si hay algo a mergear lo mergea
        {
            mergedSets.insert(subset);
        }
        /*Termina el mergeador 3000*/
    }

    return mergedSets; // Regresa el set mergeado
}

int kruskal()
{
    std::ifstream inputFile("example.txt"); // Lee el archivo

    if (!inputFile.is_open())
    {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }

    // Almacena origen, destino y peso
    std::vector<int> firstNumbers;
    std::vector<int> secondNumbers;
    std::vector<int> thirdNumbers;

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        int first, second, third;
        if (iss >> first >> second >> third)
        {
            firstNumbers.push_back(first);
            secondNumbers.push_back(second);
            thirdNumbers.push_back(third);
        }
    }

    inputFile.close();

    /*Inicia sort*/
    for (size_t i = 1; i < thirdNumbers.size(); ++i)
    {
        int key1 = firstNumbers[i];
        int key2 = secondNumbers[i];
        int key3 = thirdNumbers[i];
        int j = i - 1; // La j se utiliza para comparar el valor anterior

        while (j >= 0 && thirdNumbers[j] > key3) // Compara el valor anterior con el actual utilizando las llaves
        {
            firstNumbers[j + 1] = firstNumbers[j];
            secondNumbers[j + 1] = secondNumbers[j];
            thirdNumbers[j + 1] = thirdNumbers[j];
            --j;
        }

        // Vuelve a armar el vector con los valores ordenados
        firstNumbers[j + 1] = key1;
        secondNumbers[j + 1] = key2;
        thirdNumbers[j + 1] = key3;
    }
    /*Termina sort*/

    cout << endl;
    std::cout << "Organized Edges: " << std::endl;   // Imprime los datos del archivo ordenados
    for (size_t i = 0; i < firstNumbers.size(); ++i) // Imprime los datos del archivo ordenados
    {
        std::cout << firstNumbers[i] << " ";
        std::cout << secondNumbers[i] << " ";
        std::cout << thirdNumbers[i] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Se crean sets nuevos para almacenar los datos
    std::set<std::set<int>> u;
    std::set<std::set<int>> answer;
    int a, b, sum = 0;

    cout << "Adding edges..." << endl;
    for (size_t i = 0; i < firstNumbers.size(); ++i) // Recorre los datos ordenados
    {
        // v funciona como una temporal para la comparación y futura inserción en u
        std::set<int> v = {};
        a = firstNumbers[i];
        b = secondNumbers[i];
        v.insert(a);
        v.insert(b);

        bool test = false; // Se utiliza para saber si el camino ya existe

        for (const std::set<int> &subset : u) // Checa si el camino ya existe
        {
            if (std::find(subset.begin(), subset.end(), a) != subset.end() &&
                std::find(subset.begin(), subset.end(), b) != subset.end()) // Se utiliza para encontrar si a o b existe en otra parte del subset
            {
                test = true;
                break;
            }
        }

        if (test == false) // Si el camino no existe, se agrega
        {
            cout << "The edge { "; // Imprime el camino actual
            for (int vertex : v)
            {
                cout << vertex << " ";
            }
            cout << "} has been accepted." << endl;
            u.insert(v);                 // Inserta todo el subset
            v.insert(thirdNumbers[i]);   // Inserta el peso
            answer.insert(v);            // Subset final
            sum = sum + thirdNumbers[i]; // Calcula el peso final
            u = mergeSubsets(u);         // Función de unión
        }

        // Y volvemos a empezar
        test = false;
        v.erase(a);
        v.erase(b);
    }

    // Imprime el resultado final
    std::cout << std::endl;

    for (const std::set<int> &subset : u)
    { // Imprime el set mergeado
        std::cout << "All nodes have been visited:" << std::endl;
        std::cout << "{ ";
        for (int vertex : subset)
        {
            std::cout << vertex << " ";
        }
        std::cout << "}" << std::endl;
    }

    cout << endl;
    cout << "Final sum of the weights: " << sum << endl;
    cout << endl;
    return 0;
}

int main() // Corre la función
{
    kruskal();
    return 0;
}
