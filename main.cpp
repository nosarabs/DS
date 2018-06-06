//#include "llist.h"
//#include "bstree.h"
#include "rbtree.h"
#include "hasht.h"
#include <stdio.h>
#include <time.h>
#define tam 1000000

int main () {

  stack<int> s;
  //
  // // PRUEBAS ARBOL
  //
  // t.secTree();
  // //t.inorderTreeWalk(t.getRoot(), s);
  // std::cout << "creado" << '\n';
  //
  // int conta = 0;
  // int num1;
  // long x = time(NULL);
  // long y = x + 10;
  // while (x < y) {
  //   num1 = rand() % (MAX * 2 + 1);
  //   t.iterativeTreeSearch(num1);
  //   ++conta;
  //   x = time(NULL);
  // }
  // std::cout << conta << '\n';

  //rbtree<int> r;
  hasht<int> h(tam);

  for (int i = 0; i<tam-1; ++i) {
    //int num = rand() % (tam * 2 + 1);
    h.insert(i);
  }
  std::cout << "CREADO" << '\n';

  int conta = 0;
  int num1;
  long x = time(NULL);
  long y = x + 10;
  while (x < y) {
    num1 = rand() % (tam * 2 + 1);
    h.search(num1);
    ++conta;
    x = time(NULL);
  }
  std::cout << conta << '\n';









}
