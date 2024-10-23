#include <iostream>
#include <vector>

using namespace std ;

/*
String Encode and Decode
Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Please implement encode and decode

Example 1:

Input: ["neet","code","love","you"]

Output:["neet","code","love","you"]
Example 2:

Input: ["we","say",":","yes"]

Output: ["we","say",":","yes"]
Constraints:

0 <= strs.length < 100
0 <= strs[i].length < 200
strs[i] contains only UTF-8 characters.

*/

string encode(vector<string>& strs) {

    string response = "";

    int i = 0 ;

    while( i < strs.size()) {
        string word = strs[i] ;
        
        string wordSize = to_string(word.size()) ;

        response += wordSize + "#" + word ;

        i++ ;
    }

    cout << "encoded: " << response << endl ;

    return response ;
}

vector<string> decode(string s) {

    vector<string> result ;

    int i = 0 ; 
    
    while( i < s.size() ){
        
        int j = i ;
        // ' j ' will always start at the position of ' i ', that being the position of the start of the number

        while( s[j] != '#'){
            j++ ;
        } 
        // updating the ' j ' pointer until it reaches the ' # ' symbol, that way we know how many characters we need to extract to get the length of the string

        int length = stoi(s.substr(i, j - i)) ; 
        // size of encoded word 

        string word = s.substr(j + 1, length) ; 
        // extracting the substring fom word using  substr function, which will extract a string starting from first argument, to ' length ' characters from the string

        result.push_back(word) ;
        // appending the word to the vector of strings ' result '

        i = j + 1 + length ; //moving to the next number 
    }

    return result ;
}

int main() {    

    vector<string> strs = {"we","say",":","yes", "!@#$%^&*()" } ;

    string response = encode(strs) ;

    vector<string> answer = decode(response) ;

    for(int i = 0 ; i < answer.size() ; i++ ){
        cout << answer[i] << " " ;
    }

    return 0 ;
}