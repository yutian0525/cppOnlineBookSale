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
//����Ĺ��캯��
    name = n;
    buyerID = b;
    address = a;
    pay = p;
}

double buyer::getpay()
//ȡ�������
{ return pay; }

string buyer::getaddress()
//ȡ�����˵�ַ
{ return address; }

string buyer::getbuyname()
//ȡ����������
{ return name; }

int buyer::getid() { return buyerID; }
//ȡ�����˱��