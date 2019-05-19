/*!
   \file operadoresExternosPolinomios.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include "operadoresExternosPolinomios.hpp"

#include "operadoresExternosMonomios.hpp"

// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed
{


// COMPLETAR LOS OTROS OPERADORES DE DESIGUALDAD

//////////////////////////////////////////////////////////////////////////////////////

// Operadores unarios

// COMPLETAR

Polinomio & operator-(Polinomio const &p)
{
	Polinomio *retV = new Polinomio;
	for(unsigned int i = 0; i < p.getNumeroMonomios(); i++){
		*retV -= p.getMonomios()[i];
	}
	return  *retV;
}


//////////////////////////////////////////////////////////////////////////////////////

// Operadores binarios de la suma
Polinomio & operator+(Polinomio const &p1,  Polinomio const &p2)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p1);
	*nuevo += p2;

	// Se devuelve el resultado
	return *nuevo;
}

Polinomio & operator+(Polinomio const &p,  Monomio const &m)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p);
	*nuevo += m;

	// Se devuelve el resultado
	return *nuevo;
}

Polinomio & operator+(Polinomio const &p,  double const &x)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p);
	*nuevo += x;

	// Se devuelve el resultado
	return *nuevo;
}

Polinomio & operator+(Monomio const &m, Polinomio const &p)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p);
	*nuevo += m;

	// Se devuelve el resultado
	return *nuevo;
}

Polinomio & operator+(double const &x, Polinomio const &p)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p);
	*nuevo += x;

	// Se devuelve el resultado
	return *nuevo;
}
	////////////


Polinomio & operator-(Polinomio const &p1,  Polinomio const &p2)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p1);
	*nuevo -= p2;

	// Se devuelve el resultado
	return *nuevo;
}

Polinomio & operator-(Polinomio const &p,  Monomio const &m)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p);
	*nuevo -= m;

	// Se devuelve el resultado
	return *nuevo;
}

Polinomio & operator-(Polinomio const &p,  double const &x)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p);
	*nuevo -= x;

	// Se devuelve el resultado
	return *nuevo;
}


Polinomio & operator-(Monomio const &m, Polinomio const &p)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p);
	*nuevo -= m;

	// Se devuelve el resultado
	return *nuevo;
}

Polinomio & operator-(double const &x, Polinomio const &p)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p);
	*nuevo -= x;

	// Se devuelve el resultado
	return *nuevo;
}

	//////////////////


Polinomio & operator*(Polinomio const &p1,  Polinomio const &p2)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p1);
	*nuevo *= p2;

	// Se devuelve el resultado
	return *nuevo;
}

Polinomio & operator*(Polinomio const &p,  Monomio const &m)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p);
	*nuevo *= m;

	// Se devuelve el resultado
	return *nuevo;
}

Polinomio & operator*(Polinomio const &p,  double const &x)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p);
	*nuevo *= x;

	// Se devuelve el resultado
	return *nuevo;
}

Polinomio & operator*(Monomio const &m, Polinomio const &p)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p);
	*nuevo *= m;

	// Se devuelve el resultado
	return *nuevo;
}

Polinomio & operator*(double const &x, Polinomio const &p)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p);
	*nuevo *= x;

	// Se devuelve el resultado
	return *nuevo;
}

	////////////
	// División
Polinomio & operator/(Polinomio const &p1,  Polinomio const &p2)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p1);
	*nuevo /= p2;

	// Se devuelve el resultado
	return *nuevo;
}

Polinomio & operator/(Polinomio const &p,  Monomio const &m)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p);
	*nuevo /= m;

	// Se devuelve el resultado
	return *nuevo;
}

Polinomio & operator/(Polinomio const &p,  double const &x)
{
	// COMPLETAR Y MODIFICAR
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio(p);
	*nuevo /= x;

	// Se devuelve el resultado
	return *nuevo;
}

Polinomio & operator/(Monomio const &m, Polinomio const &p)
{
	#ifndef NDEBUG
		assert(m.getGrado()>=p.getGrado());
	#endif
	// Se crea un nuevo objeto
	Polinomio *nuevo = new Polinomio;	
	*nuevo = m;
	*nuevo /= p;

	// Se devuelve el resultado
	return *nuevo;
}

Polinomio & operator/(double const &x, Polinomio const &p)
{
	#ifndef NDEBUG
		assert(p.getGrado()==0);
		assert(std::abs(p.getMonomio(0).getCoeficiente()) >=COTA_ERROR);
	#endif

	Polinomio *nuevo = new Polinomio;
	*nuevo = x;
	*nuevo /= p;

	// Se devuelve el resultado
	return *nuevo;
}


////////////////////////////////////////////////////////////////////////////

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, Polinomio &p)
{
	Monomio aux;
	
	stream.ignore();
	while(!stream.eof()){
		stream >> aux;
		p += aux;
	}
		
	return stream;
}



// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, Polinomio const &p)
{
	std::vector<Monomio> monomios = p.getMonomios();
	for(unsigned int i = 0; i<monomios.size(); i++){
		stream << monomios[i] << ' ';
	}
	// Se devuelve el flujo de salida
  return stream;
}


} // Fin del espacio de nombres ed
