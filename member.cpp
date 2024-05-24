//
// Created by nilei on 24-5-24.
//
#include "member.h"

void member::display() {
    cout << "购书人姓名:" << name << "\t";
    cout << "购书人编号:" << buyerID << "\t";
    cout << "购书人为会员,级别:" << leaguer_grade << "\n";
    cout << "地址:" << address << "\n";
}

void member::setpay(double p) {
    if (leaguer_grade == 1)
        pay = .95 * p + pay;
    else if (leaguer_grade == 2)
        pay = .90 * p + pay;
    else if (leaguer_grade == 3)
        pay = .85 * p + pay;
    else if (leaguer_grade == 4)
        pay = .8 * p + pay;
    else if (leaguer_grade == 5)
        pay = .7 * p + pay;

    else
        cout << "级别错误!";
}