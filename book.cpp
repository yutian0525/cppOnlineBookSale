//
// Created by nilei on 24-5-24.
//
#include "book.h"

book::book(string b_id, string b_n, string au, string pu, double pr) {
//���
    bookID = b_id;
//����
    bookName = b_n;
//����
    author = au;
    //������
    publishing = pu;
//����
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
    cout << "���:" << bookID << "\t";
    cout << "����:" << bookName << "\t";
    cout << "����:" << author << "\n";
    cout << "������:" << publishing << "\t";
    cout << "����:" << price << "\n";
}

string book::getbookId()//ȡ���
{ return bookID; }

//ȡ����
string book::getbookName() { return bookName; }

string book::getauthor() { return author; }

string book::getpublishing() { return publishing; }

double book::getprice() { return price; }