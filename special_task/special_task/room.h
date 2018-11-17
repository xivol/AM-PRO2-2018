//
//  room.h
//  special_task
//
//  Created by Илья Лошкарёв on 13.11.2018.
//  Copyright © 2018 SFEDU. All rights reserved.
//

#ifndef room_h
#define room_h

#pragma once
#include <cstdint>
#include <iostream>
#include <string>

class string_presentable
{
protected:
    virtual bool parse(int index, const std::string &component) = 0;
    void parseString(const std::string &params);
public:
    virtual void print(std::ostream &os) const = 0;
};

class room: public string_presentable
{
    uint16_t number;
    char letter[3];
    bool natural_light;

protected:
    bool parse(int index, const std::string &component);
public:
    room(uint16_t number, bool has_natural_light = true);

    uint16_t get_number() const;
    bool has_natural_light() const;
};

class named
{
public:
    virtual std::string get_name() const = 0;
};

class utility_room : public room, public named
{
    std::string name;
protected:
    bool parse(int index, const std::string &component);
public:
    utility_room(uint16_t number, const std::string &name, bool has_natural_light = false);
    utility_room(const std::string &str);
    std::string get_name() const;
    
    void print(std::ostream &os) const;
};

#endif /* room_h */
