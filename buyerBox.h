//
// Created by nilei on 2024/5/27.
//

#ifndef ONLINE_BUYERBOX_H
#define ONLINE_BUYERBOX_H
#include "Box.h"
class BuyerBox:public Box{
protected:
    vector<buyer *> users;
public:

    BuyerBox();
    void read();
    void print();
    vector<buyer *> getusers();
    ~BuyerBox();
};

#endif //ONLINE_BUYERBOX_H
