#include <iostream>
#include "./set_utilities.cpp"
#include <list>
using namespace std;

/*
DiferenciaSim´etrica. Dada una lista de conjuntos de enteros list< set<int> > l escribir una
funci´on void diffsym(list< set<int> > &L, set<int> &ad) que retorna en ad el conjunto de
los elementos que pertenecen a uno y s´olo uno de los conjuntos de L. Por ejemplo, si
L = ({1,2,3},{2,4,5},{4,6}) entonces ad = {1,3,5,6}. Notar que si el n´umero de conjuntos
en L es 2 y los llamamos A y B, entonces debe retornar ad = (A-B-C-D)U(D-C-B-A).
*/

void symDiff(list<set<int>> &L, set<int> &ad){
	
	auto itL=L.begin();
	
	while (itL!=L.end()){
		
		set<int> dif=*itL;
		
		auto itL2=L.begin();
		while (itL2!=L.end()){
			if(itL2==itL){++itL2; continue;}
			set<int> aux;
			
			set_difference(dif,*itL2,aux);
			
			dif=aux;
			
			++itL2;
		}
		
		
		ad.insert(dif.begin(),dif.end());
		++itL;
	}
	
}

	
int main() {
	
	list<set<int>> L={{1,2,3},{2,4,5},{4,6}};
	set<int> sd;
	
	symDiff(L,sd);
	
	mostrarSet(sd);
	
	
	return 0;
}

