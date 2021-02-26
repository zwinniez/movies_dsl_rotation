#include "common.h"
#include "MovieIO.h"

/*
* 
Main function 

Works with the "movies.txt" file
Instantiates MovieIO and returns three files
with movies sorted in ascending order
based on their mean rating, max rating, and min rating

*/

int main() {
	MovieIO mio("movies.txt", " ", true, { 6, 6, 0 });
	mio.getMetrics();
}