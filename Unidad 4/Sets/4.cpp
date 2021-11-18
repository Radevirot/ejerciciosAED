#include <iostream>
#include <list>
#include "./set_utilities.cpp"
using namespace std;

/*
ClasesDeCongruencia. Dado un conjunto S implementar la funci´on
congrClasses(set<int> &S, int m,list<set<int>> &L) que retorna las clases de congruencia
m´odulo m en la lista list<set<int>> L.
*/

void congrClasses(set<int> &S, int m,list<set<int>> &L){
	
	for(int i=0;i<m;i++) { 
		set<int> aux;
		
		auto itS=S.begin();
		while (itS!=S.end()){
			if (*itS%m==i) aux.insert(*itS);
			++itS;
		}
		
		L.push_back(aux);
	}
	
	
	
	
}

int main() {
	
	list<set<int>> L;
	set<int> S={2,4,5,6,7,9};
	congrClasses(S,2,L);
	
	auto itL=L.begin();
	while(itL!=L.end()){
		mostrarSet(*itL);
		++itL;
	}
	
	
	
	
	
	return 0;
}

