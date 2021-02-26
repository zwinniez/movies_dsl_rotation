#include "MovieIO.h"

MovieIO::MovieIO(const std::string name, const std::string delim, const bool sflag,
	const std::vector<size_t> dims) : AbmIO(name, delim, sflag, dims),
	movies(getMovies()) {}


MovieIO::~MovieIO() {
	//iterates through vector of movie pointers to delete objects off heap
	for (Movie* m : movies) { delete m; }
}

std::vector<Movie*> MovieIO::getMoviesForTesting() const { return movies; }

std::vector<Movie*> MovieIO::getMovies() {

	//calls read_vector template function from AbmIO interface, uses std::string as the T object 
	std::vector<std::vector<std::string>> fileData = AbmIO::read_vector<std::string>();

	//loads the movies and its attributes and stores movie objects in movies vector
	std::vector<Movie*> movies = loadMovies(fileData);
	return movies;
}

void MovieIO::write_vector(const std::string& fileWrite, const std::string& metric) const {
	FileHandler file(fileWrite, std::ios_base::out | std::ios_base::trunc);
	std::fstream& fout = file.get_stream();
	//checks for specific stat wanted and fout the desired data
	for (Movie* movie : movies) {
		fout << movie->getName() << " " << movie->getYear()
			<< " " << movie->getGenre() << " ";
		if (metric == "mean") {
			fout << movie->getMean()<< std::endl;
		}
		else if (metric == "max") {
			fout << movie->getMax() << std::endl;
		}
		else if (metric == "min") {
			fout << movie->getMin() << std::endl;
		}
	}
}

std::vector<Movie*> MovieIO::loadMovies(std::vector<std::vector<std::string>> data) const {
	std::vector<Movie*> movies;
	std::string name, genre;
	int year;
	double rating1, rating2, rating3;
	//index out all six attributes to create Movie objects on the heap and store in movies
	for (const std::vector<std::string>& line : data) {
		name = line[0];
		year = std::stoi(line[1]);
		genre = line[2];
		rating1 = std::stod(line[3]);
		rating2 = std::stod(line[4]);
		rating3 = std::stod(line[5]);
		Movie* newMovie = new Movie(name, year, genre, rating1, rating2, rating3);
		movies.push_back(newMovie);
	}
	return movies;
}

void MovieIO::getMetrics() {
	//sorts movies and creates three files to present 
	//mean, max, and min in ascending order
	MovieIO::sortByMetric("mean");
	MovieIO::write_vector("movies_mean.txt", "mean");
	MovieIO::sortByMetric("max");
	MovieIO::write_vector("movies_max.txt", "max");
	MovieIO::sortByMetric("min");
	MovieIO::write_vector("movies_min.txt", "min");
}

struct MovieIO::lessMean {
	//returns true if lhs Movie has a lower mean than rhs Movie
	inline bool operator() (Movie* mov1, Movie* mov2) {
		return (mov1->getMean() < mov2->getMean());
	}
};

struct MovieIO::lessMax {
	//returns true if lhs Movie has a lower max than rhs Movie
	inline bool operator() (Movie* mov1, Movie* mov2) {
		return(mov1->getMax() < mov2->getMax());
	}
};

struct MovieIO::lessMin {
	//returns true if lhs Movie has a lower min than rhs Movie
	inline bool operator() (Movie* mov1, Movie* mov2) {
		return(mov1->getMin() < mov2->getMin());
	}
};

void MovieIO::sortByMetric(const std::string& metric) {
	//sort the movies based on given metric
	if (metric == "mean") {
		std::sort(movies.begin(), movies.end(), lessMean());
	}
	else if (metric == "max") {
		std::sort(movies.begin(), movies.end(), lessMax());
	}
	else if (metric == "min") {
		std::sort(movies.begin(), movies.end(), lessMin());
	}
}



