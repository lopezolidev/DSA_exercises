/*
Validate Parentheses
You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

Every open bracket is closed by the same type of close bracket.
Open brackets are closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Return true if s is a valid string, and false otherwise.

Example 1:

Input: s = "[]"

Output: true
Example 2:

Input: s = "([{}])"

Output: true
Example 3:

Input: s = "[(])"

Output: false
Explanation: The brackets are not closed in the correct order.

Constraints:

1 <= s.length <= 1000
*/

#include <iostream>
#include <stack>

using namespace std ;

bool isValid(string s) {
    stack<string> parenthesis ;

    for(int i = 0 ; i < s.size() ; i++ ){
        if( parenthesis.empty() ){
            
            char character = s[i] ;
            string firstChar = "" ;

            firstChar = character ;
 
            parenthesis.push(firstChar) ;
            continue ;

        } // inserting the first parenthesis at the bottom of the stack in case that it's empty and going for the next iteration

        string previousParenthesis = parenthesis.top() ;

        string comparingParenthesis = parenthesis.top() + s[i];

        if(comparingParenthesis == "[]" || comparingParenthesis == "()" || comparingParenthesis == "{}"){
            parenthesis.pop() ;
            continue ;
        } else if( comparingParenthesis == "([" || comparingParenthesis == "({" || comparingParenthesis == "[(" || comparingParenthesis == "[{" || comparingParenthesis == "{(" || comparingParenthesis == "{["){
            
            char character = s[i] ;
            string incomingParentheis = "" ;

            incomingParentheis = character ;

            parenthesis.push(incomingParentheis) ;
        
            continue ;

        // appending a new parenthesis into the stack when there're 2 opening parenthesis and continuing for next iteration

        } else {
            return false ;
        } 
    }

    if( parenthesis.empty() ) return true ;
    
    return false ;
}

int main () {

    if( isValid("[(])") ) {
        cout << "valid parenthesis " ;
    } else {
        cout << "not valid parenthesis " ;
    };

    return 0 ;
}