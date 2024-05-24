//
// Created by nilei on 24-5-24.
//
#include "buyer.h"
buyer::buyer(){
    name = "";
    buyerID = 0;
    address = "";
    pay = 0;
}
buyer::buyer(string n, int b, string a, double p) {
//基类的构造函数
    name = n;
    buyerID = b;
    address = a;
    pay = p;
}

double buyer::getpay()
//取购书费用
{ return pay; }

string buyer::getaddress()
//取购书人地址
{ return address; }

string buyer::getbuyname()
//取购书人名字
{ return name; }

int buyer::getid() { return buyerID; }
//取购书人编号