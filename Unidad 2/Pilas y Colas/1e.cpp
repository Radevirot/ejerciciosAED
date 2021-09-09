#include <iostream>
#include <stack>
using namespace std;

/*
Asignar i al elemento del fondo de la pila, dejando la pila sin modificar.
*/

int main(int argc, char *argv[]) {
	
	stack<int> pila, pilaux;
	
	for(int i=0;i<5;i++) { 
		pila.push(i+1);
	}
	

	while(!pila.empty()){
		pilaux.push(pila.top());
		pila.pop();
	}
	pilaux.pop();
	pila.push(80);

	while(!pilaux.empty()) { 
		pila.push(pilaux.top());
		pilaux.pop();
	}

	while(!pila.empty()) { 
		cout << pila.top() << " ";
		pila.pop();
	}
	
	
	return 0;
}
