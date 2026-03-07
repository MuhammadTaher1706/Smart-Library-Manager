//
// Created by Muhammad Taher on 07/03/2026.
//
#pragma once
#include <string>
using std::string;


class Book {
    int id;
    string title;
    string author;
    string category;
    int year;
    int totalCopies;
    int availbleCopies;


public:
    Book(int id,const string& title,const string& author,const string& category,int year,int totalCopies=0,int availbleCopies=0);

    int getId()const;
    const string& getTitle()const;
    const string& getAuthor()const;
    const string& getCategory()const;
    int getYear()const;
    int getTotalCopies()const;
    int getAvailbleCopies()const;

    bool isAvailble()const;

    void borrowCopy();
    void returnCopy();

    void addCopy();

};

std::ostream& operator<<(std::ostream& os,const Book& b1);