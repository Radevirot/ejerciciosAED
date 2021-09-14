#include <iostream>
#include <list>
using namespace std;

list<int> generar_lista(int tam){
	list<int> lista;
	for(int i=0; i<tam; i++){
		lista.push_back(rand()%100+1);
	}
	return lista;
}
	
void mostrar_lista(list<int> &L){
	cout << "[";
	for( list<int>::iterator it=L.begin(); it!=--L.end(); ++it ) {cout << *it << ",";}
	cout << *(--L.end()) << "]" << endl;
}

list<int> mediaMovilEntera(list<int>&l,int v){
	list<int> resultado;
	if (v==0) return resultado;
	list<int>::iterator itB=l.begin(),itE=l.end(),itBProm;
	advance(itE,-v+1);

	while(itB!=itE){
		int suma=0;
		itBProm=itB;
		
		for(int i=0;i<v;i++) { 
			suma+=*itBProm;
			++itBProm;
		}
		resultado.push_back(suma/v);
		
		++itB;
	}
	
	return resultado;
}
	
	
int main(int argc, char *argv[]) {
	
	
	list<int> A=generar_lista(5); mostrar_lista(A);
	list<int> B=mediaMovilEntera(A,2);
	mostrar_lista(B);
	
	return 0;
}

