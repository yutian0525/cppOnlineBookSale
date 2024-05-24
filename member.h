//
// Created by nilei on 24-5-24.
//
#include "buyer.h"

#ifndef ONLINEBOOKSALE2_MEMBER_H
#define ONLINEBOOKSALE2_MEMBER_H

class member : public buyer {
private:
    int leaguer_grade;

public:
    member(string n, int b, int l, string a, double p) : buyer(n, b, a, p) { leaguer_grade = l; }

    void display();

    void setpay(double p);
};

#endif //ONLINEBOOKSALE2_MEMBER_H
