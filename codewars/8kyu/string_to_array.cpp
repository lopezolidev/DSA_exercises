#include <iostream>
#include <string>
#include <vector>

using namespace std ;

int main (){

    vector<string> res ;

    string s = "Robin Singh" ;
    string temp = "" ;

    int i = 0 ;
    while(i < s.size()){
        if(s[i] != ' '){
            temp.push_back(s[i]) ;
        } else {
            if(!temp.empty()){
                res.push_back(temp) ;
                temp = "" ;
            }
        }
        i++ ;
    }
    if(!temp.empty()){
        res.push_back(temp) ;
        temp = "" ;
    }


    // Imprimir el resultado (válido para ambas opciones)
    cout << "Palabras extraídas:" << endl;
    for (int i = 0; i < res.size(); ++i) { // O puedes usar un for-each loop: for (const string& w : res)
        cout << res[i] << endl;
    }

    return 0 ;
}