#include <iostream>
#include <map>
#include <list>
#include <graphviz.hpp>
#include "./listcomp.cpp"
using namespace std;
typedef map<int,list<int>> graph;

bool es_camino(graph G, list<int> &L){
	bool adyacente=false;
	auto itL=L.begin();
	
	while (itL!=--L.end()){					//Hago el loop hasta terminar la lista de la sucesión de vértices del camino
		auto itG=G.find(*itL);				//Hago que el iterador del grafo se ubique en el primer/próximo vértice de la lista
		++itL;								//Paso al próximo vértice de la lista
		auto itAdy = itG->second.begin();	//Iterador que apunta al principio de la lista de vértices adyacentes de un vértice
		
		while (itAdy != itG->second.end()){	//Recorro la lista de vértices adyacentes completa
			
			if (*itAdy == *itL) {			//Si dentro de la lista de vértices adyacentes encuentro el siguiente vértice del camino
				
				adyacente=true;				//Indico que efectivamente son adyacentes
				break;						//Y corto la recorrida de vértices adyacentes (porque ya sé que hay uno adyacente)
			}
			++itAdy;
			
		}
		
		if (!adyacente) return false; 		//Si no es adyacente, directamente retorno que no es un camino.
		adyacente=false;					//Reseteo el valor de verdad del adyacente.
	}
	
	return true;							//Si logra salir del ciclo luego de recorrer toda la lista de sucesión de vértices, significa que es un camino.
}


int main() {
	
	graph G={{1,{2,3}},{2,{}},{3,{4}},{4,{}}};
	list<int> L={1,6};
	
	
	if (es_camino(G,L)) cout << "si"; else cout << "no";
	
	
	return 0;
}







