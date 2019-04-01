/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>
#include <algorithm>

#include "Polinomio.hpp"


namespace ed{

int Polinomio::findMonomio(int const grado) const
{
	#ifndef NDEBUG
		assert(getNumeroMonomios() > 0);
	#endif

	bool found = false;
	unsigned int i;
	for(i = 0; i < getNumeroMonomios() && !found; i++){
		if(_monomios[i].getGrado() == grado) found = true;
	}
	return found?i-1:-1;	
}

void Polinomio::sort()
{
	std::sort(_monomios.begin(), _monomios.end());
	std::reverse(_monomios.begin(), _monomios.end());
	for(unsigned int i = 0; i < getNumeroMonomios(); i++){
		if(std::abs(_monomios[i].getCoeficiente()) < COTA_ERROR){
			_monomios.erase(_monomios.begin() + i);
		}
	}
}

/////////////////////////////////////////////////////////////

Polinomio & Polinomio::operator=(Polinomio const &p)
{
	#ifndef NDEBUG
		assert(_monomios != p._monomios);
	#endif

	_monomios = (p._monomios);

	#ifndef NDEBUG
		assert(_monomios == p._monomios);
	#endif
		
	return *this;
}


Polinomio & Polinomio::operator=(Monomio const &m)
{
	_monomios.assign(1, m);

	#ifndef NDEBUG
		assert((getNumeroMonomios() == 1) 
			&& (_monomios[0] == m));
	#endif

	return *this;
}


Polinomio & Polinomio::operator=(double const &x)
{
	_monomios.assign(1, Monomio(0, x));

	#ifndef NDEBUG
		assert((getNumeroMonomios() == 1) 
			&& (_monomios[0] == x));
	#endif

	return *this;
}

/////////////////////////////////https://stackoverflow.com/questions/2758080/how-to-sort-an-stl-vector/////////////////////////////

Polinomio & Polinomio::operator+=(Polinomio const &p)
{
	for(unsigned int i = 0; i < p.getNumeroMonomios(); i++){
		int currGrado = p._monomios[i].getGrado();
		if(existeMonomio(currGrado)){
			_monomios[findMonomio(currGrado)] += p._monomios[i];
		}
		else{
			_monomios.push_back(p._monomios[i]);
		}
	}
	sort();

	#ifndef NDEBUG
		assert(isOrdered());
	#endif

	return *this;
}

Polinomio & Polinomio::operator+=(Monomio const &m)
{
	int grado = m.getGrado();
	if(existeMonomio(grado)){
		_monomios[findMonomio(grado)] += m;
	}
	else{
		_monomios.push_back(m);
	}
	sort();

	#ifndef NDEBUG
		assert(isOrdered());
	#endif
	
	return *this;
}

Polinomio & Polinomio::operator+=(double const &x)
{
	if(existeMonomio(0)){
		_monomios[findMonomio(0)] += Monomio(0, x);
	}
	else{
		_monomios.push_back(Monomio(0, x));
	}
	//sort();

	#ifndef NDEBUG
		assert(isOrdered());
	#endif
	
	return *this;
}

Polinomio & Polinomio::operator-=(Polinomio const &p)
{
	for(unsigned int i = 0; i < p.getNumeroMonomios(); i++){
		int currGrado = p._monomios[i].getGrado();
		if(existeMonomio(currGrado)){
			_monomios[findMonomio(currGrado)] -= p._monomios[i];
		}
		else{
			_monomios.push_back(-p._monomios[i]);
		}
	}
	sort();

	#ifndef NDEBUG
		assert(isOrdered());
	#endif

	return *this;
}

Polinomio & Polinomio::operator-=(Monomio const &m)
{
	int grado = m.getGrado();
	if(existeMonomio(grado)){
		_monomios[findMonomio(grado)] -= m;
	}
	else{
		_monomios.push_back(-m);
	}
	sort();

	#ifndef NDEBUG
		assert(isOrdered());
	#endif
	
	return *this;
}

Polinomio & Polinomio::operator-=(double const &x)
{
	if(existeMonomio(0)){
		_monomios[findMonomio(0)] -= Monomio(0, x);
	}
	else{
		_monomios.push_back(Monomio(0, -x));
	}
	//sort();
	#ifndef NDEBUG
		assert(isOrdered());
	#endif
	
	return *this;
}

Polinomio & Polinomio::operator*=(Polinomio const &p)
{
	Polinomio old(*this);
	Polinomio aux;
	_monomios.assign(1, Monomio(0, 0.0));
	for(unsigned int i = 0; i < p.getNumeroMonomios(); i++){
		aux = old;
		aux *= p._monomios[i];
		*this += aux;
	}

	sort();

	#ifndef NDEBUG
		assert(isOrdered());
	#endif

	return *this;
}

Polinomio & Polinomio::operator*=(Monomio const &m)
{
	for(unsigned int i = 0; i < getNumeroMonomios(); i++){
		_monomios[i] *= m;
	}

	#ifndef NDEBUG
		assert(isOrdered());
	#endif
	
	return *this;
}

Polinomio & Polinomio::operator*=(double const &x)
{
	for(unsigned int i = 0; i < getNumeroMonomios(); i++){
		_monomios[i] *= x;
	}
	//sort();
	#ifndef NDEBUG
		assert(isOrdered());
	#endif
	
	return *this;
}

/*
function n / d:
  require d ≠ 0
  q ← 0
  r ← n       # At each step n = d × q + r
  while r ≠ 0 AND degree(r) ≥ degree(d):
     t ← lead(r)/lead(d)
     q ← q + t
     r ← r − t * d
  return (q)

	q->nulo, valor devuelto
	r->this
	d->p
*/
Polinomio & Polinomio::operator/=(Polinomio const &p)
{
	#ifndef NDEBUG
		assert(!p.esNulo());
		assert(getGrado() >= p.getGrado());
	#endif

	Polinomio q = *new Polinomio();
	Polinomio r = *new Polinomio(*this);
	Polinomio aux = *new Polinomio();
	Monomio t = *new Monomio;
	while((!r.esNulo()) && (r.getGrado() >= p.getGrado())){
		t = r._monomios[0] / p._monomios[0];
		q += t;
		aux = p;
		aux *= t;
		r -= aux;
	}
	*this = q;
	return *this;
}

Polinomio & Polinomio::operator/=(Monomio const &m)
{
	#ifndef NDEBUG
		assert(!esNulo());
	#endif

	for(unsigned int i = 0; i < getNumeroMonomios(); i++){
		_monomios[i] /= m;
	}
	
	sort();
	return *this;

}

Polinomio & Polinomio::operator/=(double const &x)
{
	for(unsigned int i = 0; i < getNumeroMonomios(); i++){
		_monomios[i] /= x;
	}
	
	sort();
	return *this;
}
///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio

void Polinomio::leerPolinomio(){
	unsigned int nMon;
	_monomios.assign(1, Monomio(0, 0.0));
	Monomio aux = *new Monomio;
	std::cout << "Número de monomios a introducir: ";
	std::cin >> nMon;
	for(unsigned int i = 0; i < nMon; i++){
		aux.leerMonomio();
		*this += aux;
	}
}

void Polinomio::escribirPolinomio(){
	for(unsigned int i = 0; i < getNumeroMonomios(); i++){
		_monomios[i].escribirMonomio();
		std::cout << "    ";
	}
}

///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio
double Polinomio::calcularValor(double const &x){
	double result = 0;
	for(unsigned int i = 0; i < getNumeroMonomios(); i++){
		result += _monomios[i].calcularValor(x);
	}
	return result;
}

}
