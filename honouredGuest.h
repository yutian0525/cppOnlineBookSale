//
// Created by nilei on 24-5-24.
//
#include "buyer.h"

#ifndef ONLINEBOOKSALE2_HONOUREDGUEST_H
#define ONLINEBOOKSALE2_HONOUREDGUEST_H

class honouredGuest : public buyer {
    //贵宾类
//折扣率
    double discount_rate;
public:
    honouredGuest(string n, int b, double r, string a, double p) : buyer(n, b, a, p)
//构造函数
    { discount_rate = r; }

//显示对象
    void display();

//计算购书费用
    void setpay(double p);
};

#endif //ONLINEBOOKSALE2_HONOUREDGUEST_H
