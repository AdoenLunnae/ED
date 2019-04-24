#ifndef __ARBOLBINARIOORDENADO_HPP__
#define __ARBOLBINARIOORDENADOENLAZADO_HPP__

#include <iostream>
#include <string>
#include <cassert>
#include "arbolbinarioordenado.hpp"
#include "operadornodo.hpp"

using namespace std;
/*!
\brief Espacio de nombres para la asignatura Estructura de datos.
*/
namespace ed
{
	/*!\brief Interfaz para definir un ArbolBinario ordenado.

	Define una interfaz para definir un ArbolBinarioOrdenado.

	\arg G define el campo de información a contener en el arbol.
	\pre G debe tener definidos los operadores < y ==.
	*/
	template<class G>
	class ArbolBinarioOrdenadoEnlazado:public ArbolBinarioOrdenado<G>
	{
	private:

		/*!\brief Define un nodo del arbol binario.*/
		class NodoArbolBinario
		{
		private:
			G _info;  //Valor informativo almacenado en el nodo
			NodoArbolBinario * _izquierdo;  //Puntero al hijo izquierdo
			NodoArbolBinario * _derecho;  //Puntero al hijo derecho

		public:
			NodoArbolBinario (const G &info)
			{
				setInfo(info);
				setIzquierdo(NULL);
				setDerecho(NULL);

				#ifndef NDEBUG
					assert(esHoja());
				#endif
			}

			NodoArbolBinario (const NodoArbolBinario &n)
			{
				setInfo(n.getInfo());
				setDerecho(n.getDerecho());
				setIzquierdo(n.getIzquierdo());

				#ifndef NDEBUG
					assert(getDerecho() == n.getDerecho());
					assert(getIzquierdo() == n.getIzquierdo());
					assert(getInfo() == n.getInfo());
				#endif
			}

			/*!\brief Observadores.*/
			const G & getInfo() const
			{
				return _info;
			}

			NodoArbolBinario *getIzquierdo() const
			{
				return _izquierdo;
			}

			NodoArbolBinario *getDerecho() const
			{
				return _derecho;
			}

			bool esHoja() const
			{
				return ((getDerecho() == NULL) && (getIzquierdo() == NULL));
			}

			void recorridoPreOrden(OperadorNodo<G> &operador) const
			{
				operador.aplicar(getInfo());
				if(getIzquierdo() != NULL) getIzquierdo()->recorridoPreOrden(operador);
				if(getDerecho() != NULL) getDerecho()->recorridoPreOrden(operador);
			}

			void recorridoPostOrden(OperadorNodo<G> &operador) const
			{
				if(getIzquierdo() != NULL) getIzquierdo()->recorridoPostOrden(operador);
				if(getDerecho() != NULL) getDerecho()->recorridoPostOrden(operador);
				operador.aplicar(getInfo());
			}

			void recorridoInOrden(OperadorNodo<G> &operador) const
			{
				if(getIzquierdo() != NULL) getIzquierdo()->recorridoInOrden(operador);
				operador.aplicar(getInfo());
				if(getDerecho() != NULL) getDerecho()->recorridoInOrden(operador);
			}

			/*!\brief Modificadores. */
			void setInfo(const G &info)
			{
				_info = info;
			}

			void setIzquierdo(NodoArbolBinario *n)
			{
				_izquierdo = n;
			}

			void setDerecho(NodoArbolBinario *n)
			{
				_derecho = n;
			}

			NodoArbolBinario & operator=(const NodoArbolBinario &n)
			{
				setInfo(n.getInfo());
				setDerecho(n.getDerecho());
				setIzquierdo(n.getIzquierdo());

				#ifndef NDEBUG
					assert(getDerecho() == n.getDerecho());
					assert(getIzquierdo() == n.getIzquierdo());
					assert(getInfo() == n.getInfo());
				#endif

				return *this;
			}


		}; //Fin clase NodoArbolBinario

		//Implementación de la raíz
		NodoArbolBinario * _raiz; /*!<La raiz del árbol*/
		NodoArbolBinario * _actual; /*!<Cursor al nodo actual*/
		NodoArbolBinario * _padre; /*!<Cursor al nodo actual*/

	public:

		ArbolBinarioOrdenadoEnlazado ()
		{
			_raiz = NULL;
			_actual = NULL;
			_padre = NULL;

			#ifndef NDEBUG
				assert(estaVacio());
			#endif
		}

		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G>& a)
		{
			_raiz = a._raiz;
			_actual = a._actual;
			_padre = a._padre;
		}

		~ArbolBinarioOrdenadoEnlazado ()
		{
			if (not estaVacio())
			borrarArbol();
			cout << "Destructor Usado \n";
		}

		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado& a)
		{
			_raiz = a._raiz;
			_actual = a._actual;
			_padre = a._padre;
		}

		bool insertar(const G &x)
		{
			bool inserted = false;
			if(estaVacio()){
				_raiz = new NodoArbolBinario(x);
				inserted = true;
				_actual = _raiz;
				_padre = NULL;
			}
			NodoArbolBinario *aux = _raiz;
			while(!inserted){
				if(x > aux->getInfo()){
					if(aux->getDerecho() != NULL){
						aux = aux->getDerecho();
					}
					else{
						aux->setDerecho(new NodoArbolBinario(x));
						inserted = true;
					}
				}
				else if(x < aux->getInfo()){
					if(aux->getIzquierdo() != NULL){
						aux = aux->getIzquierdo();
					}
					else{
						aux->setIzquierdo (new NodoArbolBinario(x));
						inserted = true;
					}
				}
			}
			return inserted;
		}

		void borrarArbol()
		{
			#ifndef NDEBUG
				assert(! estaVacio());
			#endif

			_raiz = NULL;

			#ifndef NDEBUG
				assert(estaVacio());
			#endif
		}

		bool borrar()
		{
			#ifndef NDEBUG 
				assert(!estaVacio());
				assert(existeActual());
				G old = _actual->getInfo();
			#endif
			
			if(_actual->esHoja()){
				if(_actual == _raiz) borrarArbol();
				
				else{
					if(_actual->getInfo() > _padre->getInfo()){
						_padre->setDerecho(NULL);
					}
					else{
						_padre->setIzquierdo(NULL);
					}
					_actual = _raiz;
					_padre = NULL;
				}
			}
			else{
				NodoArbolBinario *paux = _padre;
				NodoArbolBinario *aux = _actual;
				if(aux->getDerecho() != NULL){
					paux = aux;
					aux = aux->getDerecho();

					while(aux->getIzquierdo() != NULL){
						paux = aux;
						aux = aux->getIzquierdo();
					}
					if(aux->getInfo() < paux->getInfo())
						paux->setIzquierdo(aux->getDerecho());
					else
						paux->setDerecho(aux->getDerecho());
				}
				else{
					paux = aux;
					aux = aux->getIzquierdo();

					while(aux->getDerecho() != NULL){
						paux = aux;
						aux = aux->getDerecho();
					}
					if(aux->getInfo() < paux->getInfo())
						paux->setIzquierdo(NULL);
					else
						paux->setDerecho(NULL);
				}
				_actual->setInfo(aux->getInfo());
			}
			
			#ifndef NDEBUG
				assert(! buscar(old));
			#endif
			
			return true;
		}

		void recorridoPreOrden (OperadorNodo<G> &operador) const
		{
			#ifndef NDEBUG 
				assert(!estaVacio());
			#endif

			_raiz->recorridoPreOrden(operador);
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const
		{
			#ifndef NDEBUG 
				assert(!estaVacio());
			#endif

			_raiz->recorridoPostOrden(operador);
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const
		{
			#ifndef NDEBUG 
				assert(!estaVacio());
			#endif

			_raiz->recorridoInOrden(operador);
		}

		bool buscar(const G& x)
		{
			#ifndef NDEBUG 
				assert(!estaVacio());
			#endif

			//Si el cursor no apuntaba a ningún nodo, al finalizar
			//sin encontrar el dato, quedará en la raíz.
			NodoArbolBinario *olda = _raiz;
			NodoArbolBinario *oldp = NULL;

			//Si el cursor apuntaba a un nodo, volverá a él si
			//no encuentra el dato buscado.
			if(existeActual()){
				NodoArbolBinario *olda = _actual;
				NodoArbolBinario *oldp = _padre;
			}
				
			_actual = _raiz;
			_padre = NULL;
			bool found = false;
			while((_actual != NULL) && (!found)){
				//Si el actual es mayor que el dato, éste estará a la izquierda
				if(_actual->getInfo() > x){
					_padre = _actual;
					_actual = _actual->getIzquierdo();
				}
				//Si es menor, estará a la derecha
				else if(_actual->getInfo() < x){
					_padre = _actual;
					_actual = _actual->getDerecho();
				}
				else{
					found = true;
				}
			}
			if(!found){
				//Asignamos los valores antiguos si no encontramos el dato
				_actual = olda;
				_padre = oldp;
			}
			return found;
		}

		bool estaVacio() const
		{
			return _raiz == NULL;
		}

		G raiz() const
		{
			return _raiz->getInfo();
		}

		bool existeActual() const
		{
			return _actual != NULL;
		}

		G actual() const
		{
			return _actual->getInfo();
		}
		/*!@}*/
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
