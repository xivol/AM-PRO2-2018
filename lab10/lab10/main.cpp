//
//  main.cpp
//  lab10
//
//  Created by Илья Лошкарёв on 02.10.2018.
//  Copyright © 2018 SFEDU. All rights reserved.
//

#include <iostream>
#include "bignum.h"

using namespace std;

int main()
{
    bignum a = -100000000000000000;
    bignum b = -100000000000000001;
    try {
        cout<< (long)a << " == " << (long)b << " : " << boolalpha << (a == b) <<endl;
    }
    catch (const exception &e){
        cout<<e.what()<<endl;
    }
    return 0;
}
