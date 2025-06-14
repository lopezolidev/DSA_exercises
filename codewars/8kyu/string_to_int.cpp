#include <iostream>
#include <string>

using namespace std ;

int main (){
    
    string s ;

    cin >> s ;

    int res = 0 ;

    if(int(s[0]) == 45){
        int i = 1 ;
        while(i < int(s.size())){
            res += int(s[i]) - 48 ;
            res *= 10 ;
            i++ ;
        }
        res /= 10 ;
        res *= -1 ;
    } else {
        int i = 0 ;
        while(i < int(s.size())){
            res += int(s[i]) - 48 ;
            res *= 10 ;
            i++ ;
        }
        res /= 10 ;
    }
    cout << res ;
    return res ;
}