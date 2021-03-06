//
// ������������ ������ �9. ������. ����������� �����������. Copy-and-Swap
// dyn_array.h
//
#pragma once
#include <iostream>

// ����� ������������ ������
class dyn_array
{
public:
    // ��� ������, ���������� � �������
    typedef double datatype;

private:
    // ��������� �� ������
    datatype *data;

    // ���������� ��������� � �������
    int size;

    // ������� ����������� �������� �� ������� � ������
    void copy(const datatype *from, datatype* to, int size);

    // ������� ����������� �������� �� ������� ������������� �������
    void swap(dyn_array &other) noexcept;

public:

    /*
    �������������
    */

    // ����������� �� ���������
    dyn_array();

    // ����������� �� �������
    // ����������� std::invalid_argument ��� size < 0
    dyn_array(int size);

    // ����������
    ~dyn_array();

    // ����������� �����������
    dyn_array(const dyn_array& d);

    // ����������� �����������
    dyn_array(dyn_array&& d);

    /*
    ��������
    */

    // �������� ������������ ����� �����������
    dyn_array &operator=(dyn_array d);

    // �������� ������� � ���������
    // ����������� std::out_of_range ��� index < 0 ��� index >= size
    datatype &operator[](int index);

    // �������� ������� � ��������� ��� ������
    // ����������� std::out_of_range ��� index < 0 ��� index >= size
    datatype operator[](int index) const;

    // �������� ��������� �������� �� ���������
    bool operator==(const dyn_array &other) const;

    // �������� ��������� �������� �� �����������
    bool operator!=(const dyn_array &other) const;

    /*
    ������
    */

    // ���������� ��������� � �������
    int count() const;

    // ��������� ������� �������
    // ����������� std::invalid_argument ��� new_size < 0
    void resize(int new_size);

    // ���������� �������� � ����� �������
    // � ����������� ������� �������
    void append(const datatype &x);

    // ������� �������� �� ��������� �������
    // ����������� std::out_of_range ��� index < 0 ��� index >= size
    void insert(int index, const datatype &x);

    // �������� �������� �� ���������� �������
    // ����������� std::out_of_range ��� index < 0 ��� index >= size
    void remove(int index);

    // ����� ��������� ��������
    // ���������� ������ ���������� ��������
    // ��� -1 ���� ������ �������� � ������� ���
    int find(const datatype &x) const;


    // ���������� �������� � ������� �� ��������
    void sort();

    // �������� ������������� �������� � �������
    void unique();

    // ���������� ���� �������� � ����� �������
    void append(const dyn_array &d);
};

// �������� ������
std::ostream &operator<<(std::ostream &os, const dyn_array &d);

// �������� �����
std::istream &operator>>(std::istream &is, dyn_array &d);
