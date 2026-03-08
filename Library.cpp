//
// Created by Muhammad Taher on 08/03/2026.
//
#include "Library.h"

#include <ostream>

class BookNotFound:public std::exception {
    const char* what() const noexcept override {
        return "The Book Not Found....!";
    }
};

class UserNotFound:public std::exception {
    const char* what() const noexcept override {
        return "The User Not Found....!";
    }
};

class UserDontBorrow:public std::exception {
    const char* what() const noexcept override {
        return "The User Not Borrow This Book....!";
    }
};
Library::Library() =default;

auto Library::findBook(int id) {
    if(!L_Books.find(id))
        throw BookNotFound();
    std::unique_ptr<Book> res=std::move(L_Books[id]);
    L_Books.erase(id);
    return res;
}
auto Library::findUser(int id) {
    if(!L_Users.find(id))
        throw BookNotFound();
    return L_Users[id];
}

void Library::borrowBook(int b_id, int u_id) {
    std::unique_ptr<Book> b1=std::move(findBook(b_id));
    std::shared_ptr<User> u1=findUser(u_id);
    u1->BorrowBook(std::move(b1));
}

void Library::returnBook(int b_id, int u_id) {
    std::shared_ptr<User> u1=findUser(u_id);
    if(!u1->hasBorrowed(b_id))
        throw UserDontBorrow();
    std::unique_ptr<Book> b1=std::move(u1->returnBook(b_id));
    L_Books[b_id]=std::move(b1);
}

void Library::addBook(std::unique_ptr<Book> b1) {
    L_Books[b1->getId()]=std::move(b1);
}

void Library::addUser(std::shared_ptr<User> u1) {
    L_Users[u1->getId()]=u1;
}

auto Library::getAllBooks() const {
    return L_Books;
}
auto Library::getAllUsers() const {
    return L_Users;
}

void Library::removeBook(std::unique_ptr<Book> b1) {
    L_Books.erase(b1->getId());
}


std::ostream& operator<<(std::ostream& os,const Library& l1) {
    os<<"Books : "<<std::endl;
    for (const auto& it:l1.getAllBooks())
        os<<it;
    os<<"Users : "<<std::endl;
    for (const auto& it:l1.getAllUsers())
        os<<it;
    return os;
}