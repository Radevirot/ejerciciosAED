#include <iostream>
#include <iostream>
#include <map>
#include <list>
#include <graphviz.hpp>
#include "./listcomp.cpp"
using namespace std;
typedef map<int,list<int>> graph;

bool es_camino(graph G, list<int> &L){  //Reutilizo la funci�n que verifica si son caminos
	bool adyacente=false;
	auto itL=L.begin();
	
	while (itL!=--L.end()){					//Hago el loop hasta terminar la lista de la sucesi�n de v�rtices del camino
		auto itG=G.find(*itL);				//Hago que el iterador del grafo se ubique en el primer/pr�ximo v�rtice de la lista
		++itL;								//Paso al pr�ximo v�rtice de la lista
		auto itAdy = itG->second.begin();	//Iterador que apunta al principio de la lista de v�rtices adyacentes de un v�rtice
		
		while (itAdy != itG->second.end()){	//Recorro la lista de v�rtices adyacentes completa
			
			if (*itAdy == *itL) {			//Si dentro de la lista de v�rtices adyacentes encuentro el siguiente v�rtice del camino
				
				adyacente=true;				//Indico que efectivamente son adyacentes
				break;						//Y corto la recorrida de v�rtices adyacentes (porque ya s� que hay uno adyacente)
			}
			++itAdy;
			
		}
		
		if (!adyacente) return false; 		//Si no es adyacente, directamente retorno que no es un camino.
		adyacente=false;					//Reseteo el valor de verdad del adyacente.
	}
	
	return true;			//Si logra salir del ciclo luego de recorrer toda la lista de sucesi�n de v�rtices, significa que es un camino.
}

bool isHamilt(graph G, list<int> &L){
	
	
	if (!es_camino(G,L)) return false;	//Si no es camino, no es camino hamiltoniano
	if (L.size()!=G.size()) return false;	//Si la cantidad de v�rtices a recorrer no coincide con la del grafo, entonces no es camino hamiltoniano.
	
	auto itL=L.begin();
	auto itL2=L.begin();
	
	while (itL!=--L.end()){		//Si se repiten v�rtices dentro de la lista de v�rtices a recorrer, no es hamiltoniano
		++itL2;
		while (itL2!=L.end()){
			if (*itL==*itL2) return false;
			++itL2;
		}
		itL2 = ++itL;
	}
	
	L.sort();	//Ordeno la lista de v�rtices para poder comparar con los del grafo
	itL=L.begin();
	auto itG = G.begin();
	
	while (itL!=L.end()){	
		if (*itL!=itG->first) return false;	//Si en alg�n momento no coinciden los v�rtices de la lista con los del grafo, no es camino hamiltoniano.
		++itL;
		++itG;
	}
	
	return true;
	
	
}

int main() {
	
	graph G={{1,{2,3}},{2,{3,4}},{3,{2,4}},{4,{2}}};
	list<int> L={1,3,4,2};
	
	
	if (isHamilt(G,L)) cout << "si"; else cout << "no";
	
	return 0;
}







