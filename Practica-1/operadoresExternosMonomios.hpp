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


	/*!
		\brief Comprueba si un monomio es distinto de otro
		\param x: monomio a la izquierda
		\param m1: monomio a la derecha
		\pre Ninguna
		\post El valor devuelto es verdadero si los grados o los coeficientes son
		distintos, falso en el caso de que sean iguales.
	*/
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);

	/*!
		\brief Comprueba si un monomio es igual a un número real
		\param m1: monomio a la izquierda
		\param x: numero real a la derecha
		\pre Ninguna
		\post El valor devuelto es verdadero si el grado del monomio no es 0
		o el coeficiente es distinto de x
	*/
	bool operator!=(ed::Monomio const & m1, double const x);

	/*!
		\brief Comprueba si un monomio es igual a un número real
		\param x: numero real a la izquierda
		\param m1: monomio a la derecha
		\pre Ninguna
		\post El valor devuelto es verdadero si el grado del monomio no es 0
		o el coeficiente es distinto de x
	*/
	bool operator!=(double const x, ed::Monomio const & m1);

	///////////////////////////////////////////////////

	//! \name Operadores unarios prefijos

	/*!
		\brief Función que devuelve una copia de un monomio
		\param m: monomio a copiar
		\pre Ninguna
		\post El monomio devuelto es igual a m
		\return Copia del monomio pasado como argumento
	*/
	ed::Monomio & operator+(ed::Monomio const & m);

	/*!
		\brief Función que devuelve el opuesto de un monomio
		\param m: monomio del que se devolverá el opuesto
		\pre Ninguna
		\post El grado del monomio devuelto es igual al de m, y su coeficiente es el
		opuesto al de m
		\return Opuesto del monomio pasado como argumento
	*/
	ed::Monomio & operator-(ed::Monomio const & m);


	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma

	/*!
		\brief Función que calcula la suma de dos monomios
		\param m1: monomio a la izquierda del operador
		\param m2: monomio a la derecha del operador
		\pre Los grados de m1 y m2 son iguales
		\post El grado del monomio devuelto es igual al de m1 y m2
		\post El coeficiente del monomio devuelto es la suma del de m1 y el de m2
		\return La suma de m1 y m2
	*/
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2);


	//////////////////////////////////////////////////////////
	//! \name Operador binario de la resta

	/*!
		\brief Función que calcula la suma de dos monomios
		\param m1: monomio a la izquierda del operador
		\param m2: monomio a la derecha del operador
		\pre Los grados de m1 y m2 son iguales
		\post El grado del monomio devuelto es igual al de m1 y m2
		\post El coeficiente del monomio devuelto es la diferencia del de m1 y el
		de m2
		\return La diferencia de m1 y m2
	*/
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2);


	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación

	/*!
		\brief Función que calcula el producto de dos monomios
		\param m1: monomio a la izquierda del operador
		\param m2: monomio a la derecha del operador
		\pre Ninguna
		\post El grado del monomio devuelto es igual a la suma de los de m1 y m2
		\post El coeficiente del monomio devuelto es igual al producto del de m1 y
		el de m2
		\return El producto de m1 y m2
	*/
	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2);

	/*!
		\brief Función que calcula el producto de un monomio y un real
		\param m1: monomio a la izquierda del operador
		\param x: número real a la derecha del operador
		\pre Ninguna
		\post El grado del monomio devuelto es igual al de m1
		\post El coeficiente del monomio devuelto es igual al producto del de m1 y x
		\return El producto de m1 y x
	*/
	ed::Monomio & operator* (ed::Monomio const &m1, double const x);

	/*!
		\brief Función que calcula el producto de un real y un monomio
		\param x: número real a la izquierda del operador
		\param m1: monomio a la derecha del operador
		\pre Ninguna
		\post El grado del monomio devuelto es igual al de m1
		\post El coeficiente del monomio devuelto es igual al producto del de m1 y x
		\return El producto de x y m1
	*/
	ed::Monomio & operator* (double const x, ed::Monomio const &m1);


	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división

	/*!
		\brief Función que calcula el cociente de dos monomios
		\param m1: monomio a la izquierda del operador (dividendo)
		\param m2: monomio a la derecha del operador (divisor)
		\pre El grado me m2 es menor o igual que el de m1
		\pre El coeficiente de m2 no es 0.0
		\post El grado del monomio devuelto es igual al de m1 menos el de m2
		\post El coeficiente del monomio devuelto es igual al cociente del de m1 y
		el de m2
		\return El cociente de m1 y m2
	*/
	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2);

	/*!
		\brief Función que calcula el cociente de un monomio y un real
		\param m1: monomio a la izquierda del operador (dividendo)
		\param x: número real a la derecha del operador (divisor)
		\pre El valor x no es 0.0
		\post El grado del monomio devuelto es igual al de m1
		\post El coeficiente del monomio devuelto es igual al cociente del de m1 y x
		\return El cociente de m1 y x
	*/
	ed::Monomio & operator/ (ed::Monomio const &m1, double const x);

	/*!
		\brief Función que calcula el cociente de un real y un monomio
		\param x: número real a la izquierda del operador (dividendo)
		\param m1: monomio a la derecha del operador (divisor)
		\pre El grado de x es 0
		\pre El coeficiente de x no es 0.0
		\post El grado del monomio devuelto es 0
		\post El coeficiente del monomio devuelto es igual al cociente de x y del
		coeficiente de m1
		\return El cociente de x y m1
	*/
	ed::Monomio & operator/ (double const x, ed::Monomio const &m1);


	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida

	/*!
		\brief Lee de un flujo los datos de un monomio separados por espacios
		(coeficiente grado)
		\param stream: flujo del que leer
		\param m: monomio que leer
		\pre Ninguna
		\post Ninguna
		\return Flujo pasado como parámetro
	*/
	 istream &operator>>(istream &stream, ed::Monomio &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	 ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_
