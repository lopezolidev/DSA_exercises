#include <iostream>
using namespace std ;

int nbDig(int n, int d){
      if(n == 0 && d != 0 ) return 0 ;
      int i = 0 ;
      int c = 0 ;
      while(i <= n){
        long long k = (long long)i * i ;
        if(k == 0 && d == 0) {
            c++;
        }
        else {
            while( k > 0){
                int v = k % 10 ;
                if( v == d) c++ ;
                k /= 10 ;
            }
        }
        i++ ;
      }
      return c ;
};

// int nbDig(int n, int d) {
//     int c = 0;
//     // Bucle para iterar desde 0 hasta n
//     for (int i = 0; i <= n; ++i) {
//         long long k = (long long)i * i; // Usamos long long para evitar desbordamiento
        
//         if (k == 0) {
//             if (d == 0) {
//                 c++;
//             }
//         } else {
//             // Contar el dígito 'd' en el cuadrado
//             while (k > 0) {
//                 int v = k % 10;
//                 if (v == d) {
//                     c++;
//                 }
//                 k /= 10;
//             }
//         }
//     }
//     return c;
// }

int main () {
    cout << nbDig(25, 1) << endl; // Example usage
    cout << nbDig(10, 1) << endl; // Example usage
    cout << nbDig(5750, 0) << endl; // Equal to 4700
    cout << nbDig(11011, 2) << endl; // Equal to 9481
    cout << nbDig(12224, 8) << endl; // Equal to 7733
    return 0;
}