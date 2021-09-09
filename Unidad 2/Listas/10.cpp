#include <iostream>
#include <string>
#include <list>
using namespace std;

list<int> generar_lista(int tam){
	list<int> lista;
	for(int i=0; i<tam; i++){
		lista.push_back(rand()%100+1);
	}
	return lista;
}
	
void mostrar_lista(list<string> &L){
	cout << "[";
	for( list<string>::iterator it=L.begin(); it!=--L.end(); ++it ) {cout << *it << ",";}
	cout << *(--L.end()) << "]" << endl;
}
	
list<string> josephus(list<string> &nombres,int n){
	int randomSoldier=0, contador=0;
	list<string> sortedNames;
	list<string>::iterator itB=nombres.begin();
	advance(itB,randomSoldier-1);
	while(!nombres.empty()){
		cout << contador << endl;
		if(contador==n){
			sortedNames.push_back(*itB);
			itB = nombres.erase(itB);
			contador=0;
			itB--;
		}
		if(++itB==nombres.end()){
			itB=nombres.begin();
		}
		
		
		++contador;
	}
	return sortedNames;
}

int main(int argc, char *argv[]) {
	
	list<string> L{"A","B","C","D","E","F","G","H"};
	mostrar_lista(L);
	list<string> nueva=josephus(L,3);
	mostrar_lista(nueva);
	
	
	return 0;
}

