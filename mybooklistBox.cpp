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
        cout << "�������û�����";
        cin >> inputUser;
        for (buyer *us: users)
            if (us->getbuyname() == inputUser) {
                flag = 1;
                onloadUser = us;
                break;
            }
        if (!flag) { cout << "�û���������" << endl; }
    }
}
void mybooklistBox::choose(vector<book *> books) {
    book *choosebook;
    int flag = 0;

    cout << "\n ��ѡ��Ҫ�����ͼ���ţ�";
    string inputBook;
    cin >> inputBook;
    for (book *bk: books) {
        if (inputBook == bk->getbookId()) {
            flag = 1;
            choosebook = bk;
            break;
        }
    }
    if (!flag) { cout << "ͼ���Ų�����" << endl; }
    else {
        cout << "\n �Ѽ��빺�ﳵ��\n";
        choosebook->display();
        mybooklist.push_back(choosebook);
    }
}
order mybooklistBox::checkout() {
    onloadUser->display();
    for (book *bk: mybooklist) {
        onloadUser->setpay(bk->getprice());
    }
    cout << endl << "��������Ҫ����:" << onloadUser->getpay() << "\n";
    cout << "�����嵥��" << endl;
    order no(onloadUser->getid(), onloadUser->getpay());
    for (book *bk: mybooklist) {
        bk->display();
        no.addbook("������" + bk->getbookName() + "����ţ�" + bk->getbookId() + "�����ߣ�" + bk->getauthor() + "�������磺" +
                    bk->getpublishing() + "���۸�" + to_string(bk->getprice()));
    }
    cout << endl;
    return no;
}
void mybooklistBox::display() {
    onloadUser->display();
}