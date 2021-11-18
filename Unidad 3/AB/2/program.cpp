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

bool sameStructure(btree<int> &TA, btree<int> &TB, node_bt na, node_bt nb){
  
  if (na==TA.end() && nb==TB.end()) return true;
  
  if((na==TA.end() && nb!=TB.end()) || (nb==TB.end() && na!=TA.end())){
    return false;
  }
  
  if (!sameStructure(TA,TB,na.left(),nb.left())) return false;
  if (!sameStructure(TA,TB,na.right(),nb.right())) return false;

  return true;
  
}

  
bool isMirror(btree<int> &TA, btree<int> &TB, node_bt na, node_bt nb){
  
  if (na==TA.end() && nb==TB.end()) return true;
  
  if((na==TA.end() && nb!=TB.end()) || (nb==TB.end() && na!=TA.end())){
    return false;
  }
  
  if (!isMirror(TA,TB,na.left(),nb.right())) return false;
  if (!isMirror(TA,TB,na.right(),nb.left())) return false;
  
  return true;
  
}
  
bool sameTree(btree<int> &TA, btree<int> &TB, node_bt na, node_bt nb){
  
  if (na==TA.end() && nb==TB.end()) return true;
  
  if(*na!=*nb){
    return false;
  }
  
  if (!sameTree(TA,TB,na.left(),nb.left())) return false;
  if (!sameTree(TA,TB,na.right(),nb.right())) return false;
  
  return true;
  
}
  
void mirrorTree(btree<int> &TA, btree<int> &TB, node_bt na, node_bt nb){
  
  if (na==TA.end()){
    return;
  }
  
  
  auto lc = na.left();
  auto rc = na.right();
  if (lc!=TA.end()) mirrorTree(TA,TB,lc,TB.insert(nb.right(),*lc));
  if (rc!=TA.end()) mirrorTree(TA,TB,rc,TB.insert(nb.left(),*rc));
  
}
  
void mirrorTree(btree<int> &TA, btree<int> &TB){
  
  auto it = TA.begin();
  auto itb = TB.insert(TB.begin(),*it);
  mirrorTree(TA,TB,it,itb);
  
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

  btree<int> TA;
  btree<int> TB;
  list<int> L;
  
//  lisp2btree("(1 (2 3 (5 6 7)) (4 8 (9 10 11)))",TA);
//  lisp2btree("(1 (2 3 (5 6 7)) (4 8 (9 10 11)))",TB);
//  lisp2btree("(5 (5 5 (5 5 5)) (5 5 (5 5 5)))",TB);
  
  lisp2btree("(1 (2 3 (5)) (0 4))",TA);
//  lisp2btree("(1 (0 2 4) (2 3 (5))",TB);
  
  mirrorTree(TA, TB);
  
//  mostrar_lista(L);
  
  btree2dot(TA,"arbol");
  btree2dot(TB,"arbol");
  
  return 0;
}
