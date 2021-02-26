#ifndef TEST_H
#define TEST_H

#include "Movie.h"
#include "MovieIO.h"

/*
Testing for MovieIO and Movie class
all test functions return true for passing and false for failing
*/

//runs all tests listed below
//std::cout messages based on results
//returns true if all tests passed 
bool run_all_tests();

//movie_mean_test() function
//checks for the accuracy of Movie's mean method()
bool movie_mean_test();

//movie_max_test() function
//checks for the accuracy of Movie's max method()
bool movie_max_test();

//movie_min_test() function
//checks for the accuracy of Movie's min method()
bool movie_min_test();

//movieIO_sorting_by_mean_test()
//checks for the accuracy of sorting movies by their means
bool movieIO_sorting_by_mean_test();

//movieIO_sorting_by_max_test()
//checks for the accuracy of soring movies by their max ratings
bool movieIO_sorting_by_max_test();

//movieIO_sorting_by_min_test() 
//checks for the accuracy of sorting movies by their min ratings
bool movieIO_sorting_by_min_test();


#endif