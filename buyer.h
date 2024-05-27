//
// Created by nilei on 24-5-24.
//
#include <string>
#include <iostream>

using namespace std;
#ifndef ONLINEBOOKSALE2_BUYER_H
#define ONLINEBOOKSALE2_BUYER_H

class buyer {
protected:
    // 买家的姓名
    string name;

    // 买家的ID
    int buyerID;

    // 买家的地址
    string address;

    // 买家的支付金额
    double pay;

public:
    // 默认构造函数，未提供具体初始化值
    buyer();

    // 初始化买家对象的构造函数
    buyer(string n, int b, string a, double p);

    // 获取买家姓名
    string getbuyname();

    // 获取买家的地址
    string getaddress();

    // 获取买家的支付金额
    double getpay();

    // 获取买家ID
    int getid();

    // 虚函数，派生类需要覆盖以提供显示买家信息的实现
    virtual void display() = 0;

    // 虚函数，派生类需要覆盖以提供设置支付金额的实现，可选参数默认为0
    virtual void setpay(double p = 0) = 0;
};

#endif //ONLINEBOOKSALE2_BUYER_H
