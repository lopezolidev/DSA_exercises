#include <iostream>

using namespace std;

string encode(char* s){
    int i = 0;

    string ciphered = ""; // initializing empty result

    string str = "" ;

    int m = 0 ;
    int size = 0 ;
    while (s[m] != '\0'){
        m++ ;
        size++ ;
    } // obtaining the size of the dynamic characters array


    int k = 0 ;
    while(k < size) {

        str += (char)tolower(s[k]) ;
        k++ ;
    } // lowering each character of the dynamic characters array

    int counter = 0 ;

    while(i < size){

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
        } // appending the character number into the ciphered string, increasing the counter of characters in ciphered string and looping to the next character. Including resetting of counter and add of space when counter is equal to 5

        char encryptedCharacter = char(int('z') - (int(str[i]) - int('a'))); 
        // formulae to encrypt the character in atbash ciphering 

        ciphered += encryptedCharacter ; // appending encrypted character
        counter++;

        if(counter == 5){
            ciphered += ' ';
            counter = 0;
        } // if counter is equal to 5, append space to ciphered text and resetting counter

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
} // algorithm to cipher text in atbash key

string decode(char* s){
    string res = "";

    int j = 0 ; 
    int size = 0 ;
    while ( s[j] != '\0'){
        j++ ;
        size++ ;
    } // obtaining the size of a dynamic characters array

    int i = 0 ;
    while( i < size ){

        if( s[i] == ' '){
            i++ ;
            continue ;
        } // if empty space, continue to next iteration 

        if(s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] ==  '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'){
            
            res += s[i];
            i++ ;

            continue ;
        } // if the character is a number,  it will be appended just like it and the loop will continue to the next iteration


        res += char((int('z') - int(s[i])) + int('a')) ; // formulae to decode character

        i++ ;
    } // loop to traverse ciphered text and append deciphered character into result string

    return res ; 
} // fuction of decoding

int main() {

    char* str = "answer" ;

    // string answer = encode(str) ;

    // cout << answer << endl ;

    char* repply = "gvhgr mt123 gvhgr mt" ;

    string result = decode(repply) ;

    cout << result ;
    // testing123testing

    return 0;
}