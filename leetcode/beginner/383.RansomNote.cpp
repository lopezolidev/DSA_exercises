#include <iostream>

using namespace std ;

/*
383. Ransom Note

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote. 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/

bool canConstruct(string ransomNote, string magazine) {
    bool answer = true ;

    int alphabet[26] = {0} ;

    int i = 0 ;
    while ( i < magazine.size()){

        int value = int( int(magazine[i]) - int('a') ) ;

        alphabet[value]++ ;

        i++ ;
    } // loop to initialize the hash table with the number of letters that ' magazine ' contains

    i = 0 ;

    while ( i < ransomNote.size()) {

        int valueToSubstract = int( int(ransomNote[i]) - int('a')) ;

        alphabet[valueToSubstract]-- ;

        i++ ;
    } // loop to substract letters of ' ransomNote ' from the alphabet array made up from ' magazine '

    i = 0 ;
    while(i < 26) {
        if( alphabet[i] < 0 ) {
            answer = false ;
        }

        i++ ;
    } // loop to determine when ' magazine ' cannot reconstruc ' ransomNote ' due to a letter (or more) being present in ' ransomNote ' and not in ' magazine '

    return answer ;
}

int main () {

    bool answer = canConstruct("camelot", "tocomelcat") ;

    if(answer){
        cout << "TRUE" ;
    } else {
        cout << "FALSE" ;
    }

    return 0 ;
}