//
// Created by nilei on 24-5-24.
//
#include "layfolk.h"

void layfolk::display()
//普通类显示函数
{
    cout << "购书人姓名:" << name << "\t";
    cout << "购书人编号:" << buyerID << "\t";
    cout << "购书人为普通人" << "\n";
    cout << "地址:" << address << "\n\n";
}

void layfolk::setpay(double p) { pay = pay + p; }