#ifndef LCHAT_REMOVEVECTOR_H__
#define LCHAT_REMOVEVECTOR_H__

#include <vector>
#include <iostream>


//判断data存不存在于number里，如果存在就删除
template<typename T, typename T_1>
int RemoveVector(T number, T_1 data){
    int ret = 0;

    auto ite = number.begin();
    while(ite != number.end()){
        if (*ite == data){
            ite = number.erase(ite);
        }
        ++ite;
    }
    return ret;
}


#endif
