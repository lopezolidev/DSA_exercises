#include <iostream>
#include <ctime>
using namespace std;

int productarray(int arrayp[], int n){
    intarrayaux= new int [n];
    int index=0;
    int prod = 1;

    for (int i = 0; i < n; index++){
        if (index<n)
        {
            if(index!=i){
                prod=prodarrayp[index];
            }
        }else{
            index=0;
            prod=1;
            i++;
        }
        arrayaux[i]=prod;
    }

    intres=arrayaux;
    delete []arrayaux;
    return res;
}

int main (){
    clock_t inicio = clock();
    int array[4]={1,2,4,6};
    int *puntero=productarray(array,4);
    for (int i = 0; i < 4; i++)
    {
        cout<<puntero[i]<<endl;
    }
    clock_t final = clock();
    double tiempo_segundos = double(final - inicio) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecución: " << tiempo_segundos << " segundos" << endl;
    return 0;
}