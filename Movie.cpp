#include "Movie.h"

//Movie's output operator
//All attributes returned
std::ostream& operator<< (std::ostream& os, Movie rhs) {
	os << rhs.name << " " << rhs.year << " " << rhs.genre 
		<< "\nThis is the mean: " << rhs.mean
		<< "\nThis is the max: " << rhs.max
		<< "\nThis is the min: " << rhs.min
		<< std::endl;
	return os;
}


Movie::Movie(const std::string& name, int year, const std::string& genre,
	double r1, double r2, double r3) : name(name), year(year), genre(genre) {
	//calls three methods to calculate avg, max, min
	calcAvg(r1, r2, r3);
	calcMax(r1, r2, r3);
	calcMin(r1, r2, r3);
}

void Movie::calcAvg(double r1, double r2, double r3) {
	mean = (r1 + r2 + r3) / 3;  
}

void Movie::calcMax(double r1, double r2, double r3) {
	max = r1;
	if (r2 > max) { max = r2; }
	if (r3 > max) { max = r3; }
}

void Movie::calcMin(double r1, double r2, double r3) {
	min = r1;
	if (r2 < min) { min = r2; }
	if (r3 < min) { min = r3; }
}

//getter methods 
double Movie::getMean() const { return mean; }
double Movie::getMax() const { return max; }
double Movie::getMin() const { return min; }
const std::string& Movie::getName() const { return name; }
int Movie::getYear() const { return year; }
const std::string& Movie::getGenre() const { return genre; }