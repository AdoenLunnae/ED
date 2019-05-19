#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>

using namespace std;

namespace ed
{

	template <class G_Nodo, class G_Lado>
	class Grafo
	{
	public:

		G_Lado **_lados;

		G_Nodo *_nodos;

	public:

		// constructores
		Grafo(){
			_lados = {};
			_nodos = {};
		}
		
		Grafo(int const n){
			_lados = new G_Lado* [n];
			for(int i = 0; i < n; i++){
				_lados[i] = new G_Lado[n];
			}
			_nodos = new G_Nodo[n];
		}

		Grafo(Grafo const g){
			_nodos = g._nodos;
			_lados = g._lados;
		}



		// destructor
		~Grafo(){
			borrarGrafo();		
		}

		// funciones
		// TODO
		void borrarGrafo() {
			delete[] _lados;
			_lados = NULL;
			delete _nodos;
			_nodos = NULL;
		}

	};
}

#endif
