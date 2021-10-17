#include <iostream>
#include <map>
#include <list>
#include "./listcomp.cpp"
using namespace std;

void list2map(map<int,int> &M, list<int> &Claves, list<int> &Valores) {
	
	list<int>::iterator itCB=Claves.begin(),itVB=Valores.begin();
	while(itCB!=Claves.end()){
		
		if (itVB!=Valores.end()){
			M[*itCB] = *itVB;
			++itVB;
		} else{
			M[*itCB] = 0;
			
		}
		
		++itCB;
	}
	
}


int main() {
	
	list<int> C ={4,4,4,4}, V = generar_lista(8);
	map<int,int> M;
	
	mostrar_lista(C); mostrar_lista(V);
	
	list2map(M,C,V);
	
	mostrar_map(M);
	
	return 0;
}







