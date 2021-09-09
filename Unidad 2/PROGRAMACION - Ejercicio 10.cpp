#include <iostream>
#include <list>
#include <queue>
using namespace std;

list<int> generar_lista(int tam){
	list<int> lista;
	for(int i=0; i<tam; i++){
		lista.push_back(rand()%10+1);
	}
	return lista;
}
	
void mostrar_lista(list<int> &L){
	cout << "[";
	for( list<int>::iterator it=L.begin(); it!=--L.end(); ++it ) {cout << *it << ",";}
	cout << *(--L.end()) << "]" << endl;
}
	
void compacta(list<int> &L,list<int> &S){
	list<int>::iterator SitB=S.begin(),SitE=S.end(),LitB=L.begin();
	int suma=0;
	while(SitB!=SitE){
		if((*SitB)>0){
			for(int i=0;i<*SitB;i++) { 
				suma+=(*LitB);
				LitB = L.erase(LitB);
				if (LitB==L.end()) break;
			}
			L.insert(LitB,suma);
			suma=0;
			if (LitB==L.end()) return;
		}
		
		++SitB;
	}
}
	
void compactaC(list<int> &L,list<int> &S){
	
	priority_queue<int> Q;
	list<int>::iterator SitB=S.begin(),SitE=S.end(),LitB=L.begin();
	int suma=0;
	while(SitB!=SitE){
		if((*SitB)>0){
			for(int i=0;i<*SitB;i++) { 
				suma+=(*LitB);
				LitB = L.erase(LitB);
				if (LitB==L.end()) break;
			}
			Q.push(suma);
			suma=0;
			if (LitB==L.end()) return;
		}
		
		++SitB;
	}
	while(!Q.empty()){
		L.insert(LitB,Q.top());
		Q.pop();
	}
}

int main(int argc, char *argv[]) {
	
	list<int> L ={1,7,8,2,3}, S ={2,2,2,2,2};
	mostrar_lista(L); mostrar_lista(S);
	
	compacta(L,S);
	
	mostrar_lista(L); mostrar_lista(S);
	
	return 0;
}

