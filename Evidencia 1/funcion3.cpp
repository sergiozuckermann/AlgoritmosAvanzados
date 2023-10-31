#include <iostream>
#include <vector>
#include <string>

std::vector <int> prefixFunction(std::string pattern, std::string pattern2){
    int pattern_length = pattern.length();
    int key_length = pattern2.length();
    std::vector <int> result(key_length);
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

    for (i=0; i<pattern_length; i++){
        if(prefixVector[i]==key_length){
            i=i-key_length+1;
            for(j=0; j<key_length; j++){
                result[j]=i;
                i++;
            }
        }
        else{
            i++;
        }
    }

    return result;

}

int main(){
    std::string pattern_test = "ABABCABCABABABD";
    std::string pattern = "ABABD";

    std::vector <int> vector_test1 = prefixFunction(pattern_test, pattern);

    std::cout<<"Pattern found in positions: "<< std::endl;
    for (int i = 0; i < vector_test1.size(); i++){
        std::cout << vector_test1[i] << " ";
    }
}