#ifndef BINARY_SEARCH_Tree
#define BINARY_SEARCH_Tree
#include <iostream>
#include <stack>
#define MAX 1000000
using namespace std;
// Nodos del arbol:
template <typename T>
class node{
   public:
		// Esta clase es usada por otras clases.
		// Para mayor eficiencia, los atributos se hacen publicos.
		T key;
		node<T> *p, *left, *right;

		// Constructor por omision
		node(){
		};

		// Constructor por copia. Copia el nodo y sus hijos.
		node(const node<T> * obj, node<T> * padre){
      this->key = obj->key;
      this->p = padre;
      this->left = obj->left;
      this->right = obj->right;
		}

        // Inicializacion de datos miembro
		node(const T& k, node<T> *w = NULL, node<T> *y = NULL, node<T> *z = NULL):key(k), p(w), left(y), right(z){};

		~node(){
		}
};

// Arbol:
template <typename T>
class tree{

	public:

		tree(){
      root = nullptr;
		};
			// Constructor. Crea un arbol vacio

		tree(const tree<T>& obj){
      root = nullptr;
      node<T> * ptr = obj.getRoot();
      stack<T> s;
      inorderTreeWalk(ptr, s);
      while (!s.empty()) {
         node<T> * n;
         n->key = s.top();
         treeInsert(n);
         s.pop();
      }
		};
			// Constructor copia

		~tree(){
      while (root) {
        treeDelete(root);
      }
		};
			// Destructor (borra el arbol)

		void inorderTreeWalk(node<T>* x, stack<T> & pila){
      if (x != nullptr) {
        inorderTreeWalk(x->left, pila);
        pila.push(x->key);
        inorderTreeWalk(x->right, pila);
      }
		};
            // Efectua un recorrido en orden del sub�rbol cuya raiz es apuntada
            // por x, guardando en cada visita la llave de cada nodo en la pila.
            // Es decir, cada vez que se llega a un nodo se hace
            // pila.push(x->key). Si se hace correctamente, al finalizar el
            // metodo la pila debe contener las llaves de los nodos del
            // subarbol ordenadas de mayor a menor.

		node<T>* treeSearch(const T& k){
      node<T> * ptr = root;
      treeSearchRec(ptr, k);
      return ptr;
		};
			      // Busca la llave recursivamente; si la encuentra, devuelve un
            // apuntador al nodo que la contiene, sino devuelve NULL

		node<T>* iterativeTreeSearch(const T& k){
      node<T> * ptr = root;
      while (ptr != nullptr && k != ptr->key) {
        if (k < ptr->key) {
          ptr = ptr->left;
        } else {
          ptr = ptr->right;
        }
      }
      return ptr;
		};
			// Lo mismo que en el anterior pero usando un procedimiento
			// iterativo

		node<T>* treeMinimum(){
      node<T> * ptr = min(root);
      return ptr;
		};
			// Devuelve el nodo que tiene la llave menor.
            // Si el arbol est� vacio devuelve NULL.

		node<T>* treeMaximum(){
      node<T> * ptr = max(root);
      return ptr;
		};
			// Devuelve el nodo que tiene la llave mayor.
            // Si el arbol esta vacio devuelve NULL.

		node<T>* treeSuccessor(const node<T>* x){
      if (x->right != nullptr) {
        return min(x->right);
      }
      node<T> * y = x->p;
      while (y != nullptr && x == y->right) {
        x = y;
        y = y->p;
      }
      return y;
		};
			// Devuelve el nodo cuya llave es la que le sigue a la
            // del nodo x. Si no existe tal nodo devuelve NULL.

		void treeInsert(node<T>* z){
      node<T> * x = root;
      node<T> * y = nullptr;
      while (x != nullptr) {
        y = x; // puntero "atrasado" para luego asignarlo como padre.
        if (z->key < x->key) {
          x = x->left;
        } else {
          x = x->right;
        }
      }
      z->p = y;
      if (y == nullptr) { // si esto se cumple es la primera vez que se inserta un elemento.
        root = z;
      } else {
        if (z->key < y->key) {
          y->left = z;
        } else {
          y->right = z;
        }
      }
		};
		// Inserta el nodo z en la posicion que le corresponde en el arbol.

		node<T>* treeDelete(node<T>* z){
      if (z->left == nullptr) {
        transplant(z, z->right);
      } else {
        if (z->right == nullptr) {
          transplant(z, z->left);
        } else {
          node<T> * y = min(z->right);
          if (y->p != z) {
            transplant(y, y->right);
            y->right = z->right;
            y->right->p = y;
          }
          transplant(z, y);
          y->left = z->left;
          y->left->p = y;
        }
      }
      return z;
		};
			// Saca del arbol la llave contenida en el nodo apuntado por z.
			// Devuelve la direccion del nodo eliminado para que se pueda
			// disponer de ella.

		node<T> * getRoot() const{
			return this->root;
		};
		// Devuelve la raiz del arbol. (Para efectos de revisi�n de la tarea).

    void print(stack<T> & pila) {
      while (!pila.empty()) {
        std::cout << pila.top() << "  |  ";
        pila.pop();
      }
    };

    void secTree () {
      node<T> * x = root;
      for (int i = 0; i < MAX; ++i) {
        node<T> * n = new node<T>(i);
        if (x == nullptr) {
          root = n;
        } else {
          n->p = x;
          x->right = n;
        }
        x = n;
      }
    };

	private:

		node<T> *root;	// root of the Tree

    node<T>* treeSearchRec(node<T> * x, const T& k){
      if (x == nullptr || k == x->key) {
        return x;
      }
      if (k < x->key) {
        return treeSearchRec(x->left, k);
      } else {
        return treeSearchRec(x->right, k);
      }
    };

    node<T>* min(node<T>* x){
      while (x->left != nullptr) {
        x = x->left;
      }
      return x;
    };

    node<T>* max(node<T>* x){
      while (x->right != nullptr) {
        x = x->right;
      }
      return x;
    };

    void transplant(node<T>* u, node<T>* v){
      if (u->p == nullptr) {
        root = v;
      } else {
        if (u == u->p->left) { // si es el menor
          u->p->left = v;
        } else {
          u->p->right = v;
        }
      }
      if (v != nullptr) {
        v->p = u->p;
      }
		};





};
#endif	// BINARY_SEARCH_Tree
