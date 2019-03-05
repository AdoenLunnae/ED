/*!
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed
{
	// Operadores de igualdad

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2){
		bool cGrados = ( m1.getGrado() == m2.getGrado() );
		bool cCoef;
		cCoef = ( std::abs( m1.getCoeficiente() - m2.getCoeficiente() ) <= COTA_ERROR );
		return( cCoef && cGrados );
	}

	bool operator==(ed::Monomio const & m1, double const x){
		bool cCoef = ( std::abs( m1.getCoeficiente() - x ) <= COTA_ERROR );
		return( ( m1.getGrado() == 0 ) && cCoef);
	}

	bool operator==(double const x, ed::Monomio const & m1){
		bool cCoef = ( std::abs( m1.getCoeficiente() - x ) <= COTA_ERROR );
		return( ( m1.getGrado() == 0 ) && cCoef);
	}


	// Operadores de desigualdad

	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2){
		return( !( m1 == m2 ) );
	}

	bool operator!=(ed::Monomio const & m1, double const x){
		return( !( m1 == x ) );
	}

	bool operator!=(double const x, ed::Monomio const & m1){
		return( !( x == m1 ) );
	}

	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos

	ed::Monomio & operator+(ed::Monomio const & m){
		ed::Monomio *nuevo = new ed::Monomio(m);

		return *nuevo;
	}

	ed::Monomio & operator-(ed::Monomio const & m){
		ed::Monomio *nuevo = new Monomio(m);
		nuevo->setCoeficiente( 0 - nuevo->getCoeficiente() );

		return *nuevo;
	}



	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2){
		#ifndef NDEBUG
			assert( m1.getGrado() == m2.getGrado() );
		#endif

		ed::Monomio *nuevo = new ed::Monomio(m1);
		*nuevo += m2;

		#ifndef NDEBUG
			assert( nuevo->getGrado() == m1.getGrado() );
			assert( std::abs( nuevo->getCoeficiente() - ( m1.getCoeficiente() + \
						m2.getCoeficiente() ) ) <= COTA_ERROR );
		#endif

		return *nuevo;
	}


	////////////
	// Resta
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2){
		#ifndef NDEBUG
			assert( m1.getGrado() == m2.getGrado() );
		#endif

		ed::Monomio *nuevo = new ed::Monomio(m1);
		*nuevo -= m2;

		#ifndef NDEBUG
			assert( nuevo->getGrado() == m1.getGrado() );
			assert( std::abs( nuevo->getCoeficiente() - ( m1.getCoeficiente() - \
						m2.getCoeficiente() ) ) <= COTA_ERROR );
		#endif

		return *nuevo;
	}


	//////////////////
	// Multiplicación
	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2){
		ed::Monomio *nuevo = new Monomio(m1);
		*nuevo *= m2;

		#ifndef NDEBUG
			assert( nuevo->getGrado() == ( m1.getGrado() + m2.getGrado() ) );
			assert( std::abs( nuevo->getCoeficiente() - ( m1.getCoeficiente() * \
						m2.getCoeficiente() ) ) <= COTA_ERROR );
		#endif

		return *nuevo;
	}

	ed::Monomio & operator* (ed::Monomio const &m1, double const x){
		ed::Monomio *nuevo = new Monomio(m1);
		*nuevo *= x;

		#ifndef NDEBUG
			assert( nuevo->getGrado() == m1.getGrado() );
			assert( std::abs( nuevo->getCoeficiente() - ( m1.getCoeficiente() * x ) )\
			 			<= COTA_ERROR );
		#endif

		return *nuevo;
	}
	ed::Monomio & operator* (double const x, ed::Monomio const &m1){
		ed::Monomio *nuevo = new Monomio(m1);
		*nuevo *= x;

		#ifndef NDEBUG
			assert( nuevo->getGrado() == m1.getGrado() );
			assert( std::abs( nuevo->getCoeficiente() - ( m1.getCoeficiente() * x ) )\
						<= COTA_ERROR );
		#endif

		return *nuevo;
	}

	////////////
	// División
	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2){
		#ifndef NDEBUG
			assert( m1.getGrado() >= m2.getGrado() );
			assert( std::abs( m2.getCoeficiente() ) >= COTA_ERROR );
		#endif

		Monomio *nuevo = new Monomio(m1);
		*nuevo /= m2;

		#ifndef NDEBUG
			assert( nuevo->getGrado() == ( m1.getGrado() - m2.getGrado() ) );
			assert( std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente() \
						/ m2.getCoeficiente() ) ) <= COTA_ERROR );
		#endif

		return *nuevo;
	}

	ed::Monomio & operator/ (ed::Monomio const &m1, double const x){
		#ifndef NDEBUG
			assert( std::abs( x ) >= COTA_ERROR );
		#endif

		Monomio *nuevo = new Monomio(m1);
		*nuevo /= x;

		#ifndef NDEBUG
			assert( nuevo->getGrado() == m1.getGrado() );
			assert( std::abs(nuevo->getCoeficiente() - (m1.getCoeficiente() / x ) ) \
						<= COTA_ERROR );
		#endif

		return *nuevo;
	}

	ed::Monomio & operator/ (double const x, ed::Monomio const &m1){
		#ifndef NDEBUG
			assert( m1.getGrado() == 0 );
			assert( std::abs( m1.getCoeficiente() ) >= COTA_ERROR );
		#endif

		ed::Monomio *nuevo = new Monomio();
		nuevo->setGrado(0);
		nuevo->setCoeficiente( x / m1.getCoeficiente());
		
		#ifndef NDEBUG
			assert( nuevo->getGrado() == 0 );
			assert( std::abs( nuevo->getCoeficiente() - ( x / m1.getCoeficiente() ) ) \
						<= COTA_ERROR );
		#endif

		return *nuevo;
	}


	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m){
		double nCoef;
		int nGrado;
		stream >> nCoef >> nGrado;
		m.setCoeficiente(nCoef);
		m.setGrado(nGrado);
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m){
		stream << m.getCoeficiente() << " " << m.getGrado() << '\n';
		return stream;
	}


}  // namespace ed
