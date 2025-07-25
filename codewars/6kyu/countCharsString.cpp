#include <iostream>
#include <string>
#include <map>

using namespace std;
map<char, unsigned> count(const std::string& string) {
    if(string == "") return {};

    map<char, unsigned> m; // map to store character counts
    for ( int i = 0 ; i < string.length() ; i++ ){
        if(!m[string[i]]){
            m[string[i]] = 1 ;
        } else {
            m[string[i]]++ ;
        }
    } //if the element in the map doesn't exists, its initialized in 1, when already exists its value is increased 

    map<char, unsigned> r ; // map for result
    
    for(auto it = m.begin() ; it != m.end() ; ++it){
        if( it->second > 0){
            r.emplace(it->first, it->second) ;
        }
    } // if the element in map is greater than 0, then is added to the result map

    return r ;
}


// Función auxiliar para imprimir el mapa
void printMap(const map<char, unsigned>& m) {
    cout << "{ ";
    for (auto const& [key, val] : m) {
        cout << "'" << key << "': " << val << " ";
    }
    cout << "}" << endl;
}

int main() {
    // Caso de prueba 1: "aba"
    cout << "Input: \"aba\"" << endl;
    map<char, unsigned> result1 = count("aba");
    cout << "Output: ";
    printMap(result1); // Usamos la función auxiliar para imprimir

    // Caso de prueba 2: ""
    cout << "Input: \"\"" << endl;
    map<char, unsigned> result2 = count("");
    cout << "Output: ";
    printMap(result2); // Imprime un mapa vacío

    // Caso de prueba 3: "abc"
    // create a new test case different from the previous one
    cout << "Input: \"abc\"" << endl;
    map<char, unsigned> result3 = count("abc");
    cout << "Output: ";
    printMap(result3); // Imprime un mapa con cada letra y su cuenta


    // Additional test cases can be added here
    cout << "Input: \"aabbcc\"" << endl;
    map<char, unsigned> result4 = count("aabbcc");
    cout << "Output: ";
    printMap(result4); // Imprime un mapa con cada letra y su cuenta

    // Caso de prueba 5: "aA11"
    cout << "Input: \"aA11\"" << endl;
    map<char, unsigned> result5 = count("aA11");
    cout << "Output: ";
    printMap(result5); // Imprime un mapa con cada letra y su cuenta, considerando case insensitivity   

    return 0;
}