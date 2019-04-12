//
// Created by liuaotian on 19-4-12.
//

/**
 * 描述:
 *      来自刘傲天
 * @author liuaotian
 * @create 2019-04-12 上午10:56
 */
#include "Client.h"
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <zconf.h>
#include <thread>


using namespace std;


void Client::init() {
    /*
     * 初始化信息
     */
    socks = 0;
    //服务器信息绑定
    bzero((struct sockaddr_in *)&server_addr, sizeof(server_addr));
    cout << "INFO [+] create server addr success" << endl;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip->c_str());
    //server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

}


void Client::l_connect() {
    /*
     * 创建连接
     */
    socks = socket(AF_INET, SOCK_STREAM, 0);
    if (socks < 0){
        cerr << "Error socks" << endl;
    }
    int ret = connect(socks, (struct sockaddr*)&server_addr,
                      sizeof(server_addr));
    if (ret != 0){
        cerr << "INFO [-] Error in function l_connect "
             << "line:"
             << __LINE__
             << "\tError code is :"
             << errno
             << endl;
        exit(3);
    }
    SendRecvMsg();
    close(socks);
}


void Client::SendRecvMsg() {
    /*
     * 处理发送和接收消息的逻辑
     */
    thread t1(&Client::SendMsg, this);
    thread t2(&Client::RecvMsg, this);
    t1.join();
    t2.join();
}


void Client::SendMsg() {
    /*
     * 发送消息
     */
    char msg[1024] = {0};
    while(1){
        cout << ">>>";
        cin >> msg;
        write(socks, msg, sizeof(msg));
        bzero(msg, sizeof(msg));
    }

}


void Client::RecvMsg() {
    /*
     * 接收消息
     */
    char msg[1024] = {0};
    while(1){
        int ret = read(socks, msg, sizeof(msg));
        if (ret == 0){
            cout << "服务端断开连接" << endl;
            //close(socks);
            exit(0);
        }
        cout << "接收:" << msg << endl;
    }
}