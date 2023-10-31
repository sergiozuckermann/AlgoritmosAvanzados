#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

void palindrome(std::string original)
{
    std::string texto = "";
    for (int i = 0; i < original.length(); i++)
    {
        texto = texto + "$" + original[i];
    }
    texto=texto+"$";
    std::cout<<texto<< std::endl;
    int i = 1;                        // Iterador
    int counter = 0;                  // Contador
    int text_length = texto.length(); // Tamaño de texto
    int distancia = 1;                // Distancia entre los palindromos

    std::vector<int> Lstring(text_length); // Vector resultado
    Lstring[0] = 0;

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
            i++;
        }
        else
        {
            i++;
            counter = 0;
            Lstring[i] = counter;
        }
    }

    for (int i = 0; i < Lstring.size(); i++)
    {
        std::cout << Lstring[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{

    std::string texto = "abba";

    palindrome(texto);

}
