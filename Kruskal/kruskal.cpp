#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;



int kruskal(){
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

	
    // Print the contents of the vectors
    std::cout << "Organized Edges: ";
    std::cout << std::endl;
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
        
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
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

    // Print the contents of the vectors
    std::cout << "Organized Edges: ";
    std::cout << std::endl;
    for (size_t i = 0; i < firstNumbers.size(); ++i) {
        std::cout << firstNumbers[i] << " ";
        std::cout << secondNumbers[i] << " ";
        std::cout << thirdNumbers[i] << " ";
        std::cout << std::endl;
        
    }


    std::set<std::set<int>> u;
    std::set<std::set<int>> answer;
    int a,b,sum=0;

    for (size_t i = 0; i < firstNumbers.size(); ++i) {
        std::set<int> v= {};
        a = firstNumbers[i];
        b = secondNumbers[i];
        v.insert(a);
        v.insert(b);
        cout << "Current Edge: { ";
        for (int vertex : v) {
        cout << vertex << " ";
        }
        cout << "}" << endl;
        bool test = false;

        for (const set<int>& subset : u) {
            if (subset == v) {
                test = true;
                break;
            }
        }
        
        if (test == false) {
            cout<<a<<" "<<b<<endl;
            u.insert(v);
            answer.insert(v);
            sum=sum+thirdNumbers[i];
            
            //CODIGO AQUI
        }
        test = false;
        v.erase(a);
        v.erase(b);

    }
    cout << "Sets of Vertices in u:" << endl;
    for (const std::set<int>& subset : u) {
        cout << "{ ";
        for (int vertex : subset) {
            cout << vertex << " ";
        }
    cout << "}" << endl;
    }
    cout << "Final sum:" << sum << endl;
    cout << endl;
    return 0;
}

int main() {

	kruskal();
	return 0;


}


