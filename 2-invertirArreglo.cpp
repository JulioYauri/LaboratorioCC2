#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
const int num = 1e6;

void intercambio(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;	
}

void invertirIterativa(int *arr, int tam){
	int *l = arr, *r = arr + tam - 1; 
	while(l < r){
		intercambio(l , r);
		l++;
		r--;	
	}
}

//se utilizó goto para no consumir la memoria de la pila
void invertirRecursiva(int *arr, int l, int r){
	inversion:
		if(l > r) return;
		//intercambia los numeros ubicados en l y r
		//l avanza y r retrocede
		intercambio(&l, &r);
		l++, r--;
		goto inversion;
}

int main(){
	int* arr = new int [num];
	int tam = num;
	//generando los numeros aleatorios
	srand(time(NULL));
	for(int i = 0; i < tam; i++) *(arr + i) = rand() % 1000;
	
	cout << "Primeros 20 elementos del arreglo inicial: ";
	for(int i = 0; i < 20; i++) cout << *(arr + i) << " ";
	cout << "\nUltimos 20 elementos del arreglo inicial: ";
	for(int i = 20; i > 0; i--) cout << *(arr + tam - i) << " ";

	invertirIterativa(arr, tam);
	cout << "\n\nIteracion\n";
	cout << "Primeros 20 elementos del arreglo invertido: ";
	for(int i = 0; i < 20; i++) cout << *(arr + i) << " ";
	cout << "\nUltimos 20 elementos del arreglo invertido: ";
	for(int i = 20; i > 0; i--) cout << *(arr + tam - i) << " ";

	invertirRecursiva(arr, 0, tam - 1);
	cout << "\n\nRecursion\n";
	cout << "Primeros 20 elementos del arreglo invertido: ";
	for(int i = 0; i < 20; i++) cout << *(arr + i) << " ";
	cout << "\nUltimos 20 elementos del arreglo invertido: ";
	for(int i = 20; i > 0; i--) cout << *(arr + tam - i) << " ";

	delete [] arr;
}
