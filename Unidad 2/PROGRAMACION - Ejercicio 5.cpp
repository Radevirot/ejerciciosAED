#include <iostream>
#include <list>
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
	
void mostrar_LL(list<list<int>> &LL){
	for( list<list <int>>::iterator it=LL.begin(); it!=LL.end(); ++it ) { 
		mostrar_lista(*it); cout << ", ";
	}
}
	
void junta(list<int> &L, int c){
	
	if (c<=1) return;
	
	int suma=0;
	int cont=0;
	list<int>::iterator itB=L.begin(),itE=L.end();
	list<int> aux;
	while(itB!=itE){
		if(cont!=c){
			suma+=*itB;
			itB=L.erase(itB);
			++cont;
		} else{
			aux.push_back(suma);
			suma=0;
			cont=0;
		}
	}
	if (cont!=0) aux.push_back(suma);
	
	L.swap(aux);
	
}
	
	
int main(int argc, char *argv[]) {
	
	list<int> L=generar_lista(7);
	mostrar_lista(L);
	junta(L,3);
	mostrar_lista(L);
	
	return 0;
}
