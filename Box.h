//
// Created by nilei on 2024/5/27.
//

#ifndef ONLINE_BOX_H
#define ONLINE_BOX_H
#include "buyer.h"
#include "book.h"
#include "layfolk.h"
#include "member.h"
#include "honouredGuest.h"
#include "order.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;


class Box {

public:
    Box();
    virtual void read()=0;
    virtual void print()=0;
};


#endif //ONLINE_BOX_H
