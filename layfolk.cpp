//
// Created by nilei on 24-5-24.
//
#include "layfolk.h"

void layfolk::display()
//��ͨ����ʾ����
{
    cout << "����������:" << name << "\t";
    cout << "�����˱��:" << buyerID << "\t";
    cout << "������Ϊ��ͨ��" << "\n";
    cout << "��ַ:" << address << "\n\n";
}

void layfolk::setpay(double p) { pay = pay + p; }