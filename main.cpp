#include "common.h"
#include "MovieIO.h"
#include "test.h"


int main() {
	MovieIO mio("movies.txt", " ", true, { 6, 6, 0 });
	mio.getMetrics();
	//std::cout << std::boolalpha << run_all_tests();
}


