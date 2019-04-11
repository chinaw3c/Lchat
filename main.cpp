#include <iostream>
#include "socket/Server.h"

int main() {
    auto sock = new Socket();
    sock->connect();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}