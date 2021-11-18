#include <iostream>
#include <vector>
#include "./set_utilities.cpp"
using namespace std;

/*
CubreTodo. Escribir una funci�on predicado cubre_todo(vector<set<T>>&v, set<T>& W) que
verifica si todos los conjuntos en el vector de conjuntos v est�an incluidos en W.
*/

/*
Para el prop�sito de este ejercicio, se comenzar� programando una funci�n
bool isSubset(set<T> &a, set<T> &b) que detecte cu�ndo un conjunto es subconjunto
de otro, y luego se utilizar� dicha funci�n en la solicitada inicialmente.

Esta ser� escrita en "set_utilities.cpp" por ser considerada una utilidad.
*/

template <class T>
bool cubre_todo(vector<set<T>>&v, set<T>& W){
	
	auto itV=v.begin();
	while (itV!=v.end()){
		if (!isSubset(*itV,W)) return false;
		++itV;
	}
	
	return true;
}


// El main se encuentra comentado para poder utilizar este cpp
// en el ejercicio 6, en caso de necesitar usar el programa, descomentarlo.
//int main() {
//	
//	set<int> a={1,3},b={4,5},c={2},W={1,2,3,4,5,6};
//	
//	vector<set<int>> v; v.push_back(a); v.push_back(b); v.push_back(c); 
//	
//	cout << cubre_todo(v,W);
//	
//	return 0;
//}

