#include <iostream>
#include <list>
#include <queue>
#include "./listcomp.cpp"
using namespace std;
	
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
	

int main(int argc, char *argv[]) {
	
	list<int> L ={1,7,8,2,3}, S ={2,2,2,2,2};
	mostrar_lista(L); mostrar_lista(S);
	
	compacta(L,S);
	
	mostrar_lista(L); mostrar_lista(S);
	
	return 0;
}

