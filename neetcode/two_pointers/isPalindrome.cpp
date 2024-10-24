/*
Is Palindrome
Given a string s, return true if it is a palindrome, otherwise return false.

A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

Example 1:

Input: s = "Was it a car or a cat I saw?"

Output: true
Explanation: After considering only alphanumerical characters we have "wasitacaroracatisaw", which is a palindrome.

Example 2:

Input: s = "tab a cat"

Output: false
Explanation: "tabacat" is not a palindrome.

Constraints:

1 <= s.length <= 1000
s is made up of only printable ASCII characters.

*/

#include <iostream>
#include <string>

using namespace std ;

bool isPalindrome(string s) {
    string copy = "" ;

    for(int k = 0 ; s[k] != '\0' ;  k++){
        
        if(s[k] == ' '){
            k++ ;
        } // if its an empty space

        if( int(s[k]) > 64 && int(s[k]) < 91 ){
            copy += char(int(s[k]) + 32) ;
        } // casting to lower character
        else if( int(s[k]) > 96 && int(s[k]) < 123 || int(s[k]) > 47 && int(s[k]) < 58) {
            copy += s[k] ;
        } 
       
    }// casting the string to obtain a single continuous alphanumeric string

    cout << "copy: " << copy << endl ;

    int i = 0 ;
    int j = copy.size() - 1 ;

    while( i < copy.size() / 2 ) {
        
        if( copy[i] != copy[j] ){
            return false ;
        }
            
        if( i == j ){
            break ;
        }
        
        i++ ;
        j-- ;

    }// finding out when the string is valid palindrome or not when characters differ

    return true ;    
}

int main () {
    
    string str = "0P" ;

    isPalindrome(str) ;

    // if(isPalindrome(str)){

    //     cout << "is valid" ;
    
    // } else {

    //     cout << "is not valid" ;

    // } 
    
    return 0 ;
}