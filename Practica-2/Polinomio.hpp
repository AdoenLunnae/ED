/*!
   \file Polinomio.hpp
   \brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_

// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>

// Para usar la función abs
#include <cmath>


#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"
#include "operadoresExternosMonomios.hpp"

// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed{
//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
	class Polinomio: public PolinomioInterfaz{

	//! \name Atributos privados de la clase Polinomio
	private:
		std::vector<Monomio> _monomios; //!< Vector de monomios

		/**
		 * @brief Devuelve el indice del monomio de un grado determinado
		 *
		 * @param grado: Grado que comprobamos
		 * @pre El polinomio existe
		 * @post Ninguna
		 * @return int: el indice del monomio buscado si existe
		 * @return int: -1 si el monomio no existe
		 */
		int findMonomio(int const grado) const;

		void sort();

	//! \name Funciones o métodos públicos de la clase Polinomio
	public:

		//! \name Constructores de la clase Polinomio
		/**
		 * @brief Construye un polinomio nulo
		 * @note Función inline 
		 * @pre Ninguna
		 * @post El polinomio es nulo
		 */
		inline Polinomio(){
			_monomios.push_back(Monomio());

			#ifndef NDEBUG
				assert(esNulo());
			#endif
		}	
		/**
		 * @brief Construye un polinomio igual a otro
		 * @note Función inline 
		 * @param p: Polinomio a copiar
		 * @pre Ninguna
		 * @post Los polinomios son iguales
		 */
		inline Polinomio(Polinomio const &p){
			_monomios = p._monomios;

			#ifndef NDEBUG
				assert(_monomios == p._monomios);
			#endif
		}

		//! \name Observadores: funciones de consulta de la clase Polinomio
		/**
		 * @brief Comprueba si un polinomio es nulo
		 * @warning Usa el calificador const
		 * @note Función inline 
		 * @pre Ninguna
		 * @post Ninguna
		 * @return true: el polinomio es igual al monomio de grado 0 y coeficiente 0.0 
		 * @return false: cualquier otro caso
		 */
		inline bool esNulo() const
		{
			return((_monomios.size() == 1)
				&& (_monomios[0].getGrado() == 0))
				&& (std::abs(_monomios[0].getCoeficiente()) < COTA_ERROR);
		}

		/**
		 * @brief Devuelve el grado del polinomio
		 * @pre Los monomios están ordenados de mayor a menor grado
		 * @post Ninguna
		 * @return int: Grado del monomio de mayor grado
		 */
		inline int getGrado() const
		{
			#ifndef NDEBUG
				assert(isOrdered());
			#endif

			if(_monomios.empty()) return 0;
			
			return(_monomios[0].getGrado());
		}

		inline std::vector<Monomio> getMonomios()const{
			return _monomios;
		}

		/**
		 * @brief Devuelve el número de monomios
		 * @pre Ninguna
		 * @post Ninguna
		 * @return unsigned int: Número de monomios del polinomio
		 */
		inline unsigned int getNumeroMonomios() const
		{
			return (_monomios.size());
		}

		/**
		 * @brief Comprueba si existe un monomio de un grado determinado
		 *
		 * @param grado: Grado que comprobamos
		 * @pre El polinomio existe
		 * @post Ninguna
		 * @return true: si existe un monomio de grado igual al parámetro
		 * @return false: en cualquier otro caso
		 */
		inline bool existeMonomio(int const grado) const
		{
			#ifndef NDEBUG
				assert(getNumeroMonomios() > 0);
			#endif

			return(findMonomio(grado) != -1);
		}

		/**
		 * @brief Devuelve el monomio de un grado determinado
		 *
		 * @param grado: Grado que comprobamos
		 * @pre El polinomio existe
		 * @post Ninguna
		 * @return Monomio: el monomio del grado buscado si existe
		 * @return Monomio: un monomio del grado buscado y coeficiente 0.0 si no existe
		 */
		inline Monomio getMonomio(int const grado) const
		{
			#ifndef NDEBUG
				assert(getNumeroMonomios() > 0);
			#endif
			
			int index = findMonomio(grado);
			return (index == -1)?*(new Monomio()):_monomios[index];		
		}

		/**
		 * @brief Comprueba si un polinomio está ordenado
		 * @pre Ninguna
		 * @post Ninguna
		 * @return true: si los monomios están ordenados de mayor a menor grado 
		 * @return false: en caso contrario
		 */
		inline bool isOrdered() const
		{
			unsigned int i;
			bool retV = true;
			if(getNumeroMonomios() <= 1) return true;
			for(i = 0; (i < getNumeroMonomios() - 1) && (retV); ++i){
				if((_monomios[i].getGrado()) <= (_monomios[i+1].getGrado())){
					retV = false;
				}
			}
			return retV;
		}
		//! \name Funciones de modificación de la clase Polinomio



		////////////////////////////////////////////////////////////////

		//! \name Operadores de la clase Polinomio

		/**
		 * @brief Asigna un polinomio a otro
		 * 
		 * @param p: Polinomio que será asignado
		 * @pre Ninguna
		 * @post El polinomio que llama es igual a p
		 * @return Polinomio&: polinomio modificado 
		 */
		Polinomio & operator=(Polinomio const &p);

		/**
		 * @brief Asigna un monomio a un polinomio
		 * 
		 * @param m: Monomio que será asignado
		 * @pre Ninguna
		 * @post El polinomio que llama es igual a m
		 * @return Polinomio&: polinomio modificado 
		 */
		Polinomio & operator=(Monomio const &m);

		/**
		 * @brief Asigna un número real a un polinomio
		 * 
		 * @param x: Real que será asignado
		 * @pre Ninguna
		 * @post El polinomio que llama es igual a x
		 * @return Polinomio&: polinomio modificado 
		 */
		Polinomio & operator=(double const &x);

		// Operadores aritméticos y asignación

		/**
		 * @brief Operador de suma y asignación con otro Polinomio
		 * 
		 * @param p: Polinomio a sumar
		 * @return Polinomio&: El polinomio original modificado
		 */
		Polinomio & operator+=(Polinomio const &p);

		/**
		 * @brief Operador de suma y asignación con un Monomio
		 * 
		 * @param m: Monomio a sumar
		 * @return Polinomio&: El polinomio original modificado
		 */
		Polinomio & operator+=(Monomio const &m);

		/**
		 * @brief Operador de suma y asignación con un real
		 * 
		 * @param x: Número a sumar
		 * @return Polinomio&: El polinomio original modificado
		 */
		Polinomio & operator+=(double const &x);

		/**
		 * @brief Operador de resta y asignación con otro Polinomio
		 * 
		 * @param p: Polinomio a restar
		 * @return Polinomio&: El polinomio original modificado
		 */
		Polinomio & operator-=(Polinomio const &p);

		/**
		 * @brief Operador de resta y asignación con un Monomio
		 * 
		 * @param m: Monomio a restar
		 * @return Polinomio&: El polinomio original modificado
		 */
		Polinomio & operator-=(Monomio const &m);

		/**
		 * @brief Operador de resta y asignación con un real
		 * 
		 * @param x: Número a restar
		 * @return Polinomio&: El polinomio original modificado
		 */
		Polinomio & operator-=(double const &x);

		/**
		 * @brief Operador de multiplicación y asignación con otro Polinomio
		 * 
		 * @param p: Polinomio por el que multiplicar
		 * @return Polinomio&: El polinomio original modificado
		 */
		Polinomio & operator*=(Polinomio const &p);

		/**
		 * @brief Operador de multiplicación y asignación con un Monomio
		 * 
		 * @param m: Monomio por el que multiplicar
		 * @return Polinomio&: El polinomio original modificado
		 */
		Polinomio & operator*=(Monomio const &m);

		/**
		 * @brief Operador de multiplicación y asignación con un real
		 * 
		 * @param x: Número por el que multiplicar
		 * @return Polinomio&: El polinomio original modificado
		 */
		Polinomio & operator*=(double const &x);

		/**
		 * @brief Operador de división y asignación con otro Polinomio
		 * 
		 * @param p: Polinomio por el que dividir
		 * @pre El grado de p es menor o igual que el del polinomio
		 * @pre p no es nulo
		 * @return Polinomio&: El polinomio original modificado
		 */
		Polinomio & operator/=(Polinomio const &p);

		/**
		 * @brief Operador de división y asignación con un Monomio
		 * 
		 * @param m: Monomio por el que dividir
		 * @pre El grado de m es menor o igual que el del polinomio
		 * @pre El polinomio actual no es nulo
		 * @return Polinomio&: El polinomio original modificado
		 */
		Polinomio & operator/=(Monomio const &m);

		/**
		 * @brief Operador de división y asignación con un real
		 * 
		 * @param x: Número por el que dividir
		 * @return Polinomio&: El polinomio original modificado
		 */
		Polinomio & operator/=(double const &x);
		/////////////////////////////////////////////////////////////////////////////////////

		//! \name Funciones lectura y escritura de la clase Polinomio

		void leerPolinomio();

		void escribirPolinomio();

		///////////////////////////////////////////////////////////////////////

		//! \name Funciones auxiliares de la clase Polinomio
		double calcularValor(double const &x);


	}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
