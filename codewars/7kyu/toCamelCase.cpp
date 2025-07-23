#include <iostream>
#include <string>

using namespace std; 
string to_camel_case(string text) {
  if(text == "") return "";
  string result = "";

    if(text[0] == '-' || text[0] == '_') {
        text.erase(0, 1);
    }

    // if(text[0] < 97){
    //     result.push_back(text[0]) ;
    // }
    for (int i = 0; i < text.length(); i++){
        if(text[i] == '-' || text[i] == '_'){
            i++;
            if((int)text[i] < 97){
                result.push_back(text[i]) ;
                continue;
            } else {
                result.push_back(char((int)text[i] - 32)) ;
                continue;
            }
        }
        result.push_back(text[i]) ;
    }
  return result ;
}
int main () {

    cout << to_camel_case("the_stealth_warrior") << endl; // "theStealthWarrior"
    cout << to_camel_case("The_Stealth_Warrior") << endl; // "TheStealthWarrior"
    cout << to_camel_case("The-Stealth-Warrior") << endl; // "TheStealthWarrior"
    cout << to_camel_case("the-stealth-warrior") << endl; // "theStealthWarrior"
    cout << to_camel_case("the-stealth-warrior-") << endl; // "theStealthWarrior"
    cout << to_camel_case("the_stealth_warrior-") << endl; // "theStealthWarrior"
    cout << to_camel_case("the_stealth_warrior-") << endl; // "theStealthWarrior"
    cout << to_camel_case("the_stealth_warrior-") << endl; // "theStealthWarrior"

    return 0;
}