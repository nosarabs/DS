//#include "llist.h"
//#include "bstree.h"
#include "rbtree.h"
#include "hasht.h"
#include <stdio.h>
#include <time.h>

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

  // rbtree<int> r;
  //r.secTree(); // arbol de prueba
  // rbnode<int> * x = new rbnode<int>(6);
  // rbnode<int> * y = new rbnode<int>(7);
  // rbnode<int> * z = new rbnode<int>(8);
  // r.treeInsert(x);
  // r.treeInsert(y);
  // r.treeInsert(z);
  // r.inorderTreeWalk(r.getRoot(), s);
  // r.print(s);




  hasht<int> x(5);
  x.insert(1);
  x.insert(2);
  x.insert(3);

  hasht<int> h(x);


}
