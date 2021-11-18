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
typedef tree<int>::iterator node_t;

/*
bin2ord. Escribir una funci´on void bin2ord(btree<int> &B, tree<int> &T) que dado un ´arbol
binario B de enteros positivos lo convierte a un ´arbol ordenado orientado con la siguiente
convenci´on: En caso de que uno de los nodos del AB tenga uno s´olo de los hijos reemplazamos el
valor por un valor lambda (en este caso puede ser lambda = -1).
*/

void bin2ord(btree<int> &B, node_bt bn, tree<int> &T, node_t n){
  
  auto lc=bn.left(), rc=bn.right(); auto c=n.lchild();
  
  if (lc==B.end() && rc==B.end()){
    return;
  }

  if (lc==B.end()){
    c=T.insert(c,-1);
    ++c;
    c=T.insert(c,*rc);
    bin2ord(B,rc,T,c);
  } else{
    c=T.insert(c,*lc);
    bin2ord(B,lc,T,c);
    ++c;
    if (rc==B.end()){
      c=T.insert(c,-1);
    } else {
      c=T.insert(c,*rc);
      bin2ord(B,rc,T,c);
    }
    
  }
  
  
  
}

void bin2ord(btree<int> &B, tree<int> &T){
  
  T.insert(T.begin(),*B.begin());
  bin2ord(B,B.begin(),T,T.begin());
  
}

/*
  ord2bin. Escribir la funci´on inversa void ord2bin(tree<int> &T, btree<int> &B) que dado un
  AOO (que supuestamente fue generado por bin2ord) lo convierte de nuevo a AB. (Deber´ia ser
  siempre B=ord2bin(bin2ord(B))).  
*/  
  
  
void ord2bin(tree<int> &T, node_t n, btree<int> &B, node_bt bn){ //Error extraño???
  
  auto c=n.lchild(); auto lc=bn.left(), rc=bn.right(); 
  
  if (c==T.end()){
    return;
  }
  if(*c!=-1){
    lc=B.insert(lc,*c);
    ord2bin(T,c++,B,lc);
  }
  if(*c!=-1){
    rc=B.insert(rc,*c);
    ord2bin(T,c,B,rc);
  }
  
}
  
void ord2bin(tree<int> &T, btree<int> &B){
  
  B.insert(B.begin(),*T.begin());
  ord2bin(T,T.begin(),B,B.begin());
  
}

int main() {

  btree<int> B;
  tree<int> T;
//  list<int> L;
  
  lisp2btree("(1 (2 3 (5 . 7)) (4 8 (9 10 .)))",B);
  
  btree2dot(B,"arbol0");
  
  bin2ord(B,T);
  ord2bin(T,B);
  
//  mostrar_lista(L);
  
  btree2dot(B,"arbol1");
//  tree2dot(T,"arbol");
  
  
  return 0;
}
