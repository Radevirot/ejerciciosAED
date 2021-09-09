#include <iostream>
#include <stack>
using namespace std;

/*
Asignar i al elemento del fondo de la pila, dejando la pila vac´ia
*/

int main(int argc, char *argv[]) {
	
	stack<int> pila;
	
	for(int i=0;i<5;i++) { 
		pila.push(i+1);
	}
	
	for(int i=0;i<5;i++) { pila.pop(); }
	pila.push(80);
	
	while(!pila.empty()) { 
		cout << pila.top() << " ";
		pila.pop();
	}
	
	
	return 0;
}
