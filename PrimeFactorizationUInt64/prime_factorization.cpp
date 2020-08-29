#include "prime_factorization.h"

#include "uint64_operation.h"

std::vector<std::pair<uint64_t, uint32_t> > PrimeFactorize( uint64_t target ) {
	// target <= 5
	if ( target <= 5 ) {
		if ( target == 4 ) {
			return std::vector<std::pair<uint64_t, uint32_t> >{ { 2, 2 } };
		}
		return std::vector<std::pair<uint64_t, uint32_t> >{ { target, 1 } };
	}

	std::vector<std::pair<uint64_t, uint32_t> > answer;
	answer.reserve( 16 );  // ( 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23 * 29 * 31 * 37 * 41 * 43 * 47 * 53 ) > 2**64

	// prime number
	if ( is_prime( target ) ) {
		return std::vector<std::pair<uint64_t, uint32_t> >{ { target, 1 } };
	}
	// trailing zero count
	//	xxxxx100000 => xxxxx1 * (2^5)
	auto trailing_zero_count = _tzcnt_u64( target );
	answer.emplace_back( 2, trailing_zero_count );

	return answer;
}
