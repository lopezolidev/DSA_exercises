#include <iostream>
#include <string>

using namespace std;

string alphabet_position(const std::string &text){
    if(text == " " || text == "") return "";

    string res ;
    for(int i = 0 ; i < text.length() ; i++){

        int v = (int)text[i] ; //turning the character into an integer

        //uppercase case
        if(v <= 90 && v >= 65){
            v = v - 64 ;

            //dealing with letters from J to Z
            if( v > 9) {
                string s ;
                int i = 0 ;
                while( i < 2){
                    int j = v % 10 ; // obtaining the right digit
                    char c = char(j + 48) ; // casting the digit from 0 to 9
                    s.push_back(c) ; // pushing the character to the provisional string s
                    v /= 10 ; // reducing the number by an order of magnitude
                    i++ ;
                } // loop for copying the character in backwards order

                i = 1 ; 
                while(i > -1){
                    res.push_back(s[i]) ;
                    i-- ;
                } // copying in correct order the casted number
            } else {
                // when the letter is from A to I
            }
        } else if () // REST OF THE CODE


    }
}

int main() {

    return 0; 
}