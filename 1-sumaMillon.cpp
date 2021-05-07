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
//se utilizó goto para no consumir memoria de la pila
ll sumaRecursiva(int* arr, int tam){
	suma:
		if(tam == 1) return *arr;
		//se suma el contenido del ultimo elemento al penultimo
		//hasta que se llegue al primer elemento
		//el tamaño del arreglo va disminuyendo
		*(arr + tam - 2) += *(arr + tam - 1);
		tam--;
		//llamada recursiva a la sentencia suma
		goto suma;
}

int main(){
	//num = 1000000
	int tam = num;
	int *arr = new int[num];
	//generando numeros aleatorios para el arreglo
	//todos los numeros son menores a 20
	srand(time(NULL));
	for(ll i = 0; i < num; i++){
		*(arr + i) = rand() % 20;
	}
	cout << "Suma por iteracion: " << sumaIterativa(arr, tam) << "\n";
	cout << "Suma por recursion: " << sumaRecursiva(arr, tam) << "\n";
	delete [] arr;
}
