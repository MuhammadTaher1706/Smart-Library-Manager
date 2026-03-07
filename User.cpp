//
// Created by Muhammad Taher on 07/03/2026.
//
#include "User.h"
#include <ostream>

class UserNotBorrowed:public std::exception {
    const char* what() const noexcept override {
        return "The User Not Borrowed this Book....!";
    }
};

class UserCantBorrow:public std::exception {
    const char* what() const noexcept override {
        return "The User Can't Borrow (Max Number Of Books)....!";
    }
};

class UserAlreadyBorrow:public std::exception {
    const char* what() const noexcept override {
        return "The User Already Borrow This Book....!";
    }
};


//User
User::User(int id, string name, string email, int maxBooks):id(id),name(name),email(email),maxBooks(maxBooks) {}

const string &User::getEmail() const {
    return email;
}
int User::getId() const {
    return id;
}
const string &User::getName() const {
    return name;
}
const auto User::getBorrowedBooks() const {
    return borrowedBooks;
}
int User::getMaxSize() const {
    return maxBooks;
}
size_t User::getNumBooks() const {
    return borrowedBooks.size();
}


bool User::hasBorrowed(int id) {
    return (borrowedBooks.find(id)!=borrowedBooks.end());
}


std::unique_ptr<Book> User::returnBook(int id) {
    auto it=borrowedBooks.find(id);
    if(it==borrowedBooks.end())
        throw UserNotBorrowed();
    std::unique_ptr<Book> res=std::move(it->second());
    borrowedBooks.erase(id);
    return res;
}


string User::printBooks() const{
    string res="(";
    for (const auto& b1:borrowedBooks)
        res+=b1.second()->getTitle()+",";
    res+=")";
    return res;
}


User::~User() =default;

void User::BorrowBook(std::unique_ptr<Book> b1) {
    if(getNumBooks()==maxBooks)
        throw UserCantBorrow();
    if(borrowedBooks.find(b1->id)!=borrowedBooks.end())
        throw UserAlreadyBorrow();
    borrowedBooks[b1->id]=std::move(b1);
}

string User::print() const {
    return "(Type : "+getType()+"Id : "+std::to_string(getId())+"Name : "+getName()+"Email : "+getEmail()+"Number Of Books : "+std::to_string(getNumBooks());
}


//Student
Student::Student(int id, string name, string email):User(id,name,email,3){}

string Student::getType() const {
    return "Student";
}

//FacultyMem

FacultyMem::FacultyMem(int id, string name, string email):User(id,name,email,10){}

string FacultyMem::getType() const {
    return "Faculty Member";
}

//Librarian

Librarian::Librarian(int id, string name, string email):User(id,name,email,100){}

string Librarian::getType() const {
    return "Librarian";
}


std::ostream& operator<<(std::ostream& os,const User& u1) {
    os<<u1.print()<<std::endl;
    os<<u1.printBooks()<<std::endl;
}

