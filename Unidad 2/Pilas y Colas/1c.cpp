#include <iostream>
#include <stack>
using namespace std;

/*
Dado un entero n, asignar i al elemento n-´esimo desde la parte superior de la pila, dejando la
pila sin sus n elementos superiores.
*/

int main(int argc, char *argv[]) {
	
	stack<int> pila;
	
	for(int i=0;i<5;i++) { 
		pila.push(i+1);
	}
	
	int n;
	cout << "n? ";
	cin >> n;
	
	if (n<=pila.size()){
		for(int i=0;i<n;i++) { pila.pop(); }
		pila.push(80);
	} else{
		cout << "no hice nada" << endl;
	}
	
	while(!pila.empty()) { 
		cout << pila.top() << " ";
		pila.pop();
	}
	
	
	return 0;
}
