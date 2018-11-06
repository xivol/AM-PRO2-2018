//
// Лабораторная работа №15. Абстрактные типы данных. Стек
// test_stack.cpp
//
#include <cassert>
#include <iostream>
#include "test_stack.h"
using namespace std;


test_stack::test_stack(stack &st) : st(st)
{}

void test_stack::cleanup()
{
    while (!st.is_empty())
    {
        st.pop();
    }
}

bool test_stack::is_empty()
{
#ifdef _DEBUG
    cerr << "test_d_stack::is_empty: ";
#endif

    assert(st.is_empty());

    st.push(1);
    st.pop();
    assert(st.is_empty());

    int n = 100;
    for (int i = 0; i < n; ++i)
        st.push(i);
    for (int i = 0; i < n; ++i)
        st.pop();
    assert(st.is_empty());

#ifdef _DEBUG
    cerr << "OK" << endl;
#endif
    cleanup();
    return true;
}

bool test_stack::push()
{
#ifdef _DEBUG
    cerr << "test_d_stack::push: ";
#endif

    for (int i = 0; i < 1000; ++i) {
        st.push(i);
        assert(st.top() == i);
    }

#ifdef _DEBUG
    cerr << "OK" << endl;
#endif
    
    cleanup();
    return true;
}

bool test_stack::pop()
{
#ifdef _DEBUG
    cerr << "test_stack::pop: ";
#endif
    
    try {
        st.pop();
        assert(true);
    }
    catch (...) {
        assert(false && "Неожиданное исключение при пустом стеке");
    }

    int n = 1000;
    for (int i = 0; i < n; ++i) 
        st.push(i);
    for (int i = n-1; i > 0; --i) {
        st.pop();
        assert(st.top() == i-1);
    }

#ifdef _DEBUG
    cerr << "OK" << endl;
#endif
    
    cleanup();
    return true;
}

bool test_stack::top()
{
#ifdef _DEBUG
    cerr << "test_stack::top: ";
#endif
    try {
        st.top();
        assert(false && "Ожидалось исключение при пустом стеке");
    }
    catch (...) {
        assert(true);
    }

    for (int i = 0; i < 1000; ++i) {
        st.push(i);
        assert(st.top() == i);
    }

#ifdef _DEBUG
    cerr << "OK" << endl;
#endif
    cleanup();
    return true;
}

bool test_stack::run()
{
    return is_empty() && push() &&
           pop() && top();
}

bool test_d_stack::run()
{
    d_stack st;
    test_stack test((stack&)st);
    return test.run();
}
