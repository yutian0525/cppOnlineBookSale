//
// Created by nilei on 2024/5/27.
//

#include "ordersBox.h"
OrdersBox::OrdersBox() {
    read();
}

void OrdersBox::read(){
    ifstream inputFile;
    stringstream ss;
    string temp[10];
    inputFile.open("orders.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            ss.clear();
            ss.str(line);
            string single;
            int i = 0;
            for(i=0;i<10;i++){
                temp[i] = "";
            }
            i = 0;
            // 按照空格分隔
            while(getline(ss, single, ' ')){
                temp[i++] = single.c_str();
            }
            order *tt = new order(stoi(temp[1]), stoi(temp[2]), stoi(temp[0]));
            for(int i=4;i<stoi(temp[3])+4;i++){
                tt->addbook(temp[i]);
            }
            orders.push_back(tt);

        }
    } else {
        std::cout << "Failed to open the file." << std::endl; // 如果文件无法打开，输出错误信息
    }

    inputFile.close();
}

void OrdersBox::write(){
    ofstream outputFile;
    outputFile.open("orders.txt", ios::trunc);
    if (outputFile.is_open()) {
        for (order *o: orders) {
            outputFile << o->getid() << " " << o->getbuyerid()<< " " << o->getprice()<<" "<<o->getlistcount()<< o->getlist() << endl;
        }
    } else {
        std::cout << "Failed to open the file." << std::endl; // 如果文件无法打开，输出错误信息
    }

    outputFile.close();
}

void OrdersBox::print(){
    for (order *o: orders) {
        o->print();
    }
}
OrdersBox::~OrdersBox(){
    write();
    for (order *o: orders) {
        delete o;
    }
}
void OrdersBox::addorder(order *o){
    orders.push_back(o);
}