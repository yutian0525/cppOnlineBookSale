
#include "buyer.h"
#include "book.h"
#include "layfolk.h"
#include "member.h"
#include "honouredGuest.h"

using namespace std;

int main() {
    int i = 0, buyerid, flag;
//��ָ��������book����ĵ�ַ
    book *c[2];
    layfolk b1("��Сݱ", 1, "����", 0);
    honouredGuest b2("��ңң", 2, .6, "�Ϻ�", 0);
    member b3("�Ժ���", 3, 5, "����", 0);//��ָ�������ż̳���buyer��//����������ĵ�ַ
    book c1("7-302-04504-6", "C++�������", "̷ǿ", "�廪", 25);
    buyer *b[3] = {&b1, &b2, &b3};
    book c2("7-402-03388-9", "���ݽṹ", "��׿Ⱥ", "����", 20);

    c[0] = &c1;
    c[1] = &c2;
    cout << "��������Ϣ:\n\n";
    for (i = 0; i < 3; i++)
        b[i]->display();
    cout << "\n ͼ����Ϣ:\n\n";
    for (i = 0; i < 2; i++)
        c[i]->display();
    cout << "\n\n �����빺���˱��:";
    cin >> buyerid;
    flag = 0;
    for (i = 0; i < 3; i++)
        if (b[i]->getid() == buyerid) {
            flag = 1;
            break;
        }
    if (!flag) { cout << "��Ų�����" << endl; }
    else {
        b[i]->setpay(c[0]->getprice()); //���㹺�����
        b[i]->setpay(c[1]->getprice());
        cout << endl << "��������Ҫ����:" << b[i]->getpay() << "\n\n";
    }
    return 0;
}