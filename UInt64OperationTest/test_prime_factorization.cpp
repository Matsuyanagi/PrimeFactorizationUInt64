#include "pch.h"

#include "../PrimeFactorizationUInt64/prime_factorization.h"

typedef std::vector<std::pair<uint64_t, uint32_t> > PrimeFactorizationType;

TEST( TestPrimeFactorization, simpleSmall ) {

	// EXPECT_EQ( PrimeFactorizationType{ { 0, 1 } }, PrimeFactorize( 0ULL ) );
	auto a = PrimeFactorizationType{ { 0, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 0ULL ) );
	// EXPECT_EQ( PrimeFactorizationType{ { 1, 1 } }, PrimeFactorize( 1ULL ) );
	a = PrimeFactorizationType{ { 1, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 1ULL ) );
	// EXPECT_EQ( PrimeFactorizationType{ { 2, 1 } }, PrimeFactorize( 2ULL ) );
	a = PrimeFactorizationType{ { 2, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 2ULL ) );
	// EXPECT_EQ( PrimeFactorizationType{ { 3, 1 } }, PrimeFactorize( 3ULL ) );
	a = PrimeFactorizationType{ { 3, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 3ULL ) );
	// EXPECT_EQ( PrimeFactorizationType{ { 2, 2 } }, PrimeFactorize( 4ULL ) );
	a = PrimeFactorizationType{ { 2, 2 } };
	EXPECT_EQ( a, PrimeFactorize( 4ULL ) );
	// EXPECT_EQ( PrimeFactorizationType{ { 5, 1 } }, PrimeFactorize( 5ULL ) );
	a = PrimeFactorizationType{ { 5, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 5ULL ) );
}

TEST( TestPrimeFactorization, primeNumber ) {

	auto a = PrimeFactorizationType{ { 7, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 7ULL ) );
	a = PrimeFactorizationType{ { 11, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 11ULL ) );
	a = PrimeFactorizationType{ { 257, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 257ULL ) );
	a = PrimeFactorizationType{ { 997, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 997ULL ) );
	a = PrimeFactorizationType{ { 65537, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 65537ULL ) );
	a = PrimeFactorizationType{ { 104729, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 104729ULL ) );

	a = PrimeFactorizationType{ { 4294967291, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 4294967291ULL ) );
	a = PrimeFactorizationType{ { 4294967279, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 4294967279ULL ) );
	a = PrimeFactorizationType{ { 8589934583, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 8589934583ULL ) );
	a = PrimeFactorizationType{ { 9223372036854775783, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 9223372036854775783ULL ) );
	a = PrimeFactorizationType{ { 18446744073709551557, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 18446744073709551557ULL ) );
	a = PrimeFactorizationType{ { 18446744073709551533, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 18446744073709551533ULL ) );
}

TEST( TestPrimeFactorization, powerOf2 ) {

	auto a = PrimeFactorizationType{ { 2, 3 } };
	EXPECT_EQ( a, PrimeFactorize( 8ULL ) );
	a = PrimeFactorizationType{ { 2, 4 } };
	EXPECT_EQ( a, PrimeFactorize( 16ULL ) );
	a = PrimeFactorizationType{ { 2, 8 } };
	EXPECT_EQ( a, PrimeFactorize( 256ULL ) );
	a = PrimeFactorizationType{ { 2, 16 } };
	EXPECT_EQ( a, PrimeFactorize( 65536ULL ) );
	a = PrimeFactorizationType{ { 2, 31 } };
	EXPECT_EQ( a, PrimeFactorize( 2147483648ULL ) );
	a = PrimeFactorizationType{ { 2, 32 } };
	EXPECT_EQ( a, PrimeFactorize( 4294967296ULL ) );

	a = PrimeFactorizationType{ { 2, 60 } };
	EXPECT_EQ( a, PrimeFactorize( 1152921504606846976ULL ) );
	a = PrimeFactorizationType{ { 2, 61 } };
	EXPECT_EQ( a, PrimeFactorize( 2305843009213693952ULL ) );
	a = PrimeFactorizationType{ { 2, 62 } };
	EXPECT_EQ( a, PrimeFactorize( 4611686018427387904ULL ) );
	a = PrimeFactorizationType{ { 2, 63 } };
	EXPECT_EQ( a, PrimeFactorize( 9223372036854775808ULL ) );

}
