/*************************************************************************
   > File Name: source/UdpServer.c
   > Author: 范京凯
   > Mail: sunnyfjk@gmail.com
   > Created Time: 2017年12月29日 星期五 20时33分16秒
 ************************************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <event2/thread.h>
#include <UdpServer.h>


void *EventBaseThrad(void *arg)
{

        return NULL;
}

int UdpServerCreate(struct UdpServer_t *us)
{
        struct sockaddr_in addr;
        int ret=0;
        evthread_use_pthreads();

        addr.sin_port=htons(us->port);
        addr.sin_family=AF_INET;
        inet_pton(AF_INET,"0.0.0.0",&addr.sin_addr);
        us->base=event_base_new();
        if(us->base==NULL) {
                ret=-1;
                goto event_base_new_err;
        }

        return 0;
event_base_new_err:
        return ret;
}

void UdpServerColse(struct UdpServer_t *us)
{

}

void UdpServerRead(struct bufferevent *bev,void *arg)
{

}

void UdpServerWrite(struct bufferevent *bev,void *arg)
{

}

void UdpServerEvent(struct bufferevent *bev,short events,void *arg)
{

}

void UdpServerSignalEvent(evutil_socket_t sig, short events, void * arg)
{

}
