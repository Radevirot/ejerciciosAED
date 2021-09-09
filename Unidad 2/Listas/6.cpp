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
	
void reemplaza(list<int> &L, list<int> &SEQ, list<int> &REEMP){
	list<int> aux;
	list<int>::iterator itB=L.begin(),itE=L.end(),itAux,itAuxEnd;
	int tam=SEQ.size();
	while (itB!=itE){
		itAux=itB; itAuxEnd=itAux; advance(itAuxEnd,(tam));
		for(; itAux!=itAuxEnd; ++itAux ) {
			aux.push_back(*itAux);
		}
		if(aux==SEQ){
			for(int i=0;i<tam;i++) { itB = L.erase(itB); }
			L.insert(itB,REEMP.begin(),REEMP.end());
			aux.clear();
		} else { 
			aux.clear(); 
		}
		++itB;
		
	}
	
	
}
	
	

int main(int argc, char *argv[]) {
	
	list<int> L ={1,2,3,4,5,1,2,3,4,5,1,2,3,4,5}, SEQ={4,5,1}, REEMP={9,7,3};
	
	mostrar_lista(L);
	reemplaza(L,SEQ,REEMP);
	mostrar_lista(L);
	
	return 0;
}

