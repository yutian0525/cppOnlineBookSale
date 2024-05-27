//
// Created by nilei on 2024/5/27.
//

#include "buyerBox.h"

void BuyerBox::read() {
    ifstream inputFile;
    stringstream ss;
    string temp[10];
    inputFile.open("buyer.txt");
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
            if(temp[0] == "layfolk"){
                users.push_back(new layfolk(temp[1], stoi(temp[2]), temp[3], 0));
            }
            if(temp[0] == "honouredGuest"){
                users.push_back(new honouredGuest(temp[1], stoi(temp[2]), stof(temp[3]), temp[4], 0));
            }
            if(temp[0] == "member"){
                users.push_back(new member(temp[1], stoi(temp[2]), stoi(temp[3]), temp[4], 0));
            }

        }
    } else {
        std::cout << "Failed to open the file." << std::endl; // 如果文件无法打开，输出错误信息
    }

    inputFile.close();
}

void BuyerBox::print() {
    for (buyer *us: users)
        us->display();
}
BuyerBox::BuyerBox() {
    read();
}
BuyerBox::~BuyerBox() {
    for (buyer *us: users)
        delete us;
}
vector<buyer *> BuyerBox::getusers(){
    return users;
}