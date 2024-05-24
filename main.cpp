
#include "buyer.h"
#include "book.h"
#include "layfolk.h"
#include "member.h"
#include "honouredGuest.h"
#include <vector>
#include <memory>

using namespace std;

void chooseBook(vector<book*> books,vector<book*> &thelist){
    book *choosebook;
    int flag = 0;
    cout << "\n 图书列表:\n\n";
    for (book* bk : books)
        bk->display();
    cout << "\n 请选择要购买的图书编号：";
    string inputBook;
    cin >> inputBook;
    for (book* bk : books) {
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

void userLogin(vector<buyer*> users, buyer* &onloadUser) {
    int flag = 0;
    string inputUser;
    while (!flag) {
        cout << "请输入用户名：";
        cin >> inputUser;
        for (buyer* us : users)
            if (us->getbuyname() == inputUser) {
                flag = 1;
                onloadUser = us;
                break;
            }
        if (!flag) { cout << "用户名不存在" << endl; }
    }
}


int main() {
    vector<buyer*> users;
    vector<book*> books;
    vector<book*> mybooklist;


    users.push_back(new layfolk("林小荼", 1, "北京", 0));
    users.push_back(new honouredGuest("王遥遥", 2, .6, "上海", 0));
    users.push_back(new member("赵红艳", 3, 5, "广州", 0));

    books.push_back(new book("7-302-04504-6", "C++程序设计", "谭强", "清华", 25));
    books.push_back(new book("7-402-03388-9", "数据结构", "许卓群", "北大", 20));

    buyer *onloadUser;
    int mainMenu = 1,chooseFunction;
    cout << "欢迎来到网上书店！\n\n";
    userLogin(users,onloadUser);
    system("cls");
    while (mainMenu) {
        onloadUser->display();
        cout << "\n\n1. 去买书\n2. 购物车\n3.去结算\n4. 我的订单\n5. 退出\n\n请选择：";
        cin >> chooseFunction;
        switch (chooseFunction) {
            
        }
    }
    chooseBook(books,mybooklist);
    for(book* tbk : mybooklist) {
        tbk->display();
    }
    /*
    onloadUser->setpay(choosebook->getprice()); //计算购书费用
    cout << endl << "购书人需要付费:" << onloadUser->getpay() << "\n\n";
*/

    for(buyer* us : users) {
        delete us;
    }
    for(book* bk : books) {
        delete bk;
    }
    for(book* tbk : mybooklist){
        delete tbk;
    }
    /*
    cout << "购书人信息:\n\n";
    for (i = 0; i < 3; i++)
        b[i]->display();
*/
    return 0;
}