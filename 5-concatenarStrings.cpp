#include<iostream>

using namespace std;

string concatenar(string a, string b){
	return a+b;
}

int main(){
	string a, b; cin >> a >> b;
	cout << concatenar(a, b) << "\n";
}
