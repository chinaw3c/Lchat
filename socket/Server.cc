//
// Created by liuaotian on 19-4-11.
//

/**
 * 描述:
 *      来自刘傲天
 * @author liuaotian
 * @create 2019-04-11 下午1:56
 */
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include <zconf.h>
#include <thread>
#include "Server.h"

using namespace std;

void Socket::init() {
    /*
     * init sockfd and address
     */
    sockfd = 0;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd <= 0){
        cerr << "INFO [-] Error in function init." << "\tline"
        << __LINE__ << endl;
        exit(1);
    }

    //create socket address
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    //int ret = inet_pton(AF_INET, addr->c_str(), &address.sin_addr);
    inet_pton(AF_INET, "0.0.0.0", &address.sin_addr);
    address.sin_port = htons(port);
    int ret = bind(sockfd, (struct sockaddr *)&address, sizeof(address));
    if (ret == -1){
        cerr << "INFO [-] Error in function init->bind" << "\tline"
        << __LINE__ << endl;
        exit(1);
    }
}


inline void Socket::create(){
    //create address
    addrs.push_back(new struct sockaddr_in);
}


inline int Socket::GetListenNum() {
    //show listens number
    return addrs.size();
}

void Socket::connect(){
    /*
     * create connect
     */

    listen(sockfd, LISTEN_MAX_NUMBER);
    struct sockaddr_in client;
    socklen_t client_addrlength = sizeof(client);
    while (true){
        int connfd = accept(sockfd, (struct sockaddr *)&client,
                            &client_addrlength);
        if (connfd < 0){
            cerr << "INFO [-] Error in function connect->accept"
                 << "\tline:"
                 << __LINE__
                 << "Error code:"
                 << errno
                 << endl;
            exit(2);
        }
        else{
            //打印连接后的客户端信息
            clientL.push_back(connfd);
            cout << "连接数:" << clientL.size() << endl;
            thread one(&Socket::SendRecvMsg, this, connfd);
            one.detach();
        }
    }
}


void Socket::SendRecvMsg(int client) {
    // 收发消息
    char msg[1024] = {0};
    while(true){
        read(client, &msg, sizeof(msg));
        for (auto i : this->clientL){
            write(i, msg, sizeof(msg));
        }
    }
}
