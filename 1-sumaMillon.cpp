#include<iostream>
#include<time.h>
#include<stdlib.h>
#define ll long long
using namespace std;

int num = 1e6;

ll sumaIterativa(int* arr, int tam){
	ll suma = 0;
	for(int i = 0; i < tam; i++){
		suma += *(arr + i);
	}
	return suma;
}

ll sumaRecursiva(int* arr, int tam){
	suma:
		if(tam == 1) return *arr;
		*(arr + tam - 2) += *(arr + tam - 1);
		tam--;
		goto suma;
}

int main(){
	int tam = num;
	int *arr = new int[num];
	srand(time(NULL));
	for(ll i = 0; i < num; i++){
		*(arr + i) = rand() % 20;
	}
	cout << "Suma por iteracion: " << sumaIterativa(arr, tam) << "\n";
	cout << "Suma por recursion: " << sumaRecursiva(arr, tam) << "\n";
	delete [] arr;
}
