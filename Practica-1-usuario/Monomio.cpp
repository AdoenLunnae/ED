/*!
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>
#include <string>

#include "Monomio.hpp"
#include "macros.hpp"




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

		assert( this->getGrado() == ( old.getGrado() - m.getGrado() ) );
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

ed::Monomio & ed::Monomio::operator*=(double const x){
	ed::Monomio old(*this);
	this->setCoeficiente( this->getCoeficiente() * x );

	#ifndef NDEBUG
		assert( this->getGrado() == old.getGrado() );
		assert( std::abs( this->getCoeficiente() - ( old.getCoeficiente() * x ) )  \
					<= COTA_ERROR );
	#endif

return(*this);
}

ed::Monomio & ed::Monomio::operator/=(double const x){
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

void ed::Monomio::leerMonomio(){
	int nGrado = -1;
	double nCoef;

	while(nGrado <= 0){
		std::cout << BIGREEN << "Introduzca el grado:\t" << RESET;
		std::cin >> nGrado;
	}
	this->setGrado(nGrado);

	std::cout << BIGREEN << "Introduzca el coeficiente:\t" << RESET;
	std::cin >> nCoef;

	this->setCoeficiente(nCoef);

	#ifndef NDEBUG
		assert( this->getGrado() >= 0);
	#endif
}

void ed::Monomio::escribirMonomio() const {
	std::string result;
	if ( std::abs(this->getCoeficiente()+1) <= COTA_ERROR ){ //Grado = -1
		result += "-";
	} else if(std::abs( this->getCoeficiente()-1 ) >= COTA_ERROR){ //Grado != 1
		result += std::to_string( this->getCoeficiente() );
	}
	if( this->getGrado() != 0 ){
		result += "x";
		if( this->getGrado() != 1){
			result += "^";
			result += std::to_string( this->getGrado() );
		}
	}
	std::cout << result << std::endl;
}


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

// COMPLETAR
