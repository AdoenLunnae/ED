/*!
\file Monomio.hpp
\brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#include <iostream>
#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$
	class Monomio
	{
	//! \name Atributos privados de la clase Monomio
	private:
		int _grado; //!< Grado del monomio
		double _coeficiente; //!< Coeficiente del monomio

	//! \name Funciones o métodos públicos de la clase Monomio
	public:
	//! \name Constructores de la clase Monomio

		/*!
			\brief 		Constructor parametrizado de la clase Monomio
			\warning	Los parámetros tienen valores por defecto
			\note 		Función inline
			\param grado: grado del monomio a crear; valor por defecto 0
			\param coeficiente: coeficiente del monomio a crear; valor por defecto 0.0
			\pre grado es mayor o igual que 0
			\post El grado del monomio es igual a "grado"
			\post El coeficiente del monomio tiene el valor de "coeficiente"
			\sa setGrado(), setCoeficiente()
		*/

		inline Monomio(const int grado = 0, double const coeficiente = 0.0){

			#ifndef NDEBUG
				assert(grado >= 0);
			#endif

			setGrado(grado);
			setCoeficiente(coeficiente);

			#ifndef NDEBUG
				assert(getGrado() == grado);
				assert( std::abs(getCoeficiente() - coeficiente) < COTA_ERROR );
			#endif
		}


		/*!
			\brief Constructor de copia de la clase Monomio
			\note Función inline
			\param m: Monomio a copiar
			\pre Ninguna
			\post El grado del monomio creado es igual al de "m"
			\post El coeficiente del monomio creado es igual al de "m"
			\sa setGrado(), setCoeficiente(), getGrado(), getCoeficiente()
		*/
		inline Monomio(const Monomio &m){
			setGrado(m.getGrado());
			setCoeficiente(m.getCoeficiente());

			#ifndef NDEBUG
				assert(this->getGrado() == m.getGrado());
				assert( std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR );
			#endif
		}

		//! \name Observadores: funciones de consulta de la clase Monomio

		/*!
			\brief Función que devuelve el coeficiente del monomio
			\warning Usa el calificador const
			\note Función inline
			\pre Ninguna
			\post Ninguna
			\return El valor del coeficiente
		*/
		inline double getCoeficiente() const {
			return _coeficiente;
		}

		/*!
			\brief Función que devuelve el grado del monomio
			\warning Usa el calificador const
			\note Función inline
			\pre Ninguna
			\post Ninguna
			\return El valor del grado
		*/
		inline int getGrado() const {
			return _grado;
		}


		//! \name Funciones de modificación de la clase Monomio
		/*!
			\brief Función que asigna un valor al coeficiente
			\note Función inline
			\param coeficiente: valor a asignar
			\pre Ninguna
			\post El valor del coeficiente del monomio es "coeficiente"

		*/
		inline void setCoeficiente(double const coeficiente){
			_coeficiente = coeficiente;

			#ifndef NDEBUG
				assert( std::abs(getCoeficiente() - coeficiente) < COTA_ERROR );
			#endif
		}

		/*!
			\brief Función que asigna un valor al grado
			\note Función inline
			\param grado: valor a asignar
			\pre grado es mayor o igual que 0
			\post El valor del grado del monomio es "grado"
		*/
		void  setGrado(const int grado) {
			#ifndef NDEBUG
				assert(grado >= 0);
			#endif

			_grado = grado;

			#ifndef NDEBUG
				assert(getGrado() == grado);
			#endif
		}



		/////////////////////////////////////////////////

		//! \name Operadores de la clase Monomio

		// Operadores de asignación

		/*!
			\brief Función que asigna el grado y el coeficiente de un monomio a otro
			\note Función inline
			\param m: Monomio que será asignado
			\pre Ninguna
			\post El grado del monomio es igual al de "m"
			\post El coeficiente del monomio es igual al de "m"
			\return El monomio modificado
		*/
		inline Monomio & operator=(Monomio const &m){
			setGrado(m.getGrado());
			setCoeficiente(m.getCoeficiente());

			#ifndef NDEBUG
				assert(this->getGrado() == m.getGrado());
				assert( std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR );
			#endif

			return *this;
		}

		/*!
			\brief Función que asigna un valor al coeficiente de un monomio y 0 al grado
			\note Función inline
			\param x: Valor que será asignado
			\pre Ninguna
			\post El grado del monomio es igual a 0
			\post El coeficiente del monomio es igual a "x"
			\return El monomio modificado
		*/
		inline Monomio & operator=(double const x){
			setGrado(0);
			setCoeficiente(x);

			#ifndef NDEBUG
				assert(this->getGrado() == 0);
				assert( std::abs(this->getCoeficiente() - x ) < COTA_ERROR );
			#endif

			return *this;
		}


		// Operadores aritméticos y asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		/*!
			\brief Función que suma a un monomio otro del mismo grado
			\param m: Monomio que será sumado al original
			\pre El grado de m es igual al del monomio que llama al operador
			\post Al coeficiente del monomio que llama se le suma el de m
			\post El grado del monomio no se ha modificado
			\return El monomio modificado
		*/
		Monomio &operator+=(Monomio const &m);

		/*!
			\brief Función que resta a un monomio otro del mismo grado
			\param m: Monomio que será restado al original
			\pre El grado de m es igual al del monomio que llama al operador
			\post Al coeficiente del monomio que llama se le ha restado el de m
			\post El grado del monomio no se ha modificado
			\return El monomio modificado
		*/
		Monomio &operator-=(Monomio const &m);

		/*!
			\brief Función que multiplica un monomio por otro
			\param m: Monomio por el que será multiplicado el original
			\pre Ninguna
			\post El coeficiente del monomio se ha multiplicado por el de m
			\post El grado del monomio se ha incrementado en el de m
			\return El monomio modificado
		*/
		Monomio &operator*=(Monomio const &m);

		/*!
			\brief Función que divide un monomio por otro
			\param m: Monomio por el que será dividido el original
			\pre El grado de m es igual o menor que el del monomio que llama
			\pre El coeficiente de m es distinto de 0.0
			\post El coeficiente del monomio se ha dividido por el de m
			\post El grado del monomio se ha decrementado en el de m
			\return El monomio modificado
		*/
		Monomio &operator/=(Monomio const &m);

		/*!
			\brief Función que multiplica un monomio por un número real
			\param x: Valor por el que será multiplicado el monomio
			\pre Ninguna
			\post El coeficiente del monomio se ha multiplicado por x
			\post El grado del monomio no se ha modificado
			\return El monomio modificado
		*/
		Monomio &operator*=(double const x);

		/*!
			\brief Función que divide un monomio por un número real
			\param x: Valor por el que será dividido el monomio
			\pre x es distinto de 0.0
			\post El coeficiente del monomio se ha dividido por x
			\post El grado del monomio no se ha modificado
			\return El monomio modificado
		*/
		Monomio &operator/=(double const x);

		/////////////////////////////////////////////////////////////////////////////////////

		//! \name Funciones lectura y escritura de la clase Monomio

		// COMPLETAR
		/*!
			\brief Lee los atributos de un monomio por teclado.
			\pre Ninguna
			\post El grado del monomio es mayor o igual que 0
		*/
		void leerMonomio();

		/*!
			\brief Escribe el monomio por pantalla en el formato Coef x ^ Grado
			\pre Ninguna
			\post Ninguna
		*/
		void escribirMonomio() const;



		///////////////////////////////////////////////////////////////////////

		//! \name Funciones auxiliares de la clase Monomio

		/*!
			\brief Función que calcula el valor de un monomio para un valor de X
			\warning Usa el calificador const
			\note Función inline
			\param x: valor de X para el que se calcula el del monomio
			\pre Ninguna
			\post Ninguna
			\return El valor del monomio
		*/
		double calcularValor(double const x) const{
			return( this->getCoeficiente() * pow( x , this->getGrado() ) );
		}



	};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
