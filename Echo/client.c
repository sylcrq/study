#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>

#include "settings.h"

int main()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0); 
    if(fd < 0)  {
        printf("[CLIENT] # create socket failed\n");
        return -1;
    }  

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ECHO_SERVER_IP_ADDR);
    addr.sin_port = htons(ECHO_SERVER_PORT);

    printf("[CLIENT] # connecting...\n");

    if(connect(fd, (const struct sockaddr*)&addr, sizeof(addr)) < 0) {
        printf("[CLIENT] # connect to %s:%d failed\n", inet_ntoa(addr.sin_addr), ECHO_SERVER_PORT);
        return -1;
    }

    printf("[CLIENT] # connect to %s:%d success\n", inet_ntoa(addr.sin_addr), ECHO_SERVER_PORT);

    char buffer[1024] = {0};

    while(1)
    {
        int n = send(fd, "hello world", strlen("hello world"), 0);
        printf("[CLIENT] # send %d bytes\n", n);
        int m = recv(fd, buffer, n, 0);
        printf("[CLIENT] # recv %d bytes, %s\n", m, buffer);
        sleep(5);
    }

    close(fd);

    return 0;
}
