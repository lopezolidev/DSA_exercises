#include <iostream>
#include <string>

using namespace std ;

string printerError(const string s){
    int size_of_string = int(s.size()) ;
    string temp_size_in_string = "" ;
    while(size_of_string > 0){
        temp_size_in_string.push_back( char( (size_of_string % 10) + 48 )) ;

        size_of_string /= 10 ;
    } // string size flipped

    string size_in_string = "";
    for(int i = int(temp_size_in_string.size()) - 1 ; i >= 0 ; i--){
        size_in_string.push_back( temp_size_in_string[i] ) ;
    } // reflipping in correct order the string

    string res ;
    string temp_err ;

    int err = 0 ;
    for(int i = 0 ; i < int(s.size()) ; i++){
        if(int(s[i]) > 109 ) err++ ; 
    } // finding out number of errors
    
    
    if(err == 0){
        temp_err.push_back(char(err + 48)) ;
    } else {
        while(err > 0){
        temp_err.push_back(char((err % 10) + 48)) ;
        err /= 10 ;
        }
    } // temporal string with errors flipped

    string err_count = "";
    for(int i = int(temp_err.size()) - 1 ; i >= 0  ; i--){
        err_count.push_back(temp_err[i]) ;
    } // flipping number of errors in correct order



    res = err_count + '/' + size_in_string;

    cout << res ;

    return res;
}

int main (){

string cadena = "aaaxbbbbyyhwawiwjjjwwm" ;

printerError(cadena) ;

}