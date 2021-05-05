#include<iostream>
#include<time.h>
using namespace std;
const int num = 1e6;

void quicksort(string arr[], int lo, int hi){
	int i = lo - 1, j = hi + 1, piv = lo + (hi - lo) / 2;
	if(lo >= hi) return;
	while(1){
		while(arr[++i] < arr[piv]);
		while(arr[--j] > arr[piv]);
		if(i >= j) break;
		swap(arr[i], arr[j]);	
	}
	quicksort(arr, lo, j);			
	quicksort(arr, j + 1, hi);
}

int main(){
	srand(time(0));
	string *arr = new string[num];
	int aux = 0;
	string s = "";
	for(int i = 0; i < num; i++){
		s = "";
		for(int j = 0; j < 6; j++){
			aux = rand() % 26 + 97;
			s += (char)aux;		
		}
		*(arr + i) = s;
	}
	
	cout << "ARREGLO DESORDENADO\n\nPrimeros 10 elementos\n";
	for(int i = 0; i < 10; i++)cout << arr[i] << "\n";
	cout << "Ultimos 10 elementos\n";
	for(int i = num - 1; i >= 999990; i--)cout << arr[i] << "\n";
	
	quicksort(arr, 0, num - 1);
	cout << "\nARREGLO ORDENADO\n\nPrimeros 10 elementos\n";
	for(int i = 0; i < 10; i++)cout << arr[i] << "\n";
	cout << "Ultimos 10 elementos\n";
	for(int i = 999990; i < num; i++)cout << arr[i] << "\n";
	
	delete [] arr;
}

