//
// Лабораторная работа №15. Абстрактные типы данных. Стек
// test_stack.cpp
//
#include <cassert>
#include <iostream>
#include "test_stack.h"

using namespace std;

//
// TEST D_STACK
//

bool test_d_stack::is_empty()
{
#ifdef _DEBUG
    cerr << "test_d_stack::is_empty: ";
#endif
    d_stack st;
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
    return true;
}

bool test_d_stack::push()
{
#ifdef _DEBUG
    cerr << "test_d_stack::push: ";
#endif
    d_stack st;
    for (int i = 0; i < 1000; ++i) {
        st.push(i);
        assert(st.top() == i);
    }

#ifdef _DEBUG
    cerr << "OK" << endl;
#endif
    return true;
}

bool test_d_stack::pop()
{
#ifdef _DEBUG
    cerr << "test_stack::pop: ";
#endif
    d_stack st;
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
    return true;
}

bool test_d_stack::top()
{
#ifdef _DEBUG
    cerr << "test_stack::top: ";
#endif
    
    d_stack st;
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
    return true;
}

bool test_d_stack::run()
{
    test_d_stack t;
    return t.is_empty() && t.push() &&
           t.pop() && t.top();
}

//
// TEST L_STACK
//

test_l_stack::array_list test_l_stack::get_array_list(const initializer_list<stack::datatype>& data)
{
    array_list result = new l_stack::node[data.size()];
    
    int k=0;
    for (auto it = data.begin(); it!= data.end(); ++it)
    {
        result[k].data = *it;
        result[k].next = &result[k+1];
        k++;
    }
    result[data.size()-1].next = nullptr;
    
    return result;
}

bool test_l_stack::is_equal(l_stack::node *list1, l_stack::node* list2)
{
    if (list1 == list2)
        return true;
    while(list1 != nullptr && list2 != nullptr)
    {
        if (list1->data != list2->data)
            return false;
        list1 = list1->next;
        list2 = list2->next;
    }
    if (list1 != list2)
        return false;
    return true;
}
