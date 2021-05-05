#include<iostream>

using namespace std;

int tamanoIterativa(string cadena){
	int tamano = 0;
	for(int i = 0; cadena[i] != '\0'; i++, tamano++);
	return tamano;
}

int tamanoRecursiva(string cadena){
	if(cadena[0] == '\0')return 0;
	else{
		cadena.pop_back();
		return tamanoRecursiva(cadena) + 1;
	}
}

int main(){
	string cadena;
	cin >> cadena;
	cout << tamanoIterativa(cadena) << "\n";
	cout << tamanoRecursiva(cadena) << "\n";
}
