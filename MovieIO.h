#ifndef MOVIEIO_H
#define MOVIEIO_H
#include "abm_io.h"
#include "Movie.h"


class MovieIO : public AbmIO
{
public:
	MovieIO(const std::string name, const std::string delim, const bool sflag,
		const std::vector<size_t> dims);

	~MovieIO(); 

	std::vector<Movie*> getMovies();
	void write_vector(const std::string& fileWrite, const std::string& metric) const;
	std::vector<Movie*> loadMovies(std::vector<std::vector<std::string>> data) const;
	void getMetrics();
	struct lessMean;
	struct lessMax;
	struct lessMin;
	void sortByMetric(const std::string& metric);
	std::vector<Movie*> getMoviesForTesting() const; 

private:
	std::vector<Movie*> movies;
};


#endif