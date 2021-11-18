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

int factorial(int a){   //Recordando cómo funciona la recursividad...
  
  if (a==0||a==1) 
    return 1; 
  else 
    return a*factorial(a-1);
  
}

  
int contarNodosAOO(tree<int> &T, node_t n){ //Ejercicio propio
  
  //Si cantidad vale 1, se sumará 1 por cada vez que se llame a la recursividad,
  //y eso contará todos los nodos.
  //Si vale 0, solamente se sumará 1 con el "return 1", que se utiliza cada vez
  //que el algoritmo alcanza una hoja, por lo que contará todas las hojas.
  int cantidad=1;
  auto c=n.lchild();
  if(c==T.end()){
    //Si en este return se devuelve 0, las hojas no se cuentan.
    //Si se devuelve 1, las hojas se cuentan.
    return 1;
  } else {
    while(c!=T.end()){
      cantidad+=contarNodosAOO(T,c);  
      ++c;
    }
    
  }
  return cantidad;
  
}
  

int alturaAOO(tree<int> &T, node_t n){ //Ejercicio A.

  int alturamax = 1;
  int h;
  auto c = n.lchild();
  
  if (c==T.end()){
    return 1;
  } else{
    while(c!=T.end()){
      h = alturaAOO(T,c);
      if(h>alturamax){
        alturamax=h;
      }
      ++c;
    }
    return 1+alturamax;
  }
  
  
}
  
  
int contarHojasAOO(tree<int> &T, node_t n){ //Ejercicio B
  
  int cantidad=0;
  auto c=n.lchild();
  if(c==T.end()){
    return 1;
  } else {
    while(c!=T.end()){
      cantidad+=contarHojasAOO(T,c);
      ++c;
    }
    
  }
  return cantidad;
  
  
}
  
  
int obtenerEtiquetaMaxAOO(tree<int> &T, node_t n){ //Ejercicio C
  
  int max=-1;
  
  auto c=n.lchild();
  if(c==T.end()){
    return (*n);
  } else{
    while(c!=T.end()){
      int m = obtenerEtiquetaMaxAOO(T, c);
      if (*c>max){
        max=*c;
      }
      if (m>max){
        max=m;
      }
      ++c;
    }
    
  }
  return max;
  
  
}
  
  
int obtenerEtiquetaMaxParAOO(tree<int> &T, node_t n){ //Ejercicio D
  
  int max=-1;
  
  auto c=n.lchild();
  if(c==T.end()){
    if (*n%2==0){
      return (*n);
    } else{
      return 0;
    }
    
  } else{
    while(c!=T.end()){
      int m = obtenerEtiquetaMaxParAOO(T, c);
      if((*c)%2==0 && (*c)>max){
        max=*c;
      }
      if (m>max){
        max=m;
      }
      ++c;
    }
    
  }
  return max;
  
  
}
  

  
int obtenerEtiquetaMaxHojaAOO(tree<int> &T, node_t n){  //Ejercicio E
  
  int max=-1;
  
  auto c=n.lchild();
  if(c==T.end()){
    return (*n);
  } else{
    while(c!=T.end()){
      int m = obtenerEtiquetaMaxHojaAOO(T, c);
      if (m>max){
        max=m;
      }
      ++c;
    }
    
  }
  return max;
  
  
}
  
  
int obtenerSumaEtiquetasAOO(tree<int> &T, node_t n){ //Ejercicio F
  
  int suma=*n;
  
  auto c=n.lchild();
  if(c==T.end()){
    return (*n);
  } else{
    
    while(c!=T.end()){
      suma += obtenerSumaEtiquetasAOO(T, c);
      ++c;
      
    }
    
  }
  return suma;
  
  
}
  
void BorrarImparesAOO(tree<int> &T, node_t n){ //Ejercicio G
  

  while(n!=T.end()){
    if(*n%2==1){
      n = T.erase(n);
    } else {
      auto c=n.lchild();
      BorrarImparesAOO(T,c);
      ++n;
    }
  }  
  
}
  
  
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
  
void get_path(tree<int> &T, int n, list<int> &L){
  
  get_path(T,T.begin(),n,L);
  
}
  
float prom_path(tree<int> &T) {
  list<int> H;
  float prom=0;
  get_leaves(T,H);
  mostrar_lista(H); cout << endl << endl;
  auto itH=H.begin();
  while (itH!=H.end()){
    list<int> L;
    get_path(T,*itH,L);
    mostrar_lista(L); cout << "tamanio: ";
    prom+=L.size();
    cout << L.size() << endl;
    ++itH;
  }
  cout << "tamanio H:" << H.size() << endl;
  cout << "suma de tamanios: " << prom << endl;
  prom=prom/H.size();
  cout << "prom antes de restar: " << prom;
  return --prom;
  
}
  
int main() {
  
  tree<int> T;
  list<int> L;
  
//  lisp2tree("(4 (2 (1 3 5) 7) (6))",T);
  
//  lisp2tree("(5 (1 8 (9 2)) (7 3))",T);
  
  lisp2tree("(8 (2 (10 7 40 (658 2 2) 7 (711 650 (2 651 (6 (7 6 9))) 4 90))) (4 (5 124 345)))",T);
  
//  lisp2tree("(1 (1 (1 1 1 (1 1 1) 1 (1 1 (1 1 (1 (1 1 1))) 1 1))) (1 (1 1 1)))",T);
  
  
  
  cout << prom_path(T);
  
  mostrar_lista(L);
  
  
  tree2dot(T,"arbol");
  
  
  return 0;
}
  
