#include <string>
#include <iostream>

std::string number_to_string(int num) {
  std::string prov;

    if(num == 0) return "0" ;

    if(num < 0){
        prov.push_back('-') ;
        num *= -1 ;
    } // if the number is negative we push negative sign to the string and turn the number positive
    while(num > 0){
        int m = num % 10 ; // extracting the last digit
        
        char c = char(m + 48) ; // casting the digit into it's character representation
        
        prov.push_back(c) ; // pushing back the character to the response string
        
        num /= 10 ; // making the number lower by an order of magnitude
    } 

    std::string res ;
    if(prov[0] == '-'){
        res.push_back('-') ;
    }
    
    int i = prov.length() - 1;
    if(res[0] == '-'){
        while(i > 0){
            res.push_back(prov[i]) ;
            i-- ;
        }
    } else {
        while(i >= 0){
            res.push_back(prov[i]) ;
            i-- ;
        }
    }
  return res;
}

int main (){

    std::cout << number_to_string(-60) ;

    return 0 ;
}