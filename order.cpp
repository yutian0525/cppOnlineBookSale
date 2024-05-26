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
    cout<<"购书人编号:"<<buyerID<<"  订单编号："<<orderID<<endl<<"\t共"<<listcount<<"本书"<<endl;
    for(int i = 0;i<listcount;i++)
        cout<<"\t"<<i+1<<"."<<orderlist[i]<<endl;
    cout<<"实付："<<price<<endl<<endl;
}

order::order(int bi,int p,int id){
    buyerID = bi;
    orderID = id;
    listcount = 0;
    price = p;
    ordercount++;
}
int order::getid() {
    return orderID;
}
int order::getbuyerid() {
    return buyerID;
}
int order::getprice() {
    return price;
}
int order::getlistcount() {
    return listcount;
}
string order::getlist() {
    int i = 0;
    string list = "";
    for (;i<listcount;i++){
        list = list + " " + orderlist[i];
    }
    return list;
}