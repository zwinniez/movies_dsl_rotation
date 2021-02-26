#ifndef MOVIEIO_H
#define MOVIEIO_H
#include "abm_io.h"
#include "Movie.h"
#include "common.h"

/*
 class MovieIO 
 
 Derived from AbmIO interface 
 Manages IO
 Holds and manages vector of Movie objects

*/

class MovieIO : public AbmIO
{
public:

	//MovieIO constructor 
	//takes in movie title, delimiter, sflag, and dimensions of 
	//data set. Calls AbmIO constructor
	MovieIO(const std::string name, const std::string delim, const bool sflag,
		const std::vector<size_t> dims);

	//MovieIO destructor 
	//deletes the Movie objects allocated on the heap
	~MovieIO(); 

	//getMovies() method is called in the constructor
	//reads in file and data member movies to a vector of 
	//Movie pointers of Movie objects on the heap
	std::vector<Movie*> getMovies();


	//loadMovies() creates Movie objects on the heap and push_back() them to 
	//the data member movies.
	std::vector<Movie*> loadMovies(std::vector<std::vector<std::string>> data) const;

	//getMetrics() does the collective function of sorting the movie objects based
	//on metrics (mean, min, and max) using sortByMetric()
	//and write_vector() to create three separate files for each metric
	void getMetrics();

	//sorts the movies by given metric argument
	void sortByMetric(const std::string& metric);

	//write_vector() is overriden to take in filename as an extra parameter 
	//we can use write_vector() method for multiple file creations
	//creates new files with all the movies sorted by specific metrics in ascending order
	void write_vector(const std::string& fileWrite, const std::string& metric) const;

	//a predicate to sort the Movie objects by their mean ratings in ascending order
	struct lessMean;

	//a predicate to sort the Movie objects by their max ratings in ascending order
	struct lessMax;

	//a predicate to sort the Movie objects by their min ratings in ascending order
	struct lessMin;

	//returns the movies vector for testing
	std::vector<Movie*> getMoviesForTesting() const; 

private:
	std::vector<Movie*> movies;
};


#endif