#include <cinttypes>
#include <iostream>

using namespace std ;

uint64_t descendingOrder(uint64_t a)
{
  if(a == 0) return 0 ;
  int freq[10] = {0} ; // initializing all positions of frequency in zeros
  
  while(a > 0){
    int digit = a % 10 ;
    freq[digit]++ ;
    a /= 10 ; 
  } // loop to reduce a while marking the frequencies of each number
  
  uint64_t res = 0 ;
  int i = 9 ;
  while(i > -1) {
    while(freq[i] > 0){ // only enters the loop if that number appeared
      res = (res + i) * 10 ;        
      freq[i]-- ;
    } // taking the digit of frequency and summing the previous times 10, while also reducing the frequency of each digit
    i-- ;
  }
  
  res /= 10 ; // dividing the result by 10 due to the last 10 multiplication 

  return res;
}

int main() {
    uint64_t n = 11122444455555567888 ;

    cout << descendingOrder(n) ;

    return 0 ;
}