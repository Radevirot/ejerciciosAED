#include <iostream>
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
		mostrar_lista(*it); cout << ", ";
	}
}

void mostrar_map(map<int,int> &M){
	
	cout << "[";
	for( map<int,int>::iterator it=M.begin(); it!=--M.end(); ++it ) {
		cout << it->first << " -> " << it->second << endl;
	}
	cout << (--M.end())->first << " -> " << (--M.end())->second << "]" << endl;
	
}

void mostrar_map(map<int,list<int>> &M){
	
	cout << "{";
	for( map<int,list<int>>::iterator it=M.begin(); it!=--M.end(); ++it ) {
		cout << it->first << " -> ";
		mostrar_lista(it->second);
		cout << endl;
	}
	cout << (--M.end())->first << " -> ";
	mostrar_lista((--M.end())->second);
	cout << "}" << endl;
	
}
