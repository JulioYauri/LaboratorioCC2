#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
const int num = 1e6;

void QuickSort(int *lo, int* hi){
	//punteros auxiliares
	int *i, *j;
	int piv;
	if(lo >= hi)return;
	piv = *(lo + (hi-lo)/2);
	//i apunta a un elemento antes del primero
	//j apunta a un elemento despues del ultimo
	//es así porque en el bucle while se incrementa i
	//tambien disminuye j, pero ambos con el prefijo
	i = lo - 1;
	j = hi + 1;
	while(1){
		//buscando un elemento mayor al pivote
	    	while (*(++i) < piv);
		//buscando un elemento menor al pivote
	    	while (*(--j) > piv);
		//si el mayor esta a la derecha del menor 
		//no es necesario hacer más intercambios
		//se rompe el bucle
	        if (i >= j)
	            break;
		//en caso contrario se intercambian
	        swap(*i, *j);
	}
	//quicksort de los subarreglos
    QuickSort(lo, j);
    QuickSort(j+1, hi);
}

int main(){
	int* arr = new int [num];
	int tam = num;
	//generando el millon de numeros aleatorios 
	//todos menores que 1000
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
