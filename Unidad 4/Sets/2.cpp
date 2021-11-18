#include <iostream>
#include "./set_utilities.cpp"
#include <vector>
using namespace std;

/*
Escribir una funci´on predicado bool disjuntos(vector<set<T>>&v) que verifica si
todos los conjuntos Ai dentro del vector de conjuntos v son disjuntos de a pares
*/


template <class T>
bool disjuntos(vector<set<T>> &v){
	if (v.size()<2) return false;
	
	auto itV1=v.begin(), itV2=++v.begin();
	
	while (itV2!=v.end()){
		set<T> c;
		set_intersection(*itV1,*itV2,c);
		if (!c.empty()) return false;
		++itV1; ++itV2;
	}
	
	return true;
	
}


int main() {
	
	set<int> a,b,c,d;
	a={1,2}; b={3,4}; c={5,6}; d={7,8};
	
	vector<set<int>> v;
	v.push_back(a); v.push_back(b); v.push_back(c); v.push_back(d); 
	
	cout << disjuntos(v);
	
	
	return 0;
}

