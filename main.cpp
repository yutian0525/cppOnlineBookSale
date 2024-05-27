
#include "buyer.h"
#include "book.h"
#include "layfolk.h"
#include "member.h"
#include "honouredGuest.h"
#include "order.h"
#include <vector>
#include <fstream>
#include <memory>
#include <sstream>
#include "Box.h"
#include "booksBox.h"
#include "buyerBox.h"
#include "mybooklistBox.h"
#include "ordersBox.h"


using namespace std;

int main() {
    int mainMenu = 1,addMenu = 0, chooseFunction,chooseaf;
    order o;
    BooksBox books;
    BuyerBox buyers;
    mybooklistBox mybooklist;
    OrdersBox orders;
    books.print();
    buyers.print();
    orders.print();
    system("pause");

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
                buyers.print();
                mybooklist.userlogin(buyers.getusers());
                while (addMenu) {
                    system("cls");
                    cout<<"��ҳ/�½�����"<<endl<<endl;
                    mybooklist.display();
                    cout << "1. ���ͼ��\n2. ���ﳵ\n3. ����\n4. �˳�\n\n��ѡ��";
                    cin >> chooseaf;
                    switch (chooseaf) {
                        case 1:
                            system("cls");
                            cout<<"��ҳ/�½�����/���ͼ��"<<endl<<endl;
                            cout << "\n ͼ���б�:\n\n";
                            books.print();
                            mybooklist.choose(books.getbooks());
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            cout<<"��ҳ/�½�����/���ﳵ"<<endl<<endl;
                            cout << "�����ͼ�飺\n";
                            mybooklist.print();
                            system("pause");
                            break;

                        case 3:
                            system("cls");
                            cout<<"��ҳ/�½�����/����"<<endl<<endl;

                            o = mybooklist.checkout();
                            orders.addorder(&o);
                            mybooklist.clearmybooklist();
                            addMenu = 0;
                            system("pause");
                            break;
                        case 4:
                            mybooklist.clearmybooklist();
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
                orders.print();
                system("pause");
                break;
            case 3:
                mainMenu = 0;
                break;
            default:
                cout << "��������ȷ��ѡ�" << endl;
                break;
        }
    }

    return 0;
}