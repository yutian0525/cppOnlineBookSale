//
// Created by nilei on 2024/5/27.
//

#ifndef ONLINE_MYBOOKLISTBOX_H
#define ONLINE_MYBOOKLISTBOX_H

#include "Box.h"
class mybooklistBox:public Box{
private:
    buyer *onloadUser;
    vector<book *> mybooklist;
public:
    void clearmybooklist();
    void print();
    void read();
    void addbook(book *);
    mybooklistBox();
    ~mybooklistBox();
    void userlogin(vector<buyer *> users);
    void choose(vector<book *> books);
    order checkout();
    void display();
};
#endif //ONLINE_MYBOOKLISTBOX_H
