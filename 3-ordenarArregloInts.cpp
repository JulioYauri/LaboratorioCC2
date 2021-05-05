#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
const int num = 1e6;

void QuickSort(int *lo, int* hi){
	int *i, *j;
	int piv;
	if(lo >= hi)return;
	piv = *(lo + (hi-lo)/2);
	i = lo - 1;
	j = hi + 1;
	while(1){
	    while (*(++i) < piv);
	    while (*(--j) > piv);
	        if (i >= j)
	            break;
	        swap(*i, *j);
	}
    QuickSort(lo, j);
    QuickSort(j+1, hi);
}

int main(){
	int* arr = new int [num];
	int tam = num;
	srand(time(NULL));
	for(int i = 0; i < tam; i++){
		*(arr + i) = rand() % 1000;
	}
	cout << "Primeros 20 elementos del arreglo desordenado: ";
	for(int i = 0; i < 20; i++) cout << *(arr + i) << " ";
	cout << "\nUltimos 20 elementos del arreglo desordenado: ";
	for(int i = 20; i > 0; i--) cout << *(arr + tam - i) << " ";
	
	QuickSort(arr, arr + tam - 1);
	cout << "\nPrimeros 20 elementos del arreglo ordenado: ";
	for(int i = 0; i < 20; i++) cout << *(arr + i) << " ";
	cout << "\nUltimos 20 elementos del arreglo ordenado: ";
	for(int i = 20; i > 0; i--) cout << *(arr + tam - i) << " ";
	delete [] arr;
}
