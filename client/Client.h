//
// Created by liuaotian on 19-4-12.
//

#ifndef LCHAT_CLIENT_H
#define LCHAT_CLIENT_H


#include <vector>
#include <string>
#include <arpa/inet.h>

class Client {
public:
    Client() : port(8888), ip(new std::string("127.0.0.1")){
        init();
    };
    Client(int port_) : port(port_), ip(new std::string("127.0.0.1")){
        init();
    };
    Client(int port_, char *ip)
    : port(port_), ip(new std::string(ip)){
        init();
    };
    ~Client(){
        delete(ip);
    }

public:
    void init();
    void l_connect();
    void SendRecvMsg();
    void SendMsg();
    void RecvMsg();

public:
    int socks;
    struct sockaddr_in server_addr;
    int port;
    std::string *ip;


};


#endif //LCHAT_CLIENT_H
