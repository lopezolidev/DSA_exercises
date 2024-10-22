#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std ;

/*
Anagram Groups
 x
Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: strs = ["act","pots","tops","cat","stop","hat"]

Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]
Example 2:

Input: strs = ["x"]

Output: [["x"]]
Example 3:

Input: strs = [""]

Output: [[""]]
Constraints:

1 <= strs.length <= 1000.
0 <= strs[i].length <= 100
strs[i] is made up of lowercase English letters.

*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> hashMap;

    for (const auto& s : strs){

        vector<int> count(26, 0) ; // initializing a vector of 26 positions filled with 0

        for(char c : s){
            count[c - 'a']++ ;
        } // counting the letters in each string

        string key = to_string(count[0]) ; // casting the first letter to convert it to beginning of the key

        for(int j = 1 ; j < 26 ; j++ ){
            
            key += ',' + to_string(count[j]) ;

        } // appending values to the key. These integers casted to strings, represent all together the key of a respective string in the vector of strings. 

        hashMap[key].push_back(s) ; // inserting the string into the bucket of respective string
    }

    vector<vector<string>> result ; 

    for(const auto& pair : hashMap){
    
        result.push_back(pair.second) ;
    
    } // appending vectors of strings into the result matrix

    return result ; 

}

int main () {

    vector<string> words = {"act","pots","tops","cat","stop","hat"} ;

    vector<vector<string>> response = groupAnagrams(words) ;

    int i = 0 ;

    cout << "[" ;

    while( i < response.size() ){
        int j = 0 ;
        cout << "[" ;
        while( j < response[i].size() ){

            cout << response[i][j] << " " ;

            j++ ;
        }
        cout << "]" ;

        i++ ;
    }
    cout << "]" ;

    return 0 ;
}