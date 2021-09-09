#include <iostream>
#include <stack>
using namespace std;

/*
Asignar i al segundo elemento desde la parte superior de la pila, sin modificarla
*/
int main(int argc, char *argv[]) {
	
	stack<int> pila;
	
	for(int i=0;i<5;i++) { 
		pila.push(i+1);
	}
	
	int aux=pila.top();
	for(int i=0;i<2;i++) { pila.pop(); }
	pila.push(80); pila.push(aux);
	
	while(!pila.empty()) { 
		cout << pila.top() << " ";
		pila.pop();
	}
	
	
	return 0;
}
