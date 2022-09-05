/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description: This is header file for BookDB which contains all the fuction declaration.
 Credits: None
 */

#ifndef BookDB_h
#define BookDB_h

#include <vector>
using namespace std;
using std::vector;

/**
 Creating a new type Book id, year, rating
 */
struct Book{
    unsigned id;
    unsigned year;
    double rating;
};

/**
 Search the database for an entry with the given bookID. If no such entry is found, add a book with the given bookID,
 year, and rating to the end of the vector and return 1. If there is already
 an entry with the given bookID, the list should not be changed and 0 should be returned.
 
 @param bookID  book to be added
 @param year year book is produced
 @param rating rating of the book
 @return 1 if book is added else 0
 */
int addBook(unsigned bookID, unsigned year, double rating, vector<Book> &db);

/**
 Search the database for an entry with the given bookID. If such an entry is found, update the rating and the year as per the input and return 1. If no such entry is found, return 0.
 
 @param bookID  book to be search
 @param year year to be updated in database
 @param rating rating to be updated in database
 @return 1 if bookID is found in database else 0
 */
int updateBook(unsigned bookID, unsigned year, double rating, vector<Book> &db);


/**
 Search the database for an entry with the given bookID. If such an entry is found, remove the entry from the database and return 1. If no such entry is found, the list should not be changed and 0 should be returned.
 
 @param bookID  id to be search in database
 @return 0 if entry is not found 1 if it's found
 */
int deleteBook(unsigned bookID, vector<Book> &db);


/**
 Returns a pointer to the vector of Books published in the year specified by the argument.
 
 @param year year of the book to search
 @return a vector of Books published in the year specified by the argument
 */
vector<Book>* findBooks(unsigned year, const vector<Book> &db);

/**
 Calculate the average rating of all the books in the database. If no books have been added, return -1.0.
 
 @return -1 if no books have been added
 */
double calculateAverageRating(const vector<Book> &db);

/**
 Prints the contents of the database to cout, starting from the beginning entry, print out each book on its own line.
 */
void print(const vector<Book> &db);

/**
 This functions take two arguments: the book database and the user-specified sorting behaviour choice.
 Sort the books in order of increasing ID number. Sort the books in order of increasing year. Break ties by putting smaller book IDs before larger ones. Sort the books in order of increasing rating. Break ties by putting smaller book IDs before larger ones.
 
 @return 0 if user enters something other than the three possible numbers for the sort options, else 1
 */
int sortDB(vector<Book> &db, short sortingMethod);

#endif /* BookDB_hpp */
