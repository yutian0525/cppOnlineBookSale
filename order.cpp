//
// Created by nilei on 24-5-26.
//
#include "order.h"
int order::ordercount = 0;
order::order(int bi,int p) {
    buyerID = bi;
    orderID = ++ordercount;
    listcount = 0;
    price = p;
}
void order::addbook(string bookname) {
    orderlist[listcount] = bookname;
    listcount++;
}
void order::print() {
    cout<<"�����˱��:"<<buyerID<<"  ������ţ�"<<orderID<<endl<<"\t��"<<listcount<<"����"<<endl;
    for(int i = 0;i<listcount;i++)
        cout<<"\t"<<i+1<<"."<<orderlist[i]<<endl;
    cout<<"ʵ����"<<price<<endl<<endl;
}