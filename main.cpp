
#include "buyer.h"
#include "book.h"
#include "layfolk.h"
#include "member.h"
#include "honouredGuest.h"
#include "order.h"
#include <vector>
#include <memory>

using namespace std;

void chooseBook(vector<book *> books, vector<book *> &thelist) {
    book *choosebook;
    int flag = 0;
    cout << "\n 图书列表:\n\n";
    for (book *bk: books)
        bk->display();
    cout << "\n 请选择要购买的图书编号：";
    string inputBook;
    cin >> inputBook;
    for (book *bk: books) {
        if (inputBook == bk->getbookId()) {
            flag = 1;
            choosebook = bk;
            break;
        }
    }
    if (!flag) { cout << "图书编号不存在" << endl; }
    else {
        cout << "\n 已加入购物车！\n";
        choosebook->display();
        thelist.push_back(choosebook);
        system("pause");
    }
}

void userLogin(vector<buyer *> users, buyer *&onloadUser) {
    int flag = 0;
    string inputUser;
    while (!flag) {
        cout << "请输入用户名：";
        cin >> inputUser;
        for (buyer *us: users)
            if (us->getbuyname() == inputUser) {
                flag = 1;
                onloadUser = us;
                break;
            }
        if (!flag) { cout << "用户名不存在" << endl; }
    }
}

void checkout(vector<book *> mybooklist, buyer &onloadUser, vector<order *> &orders) {
    onloadUser.display();
    for (book *bk: mybooklist) {
        onloadUser.setpay(bk->getprice());
    }
    cout << endl << "购书人需要付费:" << onloadUser.getpay() << "\n";
    cout << "购物清单：" << endl;
    order *no = new order(onloadUser.getid(), onloadUser.getpay());
    for (book *bk: mybooklist) {
        bk->display();
        no->addbook("书名：" + bk->getbookName() + "，书号：" + bk->getbookId() + "，作者：" + bk->getauthor() + "，出版社：" +
                    bk->getpublishing() + "，价格：" + to_string(bk->getprice()));
    }
    orders.push_back(no);
    cout << endl;
    system("pause");
}

void showAllOrders(vector<order *> orders) {
    for (order *o: orders) {
        o->print();
    }
    system("pause");
}

int main() {
    vector<buyer *> users;
    vector<book *> books;
    vector<book *> mybooklist;
    vector<order *> orders;


    users.push_back(new layfolk("林小荼", 1, "北京", 0));
    users.push_back(new honouredGuest("王遥遥", 2, .6, "上海", 0));
    users.push_back(new member("赵红艳", 3, 5, "广州", 0));

    books.push_back(new book("7-302-04504-6", "C++程序设计", "谭强", "清华", 25));
    books.push_back(new book("7-402-03388-9", "数据结构", "许卓群", "北大", 20));

    buyer *onloadUser;
    int mainMenu = 1,addMenu = 0, chooseFunction,chooseaf;



    while (mainMenu) {
        system("cls");
        cout << "欢迎使用网上购书结账系统！\n\n";
        cout << "1. 新建订单\n2. 所有订单\n3. 退出\n\n请选择：";
        cin >> chooseFunction;
        switch (chooseFunction) {
            case 1:
                system("cls");
                cout<<"首页/新建订单/选择用户"<<endl<<endl;
                addMenu = 1;
                mybooklist.clear();
                mybooklist.shrink_to_fit();
                for (buyer *us: users)
                    us->display();
                userLogin(users, onloadUser);
                while (addMenu) {
                    system("cls");
                    cout<<"首页/新建订单"<<endl<<endl;
                    onloadUser->display();
                    cout << "1. 添加图书\n2. 购物车\n3. 结算\n4. 退出\n\n请选择：";
                    cin >> chooseaf;
                    switch (chooseaf) {
                        case 1:
                            system("cls");
                            cout<<"首页/新建订单/添加图书"<<endl<<endl;
                            chooseBook(books, mybooklist);
                            break;
                        case 2:
                            system("cls");
                            cout<<"首页/新建订单/购物车"<<endl<<endl;
                            cout << "已添加图书：\n";
                            for (book *tbk: mybooklist) {
                                tbk->display();
                            }
                            system("pause");
                            break;

                        case 3:
                            system("cls");
                            cout<<"首页/新建订单/结算"<<endl<<endl;
                            checkout(mybooklist, *onloadUser, orders);
                            addMenu = 0;
                            break;
                        case 4:
                            addMenu = 0;
                            break;
                        default:
                            cout << "请输入正确的选项！" << endl;
                            break;
                    }
                }
                break;
            case 2:
                system("cls");
                cout<<"首页/所有订单"<<endl<<endl;
                showAllOrders(orders);
                break;
            case 3:
                mainMenu = 0;
                break;
            default:
                cout << "请输入正确的选项！" << endl;
                break;
        }
    }


    for (buyer *us: users) {
        delete us;
    }
    for (book *bk: books) {
        delete bk;
    }
    for (book *tbk: mybooklist) {
        delete tbk;
    }
    for (order *o: orders) {
        delete o;
    }

    return 0;
}