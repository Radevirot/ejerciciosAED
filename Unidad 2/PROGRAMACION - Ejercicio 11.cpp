#include <iostream>
#include <list>
using namespace std;

void mostrar_lista(list<char> &L){
	cout << "[";
	for( list<char>::iterator it=L.begin(); it!=--L.end(); ++it ) {cout << *it << ",";}
	cout << *(--L.end()) << "]" << endl;
}

void invert(list<char> &L){
	list<char>::iterator itB=L.begin(), itE=(--L.end()), itB_next=(++L.begin());
	while(itB!=itE){
		swap(*itB,*itE);
		if (itB_next==itE) break;
		++itB; --itE; ++itB_next;
	}
	
}
	
bool is_palindromo(char* S){
	list<char> aux;
	for(int i=0;S[i]!='\0';++i) {
		if(S[i]!=' ') aux.push_back(S[i]); 
	}
	list<char> auxinv=aux;
	invert(auxinv);
	
	return (aux==auxinv);
}


int main(int argc, char *argv[]) {
	
	if (is_palindromo((char*)"anita lava la tina")) cout<<"Sí."<<endl;
	else cout<<"No."<<endl;
	
	return 0;
}

