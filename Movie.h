#ifndef MOVIE_H
#define MOVIE_H

#include "common.h"
#include <iostream>

/*
 class Movie

Has title, release year, genre
Avg, max, and min of three initial ratings

*/

class Movie {
	//output operator for Movie object
	friend std::ostream& operator<< (std::ostream& os, Movie rhs);

public:
	//Movie constructor
	//takes in movie title, release date, genre, and three ratings
	//calculates three statistics mean, max, and min and stores them
	Movie(const std::string& name, int year, const std::string& genre,
		double r1, double r2, double r3);

	//Movie destructor
	~Movie() = default; 

	//calcAvg() 
	//stores the avg of three ratings in mean
	void calcAvg(double r1, double r2, double r3);

	//calcMax()
	//stores the max of three  ratings in max
	void calcMax(double r1, double r2, double r3);

	//calcMin()
	//sotres the min of three ratings in min
	void calcMin(double r1, double r2, double r3);

	//getMean() returns mean
	double getMean() const; 

	//getMax() returns max
	double getMax() const;

	//getMin() returns min
	double getMin() const;

	//getName() returns movie title
	const std::string& getName() const;

	//getYear() returns year 
	int getYear() const;

	//getGenre() returns genre
	const std::string& getGenre() const;

private:

	std::string name;
	int year;
	std::string genre;
	double mean;
	double max;
	double min;
};


#endif