//
//  teaching_room.h
//  special_task
//
//  Created by Илья Лошкарёв on 13.11.2018.
//  Copyright © 2018 SFEDU. All rights reserved.
//

#ifndef teaching_room_hpp
#define teaching_room_hpp

#pragma once
#include <cstdint>
#include <iostream>
#include <string>
#include "room.h"

class teaching_room : public room
{
    uint16_t seats;
    bool projector, air_conditioning;
public:
    teaching_room(uint16_t number, uint16_t seats,
                  bool has_projector, bool has_a_c,
                  bool has_natural_light = true);

    uint16_t get_seats() const;
    bool has_projector() const;
    bool has_air_conditioning() const;
    
    void print(std::ostream &os) const;
};

class auditorium : public teaching_room, public named
{
    std::string name;
public:
    auditorium(uint16_t number, const std::string &name, uint16_t seats,
               bool has_projector, bool has_a_c, bool has_natural_light = true);

    std::string get_name() const;
    
    void print(std::ostream &os) const;
};

class laboratory : public teaching_room
{
    uint16_t workplaces;
    std::string equipment;
public:
    laboratory(uint16_t number, uint16_t seats, uint16_t workplaces,
               const std::string &equipment,
               bool has_projector, bool has_a_c, bool has_natural_light = true);
    
    uint16_t get_workplaces() const;
    std::string get_equipment() const;
    
    void print(std::ostream &os) const;
};


#endif /* teaching_room_h */
