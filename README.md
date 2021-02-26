# movies_dsl_rotation

This project works to sort movies based on their ratings. 
Each movie is given three ratings, and they are sorted by their average rating, their 
all time lowest rating, and their all time highest rating. 


An input file named "movies.txt" is taken in with the parameters of 
a movie name, date of release, genres, and three ratings respectively. 
The delimiter used for each data attribute is a single white space " ", 
and multiple genres and multi-word titles use underscores and may not contain whitespaces. 
All of the data is loaded in and instances of Movie objects are created to hold all attributes.
Then, three calculations are made to sort the movies in order based on their 
average rating, their max rating, and their min rating in ascending order. 
In return, the sorted order of the movies are saved into three separate text files called
"movies_mean.txt", "movies_max.txt", "movies_min.txt" for average, max, and min respectively. 


To compile the program, run this command in your terminal in the directory: 

$ g++ -Wall -o main main.cpp Movie.cpp MovieIO.cpp FileHandler.cpp

Then, run the executable:

$ main.exe


To run all the tests, run this command in your terminal in the directory:

$ g++ -o test test.cpp Movie.cpp MovieIO.cpp FileHandler.cpp

Then, run the executable:

$ test.exe


