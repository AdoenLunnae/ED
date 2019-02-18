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
	#ifndef NDEBUG
		assert( this->getGrado() == m.getGrado() );
	#endif

	ed::Monomio old(*this);
	this->setCoeficiente( this->getCoeficiente() + m.getCoeficiente() );

	#ifndef NDEBUG
		assert( this->getCoeficiente() == \
					( old.getCoeficiente() + m.getCoeficiente() ) );

		assert( this->getGrado() == old.getGrado() );
	#endif

	return *this;
}

ed::Monomio & ed::Monomio::operator-=(ed::Monomio const &m){
	#ifndef NDEBUG
		assert( this->getGrado() == m.getGrado() );
	#endif

	ed::Monomio old(*this);
	this->setCoeficiente( this->getCoeficiente() - m.getCoeficiente() );

	#ifndef NDEBUG
		assert( this->getCoeficiente() == \
					( old.getCoeficiente() - m.getCoeficiente() ) );

		assert( this->getGrado() == old.getGrado() );
	#endif

	return (*this);
}

ed::Monomio & ed::Monomio::operator*=(ed::Monomio const &m){
	ed::Monomio old(*this);
	this->setCoeficiente( this->getCoeficiente() * m.getCoeficiente() );
	this->setGrado( this->getGrado() - m.getGrado() );

	#ifndef NDEBUG
		assert( this->getCoeficiente() == \
					( old.getCoeficiente() * m.getCoeficiente() ) );

		assert( this->getGrado() == ( old.getGrado() * m.getGrado() ) );
	#endif

	return (*this);
}

ed::Monomio & ed::Monomio::operator/=(ed::Monomio const &m){
	#ifndef NDEBUG
		assert( this->getGrado() >= m.getGrado() );
		assert( std::abs(m.getCoeficiente() ) >= COTA_ERROR);
	#endif

	ed::Monomio old(*this);
	this->setCoeficiente( this->getCoeficiente() * m.getCoeficiente() );
	this->setGrado( this->getGrado() - m.getGrado() );

	#ifndef NDEBUG
		assert( this->getCoeficiente() == \
					( old.getCoeficiente() * m.getCoeficiente() ) );

		assert( this->getGrado() == ( old.getGrado() * m.getGrado() ) );
	#endif

	return (*this);
}

ed::Monomio & ed::Monomio::operator*=(float const x){
	ed::Monomio old(*this);
	this->setCoeficiente( this->getCoeficiente() * x );

	#ifndef NDEBUG
		assert( this->getGrado() == old.getGrado() );
		assert( std::abs( this->getCoeficiente() - ( old.getCoeficiente() * x ) )  \
					<= COTA_ERROR );
	#endif

return(*this);
}

ed::Monomio & ed::Monomio::operator/=(float const x){
	#ifndef NDEBUG
		assert( std::abs(x) >= COTA_ERROR);
	#endif

	ed::Monomio old(*this);
	this->setCoeficiente( this->getCoeficiente() / x );

	#ifndef NDEBUG
		assert( this->getGrado() == old.getGrado() );
		assert( std::abs( this->getCoeficiente() - ( old.getCoeficiente() / x ) )  \
						<= COTA_ERROR );
	#endif

return(*this);
}
///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

// COMPLETAR


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

// COMPLETAR
