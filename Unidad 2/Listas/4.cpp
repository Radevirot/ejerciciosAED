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
	
void invert(list<int> &L){
	list<int>::iterator itB=L.begin(), itE=(--L.end()), itB_next=(++L.begin());
	while(itB!=itE){
		swap(*itB,*itE);
		if (itB_next==itE) break;
		++itB; --itE; ++itB_next;
	}
	
}
	

int main(int argc, char *argv[]) {
	
	list<int> L=generar_lista(14);
	mostrar_lista(L);
	invert(L);
	mostrar_lista(L);
	
	return 0;
}

