#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

#include "prime_factorization.h"

int main( int argc, const char **argv ) {
	if ( argc < 2 ) {
		printf( "%s number(~ 2^64-1)\n", argv[ 0 ] );
		return 1;
	}
	uint64_t target_number = strtoull( argv[ 1 ], NULL, 10 );

	printf( "%llu\n", target_number );

	std::vector<std::pair<uint64_t, uint32_t> > prime_factorization;
	prime_factorization = PrimeFactorize( target_number );

	for ( auto &&element : prime_factorization ) {
		printf( "%llu, %u\n", element.first, element.second );
	}

	return 0;
}
