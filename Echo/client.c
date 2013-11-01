#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>

const char*    echo_server_ip   = "10.1.35.41";
const uint16_t echo_server_port = 8989;

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
    addr.sin_addr.s_addr = inet_addr(echo_server_ip);
    addr.sin_port = htons(echo_server_port);

    printf("[CLIENT] # connecting...\n");

    if(connect(fd, (const struct sockaddr*)&addr, sizeof(addr)) < 0) {
        printf("[CLIENT] # connect to %s:%d failed\n", "10.1.35.41", 8989);
        return -1;
    }

    printf("[CLIENT] # connect to %s:%d success\n", "10.1.35.41", 8989);

    while(1)
    {
        int n = send(fd, "hello world", 10, 0);
        printf("[CLIENT] # send %d bytes\n", n);
        sleep(5);
    }

    close(fd);

    return 0;
}
