
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
        cout << "欢迎使用网上购书结账系统！\n\n";
        cout << "1. 新建订单\n2. 所有订单\n3. 退出\n\n请选择：";
        cin >> chooseFunction;
        switch (chooseFunction) {
            case 1:
                system("cls");
                cout<<"首页/新建订单/选择用户"<<endl<<endl;
                addMenu = 1;
                buyers.print();
                mybooklist.userlogin(buyers.getusers());
                while (addMenu) {
                    system("cls");
                    cout<<"首页/新建订单"<<endl<<endl;
                    mybooklist.display();
                    cout << "1. 添加图书\n2. 购物车\n3. 结算\n4. 退出\n\n请选择：";
                    cin >> chooseaf;
                    switch (chooseaf) {
                        case 1:
                            system("cls");
                            cout<<"首页/新建订单/添加图书"<<endl<<endl;
                            cout << "\n 图书列表:\n\n";
                            books.print();
                            mybooklist.choose(books.getbooks());
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            cout<<"首页/新建订单/购物车"<<endl<<endl;
                            cout << "已添加图书：\n";
                            mybooklist.print();
                            system("pause");
                            break;

                        case 3:
                            system("cls");
                            cout<<"首页/新建订单/结算"<<endl<<endl;

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
                            cout << "请输入正确的选项！" << endl;
                            break;
                    }
                }
                break;
            case 2:
                system("cls");
                cout<<"首页/所有订单"<<endl<<endl;
                orders.print();
                system("pause");
                break;
            case 3:
                mainMenu = 0;
                break;
            default:
                cout << "请输入正确的选项！" << endl;
                break;
        }
    }

    return 0;
}