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
    static int ordercount;//�������
    int orderID;//�����˱��
    int buyerID;//��������
    int listcount;
    int price;
    string orderlist[20];
public:
    order();
    order(int bi,int p);
    void addbook(string bookname);
    void print();
};
#endif //ONLINE_ORDER_H
