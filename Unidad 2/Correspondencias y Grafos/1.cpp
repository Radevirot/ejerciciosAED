#include <iostream>
#include <map>
#include <list>
#include "./listcomp.cpp"
using namespace std;

void map2list(map<int,int> &M, list<int> &Claves, list<int> &Valores){
	map<int,int>::iterator itB=M.begin();
	while(itB!=M.end()){
		Claves.push_back(itB->first);
		Valores.push_back(itB->second);
		++itB;
	}
	
}

int main() {
	
	map<int,int> M={{2,8},{6,9},{4,15},{27,1}};
	list<int> Claves, Valores;
	map2list(M,Claves,Valores);
	mostrar_lista(Claves); mostrar_lista(Valores);
	
	
	return 0;
}







