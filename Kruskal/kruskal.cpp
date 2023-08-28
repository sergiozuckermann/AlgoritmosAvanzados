#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int kruskal() {
    std::ifstream inputFile("example.txt");

    if (!inputFile.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }

    std::vector<int> firstNumbers;
    std::vector<int> secondNumbers;
    std::vector<int> thirdNumbers;

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int first, second, third;
        if (iss >> first >> second >> third) {
            firstNumbers.push_back(first);
            secondNumbers.push_back(second);
            thirdNumbers.push_back(third);
        }
    }

    inputFile.close();

    std::cout << "Organized Edges: " << std::endl;
    for (size_t i = 0; i < firstNumbers.size(); ++i) {
        std::cout << firstNumbers[i] << " ";
        std::cout << secondNumbers[i] << " ";
        std::cout << thirdNumbers[i] << " ";
        std::cout << std::endl;
    }

    for (size_t i = 1; i < thirdNumbers.size(); ++i) {
        int key1 = firstNumbers[i];
        int key2 = secondNumbers[i];
        int key3 = thirdNumbers[i];
        int j = i - 1;

        while (j >= 0 && thirdNumbers[j] > key3) {
            firstNumbers[j + 1] = firstNumbers[j];
            secondNumbers[j + 1] = secondNumbers[j];
            thirdNumbers[j + 1] = thirdNumbers[j];
            --j;
        }
        firstNumbers[j + 1] = key1;
        secondNumbers[j + 1] = key2;
        thirdNumbers[j + 1] = key3;
    }

    std::cout << "Organized Edges: " << std::endl;
    for (size_t i = 0; i < firstNumbers.size(); ++i) {
        std::cout << firstNumbers[i] << " ";
        std::cout << secondNumbers[i] << " ";
        std::cout << thirdNumbers[i] << " ";
        std::cout << std::endl;
    }

    std::list<std::list<int>> u;
    std::list<std::list<int>> answer;
    int a, b, sum = 0;

    for (size_t i = 0; i < firstNumbers.size(); ++i) {
        std::list<int> v = {};
        a = firstNumbers[i];
        b = secondNumbers[i];
        v.push_back(a);
        v.push_back(b);
        cout << "Current Edge: { ";
        for (int vertex : v) {
            cout << vertex << " ";
        }
        cout << "}" << endl;
        bool test = false;

        for (const std::list<int>& subset : u) {
            if (std::find(subset.begin(), subset.end(), a) != subset.end() &&
                std::find(subset.begin(), subset.end(), b) != subset.end()) {
                test = true;
                break;
            }
        }
        

        if (test) {
            std::cout << "Both elements are in at least one subset." << std::endl;
        } 
        else {
        std::cout << "At least one of the elements is not in any subset." << std::endl;
        }

        if (test == false) {
            cout << a << " " << b << endl;
            u.push_back(v);
            v.push_back(thirdNumbers[i]);
            answer.push_back(v);
            sum = sum + thirdNumbers[i];

            // CODE HERE
        }
        test = false;
        v.remove(a);
        v.remove(b);
    }
    cout << "Lists of Vertices in u:" << endl;
    for (const std::list<int>& subset : answer) {
        cout << "{ ";
        for (int vertex : subset) {
            cout << vertex << " ";
        }
        cout << "}" << endl;
    }
    cout << "Final sum: " << sum << endl;
    cout << endl;
    return 0;
}

int main() {
    kruskal();
    return 0;
}
