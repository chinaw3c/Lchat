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
#include <cstring>
#include <vector>
#include <algorithm>
#include "Server.h"
#include "../tools/VectorRemove.h"



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
    //out log
    cout << "INFO [+] create socket success." << endl;

    //create socket address
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, addr->c_str(), &address.sin_addr);
    address.sin_port = htons(port);
    int ret = bind(sockfd, (struct sockaddr *)&address, sizeof(address));
    if (ret == -1){
        cerr << "INFO [-] Error in function init->bind" << "\tline"
        << __LINE__ << endl;
        exit(1);
    }
    //out log
    cout << "INFO [+] bind sockfd success" << endl;
    cout << "INFO [+] listen port " << port << endl;
    cout << "INFO [+] listen ip " << *addr << endl;
}


inline int Socket::GetListenNum() {
    //show listens number
    return clientL.size();
}

void Socket::connect(){
    /*
     * create connect
     */

    listen(sockfd, listennum);
    struct sockaddr_in client;
    bzero(&client, sizeof(client));
    socklen_t client_addrlength = sizeof(client);
    while (true){
        int connfd = accept(sockfd, (struct sockaddr *)&client,
                            &client_addrlength);
        if (clientL.size() + 1 > listennum){
            /*
             * 如果超过最大数，就拒绝连接
             */
            close(connfd);
            continue;
        }
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
            cout << "INFO [+] " << connfd << "-连接成功" << endl;
            clientL.push_back(connfd);
            //打印连接后的客户端信息
            cout << "INFO [*] 连接数：" << clientL.size() << endl;
            thread one(&Socket::SendRecvMsg, this, connfd);
            one.detach();
        }
    }
}


void Socket::SendRecvMsg(int client) {
    // 收发消息
    char msg[1024] = {0};
    while(true){
        bzero(msg, sizeof(msg));
        read(client, &msg, sizeof(msg));
        char quit[] = {"q"};
        if (strcmp(msg, quit) == 0){
            cout << "退出一位杰出的少年" << endl;
            strcpy(msg, "退出一位杰出的少年");
            for (auto i : clientL){
                write(i, msg, sizeof(msg));
            }
            int ret = close(client);
            if (ret == -1){
                cerr << "Error close" << "\tline:" << __LINE__ << endl;
            }
            clientL.erase(std::remove(clientL.begin(), clientL.end(), client), clientL.end());

            cout << "INFO [-] 连接数-1" << endl;
            cout << "INFO [*] 连接数：" << clientL.size() << endl;
            return;
        }
        for (auto i : clientL){
            if (i == client){
                continue;
            }
            write(i, msg, sizeof(msg));
        }
    }
}
