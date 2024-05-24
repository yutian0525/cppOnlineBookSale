//
// Created by nilei on 24-5-24.
//
#include "honouredGuest.h"

void honouredGuest::display() {
    cout << "购书人姓名:" << name << "\t";
    cout << "购书人编号:" << buyerID << "\t";
    cout << "购书人为贵宾!折扣率为:" << discount_rate * 100 << "名\n",
            cout << "地址:" << address << "\n\n";
}

void honouredGuest::setpay(double p)
//贵宾类计算购书费用
{ pay = pay + (1 - discount_rate) * p; }