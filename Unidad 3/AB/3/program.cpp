#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <map>
#include "aedtools/graphviz.hpp"
#include "aedtools/listcomp.cpp"

using namespace aed;
using namespace std;

typedef btree<int>::iterator node_bt;

/*
Profundidad. Escribir una funcion int cant_nodos_prof(btree<int> &A, int prof) que
retorna el numero de nodos de un arbol binario A que estan a profundidad prof o mayor.
*/

int cant_nodos_prof_eqorgreater(btree<int> &T, node_bt n, int prof){
  
  int accum=0;
  
  if (n==T.end()) return 0;
  if (prof<=0) ++accum;

  accum += cant_nodos_prof_eqorgreater(T,n.left(),prof-1)+cant_nodos_prof_eqorgreater(T,n.right(),prof-1);
  
  return accum;
}

int cant_nodos_prof_eqorgreater(btree<int> &T, int prof){
  
  cant_nodos_prof_eqorgreater(T,T.begin(),prof);
  
}

int cant_nodos_prof(btree<int> &T, node_bt n, int prof){
  
  int accum=0;
  
  if (n==T.end()) return 0;
  if (prof==0) return 1;
  
  accum += cant_nodos_prof(T,n.left(),prof-1)+cant_nodos_prof(T,n.right(),prof-1);
  
  return accum;
}
  
int cant_nodos_prof(btree<int> &T, int prof){
  
  cant_nodos_prof(T,T.begin(),prof);
  
}  


int main() {

  btree<int> T;
//  list<int> L;
  
  lisp2btree("(1 (2 3 (5 6 7)) (4 8 (9 10 11)))",T);
  
  cout << cant_nodos_prof(T,2);
  
//  mostrar_lista(L);
  
  btree2dot(T,"arbol");
  
  
  return 0;
}
