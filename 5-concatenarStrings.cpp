#include<iostream>
using namespace std;

void concatenar(char* a, char* b, int tamA, int tamB){
	//se empieza a asignar cada char de la segunda cadena para concatenar
	for(int i = 0; i < tamB; i++){
		*(a + i + tamA) = *(b + i);	
	}
	//el ultimo char de la cadena final es el carácter nulo
	*(a + tamA + tamB) = '\0';
}

int main(){
	string s1, s2;
	cout << "Ingresa dos cadenas:\n" << flush;
	cin >> s1 >> s2;
	//asignando los dos punteros
	char* p1 = &s1[0], *p2 = &s2[0];
	int t1 = s1.size(), t2 = s2.size();
	concatenar(p1, p2, t1, t2);
	cout << "\nCadena final:\n" << p1 << flush;
}
