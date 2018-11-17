//
//  room.cpp
//  special_task
//
//  Created by Илья Лошкарёв on 13.11.2018.
//  Copyright © 2018 SFEDU. All rights reserved.
//

#include "room.h"
#include <sstream>

room::room(uint16_t number, bool has_natural_light)
{
    this->number = number;
    this->natural_light = has_natural_light;
}

void string_presentable::parseString(const std::string &params)
{
    std::istringstream sin(params);
    std::string component;
    int i = 0;
    while (std::getline(sin, component, ';'))
    {
        this->parse(i++, component);
    }
}

bool room::parse(int index, const std::string &component)
{
    std::istringstream sin(component);
    
    size_t pos = component.find(':');
    if (pos == std::string::npos) {
        if(index == 0)
        {
            sin >> this->number;
            return true;
        }
        return false;
    }
    
    std::string name; sin >> name;
    if ( name == "окна:")
    {
        sin >> std::boolalpha >> this->natural_light;
        return true;
    }
    return false;
}

uint16_t room::get_number() const
{
    return this->number;
}

bool room::has_natural_light() const
{
    return this->natural_light;
}

utility_room::utility_room(uint16_t number, const std::string &name, bool has_natural_light) : room(number, has_natural_light)
{
    this->name = name;
}

utility_room::utility_room(const std::string &str):room(0,0)
{
   this->parseString(str);
}

bool utility_room::parse(int index, const std::string &component)
{
    if (room::parse(index, component)) return true;
    
    size_t pos = component.find(':');
    if (pos == std::string::npos && index == 1)
    {
        this->name = component;
        return true;
    }
    return false;
}

std::string utility_room::get_name() const
{
    return name;
}

void utility_room::print(std::ostream &os) const
{
    os<<get_number()<<
        "; "<<get_name()<<
    "; окна:"<<std::boolalpha<<has_natural_light()<<std::endl;
}

