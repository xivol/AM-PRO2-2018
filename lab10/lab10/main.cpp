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
    bignum a = -1000000000000000000; // -1 * 10^18
    bignum b = -1000000000000000001; 

    try {
        cout<< (int64_t)a << " == " << (int64_t)b << " : " << boolalpha << (a == b) <<endl;
    }
    catch (const exception &e){
        cout<<e.what()<<endl;
    }
    system("pause");
    return 0;
}
