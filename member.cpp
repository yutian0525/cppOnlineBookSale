//
// Created by nilei on 24-5-24.
//
#include "member.h"

void member::display() {
    cout << "����������:" << name << "\t";
    cout << "�����˱��:" << buyerID << "\t";
    cout << "������Ϊ��Ա,����:" << leaguer_grade << "\n";
    cout << "��ַ:" << address << "\n";
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
        cout << "�������!";
}