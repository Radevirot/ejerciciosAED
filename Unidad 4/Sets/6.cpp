#include <iostream>
#include <vector>
#include "./5.cpp"
using namespace std;

/*
IncluyeTodo. Dados n conjuntos A0, A1, ... An-1 determinar si alguno de ellos (digamos Aj )
incluye a todos los otros. Es decir Aj subconj Ak para todo k. En ese caso, retornar el indice j, si no
retornar -1. Signatura: int includes_all(vector< set<int> > &setv).
*/
/*
Para resolver este ejercicio se reutilizará la función cubre_todo del ejercicio 5.
*/


int includes_all(vector< set<int> > &setv){
	
	for(size_t i=0;i<setv.size();++i) { 
		if(cubre_todo(setv,setv[i])) return i;
	}
	return -1;
}



int main() {
	
	set<int> a={1,3},b={4,5},c={2},W={1,2,3,4,5,6};
	
	vector<set<int>> v; v.push_back(a); v.push_back(b); v.push_back(c); 
	v.push_back(W);
	
	cout << includes_all(v);
	
	return 0;
}

