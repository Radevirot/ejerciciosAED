#include <iostream>
#include <list>
#include <stdlib.h>
#include <time.h> 
using namespace std;

list<int> generar_lista(int tam){
	list<int> lista;
	for(int i=0; i<tam; i++){
		lista.push_back(rand()%100+1);
	}
	return lista;
}
	
void mostrar_lista(list<int> &L){
	cout << "[";
	for( list<int>::iterator it=L.begin(); it!=--L.end(); ++it ) {cout << *it << ",";}
	cout << *(--L.end()) << "]" << endl;
}
	
list<int> concatena_ins(list<int> &L1,list<int> &L2){
	list<int> L;
	L.insert(L.begin(),L1.begin(),L1.end());
	L.insert(L.end(),L2.begin(),L2.end());
	return L;
}
	
list<int> concatena_sublistsins(list<list <int>> &LL){
	list<int> L;
	for( list<list <int>>::iterator it=LL.begin(); it!=LL.end(); ++it ) { 
		L.insert(L.end(),(*it).begin(),(*it).end());
	}
	return L;
}
	
list<int> concatena_sublistspl(list<list <int>> &LL){
	list<int> L;
	for( list<list <int>>::iterator it=LL.begin(); it!=LL.end(); ++it ) { 
		L.splice(L.end(),(*it));
	}
	return L;
}

int main() {
	
	list<int> L=generar_lista(3);
	list<int> L2=generar_lista(3);
	list<int> L3=generar_lista(3);
	list<list <int>> LL{L,L2,L3};
	for( list<list <int>>::iterator it=LL.begin(); it!=LL.end(); ++it ) { 
		mostrar_lista(*it);
	}
	list<int> LConc = concatena_sublistspl(LL);
	mostrar_lista(LConc);
	
	
	
	
	return 0;
}

