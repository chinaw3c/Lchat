//
// Created by liuaotian on 19-4-12.
//

#include <iostream>
#include "Client.h"

int main(int args, char **argv){
    auto sock = new Client();
    sock->l_connect();



    return 0;
}

