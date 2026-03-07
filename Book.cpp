//
// Created by Muhammad Taher on 07/03/2026.
//
#include "Book.h"
#include <ostream>

class NoAvailbleBook:public std::exception {
    const char* what() const noexcept override {
        return "No Availble Book......!";
    }
};



Book::Book(int id, const string &title, const string &author, const string &category, int year, int totalCopies, int availbleCopies):id(id),title(title),author(author),year(year),category(category),totalCopies(totalCopies),availbleCopies(availbleCopies) {}


const string &Book::getAuthor() const {
    return author;
}
const string &Book::getCategory() const {
    return category;
}
const string &Book::getTitle() const {
    return title;
}
int Book::getId() const {
    return id;
}
int Book::getYear() const {
    return year;
}
int Book::getAvailbleCopies() const {
    return availbleCopies;
}
int Book::getTotalCopies() const {
    return totalCopies;
}

bool Book::isAvailble() const{
    return (availbleCopies>0);
}


void Book::borrowCopy() {
    if(!isAvailble())
        throw NoAvailbleBook();
    availbleCopies--;
}

void Book::returnCopy() {
    availbleCopies++;
}


void Book::addCopy() {
    totalCopies++;
    availbleCopies++;
}


std::ostream& operator<<(std::ostream& os,const Book& b1) {
    os<<"id: "<<b1.getId()<<std::endl;
    os<<"title: "<<b1.getTitle()<<std::endl;
    os<<"author: "<<b1.getAuthor()<<std::endl;
    os<<"category: "<<b1.getCategory()<<std::endl;
    os<<"year: "<<b1.getYear()<<std::endl;
    os<<"total copies: "<<b1.getTotalCopies()<<std::endl;
    os<<"available copies: "<<b1.isAvailble()<<std::endl;

    return os;
}


