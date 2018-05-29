#ifndef HASH_CLASS
#define HASH_CLASS
#include <list>
#include <vector>
#include <iostream>
using namespace std;
template <typename T>

class hasht{
	public:
		hasht(int nEntradas){
			numEntradas = nEntradas;
			tabla.resize(numEntradas);
		};
			// Constructor que especifica el numero de cubetas (entradas)
			// en la tabla

		hasht(const hasht<T>& obj){
			tabla = obj.tabla;
			numEntradas = obj.numEntradas;
		};
			// Constructor copia

		~hasht(){
			for (int i = 0; i < numEntradas; ++i) {
				tabla[i].clear();
			}
			tabla.clear();
		};
			// Destructor (borra la tabla)

		T* search(const T& item){
			T pos = item % numEntradas;
			if (!tabla[pos].empty()){
				typename list<T>::iterator i = tabla[pos].begin();
				while (*i != item && i != tabla[pos].end()) {
					i++;
				}
				if (*i == item) {
					return &*i;
				}
			}
			return NULL;
		};
			// Retorna un puntero a la llave o NULL si no se encuentra

		void insert(const T& item){
			T pos = item % numEntradas;
			tabla[pos].push_back(item);
		};
			// Inserta el elemento en la tabla

	private:
		int numEntradas;
			// N�mero de entradas en la tabla
		vector<list<T> > tabla;
			// La tabla es un vector de listas de STL
};
#endif
