/*! 
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{
//////////////////////////////////////////////////////////////////////////////////////
	// Operadores externos que no pertenecen a la clase Monomio

	//! \name Operadores de igualdad  

	/*!
		\brief Comprueba si dos monomios son iguales
		\param m1: monomio a la izquierda
		\param m2: monomio a la derecha
		\pre Ninguna
		\post El valor devuelto es verdadero si y sólo si tanto el grado 
		como el coeficiente de los monomios son iguales
	*/
	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2);
	

	/*!
		\brief Comprueba si un monomio es igual a un número real
		\param m1: monomio a la izquierda
		\param x: numero real a la derecha
		\pre Ninguna
		\post El valor devuelto es verdadero si el grado del monomio es 0
		y el coeficiente igual a x
	*/
	bool operator==(ed::Monomio const & m1, double const x);

	/*!
		\brief Comprueba si un monomio es igual a un número real
		\param x: numero real a la izquierda
		\param m1: monomio a la derecha
		\pre Ninguna
		\post El valor devuelto es verdadero si el grado del monomio es 0
		y el coeficiente igual a x
	*/
	bool operator==(double const x, ed::Monomio const & m1);

	//! \name Operadores de desigualdad 

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);

	// COMPLETAR LOS OTROS OPERADORES DE DESIGUALDAD

	///////////////////////////////////////////////////

	//! \name Operadores unarios prefijos

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN

	ed::Monomio & operator+(ed::Monomio const & m);

	// COMPLETAR EL OTRO OPERADOR UNARIO PREFIJO: resta


	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma 

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	 ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2);


	//////////////////////////////////////////////////////////
	//! \name Operador binario de la resta 

	// COMPLETAR


	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación 

	// COMPLETAR

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división 

	// COMPLETAR


	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida 

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	 istream &operator>>(istream &stream, ed::Monomio &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	 ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_


