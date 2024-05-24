//
// Created by nilei on 24-5-24.
//
#include<string>
#include<iostream>

using namespace std;
#ifndef ONLINEBOOKSALE2_BOOK_H
#define ONLINEBOOKSALE2_BOOK_H

class book {
protected:
    string bookID;
    string bookName;
    string author;
    string publishing;
    double price;
public:
    book();

    book(string b_id, string b_n, string au, string pu, double pr);

//重载构造函数
    void display();

    string getbookId();

    string getbookName();

    string getauthor();

    string getpublishing();

    double getprice();
};

#endif //ONLINEBOOKSALE2_BOOK_H
