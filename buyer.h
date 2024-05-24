//
// Created by nilei on 24-5-24.
//
#include <string>
#include <iostream>
using namespace std;
#ifndef ONLINEBOOKSALE2_BUYER_H
#define ONLINEBOOKSALE2_BUYER_H
class buyer{
protected:
    string name;
    int buyerID;
    string address;
    double pay;
public:
    buyer();
    buyer(string n,int b,string a,double p);
    string getbuyname();
    string getaddress();
    double getpay();
    int getid();
    virtual void display()=0;
    virtual void setpay(double=0)=0;
};
#endif //ONLINEBOOKSALE2_BUYER_H
