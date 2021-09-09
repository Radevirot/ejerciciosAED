#include <iostream>
#include <list>
using namespace std;

/*
Escribir una función void basic_sort(list<int> &L), que ordena los elementos de L
de menor a mayor. Para ello emplear el siguiente algoritmo simple: utilizando una lista auxiliar L2,
tomar el menor elemento de L, eliminarlo de L e insertarlo al final de L2 hasta que L este vacía.
Luego insertar los elementos de L2 en L.
*/

void basic_sort(list<int>& L){
	
	list<int> L2;
	
	list<int>::iterator itErase;
	
	while (!L.empty()){
		int minvalue = *L.begin();
		for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) {
			
			if (*it <= minvalue){
				minvalue=*it;
				itErase=it;
			}
			
		}
		
		L2.push_back(minvalue);
		L.erase(itErase);
	}
	for( auto it=L2.begin(); it!=L2.end(); ++it ) { 
		L.push_back(*it);
	}
}

int main() {
	
	list<int> L{6,5,4,8,4,3,2,1};

	for( auto it=L.begin(); it!=L.end(); ++it ) { 
		cout << *it << " ";
	}
	cout << endl;
	
	basic_sort(L);
	cout << endl;
	for( auto it=L.begin(); it!=L.end(); ++it ) { 
		cout << *it << " ";
	}
	cout << endl;
	

	return 0;
}

