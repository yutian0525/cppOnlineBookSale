//
// Created by nilei on 24-5-24.
//
#include "buyer.h"

#ifndef ONLINEBOOKSALE2_LAYFOLK_H
#define ONLINEBOOKSALE2_LAYFOLK_H

class layfolk : public buyer {
public:
//��ͨ����
    layfolk(string n, int b, string a, double p) : buyer(n, b, a, p) {}

//���캯��
    void display();

//��ʾ����
    void setpay(double p);
};

#endif //ONLINEBOOKSALE2_LAYFOLK_H
