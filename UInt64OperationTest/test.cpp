#include "pch.h"

#include "../UInt64Operation/uint64_operation.h"

TEST( TestCaseName, uaddmod64 ) {
	uint64_t a, b, c;

	a = 0xFFFF'FFFF'FFFF'F000;
	b = 0xFFFF'FFFF'FFFF'FF00;
	c = 0xFFFF'FFFF'FFFF'FFC5;

	EXPECT_EQ( 0xffffffffffffef3b, uaddmod64( a, b, c ) );

	EXPECT_EQ( 0, uaddmod64( 0, 0, 2 ) );
	EXPECT_EQ( 1, uaddmod64( 1, 0, 2 ) );
	EXPECT_EQ( 1, uaddmod64( 0, 1, 2 ) );
	EXPECT_EQ( 1, uaddmod64( 0, 1, 11 ) );
	EXPECT_EQ( 2, uaddmod64( 1, 1, 11 ) );
	EXPECT_EQ( 0, uaddmod64( 5, 6, 11 ) );
	EXPECT_EQ( 1, uaddmod64( 6, 6, 11 ) );
	EXPECT_EQ( 6, uaddmod64( 36, 91, 11 ) );

	c = 0xFFFF'FFFF'FFFF'FFC5;
	EXPECT_EQ( 0, uaddmod64( c, c, c ) );
	EXPECT_EQ( 127, uaddmod64( 36, 91, c ) );
	EXPECT_EQ( 116, uaddmod64( 0xFFFF'FFFF'FFFF'FFFF, 0xFFFF'FFFF'FFFF'FFFF, c ) );
	EXPECT_EQ( 2, uaddmod64( 1, 1, c ) );
	EXPECT_EQ( 0x8000000000000000, uaddmod64( 0xffffffffffffffc4, 0x8000000000000001, c ) );
	EXPECT_EQ( 0x8000000000000000, uaddmod64( 0xffffffffffffffc6, 0x7fffffffffffffff, c ) );
}

TEST( TestCaseName, usubmod64 ) {
	uint64_t a, b, c, p, ans;

	a = 5;
	b = 0xFFFF'FFFF'FFFF'FF00;
	c = 0x8000;

	EXPECT_EQ( 261, usubmod64( a, b, c ) );

	EXPECT_EQ( 0, usubmod64( 0, 0, 2 ) );
	EXPECT_EQ( 1, usubmod64( 1, 0, 2 ) );
	EXPECT_EQ( 1, usubmod64( 0, 1, 2 ) );
	EXPECT_EQ( 10, usubmod64( 0, 1, 11 ) );
	EXPECT_EQ( 0, usubmod64( 1, 1, 11 ) );
	EXPECT_EQ( 10, usubmod64( 5, 6, 11 ) );
	EXPECT_EQ( 0, usubmod64( 6, 6, 11 ) );
	EXPECT_EQ( 0, usubmod64( 36, 91, 11 ) );
	EXPECT_EQ( 0, usubmod64( 91, 36, 11 ) );
	EXPECT_EQ( 9, usubmod64( 13, 15, 11 ) );

	c = 0xFFFF'FFFF'FFFF'FFC5;
	EXPECT_EQ( 0, usubmod64( c, c, c ) );
	EXPECT_EQ( 0, usubmod64( 0, 0, c ) );
	EXPECT_EQ( 0xffffffffffffff8e, usubmod64( 36, 91, c ) );
	EXPECT_EQ( 0, usubmod64( 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, c ) );
	EXPECT_EQ( 1, usubmod64( 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFE, c ) );
	EXPECT_EQ( c - 1, usubmod64( 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF, c ) );
	EXPECT_EQ( 0x8000000000000000, usubmod64( 0xffffffffffffffc4, 0x7fffffffffffffc4, c ) );
	EXPECT_EQ( 0x8000000000000000, usubmod64( 0xffffffffffffffc6, 0x7fffffffffffffc6, c ) );
}

TEST( TestCaseName, umodinv64 ) {
	std::vector<uint64_t> prime_numbers{ 3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,  53,  59,  61,
	                                     67,  71,  73,  79,  83,  89,  97,  101, 103, 107, 109, 113, 127, 131, 137, 139, 149,
	                                     151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229 };

	for ( auto &&prime : prime_numbers ) {
		for ( size_t i = 2; i < prime - 1; i++ ) {
			const uint64_t inv = umodinv64( i, prime );

			EXPECT_EQ( 1, umulmod64( i, inv, prime ) );
			EXPECT_EQ( powmod64( i, prime - 2, prime ), inv );
		}
	}
}

TEST( TestCaseName, umodinv64_large_number ) {
	std::vector<uint64_t> prime_numbers{ 18446744073709551557ULL, 18446744073709551533ULL, 18446744073709551521ULL,
	                                     18446744073709551437ULL, 18446744073709551427ULL, 18446744073709551359ULL,
	                                     18446744073709551337ULL, 18446744073709551293ULL, 18446744073709551263ULL,
	                                     18446744073709551253ULL };

	for ( auto &&prime : prime_numbers ) {
		for ( size_t i = 2; i < 1000; i++ ) {
			const uint64_t inv = umodinv64( i, prime );
			EXPECT_EQ( 1, umulmod64( i, inv, prime ) );
			EXPECT_EQ( powmod64( i, prime - 2, prime ), inv );
		}
		for ( size_t i = prime - 1000; i < prime - 1; i++ ) {
			const uint64_t inv = umodinv64( i, prime );
			EXPECT_EQ( 1, umulmod64( i, inv, prime ) );
			EXPECT_EQ( powmod64( i, prime - 2, prime ), inv );
		}
	}
}

TEST( TestCaseName, umulmod64 ) {
	uint64_t a, b, c, p, ans;

	a = 0xFFFF'FFFF'FFFF'F000;
	b = 0xFFFF'FFFF'FFFF'FF00;
	c = 0xFFFF'FFFF'FFFF'FFC5;

	//	EXPECT_EQ( 0xffffffffffffef3b, umulmod64( a, b, c ) );

	EXPECT_EQ( 0, umulmod64( 0, 0, 2 ) );
	EXPECT_EQ( 0, umulmod64( 1, 0, 2 ) );
	EXPECT_EQ( 0, umulmod64( 0, 1, 2 ) );
	EXPECT_EQ( 0, umulmod64( 0, 1, 11 ) );
	EXPECT_EQ( 1, umulmod64( 1, 1, 11 ) );
	EXPECT_EQ( 8, umulmod64( 5, 6, 11 ) );
	EXPECT_EQ( 3, umulmod64( 6, 6, 11 ) );
	EXPECT_EQ( 9, umulmod64( 36, 91, 11 ) );

	c = 0xFFFF'FFFF'FFFF'FFC5;
	EXPECT_EQ( 0, umulmod64( c, c, c ) );
	EXPECT_EQ( 1, umulmod64( 1, 1, c ) );
	EXPECT_EQ( 3276, umulmod64( 36, 91, c ) );
	EXPECT_EQ( 4137, umulmod64( 0xFFFF'FFFF'FFFF'FF00, 0xFFFF'FFFF'FFFF'FFB0, c ) );
	EXPECT_EQ( 4137, umulmod64( 0xFFFF'FFFF'FFFF'FFB0, 0xFFFF'FFFF'FFFF'FF00, c ) );
	// EXPECT_EQ( 3364, umulmod64( 0xFFFF'FFFF'FFFF'FFFE, 0xFFFF'FFFF'FFFF'FFFF, c ) );
	EXPECT_EQ( 1653, umulmod64( 0x7FFF'FFFF'FFFF'FFFF, 0xFFFF'FFFF'FFFF'FFFF, c ) );
	EXPECT_EQ( 1653, umulmod64( 0xFFFF'FFFF'FFFF'FFFF, 0x7FFF'FFFF'FFFF'FFFF, c ) );

	c = 0xfffffffffffffeff;
	EXPECT_EQ( 1, umulmod64( 2, 9223372036854775680, c ) );
	EXPECT_EQ( 1, umulmod64( 18446744073709551349U, 16602069666338596223U, c ) );
	EXPECT_EQ( 1, umulmod64( 3, umodinv64( 3, c ), c ) );
	EXPECT_EQ( 1, umulmod64( 5, umodinv64( 5, c ), c ) );
}

TEST( TestCaseName, is_prime ) {
	EXPECT_TRUE( is_prime( 2ULL ) );
	EXPECT_TRUE( is_prime( 3ULL ) );
	EXPECT_TRUE( is_prime( 5ULL ) );
	EXPECT_TRUE( is_prime( 7ULL ) );
	EXPECT_TRUE( is_prime( 41ULL ) );
	EXPECT_TRUE( is_prime( 43ULL ) );
	EXPECT_TRUE( is_prime( 47ULL ) );
	EXPECT_TRUE( is_prime( 97ULL ) );
	EXPECT_TRUE( is_prime( 65479ULL ) );
	EXPECT_TRUE( is_prime( 65497ULL ) );
	EXPECT_TRUE( is_prime( 18446744073709551557ULL ) );
	EXPECT_TRUE( is_prime( 18446744073709551533ULL ) );
	EXPECT_TRUE( is_prime( 18446744073709551521ULL ) );
	EXPECT_TRUE( is_prime( 18446744073709551437ULL ) );
	EXPECT_TRUE( is_prime( 18446744073709551427ULL ) );
	EXPECT_TRUE( is_prime( 18446744073709551359ULL ) );
	EXPECT_TRUE( is_prime( 18446744073709551337ULL ) );
	EXPECT_TRUE( is_prime( 18446744073709551293ULL ) );
	EXPECT_TRUE( is_prime( 18446744073709551263ULL ) );
	EXPECT_TRUE( is_prime( 18446744073709551253ULL ) );

	EXPECT_FALSE( is_prime( 0ULL ) );
	EXPECT_FALSE( is_prime( 1ULL ) );
	EXPECT_FALSE( is_prime( 4ULL ) );
	EXPECT_FALSE( is_prime( 10ULL ) );
	EXPECT_FALSE( is_prime( 199ULL - 1ULL ) );
	EXPECT_FALSE( is_prime( 997ULL * 1009ULL ) );
	EXPECT_FALSE( is_prime( 65479ULL * 65497ULL ) );
	EXPECT_FALSE( is_prime( 18446744073709551557ULL + 2 ) );
	EXPECT_FALSE( is_prime( 18446744073709551533ULL + 2 ) );
	EXPECT_FALSE( is_prime( 18446744073709551521ULL + 2 ) );
	EXPECT_FALSE( is_prime( 18446744073709551437ULL + 2 ) );
	EXPECT_FALSE( is_prime( 18446744073709551427ULL + 2 ) );
	EXPECT_FALSE( is_prime( 18446744073709551359ULL + 2 ) );
	EXPECT_FALSE( is_prime( 18446744073709551337ULL + 2 ) );
	EXPECT_FALSE( is_prime( 18446744073709551293ULL + 2 ) );
	EXPECT_FALSE( is_prime( 18446744073709551263ULL + 2 ) );
	EXPECT_FALSE( is_prime( 18446744073709551253ULL + 2 ) );
	EXPECT_FALSE( is_prime( 65449ULL * 65497ULL ) );
	EXPECT_FALSE( is_prime( 65521ULL * 65521ULL ) );
	EXPECT_FALSE( is_prime( 65101ULL * 65111ULL ) );
	EXPECT_FALSE( is_prime( 4294967291ULL * 4294967291ULL ) );
	EXPECT_FALSE( is_prime( 4294967197ULL * 4294967197ULL ) );
	EXPECT_FALSE( is_prime( 4294967291ULL * 4294967279ULL ) );
	EXPECT_FALSE( is_prime( 4294966813ULL * 4294966769ULL ) );
}

TEST( TestCaseName, isqrt ) {
	EXPECT_EQ( 0xFFFFFFFF, isqrt( 0xFFFFFFFFFFFFFFFF ) );
	EXPECT_EQ( 0, isqrt( 0 ) );
	EXPECT_EQ( 1, isqrt( 1 ) );
	EXPECT_EQ( 1, isqrt( 2 ) );
	EXPECT_EQ( 1, isqrt( 3 ) );
	EXPECT_EQ( 2, isqrt( 4 ) );

	for ( uint64_t i = 5; i < 1000; i++ ) {
		EXPECT_EQ( i, isqrt( i * i ) );
		EXPECT_EQ( i, isqrt( i * i + 1 ) );
		EXPECT_EQ( i, isqrt( i * i + 1 ) );
	}
	for ( uint64_t i = 9000; i < 10000; i++ ) {
		EXPECT_EQ( i, isqrt( i * i ) );
		EXPECT_EQ( i, isqrt( i * i + 1 ) );
		EXPECT_EQ( i, isqrt( i * i + 1 ) );
	}

	for ( uint64_t i = 49000; i < 50000; i++ ) {
		EXPECT_EQ( i, isqrt( i * i ) );
		EXPECT_EQ( i, isqrt( i * i + 1 ) );
		EXPECT_EQ( i, isqrt( i * i + 2 ) );
		EXPECT_EQ( i, isqrt( i * i + 3 ) );
	}

	for ( uint64_t i = 0xFFFF; i < 0x10100; i++ ) {
		EXPECT_EQ( i, isqrt( i * i ) );
		EXPECT_EQ( i, isqrt( i * i + 1 ) );
		EXPECT_EQ( i, isqrt( i * i + 2 ) );
		EXPECT_EQ( i, isqrt( i * i + 3 ) );
	}

	for ( uint64_t i = 0xFFFFFFFF - 100; i < 0xFFFFFFFF; i++ ) {
		EXPECT_EQ( i, isqrt( i * i ) );
		EXPECT_EQ( i - 1, isqrt( i * i - 1 ) );
		EXPECT_EQ( i - 1, isqrt( i * i - 2 ) );
		EXPECT_EQ( i - 1, isqrt( i * i - 3 ) );
	}

	for ( uint64_t i = 0xFFFFFF - 100; i < 0xFFFFFF; i++ ) {
		EXPECT_EQ( i, isqrt( i * i ) );
	}
	for ( uint64_t i = 0xF'FFFF'FFFF'FFFF - 1000; i < 0xF'FFFF'FFFF'FFFF; i++ ) {
		EXPECT_EQ( (uint64_t)sqrt( (double)i ), isqrt( i ) );
	}
	for ( uint64_t i = 0xffffff8000001 - 500; i < 0xffffff8000001 + 500; i++ ) {
		EXPECT_EQ( (uint64_t)sqrt( (double)i ), isqrt( i ) );
	}

	std::map<uint64_t, uint64_t> square_and_root = {
	    { 0xFFFFFFFE00000001, 0xFFFFFFFF }, { 0xFFFFFFFE00000002, 0xFFFFFFFF }, { 0xFFFFFFFE00000003, 0xFFFFFFFF },
	    { 0xFFFFFFFE00000010, 0xFFFFFFFF }, { 0xFFFFFFFC00000004, 0xFFFFFFFE }, { 0xFFFFFFFC00000014, 0xFFFFFFFE },
	    { 0xFFFFFFFC00000024, 0xFFFFFFFE }, { 0xFFFFFFFA00000009, 0xFFFFFFFD }, { 0xFFFFFFFA00000029, 0xFFFFFFFD },
	    { 0xFFFFFFFA00000109, 0xFFFFFFFD }, { 0xFFFFFFFA00001009, 0xFFFFFFFD }, { 0xFFFFFFF800000010, 0xFFFFFFFC },
	    { 0xFFFFFFF800010010, 0xFFFFFFFC }, { 0xFFFFFFF810010010, 0xFFFFFFFC }, { 0xFFFFFFFA00000008, 0xFFFFFFFC },
	    { 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFF }, { 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFF }, { 0xFFFFFFFFFFFFFFFD, 0xFFFFFFFF },
	};

	for ( auto &&i : square_and_root ) {
		EXPECT_EQ( i.second, isqrt( i.first ) );
	}
}

TEST( TestCaseName, is_square ) {
	EXPECT_TRUE( is_square( 0ULL ) );
	EXPECT_TRUE( is_square( 1ULL ) );
	EXPECT_TRUE( is_square( 4ULL ) );
	EXPECT_TRUE( is_square( 9ULL ) );
	EXPECT_TRUE( is_square( 16ULL ) );
	EXPECT_TRUE( is_square( 25ULL ) );
	EXPECT_TRUE( is_square( 100ULL ) );
	EXPECT_TRUE( is_square( 0xFFFFULL * 0xFFFFULL ) );
	EXPECT_TRUE( is_square( 0x10000ULL * 0x10000ULL ) );
	EXPECT_TRUE( is_square( 0x10000000ULL * 0x10000000ULL ) );
	EXPECT_TRUE( is_square( 0x7FFFFFFFULL * 0x7FFFFFFFULL ) );
	EXPECT_TRUE( is_square( 0x80000000ULL * 0x80000000ULL ) );
	EXPECT_TRUE( is_square( 0xFFFFFFFEULL * 0xFFFFFFFEULL ) );
	EXPECT_TRUE( is_square( 0xFFFFFFFFULL * 0xFFFFFFFFULL ) );

	EXPECT_FALSE( is_square( 2ULL ) );
	EXPECT_FALSE( is_square( 5ULL ) );
	EXPECT_FALSE( is_square( 10ULL ) );
	EXPECT_FALSE( is_square( 136ULL ) );
	EXPECT_FALSE( is_square( 0xFFFFULL * 0xFFFFULL - 1ULL ) );
	EXPECT_FALSE( is_square( 0xFFFFULL * 0xFFFFULL + 1ULL ) );
	EXPECT_FALSE( is_square( 0x10000ULL * 0x10000ULL - 1ULL ) );
	EXPECT_FALSE( is_square( 0x10000ULL * 0x10000ULL + 1ULL ) );
	EXPECT_FALSE( is_square( 0x10000000ULL * 0x10000000ULL - 1ULL ) );
	EXPECT_FALSE( is_square( 0x10000000ULL * 0x10000000ULL + 1ULL ) );
	EXPECT_FALSE( is_square( 0x7FFFFFFFULL * 0x7FFFFFFFULL - 1ULL ) );
	EXPECT_FALSE( is_square( 0x7FFFFFFFULL * 0x7FFFFFFFULL + 1ULL ) );
	EXPECT_FALSE( is_square( 0x80000000ULL * 0x80000000ULL - 1ULL ) );
	EXPECT_FALSE( is_square( 0x80000000ULL * 0x80000000ULL + 1ULL ) );
	EXPECT_FALSE( is_square( 0xFFFFFFFEULL * 0xFFFFFFFEULL - 1ULL ) );
	EXPECT_FALSE( is_square( 0xFFFFFFFEULL * 0xFFFFFFFEULL + 1ULL ) );
	EXPECT_FALSE( is_square( 0xFFFFFFFFULL * 0xFFFFFFFFULL - 1ULL ) );
	EXPECT_FALSE( is_square( 0xFFFFFFFFULL * 0xFFFFFFFFULL + 1ULL ) );
	EXPECT_FALSE( is_square( 0x7FFFFFFFFFFFFFFFULL ) );
	EXPECT_FALSE( is_square( 0x8000000000000000ULL ) );
	EXPECT_FALSE( is_square( 0xFFFFFFFFFFFFFFFEULL ) );
	EXPECT_FALSE( is_square( 0xFFFFFFFFFFFFFFFFULL ) );

	for (uint64_t i = 0; i < 1000; i++)
	{
		uint64_t r = isqrt( i );
		if ( i == r * r ){
			EXPECT_TRUE( is_square( i ) );
		}else{
			EXPECT_FALSE( is_square( i ));
		}
	}
	
}
