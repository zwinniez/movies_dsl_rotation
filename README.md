# movies_dsl_rotation

This project takes in an input file named "movies.txt", with the parameters of 
a movie name, date of release, genres, and three ratings respectively. 

In return, it creates three file with the names of "movies_mean.txt", "movies_max.txt", "movies_min.txt", with
the movie title, release date, genre, and unique metric. 

The delimiter I used for each data attribute is a single white space " ", and multiple genres and multi-word titles
use underscores or no whitespaces. 

To compile the program, run this command in your terminal in the directory: 
g++ -Wall -o main main.cpp Movie.cpp MovieIO.cpp FileHandler.cpp
Then, run the executable:
main.exe

To run all the tests, run this command in your terminal in the directory:
g++ -o test test.cpp Movie.cpp MovieIO.cpp FileHandler.cpp 
Then, run the executable:
test.exe
