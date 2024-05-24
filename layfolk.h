//
// Created by nilei on 24-5-24.
//
#include "buyer.h"

#ifndef ONLINEBOOKSALE2_LAYFOLK_H
#define ONLINEBOOKSALE2_LAYFOLK_H

class layfolk : public buyer {
public:
//普通人类
    layfolk(string n, int b, string a, double p) : buyer(n, b, a, p) {}

//构造函数
    void display();

//显示对象
    void setpay(double p);
};

#endif //ONLINEBOOKSALE2_LAYFOLK_H
