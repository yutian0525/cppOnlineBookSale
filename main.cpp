
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
    cout << "\n ͼ���б�:\n\n";
    for (book* bk : books)
        bk->display();
    cout << "\n ��ѡ��Ҫ�����ͼ���ţ�";
    string inputBook;
    cin >> inputBook;
    for (book* bk : books) {
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

void userLogin(vector<buyer*> users, buyer* &onloadUser) {
    int flag = 0;
    string inputUser;
    while (!flag) {
        cout << "�������û�����";
        cin >> inputUser;
        for (buyer* us : users)
            if (us->getbuyname() == inputUser) {
                flag = 1;
                onloadUser = us;
                break;
            }
        if (!flag) { cout << "�û���������" << endl; }
    }
}


int main() {
    vector<buyer*> users;
    vector<book*> books;
    vector<book*> mybooklist;


    users.push_back(new layfolk("��Сݱ", 1, "����", 0));
    users.push_back(new honouredGuest("��ңң", 2, .6, "�Ϻ�", 0));
    users.push_back(new member("�Ժ���", 3, 5, "����", 0));

    books.push_back(new book("7-302-04504-6", "C++�������", "̷ǿ", "�廪", 25));
    books.push_back(new book("7-402-03388-9", "���ݽṹ", "��׿Ⱥ", "����", 20));

    buyer *onloadUser;
    int mainMenu = 1,chooseFunction;
    cout << "��ӭ����������꣡\n\n";
    userLogin(users,onloadUser);
    system("cls");
    while (mainMenu) {
        onloadUser->display();
        cout << "\n\n1. ȥ����\n2. ���ﳵ\n3.ȥ����\n4. �ҵĶ���\n5. �˳�\n\n��ѡ��";
        cin >> chooseFunction;
        switch (chooseFunction) {
            
        }
    }
    chooseBook(books,mybooklist);
    for(book* tbk : mybooklist) {
        tbk->display();
    }
    /*
    onloadUser->setpay(choosebook->getprice()); //���㹺�����
    cout << endl << "��������Ҫ����:" << onloadUser->getpay() << "\n\n";
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
    cout << "��������Ϣ:\n\n";
    for (i = 0; i < 3; i++)
        b[i]->display();
*/
    return 0;
}