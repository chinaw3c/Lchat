//
// Created by liuaotian on 19-4-11.
//

#ifndef LCHAT_SERVER_H
#define LCHAT_SERVER_H

#include <string>
#include <arpa/inet.h>
#include <vector>


//MAX listen number is 5
#define LISTEN_MAX_NUMBER 5

class Socket{
public:
    Socket() : addr(new std::string("0")), port(8888),
               listennum(LISTEN_MAX_NUMBER) {
        init();
    };
    Socket(char *addr_, int port_)
    : addr(new std::string(addr_)), port(port_), listennum(LISTEN_MAX_NUMBER) {
        init();
    };
    Socket(char *addr_, int port_, unsigned int listennum_)
    : addr(new std::string(addr_)), port(port_), listennum(listennum_) {
        init();
    };
    virtual ~Socket(){
        delete addr;
        for (auto i : addrs){
            delete i;
        }
    }


public:
    /*
     * create connect
     */
    void connect();
    inline void create();
    inline int GetListenNum();


public:


private:
    std::string * addr;
    int port;
    unsigned int listennum;
    struct sockaddr_in address;
    std::vector< struct sockaddr_in *> addrs;
    int sockfd;
    void SendRecvMsg(int client);
    std::vector< int > clientL;


private:
    void init();

};


#endif //LCHAT_SERVER_H
