//
// Created by nilei on 24-5-24.
//
#include "buyer.h"

#ifndef ONLINEBOOKSALE2_HONOUREDGUEST_H
#define ONLINEBOOKSALE2_HONOUREDGUEST_H

class honouredGuest : public buyer {
    //�����
//�ۿ���
    double discount_rate;
public:
    honouredGuest(string n, int b, double r, string a, double p) : buyer(n, b, a, p)
//���캯��
    { discount_rate = r; }

//��ʾ����
    void display();

//���㹺�����
    void setpay(double p);
};

#endif //ONLINEBOOKSALE2_HONOUREDGUEST_H
