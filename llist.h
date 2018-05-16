#ifndef LINKED_LIST_llist
#define LINKED_LIST_llist
#include <iostream>

// Nodos de la lista:
template <typename T>
class llnode{
   public:
		// Esta clase es para ser usada por otras clases.
		// Por eficiencia los atributos se dejan publicos.
		T key;
		llnode<T> *prev, *next;
		//enum colors color;

		// Constructor por omision.
		llnode(){
		};

    // Inicializacion de los datos miembro.
		llnode (const T& k, llnode<T> *w = NULL, llnode<T> *y = NULL):key(k), prev(w), next(y) {};
      // T key = k;
      // T *prev = w;
      // T *next = y;

		~llnode(){
		}
};

// Lista enlazada con nodo centinela:
template <typename T>
class llist{

	public:

		llist(){
      nil = new llnode<T>();
      nil->next = nil;
      nil->prev = nil;
		};
			// Constructor (crea una lista vacia)

		llist(const llist<T>& obj){
      nil = new llnode<T>();
      nil->next = nil;
      nil->prev = nil;
      llnode<T> * ptr = obj.getNil()->next;
      llnode<T> * o = obj.getNil();

      while (ptr->next != o) {
        ptr = ptr->next;
      }
      while(ptr != o->next) {
        listInsert(ptr);
        ptr = ptr->prev;
      }
      listInsert(ptr);
		};
			// Constructor copia

		~llist(){
      llnode<T> * actual = nil;
      while(actual) {
        llnode<T> * sig = actual->next;
        actual->prev = NULL;
        actual->next = NULL;
        actual = sig;
      }
		};
			//Destructor (borra la lista)

		llnode<T>* listSearch(const T& k){
      llnode<T> *ptr = nil->next;
      while (ptr->key != k && ptr != nil) {
        ptr = ptr->next;
      }
      if (ptr == nil) {
        return NULL;
      } else {
        return ptr;
      }
		};
			//Busca la llave iterativamente. Si la encuentra, devuelve un
      //apuntador al nodo que la contiene; sino devuelve NULL.

		void listInsert(llnode<T>* x){
      x->next = nil->next;
      if (nil->next != nil) {
        nil->next->prev = x;
      }
      nil->next = x;
		};
			// Inserta el nodo x en la lista.

		llnode<T>* listDelete(llnode<T>* x){
      std::cout << "Borrando: " << x->key << std::endl;
      llnode<T> *ptr = nil->next;
      while (ptr != x) {
        ptr = ptr->next;
      }
      ptr->prev->next = ptr->next;
      ptr->next->prev = ptr->prev;
      ptr->next = NULL;
      ptr->prev = NULL;

      return ptr;
		};
			// Saca de la lista la llave contenida en el nodo apuntado por x.
			// Devuelve la direccion del nodo eliminado para que se pueda
			// disponer de el.

		llnode<T> * getNil() const{
			return this->nil;
		};
		// Devuelve el nodo centinela. (Para efectos de revision de la tarea).

    void print () {
      llnode<T> * ptr = nil->next;
      if (ptr != nil) {
        while (ptr != nil) {
          std::cout <<ptr->key<< "  |  ";
          ptr = ptr->next;
        }
      } else {
        std::cout << "Lista Vacia" << std::endl;
      }
      std::cout << '\n';
    };

		private:

		llnode<T> * nil;	    // nodo centinela

};

#endif	// LINKED_LIST_llist
