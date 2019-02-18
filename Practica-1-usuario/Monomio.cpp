/*!
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"





//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación

// COMPLETAR


ed::Monomio & ed::Monomio::operator+=(ed::Monomio const &m){
	assert( this->getGrado() == m.getGrado() );

	ed::Monomio old(*this);
	this->setCoeficiente( this->getCoeficiente() + m.getCoeficiente() );

	assert( this->getCoeficiente() == \
				( old.getCoeficiente() + m.getCoeficiente() ) );

	assert( this->getGrado() == old.getGrado() );

	return *this;
}

ed::Monomio & ed::Monomio::operator-=(ed::Monomio const &m){
	assert( this->getGrado() == m.getGrado() );

	ed::Monomio old(*this);
	this->setCoeficiente( this->getCoeficiente() - m.getCoeficiente() );

	assert( this->getCoeficiente() == \
				( old.getCoeficiente() - m.getCoeficiente() ) );

	assert( this->getGrado() == old.getGrado() );
	// Se devuelve el objeto actual
	return (*this);
}

ed::Monomio & ed::Monomio::operator*=(ed::Monomio const &m){
	ed::Monomio old(*this);
	this->setCoeficiente( this->getCoeficiente() * m.getCoeficiente() );
	this->setGrado( this->getGrado() - m.getGrado() );

	assert( this->getCoeficiente() == \
				( old.getCoeficiente() * m.getCoeficiente() ) );

	assert( this->getGrado() == ( old.getGrado() * m.getGrado() ) );

	return (*this);
}

ed::Monomio & ed::Monomio::operator/=(ed::Monomio const &m){
	assert( this->getGrado() >= m.getGrado() );
	assert( std::abs(m.getCoeficiente() ) >= COTA_ERROR);
	ed::Monomio old(*this);
	this->setCoeficiente( this->getCoeficiente() * m.getCoeficiente() );
	this->setGrado( this->getGrado() - m.getGrado() );

	assert( this->getCoeficiente() == \
				( old.getCoeficiente() * m.getCoeficiente() ) );

	assert( this->getGrado() == ( old.getGrado() * m.getGrado() ) );

	return (*this);
}


///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

// COMPLETAR


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

// COMPLETAR
