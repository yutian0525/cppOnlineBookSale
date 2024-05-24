//
// Created by nilei on 24-5-24.
//
#include "book.h"

book::book(string b_id, string b_n, string au, string pu, double pr) {
//书号
    bookID = b_id;
//书名
    bookName = b_n;
//作者
    author = au;
    //出版社
    publishing = pu;
//定价
    price = pr;
}

book::book() {
    bookID = "";
    bookName = "";
    author = "";
    publishing = "";
    price = 0;
}

void book::display() {
    cout << "书号:" << bookID << "\t";
    cout << "书名:" << bookName << "\t";
    cout << "作者:" << author << "\n";
    cout << "出版社:" << publishing << "\t";
    cout << "定价:" << price << "\n";
}

string book::getbookId()//取书号
{ return bookID; }

//取书名
string book::getbookName() { return bookName; }

string book::getauthor() { return author; }

string book::getpublishing() { return publishing; }

double book::getprice() { return price; }