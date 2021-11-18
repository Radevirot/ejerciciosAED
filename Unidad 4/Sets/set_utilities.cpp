#include <iostream>
#include <set>
using namespace std;

template <class T>
void mostrarSet(set<T> s){
	
	if(!s.empty()){
		typename set<T>::iterator itS=s.begin();
		
		cout << "{";
		while(itS!=(--s.end())){
			cout << *itS << ", ";
			++itS;
		}
		cout << *itS << "}" << endl;
	} else {
		cout << "{}" << endl;
	}

	
}

void randomSet(set<int> &s, int size, int cap){
	
	for(int i=0;i<size;i++) { 
		int r=rand()%cap+1;
		s.insert(r);
	}
	
}

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

template <class T>
bool isSubset(set<T> &a, set<T> &b){

	auto itA=a.begin();

	while(itA!=a.end()){
		if (b.find(*itA)==b.end()) return false;
		++itA;
	}

	return true;
}	
	
