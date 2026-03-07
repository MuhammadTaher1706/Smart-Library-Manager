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

    int getNumBooks()const;

    void BorrowBook(std::unique_ptr<Book> b1);
    void returnBook(std::unique_ptr<Book> b1);

    bool hasBorrowed(int id);

    virtual ~User();
    virtual void print()const=0;
    virtual string getType()const=0;
};
