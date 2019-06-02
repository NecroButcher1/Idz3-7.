#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <iostream>
using namespace std;
#include "Stack.h"

/**
 * ставит "  " после и до заданного элемента
 *
 * @param tmp стек символов.
 * @return код ошибки: 0 - нет ошибок.
 * @return 1 - если стек пуст
 * @return 2 - если позиция задана не корректно
 */
 template<typename T>
unsigned Merge(stack<T> &tmp,int position) {
    unsigned out_value=0;
    if(tmp.empty())out_value=1;
    else{
        if((position<0)||(position>tmp.getSize()))out_value=2;
        else{
            stack<T> buff;
            T value;
            size_t i=0;
            while(i<position){
                tmp.pop(value);
                buff.push(value);
                i++;
            }
            tmp.push('"');
            buff.pop(value);
            tmp.push(value);
            tmp.push('"');
            while(!buff.empty()){
                buff.pop(value);
                tmp.push(value);
            }
        }
    }
    return out_value;
}

#endif // SORT_H_INCLUDED
