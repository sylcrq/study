#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>

#include "settings.h"

typedef struct _echo_client
{
    int fd;
    uint32_t ip;
    uint16_t port;
}echo_client;

int server_fd = -1;

//struct array to store incoming TCP connection
echo_client* clients[10] = {0};
uint16_t clients_num = 0;

void* thread_func(void* args)
{
    printf("[SERVER] # thread to accept connection\n");

    assert( server_fd > 0 );

    while(1)
    {
        struct sockaddr_in caddr;
        socklen_t caddrlen = sizeof(caddr);

        int fd = accept(server_fd, (struct sockaddr*)&caddr, &caddrlen);

        if(fd <= 0) {
            //printf("[SERVER] # accept:%d\n", fd);
            sleep(1);
            continue;
        }

        printf("[SERVER] # accept incoming TCP connection\n");

        //记录连入的连接
        echo_client* pclient = (echo_client*)malloc(sizeof(echo_client));
        memset(pclient, 0, sizeof(echo_client));

        pclient->fd   = fd;
        pclient->ip   = caddr.sin_addr.s_addr;
        pclient->port = ntohs(caddr.sin_port);

        printf("[SERVER] # fd: %d, %s:%d\n", fd, inet_ntoa(caddr.sin_addr), ntohs(caddr.sin_port));

        clients[clients_num] = pclient;
        clients_num++;
    }

    return NULL;
}

int main()
{
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0) {
        printf("[SERVER] # create socket failed\n");
        return -1;
    }

    //设置socket为非阻塞模式
    int v = fcntl(server_fd, F_GETFL, 0);
    if( fcntl(server_fd, F_SETFL, v|O_NONBLOCK) < 0 ) {
        printf("[SERVER] # fcntl failed\n");
        close(server_fd);
        return -1;
    }

    struct sockaddr_in saddr;
    memset(&saddr, 0, sizeof(saddr));

    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(ECHO_SERVER_PORT);

    if( bind(server_fd, (const struct sockaddr*)&saddr, sizeof(saddr)) < 0 ) {
        printf("[SERVER] # bind server addr failed\n");
        close(server_fd);
        return -1;
    }

    if( listen(server_fd, 10) < 0 ) {
        printf("[SERVER] # listen failed\n");
        close(server_fd);
        return -1;
    }

    printf("[SERVER] # waiting for connect...\n");

    pthread_t pid;
    pthread_attr_t attr;
    //create线程accept incoming TCP连接
    if( pthread_create(&pid, NULL, &thread_func, NULL) != 0) {
        printf("[SERVER] # create thread failed\n");
        close(server_fd);
        return -1;
    }

    while(1) 
    {
        //select
        fd_set rset; FD_ZERO(&rset);
        //fd_set wset; FD_ZERO(&wset);
        //fd_set eset; FD_ZERO(&eset);
        
        int maxfds = 0;

        struct timeval timeout;
        timeout.tv_sec  = 0;
        timeout.tv_usec = 100000; //100ms

        int ret = select(maxfds, &rset, &wset, &eset, &timeout);

        if(ret < 0) {
            printf("[SERVER] # select error!\n");
            break;
        }
        
        if(ret == 0)
            continue;

        
    }

    printf("[SERVER] # clear\n");

    //回收线程资源
    pthread_join(pid, NULL);

    //close client socket fd & free
    uint16_t i = 0;
    for(i=0; i<clients_num; i++) 
    {
        echo_client* p = clients[i];

        if(p) {
            close(p->fd);
            free(p);
            p = NULL;
        }
    }

    //close server fd
    close(server_fd);

    return 0;
}
