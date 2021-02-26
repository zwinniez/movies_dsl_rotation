#ifndef MOVIE_H
#define MOVIE_H

#include "common.h"
#include <iostream>

class Movie {
	friend std::ostream& operator<< (std::ostream& os, Movie rhs);

public:
	Movie(const std::string& name, int year, const std::string& genre,
		double r1, double r2, double r3);

	~Movie() = default; 

	void calcAvg(double r1, double r2, double r3);
	void calcMax(double r1, double r2, double r3);
	void calcMin(double r1, double r2, double r3);
	double getMean() const; 
	double getMax() const;
	double getMin() const;
	const std::string& getName() const;
	int getYear() const;
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