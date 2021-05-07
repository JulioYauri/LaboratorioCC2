#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
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
	string *arr = new string[num];
	/*
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
	*/
	ifstream palabrasDes("D:\\3ero\\cc2\\arreglosGit\\loren.txt");
	ofstream palabrasOrden("D:\\3ero\\cc2\\arreglosGit\\lorenOrdenado.txt");
	for(int i = 0; i < num; i++){
		palabrasDes >> *(arr + i);
	}	
	quicksort(arr, 0, num-1);
	for(int i = 0; i < num; i++){
		palabrasOrden << *(arr + i) << " ";
	}
	delete [] arr;
}


