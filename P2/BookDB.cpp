/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description: This program contains all of the functions to maniupulate database of books
 Credits: None
 */

#include "BookDB.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using std::vector;

int addBook(unsigned bookID, unsigned year, double rating, vector<Book> &db){
    
    for(int index = 0; index < db.size(); ++index){
        if(bookID == db[index].id){
            return 0;
        }
    }
    
    Book info;
    info.id = bookID;
    info.year = year;
    info.rating = rating;
    db.push_back(info);
    return 1;
}

int updateBook(unsigned bookID, unsigned year, double rating, vector<Book> &db){
    
    for(int index = 0; index < db.size(); ++index){
        if(bookID == db[index].id){
            db[index].year = year;
            db[index].rating = rating;
            return 1;
        }
    }

    return 0;
}

int deleteBook(unsigned bookID, vector<Book> &db){
    
    bool findBook = false;
    int indexBook = 0;
    
    for(int index = 0; index < db.size(); ++index){
        if(bookID == db[index].id){
            findBook = true;
            indexBook = index;
        }
    }
    
    if(findBook == false){
        return 0;
    }else{
        db.erase(db.begin()+indexBook);
        return 1;
    }
}

vector<Book>* findBooks(unsigned year, const vector<Book> &db){
    
    vector<Book>* foundList = new vector<Book>;
    
    for(int index = 0; index < db.size(); ++index){
        if(db[index].year == year){
            foundList->push_back(db[index]);
        }
    }
    
    return foundList;
}

double calculateAverageRating(const vector<Book> &db){
    
    if(db.size() == 0){
        return -1.0;
    }
    
    double sumRate = 0.0;
    for(int i = 0; i < db.size();i++){
        sumRate += db[i].rating;
    }
    
    return (sumRate / db.size());
}

void print(const vector<Book> &db){
    
    if(db.size() == 0){
        cout << "No entries\n";
    }else{
        for(int i = 0; i < db.size();i++){
            cout << db[i].id << ", " << db[i].year << ", " << db[i].rating << endl;
        }
    }
    
}

bool bookIDSort(Book b1, Book b2){
    return (b1.id < b2.id);
}

bool bookYearSort(Book b1, Book b2){
    
    if(b1.year == b2.year){
        return bookIDSort(b1,b2);
    }
    
    return (b1.year < b2.year);
}

bool bookRatingSort(Book b1, Book b2){
    if(b1.rating == b2.rating){
        return bookIDSort(b1,b2);
    }
    
    return (b1.rating < b2.rating);
}

int sortDB(vector<Book> &db, short sortingMethod){
    if(sortingMethod == 1){
        sort(db.begin(),db.end(), bookIDSort);
        return 1;
    }else if(sortingMethod == 2){
        sort(db.begin(),db.end(), bookYearSort);
        return 1;
    }else if(sortingMethod == 3){
        sort(db.begin(),db.end(), bookRatingSort);
        return 1;
    }else{
        return 0;
    }
}
