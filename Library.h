//
// Created by Muhammad Taher on 08/03/2026.
//
#pragma once
#include "User.h"
class Library {
    std::map<int,std::unique_ptr<Book>> L_Books;
    std::map<int,std::unique_ptr<User>> L_Users;
public:
    Library();

    void addBook(std::unique_ptr<Book> b1);
    void removeBook(std::unique_ptr<Book> b1);

    auto findBook(int id);
    auto findUser(int id);

    void borrowBook(int b_id,int u_id);
    void returnBook(std::unique_ptr<Book>,int u_id);

    auto getAllBooks()const;
    auto getAllUsers()const;

    string printAllBooks()const;
    string printAllUsers()const;
};
