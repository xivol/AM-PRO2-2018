//
//  main.cpp
//  special_task
//
//  Created by Илья Лошкарёв on 13.11.2018.
//  Copyright © 2018 SFEDU. All rights reserved.
//

#include <iostream>
#include "room.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    room* r[5];
    r[0] = new utility_room(std::string("101; Читальный зал; окна: true"));
    r[0]->print(std::cout);
    std::cout << "Hello, World!\n";
    return 0;
}
