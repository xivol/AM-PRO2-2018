//
//  staff_room.cpp
//  special_task
//
//  Created by Илья Лошкарёв on 13.11.2018.
//  Copyright © 2018 SFEDU. All rights reserved.
//

#include "staff_room.h"

staff_room::staff_room(uint16_t number, uint8_t members_count, const std::string &phone, bool has_natural_light) : room(number, has_natural_light)
{
    this->phone = phone;
    this->members_count = members_count;
}

uint8_t staff_room::get_members_count() const
{
    return this->members_count;
}

std::string staff_room::get_phone() const
{
    return this->phone;
}

void staff_room::print(std::ostream &os) const
{
    os<< get_number()<<
        "; сотрудников:"<<get_members_count()<<
        "; тел:"<<get_phone()<<
        "; окна:"<<has_natural_light()<<std::endl;
}

