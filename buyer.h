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
    // ��ҵ�����
    string name;

    // ��ҵ�ID
    int buyerID;

    // ��ҵĵ�ַ
    string address;

    // ��ҵ�֧�����
    double pay;

public:
    // Ĭ�Ϲ��캯����δ�ṩ�����ʼ��ֵ
    buyer();

    // ��ʼ����Ҷ���Ĺ��캯��
    buyer(string n, int b, string a, double p);

    // ��ȡ�������
    string getbuyname();

    // ��ȡ��ҵĵ�ַ
    string getaddress();

    // ��ȡ��ҵ�֧�����
    double getpay();

    // ��ȡ���ID
    int getid();

    // �麯������������Ҫ�������ṩ��ʾ�����Ϣ��ʵ��
    virtual void display() = 0;

    // �麯������������Ҫ�������ṩ����֧������ʵ�֣���ѡ����Ĭ��Ϊ0
    virtual void setpay(double p = 0) = 0;
};

#endif //ONLINEBOOKSALE2_BUYER_H
