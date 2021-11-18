#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include "./aedtools/graphviz.hpp"
#include "./aedtools/listcomp.cpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <map>

using namespace aed;
using namespace std;
typedef tree<int>::iterator node_t;
void get_path(tree<int> &T,node_t q,int n,list<int> &L){
  
  if(q==T.end()){
    return;
  } else if(*q==n){
    L.push_back(*q);
    return;
  } else {
    
    auto c=q.lchild();
    
    while(c!=T.end()){
      get_path(T, c, n, L);
      if(!L.empty()){
        L.push_front(*q);
        return;
      }
      ++c;
    }
  }
  
}
  
  
void get_path(tree<int> &T, int n, list<int> &L){
  
  get_path(T,T.begin(),n,L);
  
}
  

void classify_relative(tree<int> &T, int n1,int n2,int &m1, int&m2) {
  
  list<int> L1, L2;
  m1=0,m2=0;
  get_path(T,n1,L1); get_path(T,n2,L2);
  
  auto itL1=L1.begin(), itL2=L2.begin(),
    itAux1=L1.begin(), itAux2=L2.begin();
  
  int comun=-1;
  
  while (itL1!=L1.end() && itL2!=L2.end()){
    
    if(*itL1==*itL2){
      comun=*itL1;
      itAux1=itL1;
      itAux2=itL2;
    }
    
    ++itL1; ++itL2;
  }
  
  while(itAux1!=L1.end()){
    ++m1; ++itAux1;
  }
  while(itAux2!=L2.end()){
    ++m2; ++itAux2;
  }
  --m1; --m2;
}


void get_leaves(tree<int> &T, node_t q, list<int> &L){
 
 auto c=q.lchild();
 
 if(q==T.end()) return;
 if (c==T.end()){
   L.push_back(*q);
 }
 while (c!=T.end()){
   get_leaves(T,c,L);
   ++c;
 }
 
}
 
void get_leaves(tree<int> &T, list<int> &L){
 get_leaves(T,T.begin(),L);
}
 
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
float prom_path(tree<int> &T) { // Lamentablemente no avisaba el enunciado que se podían repetir números...
 list<int> H;
 float prom=0;
 get_leaves(T,H);
 auto itH=H.begin();
 while (itH!=H.end()){
   list<int> L;
   get_path(T,*itH,L);
   prom+=(L.size()-1);
   ++itH;
 }
 prom=prom/H.size();
 return prom;
 
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void filtra_deps(map<string, list<string>> &G, list<string> &L) {
  // COMPLETAR AQUI....
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  do {

//    ev.eval<1>(classify_relative,vrbs);
//    h1 = ev.evalr<1>(classify_relative,seed,vrbs);

    ev.eval<2>(prom_path,vrbs);
    h2 = ev.evalr<2>(prom_path,seed,vrbs);
//
//    ev.eval<3>(filtra_deps,vrbs);
//    h3 = ev.evalr<3>(filtra_deps,seed,vrbs);

    printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
           seed,h1,h2,h3);
    
    printf("\n\nIngrese un valor para la semilla:");
  } while (cin>>seed);

  return 0;
}
