//
// Created by nilei on 2024/5/27.
//

#include "booksBox.h"

void BooksBox::read(){
    ifstream inputFile;
    stringstream ss;
    string temp[10];
    inputFile.open("books.txt");
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
            books.push_back(new book(temp[0], temp[1], temp[2], temp[3], stof(temp[4])));
        }
    } else {
        std::cout << "Failed to open the file." << std::endl; // 如果文件无法打开，输出错误信息
    }

    inputFile.close();
}
void BooksBox::print(){
    for (book *bk: books)
        bk->display();
}
void BooksBox::clearmybooklist() {
    books.clear();
    books.shrink_to_fit();
}
BooksBox::~BooksBox() {
    for (book *bk: books) {
        delete bk;
    }
}
BooksBox::BooksBox() {
    read();
}

vector<book *> BooksBox::getbooks() {
    return books;
}