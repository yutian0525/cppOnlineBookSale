//
// Created by nilei on 2024/5/27.
//
#include "Box.h"
#ifndef ONLINE_BOOKSBOX_H
#define ONLINE_BOOKSBOX_H
class BooksBox:public Box {
private:
    vector<book *> books;
public:
    void clearmybooklist();
    void read();
    void print();
    BooksBox();
    ~BooksBox();
    vector<book *> getbooks();
};

#endif //ONLINE_BOOKSBOX_H
