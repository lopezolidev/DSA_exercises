#include <iostream>
#include <string>

using namespace std ;

int duplicateCount(const std::string& in){
    if(in == "0") return 0 ;
    
    int letters[26] = {0} ; 
    int numbers[10] = {0} ;
    // using arrays as buckets for counting the occurrence of each letter and number

    int c = 0; //counter variable for counting occurrence of more than 2 for numbers and letters

    for(int i = 0 ; i < in.length() ; i++){
        int v = (int)in[i] ;

        //for uppercase letters
        if( v <= 90 && v >= 65){
            v = v - 65; // mapping it to letter 'a'
            letters[v]++ ; // increasing count of such letter
        } else if ( v <= 122 && v >= 97){ // for lowercase letters
            v = v - 97 ;
            letters[v]++ ;
        } else if( v <= 57 && v >= 48){ // handling numbers
            v = v - 48 ;
            numbers[v]++ ;
        }

    }

    //counting numbers repeated more than once
    for( int i = 0 ; i < 10 ; i++ ) {
        if( numbers[i] > 1 ){
            c++ ;
        }
    } 
    //counting letters repeated more than once
    for( int i = 0 ; i < 26 ; i++ ) {
        if( letters[i] > 1 ){
            c++ ;
        }
    } 

    return c ;
}

int main (){
    // test cases
    cout << duplicateCount("abcde") << endl; // 0
    cout << duplicateCount("aabbcde") << endl; // 2
    cout << duplicateCount("aabBcde") << endl; // 2   
    cout << duplicateCount("indivisibility") << endl; // 1
    cout << duplicateCount("Indivisibilities") << endl; // 2
    cout << duplicateCount("aA11") << endl; // 2
    cout << duplicateCount("ABBA") << endl; // 2
    cout << duplicateCount("0") << endl; // 0   
    cout << duplicateCount("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz") << endl; // 26
    cout << duplicateCount("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") << endl; // 26
    cout << duplicateCount("d8UFEK4SXcoyMBBw7rfkbkFomPcoK9Rxa8bhe6CbHgZ5U0ilKoBDuyrHDnza63E5OOBPb5udR4ZhRKqA0NSoGqyK1PS6w5QbqBmAgXNONFowjrrG8pwviAb9IgZcl0xC1T7kFlJlADUB4Qs") << endl; // 32


    return 0 ;
}