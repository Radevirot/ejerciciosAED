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

void preorden(btree<int> &T, list<int> &L, node_bt n){
  
  if (n!=T.end()){
    L.push_back(*n);
  } else {
    return;
  }
  
  
  auto lc = n.left();
  auto rc = n.right();
  preorden(T, L, lc);
  preorden(T, L, rc);

  
}

  
void postorden(btree<int> &T, list<int> &L, node_bt n){
  
  if (n==T.end()){
    return;
  }
  
  auto lc = n.left();
  auto rc = n.right();
  postorden(T, L, lc);
  postorden(T, L, rc);
  
  L.push_back(*n);
  
}
  
void inorden(btree<int> &T, list<int> &L, node_bt n){
  
  if (n==T.end()){
    return;
  }
  
  auto lc = n.left();
  auto rc = n.right();
  inorden(T, L, lc);
  L.push_back(*n);
  inorden(T, L, rc);
  

  
}

int main() {

  btree<int> T;
  list<int> L;
  
  lisp2btree("(1 (2 3 (5 6 7)) (4 8 (9 10 11)))",T);
  
  inorden(T, L, T.begin());
  
  mostrar_lista(L);
  
  btree2dot(T,"arbol");
  
  
  return 0;
}
