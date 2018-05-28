//#include "llist.h"
//#include "bstree.h"
#include "rbtree.h"
//#include "hasht.h"
#include <stdio.h>
#include <time.h>

int main () {

  // llist<int> l;

  // PRUEBAS LISTA
  // int num;
  // for (int i = 0; i < MAX; ++i) {
  //   num = rand() % (MAX * 2 + 1);
  //   l.listInsert(new llnode<int>(num));
  // }
  //
  //
  // int conta = 0;
  // int num1;
  // long x = time(NULL);
  // long y = x + 10;
  // while (x < y) {
  //   num1 = rand() % (MAX * 2 + 1);
  //   l.listSearch(num1);
  //   ++conta;
  //   x = time(NULL);
  // }
  // std::cout << conta << '\n';

  // tree<int> t;
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

  rbtree<int> r;
  //r.secTree(); // arbol de prueba
  rbnode<int> * x = new rbnode<int>(5);
  rbnode<int> * y = new rbnode<int>(6);
  r.treeInsert(x);
  r.treeInsert(y);

  r.inorderTreeWalk(r.getRoot(), s);
  r.print(s);
  
  r.treeDelete(x);
  //x = r.treeSearch(2);
  r.inorderTreeWalk(r.getRoot(), s);
  r.print(s);
  //std::cout << '\n';
  //r.iterativeTreeSearch(7);
  //std::cout << r.treeMaximum()->key << '\n';
  //std::cout << r.treeMinimum()->key << '\n';
  //std::cout << r.treeSuccessor(x)->key << '\n';




}
