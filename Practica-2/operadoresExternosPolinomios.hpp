/*!
	\file operadoresExternosPolinomios.hpp
	\brief Ficheros con operadores de monomios y polinomios
*/

#ifndef _OperadoresPolinomios_HPP_
#define _OperadoresPolinomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Polinomio.hpp"

using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{

////////////////////////////////////////////////////////////////////////////
	// Funciones y operadores que no pertenecen a la clase Polinomio


	////////////////////////////////////////////////////////////
	//! \name Operadores de igualdad

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	inline bool operator==(Polinomio const & p1, Polinomio const & p2){
		return(p1.getMonomios() == p2.getMonomios());
	}

	inline bool operator==(Polinomio const & p, Monomio const & m){
		if(p.getNumeroMonomios() != 1) return false;
		return(p.getMonomios()[0] == m);
	}

	inline bool operator==(Monomio const & m, Polinomio const & p){
		if(p.getNumeroMonomios() != 1) return false;
		return(p.getMonomios()[0] == m);
	}

	inline bool operator==(Polinomio const & p, double const & x){
		if(p.getNumeroMonomios() != 1) return false;
		return(p.getMonomios()[0] == x);
	}

	inline bool operator==(double const & x, Polinomio const & p){
		if(p.getNumeroMonomios() != 1) return false;
		return(p.getMonomios()[0] == x);
	}

	////////////////////////////////////////////////////////////////////////////////////
	//! \name Operadores de desigualdad

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	inline bool operator!=(Polinomio const & p1, Polinomio const & p2){
		return !(p1 == p2);
	}

	inline bool operator!=(Polinomio const & p, Monomio const & m){
		return !(p==m);
	}
	inline bool operator!=(Monomio const & m, Polinomio const & p){
		return !(m==p);
	}
	inline bool operator!=(Polinomio const & p, double const & x){
		return !(p==x);
	}
	inline bool operator!=(double const & x, Polinomio const & p){
		return !(x==p);
	}
//////////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores unarios

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	inline Polinomio & operator+(Polinomio const & p){
		Polinomio *retV = new Polinomio(p);
		return *retV;
	}

	Polinomio & operator-(Polinomio const &p);


//////////////////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la suma

	
	Polinomio & operator+(Polinomio const &p1,  Polinomio const &p2);
	Polinomio & operator+(Polinomio const &p1,  Polinomio const &p2);
	Polinomio & operator+(Polinomio const &p,  Monomio const &m);
	Polinomio & operator+(Polinomio const &p,  double const &x);
	Polinomio & operator+(Monomio const &m, Polinomio const &p);
	Polinomio & operator+(double const &x, Polinomio const &p);

	Polinomio & operator-(Polinomio const &p1,  Polinomio const &p2);
	Polinomio & operator-(Polinomio const &p,  Monomio const &m);
	Polinomio & operator-(Polinomio const &p,  double const &x);
	Polinomio & operator-(Monomio const &m, Polinomio const &p);
	Polinomio & operator-(double const &x, Polinomio const &p);
	
	Polinomio & operator*(Polinomio const &p1,  Polinomio const &p2);
	Polinomio & operator*(Polinomio const &p,  Monomio const &m);
	Polinomio & operator*(Polinomio const &p,  double const &x);
	Polinomio & operator*(Monomio const &m, Polinomio const &p);
	Polinomio & operator*(double const &x, Polinomio const &p);

	Polinomio & operator/(Polinomio const &p1,  Polinomio const &p2);
	Polinomio & operator/(Polinomio const &p,  Monomio const &m);
	Polinomio & operator/(Polinomio const &p,  double const &x);
	Polinomio & operator/(Monomio const &m, Polinomio const &p);
	Polinomio & operator/(double const &x, Polinomio const &p);

	/////////////////////////////////////////////////////////////////////////////

   //! \name Sobrecarga de los operadores de flujo de la clase Polinomio.

    // COMPLETAR LOS COMENTARIOS DE DOXYGEN
    ostream &operator<<(ostream &stream, Polinomio const &p);

    // COMPLETAR LOS COMENTARIOS DE DOXYGEN
    istream &operator>>(istream &stream, Polinomio &p);

}  // Fin de namespace ed.

#endif // _OperadoresPolinomios_HPP_
