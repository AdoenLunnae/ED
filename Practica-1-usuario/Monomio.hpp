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
		int grado_;
		float coeficiente_;

	//! \name Funciones o métodos públicos de la clase Monomio
	public:

		//! \name Constructores de la clase Monomio
		Monomio(const int grado = 0, const float coeficiente = 0.0){
			assert(grado >= 0);

			grado_ = grado;
			coeficiente_ = coeficiente;

			assert(grado == grado);
			assert( fabs(coeficiente - coeficiente_) < COTA_ERROR );
		}

		Monomio(const ed::Monomio &m){
			int grado = m.getGrado();
			float coeficiente = m.getCoeficiente();

			grado_ = grado;
			coeficiente_ = coeficiente;

			assert(grado == grado);
			assert( fabs(coeficiente - coeficiente_) < COTA_ERROR );
		}

		//! \name Observadores: funciones de consulta de la clase Monomio
		float getCoeficiente() const {return coeficiente_;}

		int getGrado() const {return _grado;}


		//! \name Funciones de modificación de la clase Monomio
		void setCoeficiente(const float coeficiente){
		coeficiente_ = coeficiente;
		assert( fabs(coeficiente - coeficiente_) < COTA_ERROR );
		}

		void  setGrado(const int grado) {
			assert(grado >= 0);

			grado_ = grado;

			assert(grado == grado);
		}
		


		/////////////////////////////////////////////////

		//! \name Operadores de la clase Monomio

		// Operadores de asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
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
