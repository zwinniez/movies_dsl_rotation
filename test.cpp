#include "test.h"

bool movie_mean_test() {

	Movie movie("Title", 1987, "Genre", 1, 3, 5);
	Movie movie2("Title2", 2020, "Genre2", 3, 4.5, 5);
	Movie movie3("Title3", 2019, "Genre,genre,genre", 1, 1, 1);

	bool result1 = movie.getMean() == 3.0; 
	bool result2 = movie2.getMean() == ((3 + 4.5 + 5) / 3);
	bool result3 = movie3.getMean() == 1; 

	return result1 && result2 && result3;
}

bool movie_max_test() {

	Movie movie("Title", 1987, "Genre", 1, 3, 5);
	Movie movie2("Title2", 2020, "Genre2", 3, 4.5, 5);
	Movie movie3("Title3", 2019, "Genre,genre,genre", 1, 1, 1);

	bool result1 = movie.getMax() == 5;
	bool result2 = movie2.getMax() == 5;
	bool result3 = movie3.getMax() == 1;

	return result1 && result2 && result3;
}

bool movie_min_test() {

	Movie movie("Title", 1987, "Genre", 1, 3, 5);
	Movie movie2("Title2", 2020, "Genre2", 3, 4.5, 5);
	Movie movie3("Title3", 2019, "Genre,genre,genre", 1, 1, 1);

	bool result1 = movie.getMin() == 1;
	bool result2 = movie2.getMin() == 3;
	bool result3 = movie3.getMin() == 1;

	return result1 && result2 && result3;
}

bool movieIO_sorting_by_mean_test() {

	std::vector<double> answers{ 3.5, (12.4 / 3), (12.8 / 3), (13.4 / 3), (13.6 / 3), (13.9 / 3) };

	MovieIO mio("movies.txt", " ", true, { 6, 6, 0 });
	mio.sortByMetric("mean");
	std::vector<Movie*> movies = mio.getMoviesForTesting();
	for (size_t i = 0; i < movies.size(); i++) {
		if (answers[i] != movies[i]->getMean()) { 
			return false; }
	}
	return true;
}

bool movieIO_sorting_by_max_test() {

	std::vector<double> answers{ 3.8, 4.5, 4.6, 4.7, 5, 5 };

	MovieIO mio("movies.txt", " ", true, { 6, 6, 0 });
	mio.sortByMetric("max");
	std::vector<Movie*> movies = mio.getMoviesForTesting();
	for (size_t i = 0; i < movies.size(); i++) {
		if (answers[i] != movies[i]->getMax()) {
			return false;
		}
	}
	return true;
}

bool movieIO_sorting_by_min_test() {

	std::vector<double> answers{ 3, 3.6, 3.9, 4.1, 4.2, 4.5 };

	MovieIO mio("movies.txt", " ", true, { 6, 6, 0 });
	mio.sortByMetric("min");
	std::vector<Movie*> movies = mio.getMoviesForTesting();
	for (size_t i = 0; i < movies.size(); i++) {
		if (answers[i] != movies[i]->getMin()) {
			return false;
		}
	}
	return true;
}


bool run_all_tests() {
	bool passing = true;
	if (!movie_mean_test()) { 
		std::cout << "Movie mean method failed\n";
		passing = false;
	}
	else {
		std::cout << "Passed movie_mean_test()\n";
	}
	if (!movie_max_test()) { 
		std::cout << "Movie max method failed\n";
		passing = false; }
	else {
		std::cout << "Passed movie_max_test()\n";
	}
	if (!movie_min_test()) { 
		std::cout << "Movie min method failed\n";
		passing = false; }
	else {
		std::cout << "Passed movie_min_test()\n";
	}
	if (!movieIO_sorting_by_mean_test()) {
		std::cout << "Sorting movies by mean failed\n";
		passing = false;
	}
	else {
		std::cout << "Passed sorting_by_mean_tests()\n";
	}
	if (!movieIO_sorting_by_max_test()) {
		std::cout << "Sorting movies by max failed\n";
		passing = false;
	}
	else {
		std::cout << "Passed sorting_by_max_tests()\n";
	}
	if (!movieIO_sorting_by_min_test()) {
		std::cout << "Soring movies by min failed\n";
		passing = false;
	}
	else {
		std::cout << "Passed sorting_by_min_tests()\n";
	}
	return passing;
}

int main() {
	bool passed = run_all_tests();
	std::cout << "Passed all tests: " << std::boolalpha << passed;
}