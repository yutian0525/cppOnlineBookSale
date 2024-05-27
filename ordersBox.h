//
// Created by nilei on 2024/5/27.
//

#ifndef ONLINE_ORDERSBOX_H
#define ONLINE_ORDERSBOX_H
#include "Box.h"
class OrdersBox:public Box{
private:
    vector<order *> orders;
public:
    void read();
    void print();
    void write();
    OrdersBox();
    ~OrdersBox();
    void addorder(order *);
};

#endif //ONLINE_ORDERSBOX_H
