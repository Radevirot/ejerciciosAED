#include <iostream>
#include "./set_utilities.cpp"
using namespace std;

/*
Operaciones. Escribir las funciones
a
0 void set_union(set<T> &A,set<T> &B,set<T> &C);
b
0 void set_intersection(set<T> &A,set<T> &B,set<T> &C);
c
0 void set_difference(set<T> &A,set<T> &B,set<T> &C);
en t´erminos de los restantes m´etodos de la interfase de set.
*/

template <class T>
void set_union(set<T> &A,set<T> &B,set<T> &C){
	C.insert(A.begin(),A.end());
	C.insert(B.begin(),B.end());
}

template <class T>
void set_intersection(set<T> &A,set<T> &B,set<T> &C){
	typename set<T>::iterator itA=A.begin();
	
	while(itA!=A.end()){
		if(B.find(*itA)!=B.end()){
			C.insert(*itA);
		}
		++itA;
	}
	
	
}

template <class T>
void set_difference(set<T> &A,set<T> &B,set<T> &C){
	typename set<T>::iterator itA=A.begin();

	while(itA!=A.end()){
		if(B.find(*itA)==B.end()){
			C.insert(*itA);
		}
		++itA;
	}
	
	
}
	
int main() {
	
	set<int> a,b,c;
	
	a={4,1,2,6}; b={4,1,5,7};
	
//	randomSet(a,10,100);
//	randomSet(b,10,100);
	mostrarSet(a); mostrarSet(b);
	
	cout << endl;
	
	set_union(a,b,c); mostrarSet(c);
	c.clear();
	
	set_intersection(a,b,c); mostrarSet(c);
	c.clear();
	
	set_difference(a,b,c); mostrarSet(c);
	c.clear();
	
	return 0;
}

