//
// Created by nilei on 24-5-24.
//
#include "honouredGuest.h"

void honouredGuest::display() {
    cout << "����������:" << name << "\t";
    cout << "�����˱��:" << buyerID << "\t";
    cout << "������Ϊ���!�ۿ���Ϊ:" << discount_rate * 100 << "��\n",
            cout << "��ַ:" << address << "\n\n";
}

void honouredGuest::setpay(double p)
//�������㹺�����
{ pay = pay + (1 - discount_rate) * p; }