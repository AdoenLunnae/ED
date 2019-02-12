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
		float _coeficiente; //!< Coeficiente del monomio

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

		inline Monomio(const int grado = 0, const double coeficiente = 0.0){

			#ifndef NDEBUG
				assert(grado >= 0);
			#endif

			setGrado(grado);
			setCoeficiente(coeficiente);

			#ifndef NDEBUG
				assert(getGrado() == grado);
				assert( std::abs(getCoeficiente() - coeficiente) < COTA_ERROR )
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
		inline Monomio(const ed::Monomio &m){
			setGrado(m.getGrado());
			setCoeficiente(m.getCoeficiente());

			#ifndef NDEBUG
				assert(this->getGrado() == m.getGrado());
				assert( std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR )
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
		inline void setCoeficiente(const float coeficiente){
			_coeficiente = coeficiente;

			#ifndef NDEBUG
				assert( std::abs(getCoeficiente() - coeficiente) < COTA_ERROR )
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


		Monomio & operator=(Monomio const &m);

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Monomio & operator=(double const &x);


		// Operadores aritméticos y asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Monomio & operator+=(Monomio const &m);


		// COMPLETAR EL RESTO DE OPERADORES


		/////////////////////////////////////////////////////////////////////////////////////

		//! \name Funciones lectura y escritura de la clase Monomio

		// COMPLETAR


		///////////////////////////////////////////////////////////////////////

		//! \name Funciones auxiliares de la clase Monomio

		// COMPLETAR



	};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
