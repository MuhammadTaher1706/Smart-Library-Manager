//
// Created by Muhammad Taher on 07/03/2026.
//
#pragma once
#include <map>
#include "Book.h"


class User {
    int id;
    string name;
    string email;
    std::map<int,std::unique_ptr<Book>> borrowedBooks;
    int maxBooks;

public:
    User(int id,string name,string email,int maxBooks);

    int getId()const;
    const string& getName()const;
    const string& getEmail()const;
    const auto getBorrowedBooks()const;
    int getMaxSize()const;

    size_t getNumBooks()const;

    void BorrowBook(std::unique_ptr<Book> b1);
    std::unique_ptr<Book> returnBook(int id);

    bool hasBorrowed(int id);

    string printBooks()const;

    virtual ~User();
    string print()const;
    virtual string getType()const=0;
};


class Student:public User {
public:
    Student(int id,string name,string email);
    string getType() const override;
};

class FacultyMem:public User {
public:
    FacultyMem(int id,string name,string email);
    string getType() const override;
};

class Librarian:public User {
public:
    Librarian(int id,string name,string email);
    string getType() const override;
};

std::ostream& operator<<(std::ostream& os,const User& u1);