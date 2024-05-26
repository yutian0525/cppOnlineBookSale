//
// Created by nilei on 24-5-26.
//

#ifndef ONLINE_ORDER_H
#define ONLINE_ORDER_H
#include<string>
#include<iostream>
using namespace std;
class order {
private:
    static int ordercount;//订单编号
    int orderID;//购书人编号
    int buyerID;//购书数量
    int listcount;
    int price;
    string orderlist[20];
public:
    order();
    order(int bi,int p);
    order(int bi,int p,int id);
    void addbook(string bookname);
    void print();
    int getid();
    int getprice();
    int getbuyerid();
    int getlistcount();
    string getlist();
};
#endif //ONLINE_ORDER_H
