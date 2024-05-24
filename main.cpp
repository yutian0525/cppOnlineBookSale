
#include "buyer.h"
#include "book.h"
#include "layfolk.h"
#include "member.h"
#include "honouredGuest.h"

using namespace std;

int main() {
    int i = 0, buyerid, flag;
//用指针数组存放book对象的地址
    book *c[2];
    layfolk b1("林小荼", 1, "北京", 0);
    honouredGuest b2("王遥遥", 2, .6, "上海", 0);
    member b3("赵红艳", 3, 5, "广州", 0);//用指针数组存放继承了buyer类//的三个对象的地址
    book c1("7-302-04504-6", "C++程序设计", "谭强", "清华", 25);
    buyer *b[3] = {&b1, &b2, &b3};
    book c2("7-402-03388-9", "数据结构", "许卓群", "北大", 20);

    c[0] = &c1;
    c[1] = &c2;
    cout << "购书人信息:\n\n";
    for (i = 0; i < 3; i++)
        b[i]->display();
    cout << "\n 图书信息:\n\n";
    for (i = 0; i < 2; i++)
        c[i]->display();
    cout << "\n\n 请输入购书人编号:";
    cin >> buyerid;
    flag = 0;
    for (i = 0; i < 3; i++)
        if (b[i]->getid() == buyerid) {
            flag = 1;
            break;
        }
    if (!flag) { cout << "编号不存在" << endl; }
    else {
        b[i]->setpay(c[0]->getprice()); //计算购书费用
        b[i]->setpay(c[1]->getprice());
        cout << endl << "购书人需要付费:" << b[i]->getpay() << "\n\n";
    }
    return 0;
}