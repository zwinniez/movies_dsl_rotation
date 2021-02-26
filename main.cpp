#include "common.h"
#include "MovieIO.h"


int main() {
	MovieIO mio("movies.txt", " ", true, { 6, 6, 0 });
	mio.getMetrics();
}