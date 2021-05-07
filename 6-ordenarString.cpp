#include<iostream>
#include<time.h>
using namespace std;
const int num = 1e6;

void quicksort(string arr[], int lo, int hi){
	//asignando el pivote al elemento medio
	int i = lo - 1, j = hi + 1, piv = lo + (hi - lo) / 2;
	//en caso el subarreglo sea de tamaño 1(ya está ordenado)
	if(lo >= hi) return;
	while(1){
		//buscando una cadena mayor al pivote
		while(arr[++i] < arr[piv]);
		//buscando una cadena menor al pivote
		while(arr[--j] > arr[piv]);
		//si la cadena mayor ya esta a la derecha se detiene el bucle
		if(i >= j) break;
		//se intercambian las cadenas
		swap(arr[i], arr[j]);	
	}
	//quicksort en los subarreglos
	quicksort(arr, lo, j);			
	quicksort(arr, j + 1, hi);
}

int main(){
	srand(time(0));
	//asignando memoria al arreglo de un millon de strings
	//num = 1000000
	string *arr = new string[num];
	//generando cadenas aleatorias
	int aux = 0;
	string s = "";
	for(int i = 0; i < num; i++){
		s = "";
		//las cadenas aleatorias son de tamaño 6
		for(int j = 0; j < 6; j++){
			aux = rand() % 26 + 97;
			s += (char)aux;		
		}
		*(arr + i) = s;
	}
	
	//imprimiendo primeros y ultimos 10 strings antes y después del ordenamiento
	cout << "ARREGLO DESORDENADO\n\nPrimeros 10 elementos\n";
	for(int i = 0; i < 10; i++)cout << arr[i] << "\n";
	cout << "Ultimos 10 elementos\n";
	for(int i = num - 1; i >= 999990; i--)cout << arr[i] << "\n";

	quicksort(arr, 0, num - 1);
	cout << "\nARREGLO ORDENADO\n\nPrimeros 10 elementos\n";
	for(int i = 0; i < 10; i++)cout << arr[i] << "\n";
	cout << "Ultimos 10 elementos\n";
	for(int i = 999990; i < num; i++)cout << arr[i] << "\n";

	//liberando la memoria
	delete [] arr;
}

