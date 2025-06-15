#include <iostream>
#include <string>

using namespace std ;

//  TO BE COMPLETED... 

int main () {

    string numbers = "1 9 3 4 -5" ;
    std::string temp = "";

    std::string res = "" ;

    if (int(numbers.size()) == 1) {
        res.push_back(numbers[0]) ;
        res.push_back(' ') ;
        res.push_back(numbers[0]) ;
        return 0 ;
    }

    int i = 0 ;
    while (i < int(numbers.size())) {
        if (numbers[i] == ' ') {
            temp.push_back(',') ;
            i++;
            continue;
        }
        if (int(numbers[i]) == 45) {
            temp.push_back(numbers[i]) ;
            temp.push_back(numbers[i + 1]) ;
            i++ ;
            continue ;
        }
        temp.push_back(numbers[i]) ;
        i++;
    }

    int max ;
    int min ;


    if(int(temp[0]) == 45){
        max = int(temp[1]) - 48 ;
        max *= -1 ;
        min = int(temp[1]) - 48 ;
        min *= -1 ;
    } else {
        max = int(temp[0]) - 48 ;
        min = int(temp[0]) - 48 ;
    }

    i = 1 ;
    while(i < int(temp.size())){

        if(temp[i] == ','){
            i++ ;
            continue ;
        }
        if(int(temp[i]) == 45){
            int comparator = int(temp[i + 1]) - 48 ;
            comparator *= -1 ;
            
            if(max < comparator ){
                max = comparator ;
            }
            if(min > comparator){
                min = comparator ;
            }

            i++ ;
            continue ;
        }
        if(max < int(temp[i]) - 48 ){
            max = int(temp[i]) - 48 ;
        }
        if(min > int(temp[i]) - 48){
            min = int(temp[i]) - 48 ;
        }
        i++ ;
    } 


    res.push_back(char(max + 48));
    res.push_back(' ');

    if(min < 0){
        min *= -1 ;
        res.push_back('-');
    }

    res.push_back(char(min + 48));

    std::cout << res ;

    return 0 ;
}