#include <iostream>
#include <stack>
using namespace std;

/*
Asignar i al segundo elemento desde la parte superior de la pila, dejando la pila sin sus dos
elementos de la parte superior.
*/

int main(int argc, char *argv[]) {
	
	stack<int> pila;
	
	for(int i=0;i<5;i++) { 
		pila.push(i+1);
	}
	
	for(int i=0;i<2;i++) { pila.pop(); }
	pila.push(80);
	
	while(!pila.empty()) { 
		cout << pila.top() << " ";
		pila.pop();
	}
	
	
	return 0;
}

