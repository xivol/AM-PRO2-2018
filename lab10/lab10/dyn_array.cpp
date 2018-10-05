//
//  dyn_array.cpp
//  lab10
//
//  Created by Илья Лошкарёв on 03.10.2018.
//  Copyright © 2018 SFEDU. All rights reserved.
//
#include "dyn_array.h"
#include <iostream>
#include <cassert>
dyn_array::dyn_array()
{
    data = nullptr;
    size = 0;
};

dyn_array::dyn_array(int size)

{
    assert(size > 0);
    this->size = size;
    data = new datatype[size];
    for (int i = 0; i < size; data[i++] = 0);
}

dyn_array::~dyn_array()
{
    delete[] data;
};

void dyn_array::copy(const datatype *from, datatype* to, int size)
{
    for (int i = 0; i < size; ++i)
        to[i] = from[i];
    
}

dyn_array::dyn_array(const dyn_array& d)
{
    size = d.size;
    data = new datatype[size];
    copy(d.data, data, size);
    
}

dyn_array & dyn_array::operator=(const dyn_array& d)
{
    if (d.size > size)
    {
        delete[] data;
        data = new datatype[d.size];
        
    }
    size = d.size;
    copy(d.data, data, size);
    return *this;
    
    
}

dyn_array:: datatype &dyn_array::operator[](int index)
{
    assert(index >= 0 && index < size);
    return data[index];
}

dyn_array::datatype dyn_array::operator[](int index) const
{
    assert(index >= 0 && index < size);
    return data[index];
}

int dyn_array::count() const
{
    return size;
}

void dyn_array::resize(int new_size)
{
    assert(new_size >= 0);
    if (size < new_size)
    {
        datatype *new_data = new datatype[new_size];
        copy(data, new_data, size);
        delete[] data;
        data = new_data;
    }
    size = new_size;
}

void dyn_array::append(const datatype &x)
{
    resize(size + 1);
    
    data[size-1] = x;
    //std::cout << data[size];
}

void dyn_array::insert(int index, const datatype &x)
{
    int new_size = size + 1;
    int p = 0;
    datatype *new_data = new datatype[new_size];
    for (int i = 0; i < new_size; ++i)
    {
        if (p != index)
            new_data[p++] = data[i];
        else
            new_data[p++] = x;
    }
    
    delete[]data;
    data = new_data;
    
}

void dyn_array::remove(int index)
{
    //int new_size = size - 1;
    datatype *new_data = new datatype[size-1];
    int  p = 0;
    for (int i = 0; i < size; ++i)
    {
        if (i == index)
            i += 1;
        new_data[p++] = data[i];
        
    }
    
    delete[]data;
    data = new_data;
}

int dyn_array::find(const datatype &x) const
{
    for (int i = 0; i < size; ++i)
    {
        if (data[i] == x)
            return i;
    }
    return -1;
}
