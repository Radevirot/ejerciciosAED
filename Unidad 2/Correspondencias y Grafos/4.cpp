#include <iostream>
#include <map>
#include <list>
#include "./listcomp.cpp"
using namespace std;

void merge_map(map<int, list<int>> &A, map<int, list<int>> &B, map<int, list<int>> &C){
	
	auto itA=A.begin();
	
	while (!A.empty()){
		auto itExtra=B.find(itA->first);
		if (itExtra!=B.end()){
			list<int> aux;
			(itExtra->second).sort();
			aux.merge(itExtra->second);
			(itA->second).sort();
			aux.merge(itA->second);
			C[itA->first]=aux;
			itA = A.erase(itA);
			B.erase(itExtra);
		} else {
			C[itA->first]=itA->second;
			itA = A.erase(itA);
		}
	}
	
	auto itB=B.begin();
	
	while (!B.empty()){
		C[itB->first]=itB->second;
		itB = B.erase(itB);
	}
	
	
}


int main() {
	
	map<int,list<int>> A={{1,{1,2,3,90,56,32}},{2,{4,5,6,90}}}, B={{1,{4,8,2,1,3,5,6}},{3,{4,56,6,7}}},C;
	mostrar_map(A);mostrar_map(B);
	merge_map(A,B,C);
	mostrar_map(C);
	
	return 0;
}







