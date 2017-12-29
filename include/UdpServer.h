/*************************************************************************
   > File Name: include/UdpServer.h
   > Author: 范京凯
   > Mail: sunnyfjk@gmail.com
   > Created Time: 2017年12月29日 星期五 20时33分16秒
 ************************************************************************/

#ifndef _INCLUDE_UDPSERVER_H
#define _INCLUDE_UDPSERVER_H
#include <event.h>
#include <pthread.h>
#include <stdint.h>
#include <list.h>


struct EventBaseNode_t {
        pthread_t tid;
        int cout;
        struct event_bases *base;
        struct list_head node;
        struct sockaddr_in addr;
        int fd;
        void *arg;
};
struct UdpServer_t {
        int fd;
        int port;
        int baseCount;
        struct event_bases *base;
        struct event *signal_event;
        struct list_head root;
        pthread_attr_t attr;
};
void *EventBaseThrad(void *arg);

int UdpServerCreate(struct UdpServer_t *us);

void UdpServerColse(struct UdpServer_t *us);

void UdpServerRead(struct bufferevent *bev,void *arg);

void UdpServerWrite(struct bufferevent *bev,void *arg);

void UdpServerEvent(struct bufferevent *bev,short events,void *arg);

void UdpServerSignalEvent(evutil_socket_t sig, short events, void * arg);

#endif
