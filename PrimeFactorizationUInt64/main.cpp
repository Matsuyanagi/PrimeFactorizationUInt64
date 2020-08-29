#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

#include "prime_factorization.h"

int main( int argc, const char **argv ) {
	if ( argc < 1 ) {
		printf( "%s number(~ 2^64-1)\n", argv[ 0 ] );
	}
	uint64_t target_number = atoll( argv[ 1 ] );

	printf( "%llu\n", target_number );

	std::vector<std::pair<uint64_t, uint32_t> > prime_factorization;
	prime_factorization = PrimeFactorize( target_number );

	for ( auto &&element : prime_factorization ) {
		printf( "( %llu, %u )", element.first, element.second );
	}
	printf( "\n" );

	return 0;
}
