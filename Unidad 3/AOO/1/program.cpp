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

typedef tree<int>::iterator node_t;

void ListarAOOPre(tree<int> &T, list<int> &L, node_t n){
  L.push_back(*n);
  auto c = n.lchild();
  while(c!=T.end()){
    ListarAOOPre(T, L, c);
    ++c;
  }
  
}
  
void ListarAOOPost(tree<int> &T, list<int> &L, node_t n){
  auto c = n.lchild();
  while(c!=T.end()){
    ListarAOOPost(T, L, c);
    ++c;
  }
  L.push_back(*n);
}
  
  
  int main() {
    
    tree<int> T;
    list<int> L;
    
    lisp2tree("(1 (2 (3 7 40 5 7 (3 1 2 4 90))) (4 (5 123 345)))",T);
    
    ListarAOOPost(T, L, T.begin());
    
    mostrar_lista(L);
    
    tree2dot(T,"arbol");
    
    
    return 0;
  }
  
