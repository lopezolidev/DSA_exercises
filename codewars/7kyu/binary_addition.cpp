#include <iostream>
#include <cstdint>
#include <string>

using namespace std ;

int main () {

    uint64_t a = 0 ;
    uint64_t b = 2174483647 ;    


    uint64_t c = a + b ;

    string revRes = "";

    while( c > 0 ){
        int d = c % 2 ;
        revRes.push_back(char(d + 48));
        c /= 2 ;  
    }

    string res = "";

    int i = revRes.size() - 1 ;
    while(i >= 0){
        res.push_back(revRes[i]) ;
        i-- ;
    }
    cout << revRes << endl;
    cout << res << endl ;

    return 0 ;
}