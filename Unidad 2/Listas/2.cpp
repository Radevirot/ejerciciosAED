#include <iostream>
#include <list>
using namespace std;

void mostrar_lista(list<int> &L){
	cout << "[";
	for( list<int>::iterator it=L.begin(); it!=--L.end(); ++it ) {cout << *it << ",";}
	cout << *(--L.end()) << "]" << endl;
}

void selection_sort_conaux(list<int> &L){
	
	list<int> L2;
	list<int>::iterator itErase;
	
	while (!L.empty()){
		int minvalue = *(L.begin());
		for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) {
			
			if (*it <= minvalue){
				minvalue=*it;
				itErase=it;
			}
			
		}
		
		L2.push_back(minvalue);
		L.erase(itErase);
	}
	L2.swap(L);
	
}
	
void selection_sort(list<int> &L){
	
	for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) {
		for( list<int>::iterator it2=L.begin(); it2!=L.end(); ++it2 ) {
			if (*it < *it2){
				iter_swap(it2,it);
			}
		}
	}
	
}
	

int main() {
	
	list<int> L{4,3,2,4,1,7,9,4,2,-20,-1,99,56,-4000,500000};
/*	list<int> L2{5,7,4,1};*/
/*	iter_swap((L.begin()),(L2.begin()));*/
	mostrar_lista(L);
	selection_sort(L);
	mostrar_lista(L);
	
	
	return 0;
}

