//
//  teaching_room.cpp
//  special_task
//
//  Created by Илья Лошкарёв on 13.11.2018.
//  Copyright © 2018 SFEDU. All rights reserved.
//

#include "teaching_room.h"

teaching_room::teaching_room(uint16_t number, uint16_t seats,
                             bool has_projector, bool has_a_c, bool has_natural_light) :
    room(number, has_natural_light)
{
    this->seats = seats;
    this->projector = has_projector;
    this->air_conditioning = has_a_c;
}

uint16_t teaching_room::get_seats() const
{
    return this->seats;
}

bool teaching_room::has_projector() const
{
    return this->projector;
}

bool teaching_room::has_air_conditioning() const
{
    return this->air_conditioning;
}

void teaching_room::print(std::ostream &os) const
{
    os<<get_number()<<
        "; мест:"<<get_seats()<<
        "; проектор:"<< has_projector()<<
        "; конд:"<<has_air_conditioning()<<std::endl;
}
