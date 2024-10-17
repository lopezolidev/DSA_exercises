#include <iostream>

using namespace std;

string traverse(string s){
    int i = 0;

    string ciphered = ""; // initializing empty result

    string str = "" ;

    int k = 0 ;
    while(k < s.length()) {

        str += (char)tolower(s[k]) ;
        k++ ;
    }

    // cout << str ; 

    int counter = 0 ;

    while(i < s.length()){

        if(str[i] == ' ' || str[i] == ',' || str[i] == '.'){
            i++ ;
            continue ;
        }


        if(str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] ==  '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9'){
            
            ciphered += str[i];
            counter++ ;
            i++;

            if(counter == 5){
                ciphered += ' ';
                counter = 0;
            }

            continue ;
        }

        int letterToCode = int(str[i]) ;

        int positionOfCrypting = letterToCode - int('a') ;

        int codeOfEncrypted = int('z') - positionOfCrypting ;

        char encryptedCharacter = char(codeOfEncrypted) ;

        ciphered += encryptedCharacter ;
        counter++;

        if(counter == 5){
            ciphered += ' ';
            counter = 0;
        } 

        i++;
    } // encoding loop

    if (ciphered[ciphered.length() - 1] == ' '){
        int j = 0 ;

        string cipheredCopy = "";

        while ( j < ciphered.length() - 1){
            cipheredCopy += ciphered[j];
            j++;
        }

        return cipheredCopy ;
        
    } // if the last character is empty space we'll return the same string without the empty space


    return ciphered ;
}


int main() {

    string str = "The quick brown fox jumps over the lazy dog." ;

    int n = str.length() ;

    string answer = traverse(str) ;

    cout << answer ;

    return 0;
}