#include<iostream>

using namespace std;

int tamanoIterativa(string cadena){
	//se inicia un contador en 0
	//el contador aumenta hasta encontrar al carácter nulo
	int tamano = 0;
	for(int i = 0; cadena[i] != '\0'; i++, tamano++);
	return tamano;
}

int tamanoRecursiva(string cadena){
	//la recursion termina cuando la cadena es nula
	if(cadena[0] == '\0')return 0;
	else{
		//se borra el ultimo elemento y se suma 1
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
