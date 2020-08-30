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
	auto a = PrimeFactorizationType{ { 7ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 7ULL ) );
	a = PrimeFactorizationType{ { 11ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 11ULL ) );
	a = PrimeFactorizationType{ { 257ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 257ULL ) );
	a = PrimeFactorizationType{ { 997ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 997ULL ) );
	a = PrimeFactorizationType{ { 65537ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 65537ULL ) );
	a = PrimeFactorizationType{ { 104729ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 104729ULL ) );

	a = PrimeFactorizationType{ { 4294967291ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 4294967291ULL ) );
	a = PrimeFactorizationType{ { 4294967279ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 4294967279ULL ) );
	a = PrimeFactorizationType{ { 8589934583ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 8589934583ULL ) );
	a = PrimeFactorizationType{ { 9223372036854775783ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 9223372036854775783ULL ) );
	a = PrimeFactorizationType{ { 18446744073709551557ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 18446744073709551557ULL ) );
	a = PrimeFactorizationType{ { 18446744073709551533ULL, 1 } };
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

TEST( TestPrimeFactorization, powerOf2AndPrime ) {
	auto a = PrimeFactorizationType{ { 2, 1 }, { 3, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 6ULL ) );
	a = PrimeFactorizationType{ { 2, 1 }, { 7, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 14ULL ) );
	a = PrimeFactorizationType{ { 2, 2 }, { 3, 1 }, { 5, 1 }, { 7, 2 } };
	EXPECT_EQ( a, PrimeFactorize( 2940ULL ) );
	a = PrimeFactorizationType{ { 2, 1 }, { 971, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 1942ULL ) );
	a = PrimeFactorizationType{ { 2, 2 }, { 62549, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 250196ULL ) );
	a = PrimeFactorizationType{ { 2, 32 }, { 104651ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 449472622493696ULL ) );

	a = PrimeFactorizationType{ { 2, 1 }, { 104161ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 208322ULL ) );
	a = PrimeFactorizationType{ { 2, 2 }, { 3, 2 }, { 100621ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 3622356ULL ) );
	a = PrimeFactorizationType{ { 2, 1 }, { 9223372036854775421ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 18446744073709550842ULL ) );
	a = PrimeFactorizationType{ { 2, 1 }, { 2147483629ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 4294967258ULL ) );
}

TEST( TestPrimeFactorization, divSmallPrime ) {
	auto a = PrimeFactorizationType{ { 3ULL, 2 } };
	EXPECT_EQ( a, PrimeFactorize( 3ULL * 3ULL ) );
	a = PrimeFactorizationType{ { 3ULL, 3 } };
	EXPECT_EQ( a, PrimeFactorize( 27ULL ) );
	a = PrimeFactorizationType{ { 3ULL, 4 } };
	EXPECT_EQ( a, PrimeFactorize( 81ULL ) );
	a = PrimeFactorizationType{ { 3ULL, 2 }, { 5ULL, 2 } };
	EXPECT_EQ( a, PrimeFactorize( 225ULL ) );
	a = PrimeFactorizationType{ { 3ULL, 40 } };
	EXPECT_EQ( a, PrimeFactorize( 12157665459056928801ULL ) );
	a = PrimeFactorizationType{ { 5ULL, 27 } };
	EXPECT_EQ( a, PrimeFactorize( 7450580596923828125ULL ) );
	a = PrimeFactorizationType{ { 3ULL, 20 }, { 5ULL, 13 } };
	EXPECT_EQ( a, PrimeFactorize( 4256328614501953125 ) );
	a = PrimeFactorizationType{ { 3ULL, 2 }, { 5ULL, 2 }, { 7ULL, 2 } };
	EXPECT_EQ( a, PrimeFactorize( 11025ULL ) );
	a = PrimeFactorizationType{ { 5ULL, 2 }, { 13ULL, 3 }, { 17ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 933725ULL ) );
	a = PrimeFactorizationType{ { 2ULL, 1 }, { 3ULL, 2 }, { 101ULL, 1 }, { 907ULL, 1 }, { 911ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 1502171586ULL ) );

	a = PrimeFactorizationType{ { 2ULL, 1 },  { 3ULL, 1 },  { 5ULL, 1 },  { 7ULL, 1 },  { 11ULL, 1 },
	                            { 13ULL, 1 }, { 17ULL, 1 }, { 19ULL, 1 }, { 23ULL, 1 }, { 29ULL, 1 },
	                            { 31ULL, 1 }, { 37ULL, 1 }, { 41ULL, 1 }, { 43ULL, 1 }, { 47ULL, 1 } };
	EXPECT_EQ( a, PrimeFactorize( 614889782588491410ULL ) );
	a = PrimeFactorizationType{ { 65521ULL, 4 } };
	EXPECT_EQ( a, PrimeFactorize( 18429861372428076481ULL ) );
}

TEST( TestPrimeFactorization, tryingSquareRoot ) {
	auto a = PrimeFactorizationType{ { 3ULL, 3 }, { 131059ULL, 2 } };
	EXPECT_EQ( a, PrimeFactorize( 463764459987ULL ) );
	a = PrimeFactorizationType{ { 2147483579ULL, 2 } };
	EXPECT_EQ( a, PrimeFactorize( 4611685722074649241ULL ) );
	a = PrimeFactorizationType{ { 131041ULL, 2 } };
	EXPECT_EQ( a, PrimeFactorize( 17171743681ULL ) );
	a = PrimeFactorizationType{ { 1048573ULL, 2 } };
	EXPECT_EQ( a, PrimeFactorize( 1099505336329ULL ) );
	a = PrimeFactorizationType{ { 2ULL, 2 }, { 3ULL, 3 }, { 1048571ULL, 2 } };
	EXPECT_EQ( a, PrimeFactorize( 118746123340428ULL ) );
}
