#include <iostream>
#include <list>
#include <vector>
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
	cout << *(--L.end()) << "]";
}
	
void mostrar_LL(list<list<int>> &LL){
	for( list<list <int>>::iterator it=LL.begin(); it!=LL.end(); ++it ) { 
		cout << endl;
		mostrar_lista(*it);
	}
}
	
void asc1(list<int> &L, list<list<int>> &LL){
	list<int>::iterator it=L.begin();
	list<int>::iterator it_next=++(L.begin());
	list<int> aux;
	while(it!=L.end()){
		aux.push_back(*it);
		if(*it_next<*it){
			LL.push_back(aux);
			aux.clear();
		}
		++it; ++it_next;
	}
}
	
	
int main(int argc, char *argv[]) {
	
	list<int> L = generar_lista(20);
	mostrar_lista(L);
	list<list<int>> LL;
	asc1(L,LL);
	mostrar_LL(LL);
	
	return 0;
}
	
