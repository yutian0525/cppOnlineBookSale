//
// Created by nilei on 2024/5/27.
//

#include "mybooklistBox.h"
void mybooklistBox::read() {

}
void mybooklistBox::print() {
    for (book *tbk: mybooklist) {
        tbk->display();
    }
}
mybooklistBox::mybooklistBox() {
}
mybooklistBox::~mybooklistBox() {
    for (book *tbk: mybooklist) {
        delete tbk;
    }
}
void mybooklistBox::clearmybooklist() {
    mybooklist.clear();
    mybooklist.shrink_to_fit();
}
void mybooklistBox::userlogin(vector<buyer *> users) {
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
void mybooklistBox::choose(vector<book *> books) {
    book *choosebook;
    int flag = 0;

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
        mybooklist.push_back(choosebook);
    }
}
order mybooklistBox::checkout() {
    onloadUser->display();
    for (book *bk: mybooklist) {
        onloadUser->setpay(bk->getprice());
    }
    cout << endl << "购书人需要付费:" << onloadUser->getpay() << "\n";
    cout << "购物清单：" << endl;
    order no(onloadUser->getid(), onloadUser->getpay());
    for (book *bk: mybooklist) {
        bk->display();
        no.addbook("书名：" + bk->getbookName() + "，书号：" + bk->getbookId() + "，作者：" + bk->getauthor() + "，出版社：" +
                    bk->getpublishing() + "，价格：" + to_string(bk->getprice()));
    }
    cout << endl;
    return no;
}
void mybooklistBox::display() {
    onloadUser->display();
}