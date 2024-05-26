
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
    cout << "\n ͼ���б�:\n\n";
    for (book *bk: books)
        bk->display();
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
        thelist.push_back(choosebook);
        system("pause");
    }
}

void userLogin(vector<buyer *> users, buyer *&onloadUser) {
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

void checkout(vector<book *> mybooklist, buyer &onloadUser, vector<order *> &orders) {
    onloadUser.display();
    for (book *bk: mybooklist) {
        onloadUser.setpay(bk->getprice());
    }
    cout << endl << "��������Ҫ����:" << onloadUser.getpay() << "\n";
    cout << "�����嵥��" << endl;
    order *no = new order(onloadUser.getid(), onloadUser.getpay());
    for (book *bk: mybooklist) {
        bk->display();
        no->addbook("������" + bk->getbookName() + "����ţ�" + bk->getbookId() + "�����ߣ�" + bk->getauthor() + "�������磺" +
                    bk->getpublishing() + "���۸�" + to_string(bk->getprice()));
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


    users.push_back(new layfolk("��Сݱ", 1, "����", 0));
    users.push_back(new honouredGuest("��ңң", 2, .6, "�Ϻ�", 0));
    users.push_back(new member("�Ժ���", 3, 5, "����", 0));

    books.push_back(new book("7-302-04504-6", "C++�������", "̷ǿ", "�廪", 25));
    books.push_back(new book("7-402-03388-9", "���ݽṹ", "��׿Ⱥ", "����", 20));

    buyer *onloadUser;
    int mainMenu = 1,addMenu = 0, chooseFunction,chooseaf;



    while (mainMenu) {
        system("cls");
        cout << "��ӭʹ�����Ϲ������ϵͳ��\n\n";
        cout << "1. �½�����\n2. ���ж���\n3. �˳�\n\n��ѡ��";
        cin >> chooseFunction;
        switch (chooseFunction) {
            case 1:
                system("cls");
                cout<<"��ҳ/�½�����/ѡ���û�"<<endl<<endl;
                addMenu = 1;
                mybooklist.clear();
                mybooklist.shrink_to_fit();
                for (buyer *us: users)
                    us->display();
                userLogin(users, onloadUser);
                while (addMenu) {
                    system("cls");
                    cout<<"��ҳ/�½�����"<<endl<<endl;
                    onloadUser->display();
                    cout << "1. ���ͼ��\n2. ���ﳵ\n3. ����\n4. �˳�\n\n��ѡ��";
                    cin >> chooseaf;
                    switch (chooseaf) {
                        case 1:
                            system("cls");
                            cout<<"��ҳ/�½�����/���ͼ��"<<endl<<endl;
                            chooseBook(books, mybooklist);
                            break;
                        case 2:
                            system("cls");
                            cout<<"��ҳ/�½�����/���ﳵ"<<endl<<endl;
                            cout << "�����ͼ�飺\n";
                            for (book *tbk: mybooklist) {
                                tbk->display();
                            }
                            system("pause");
                            break;

                        case 3:
                            system("cls");
                            cout<<"��ҳ/�½�����/����"<<endl<<endl;
                            checkout(mybooklist, *onloadUser, orders);
                            addMenu = 0;
                            break;
                        case 4:
                            addMenu = 0;
                            break;
                        default:
                            cout << "��������ȷ��ѡ�" << endl;
                            break;
                    }
                }
                break;
            case 2:
                system("cls");
                cout<<"��ҳ/���ж���"<<endl<<endl;
                showAllOrders(orders);
                break;
            case 3:
                mainMenu = 0;
                break;
            default:
                cout << "��������ȷ��ѡ�" << endl;
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