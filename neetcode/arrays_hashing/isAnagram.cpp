#include <iostream> 

using namespace std ;

/*
Is Anagram
 
Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: s = "racecar", t = "carrace"

Output: true
Example 2:

Input: s = "jar", t = "jam"

Output: false
Constraints:

s and t consist of lowercase English letters.

*/

bool isAnagram(string s, string t){
    int alphabet[26] = {0} ;

    int i = 0 ;
    while( i < s.size()){
        alphabet[int(s[i]) - int('a')]++ ;

        i++ ;
    } // creating the hashmap for the first string, casting its characters into integers

    i = 0 ;
    while(i < t.size()) {

        alphabet[int(t[i]) - int('a')]-- ;

        i++ ;
    } // substracting each casted character of second string from hashmap of first string 

    i = 0 ;
    while(i < 26) {

        if(alphabet[i] != 0){
            return false ;
        }

        i++ ;
    } // if there's a single casted character different from 0, then one string is not anagram of the other
    return true ;
    // otherwise if all positions are 0 from the hashmap, then one string is anagram of the other

} //hashmap solution 

/*
Time complexity: 
    O(n) → due to traversing each string entirely

Space complexity: 
    O(1) → due to the hashmap
*/

int main() {

    string a = "xx" ;

    string b = "x" ;

    if(isAnagram(a, b)){
        cout << "TRUE" ;
    } else {
        cout << "FALSE" ; 
    }

    return 0 ;
}