#include <iostream>
#include <map>
#include <list>
#include <graphviz.hpp>
#include "./listcomp.cpp"
using namespace std;
typedef map<int,list<int>> graph;

void comp_conexas(graph &G, list<list<int>> &D){
	auto itG=G.begin();
	
	while (itG!=G.end()){	//Recorro todo el grafo
		
		auto itSubL=(itG->second).begin();	//Creo un iterador de la lista a la que apunta el elemento del map
		
		while (itSubL!=(itG->second).end()){	//Recorro toda la sublista
			
			graph::iterator itExtra=G.find(*itSubL);	//Por cada elemento de la sublista, reviso si es una clave del map
			if(itExtra!=G.end()){						//Si es una clave del map
				
				auto itSubL2=(itExtra->second).begin(); //Creo un iterador de la segunda sublista
				while(itSubL2!=(itExtra->second).end()){	//Recorro toda la sublista
					
					if(*itSubL2==(itG->first)){		//Si el valor de la segunda sublista corresponde con la clave del primer valor del map
						list<int> aux;				//Creo una lista auxiliar
						aux.push_back(itG->first);	//Inserto en la lista auxiliar la clave original
						aux.push_back(*itSubL);		//Y el elemento de la sublista que se detectó espejado
						D.push_back(aux);			//Inserto la lista auxiliar en la lista D
						
					}
					++itSubL2;
				}
			}
			++itSubL;
		}
		itG = G.erase(itG);	//Borro la posición actual del grafo para no obtener resultados repetidos
	}
	
}


int main() {
	
	graph G={{1,{2,3}},{2,{1,3}},{3,{1,2,4}},{4,{2,3}}};
	list<list<int>> D;
	comp_conexas(G,D);
	mostrar_LL(D);
	
	
	
	
	return 0;
}







