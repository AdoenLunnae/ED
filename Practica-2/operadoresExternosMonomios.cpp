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

	bool operator==(Monomio const & m1, Monomio const & m2){
		bool cGrados = ( m1.getGrado() == m2.getGrado() );
		bool cCoef;
		cCoef = ( std::abs( m1.getCoeficiente() - m2.getCoeficiente() ) <= COTA_ERROR );
		return( cCoef && cGrados );
	}

	bool operator==(Monomio const & m1, double const x){
		bool cCoef = ( std::abs( m1.getCoeficiente() - x ) <= COTA_ERROR );
		return( ( m1.getGrado() == 0 ) && cCoef);
	}

	bool operator==(double const x, Monomio const & m1){
		bool cCoef = ( std::abs( m1.getCoeficiente() - x ) <= COTA_ERROR );
		return( ( m1.getGrado() == 0 ) && cCoef);
	}


	// Operadores de desigualdad

	bool operator!=(Monomio const & m1, Monomio const & m2){
		return( !( m1 == m2 ) );
	}

	bool operator!=(Monomio const & m1, double const x){
		return( !( m1 == x ) );
	}

	bool operator!=(double const x, Monomio const & m1){
		return( !( x == m1 ) );
	}

	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos

	Monomio & operator+(Monomio const & m){
		Monomio *nuevo = new Monomio(m);

		return *nuevo;
	}

	Monomio & operator-(Monomio const & m){
		Monomio *nuevo = new Monomio(m);
		nuevo->setCoeficiente( 0 - nuevo->getCoeficiente() );

		return *nuevo;
	}



	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	Monomio & operator+ (Monomio const &m1, Monomio const &m2){
		#ifndef NDEBUG
			assert( m1.getGrado() == m2.getGrado() );
		#endif

		Monomio *nuevo = new Monomio(m1);
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
	Monomio & operator- (Monomio const &m1, Monomio const &m2){
		#ifndef NDEBUG
			assert( m1.getGrado() == m2.getGrado() );
		#endif

		Monomio *nuevo = new Monomio(m1);
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
	Monomio & operator* (Monomio const &m1, Monomio const &m2){
		Monomio *nuevo = new Monomio(m1);
		*nuevo *= m2;

		#ifndef NDEBUG
			assert( nuevo->getGrado() == ( m1.getGrado() + m2.getGrado() ) );
			assert( std::abs( nuevo->getCoeficiente() - ( m1.getCoeficiente() * \
						m2.getCoeficiente() ) ) <= COTA_ERROR );
		#endif

		return *nuevo;
	}

	Monomio & operator* (Monomio const &m1, double const x){
		Monomio *nuevo = new Monomio(m1);
		*nuevo *= x;

		#ifndef NDEBUG
			assert( nuevo->getGrado() == m1.getGrado() );
			assert( std::abs( nuevo->getCoeficiente() - ( m1.getCoeficiente() * x ) )\
			 			<= COTA_ERROR );
		#endif

		return *nuevo;
	}
	Monomio & operator* (double const x, Monomio const &m1){
		Monomio *nuevo = new Monomio(m1);
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
	Monomio & operator/ (Monomio const &m1, Monomio const &m2){
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

	Monomio & operator/ (Monomio const &m1, double const x){
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

	Monomio & operator/ (double const x, Monomio const &m1){
		#ifndef NDEBUG
			assert( m1.getGrado() == 0 );
			assert( std::abs( m1.getCoeficiente() ) >= COTA_ERROR );
		#endif

		Monomio *nuevo = new Monomio();
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
	istream &operator>>(istream &stream, Monomio &m){
		double nCoef;
		int nGrado;
		stream >> nCoef >> nGrado;
		m.setCoeficiente(nCoef);
		m.setGrado(nGrado);
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, Monomio const &m){
		stream << m.getCoeficiente() << " " << m.getGrado();
		return stream;
	}

	bool operator<(Monomio const & m1, Monomio const & m2){
		if( m1.getGrado() < m2.getGrado() ) return true;
		else if(( m1.getGrado() == m2.getGrado()) 
		&& (std::abs(m2.getCoeficiente() - m1.getCoeficiente()) >= COTA_ERROR)){
			return true;
		}
		return false;
	}


}  // namespace ed
