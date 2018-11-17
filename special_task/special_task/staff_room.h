//
//  staff_room.h
//  special_task
//
//  Created by Илья Лошкарёв on 13.11.2018.
//  Copyright © 2018 SFEDU. All rights reserved.
//

#ifndef staff_room_hpp
#define staff_room_hpp

#pragma once
#include <cstdint>
#include <iostream>
#include <string>
#include "room.h"

class staff_room : public room
{
    uint8_t members_count;
    std::string phone;
public:
    staff_room(uint16_t number, uint8_t members_count, const std::string &phone,
               bool has_natural_light = true);
    
    uint8_t get_members_count() const;
    std::string get_phone() const;
    
    void print(std::ostream &os) const;
};

class department : public staff_room, public named
{
    std::string name;
public:
    department(uint16_t number, const std::string &name,
               uint8_t members_count, const std::string &phone, bool has_natural_light = true);
    std::string get_name() const;
    
    void print(std::ostream &os) const;
};

#endif /* staff_room_h */
