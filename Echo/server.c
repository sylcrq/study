#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

const char*    echo_server_ip   = "10.1.35.41";
const uint16_t echo_server_port = 8989;

int main()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0) {
        printf("[SERVER] # create socket failed\n");
        return -1;
    }

    int v = fcntl(fd, F_GETFL, 0);
    if( fcntl(fd, F_SETFL, v|O_NONBLOCK) < 0 ) {
        printf("[SERVER] # fcntl failed\n");
        return -1;
    }

    struct sockaddr_in saddr, caddr;
    memset(&saddr, 0, sizeof(saddr));
    memset(&caddr, 0, sizeof(caddr));

    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(echo_server_port);

    if( bind(fd, (const struct sockaddr*)&saddr, sizeof(saddr)) < 0 ) {
        printf("[SERVER] # bind server addr failed\n");
        return -1;
    }

    if( listen(fd, 10) < 0 ) {
        printf("[SERVER] # listen failed\n");
        return -1;
    }

    printf("[SERVER] # waiting for connect...\n");

#if 0
    pthread_create();

    socklen_t addrlen;
    int client = -1;

    while( (client = accept(fd, (struct sockaddr*)&caddr, &addrlen)) < 0 )
    {}

    printf("[SERVER] # incoming ip:%s, port:%d\n", inet_ntoa(caddr.sin_addr), ntohs(caddr.sin_port));

    char buffer[1024];

    while(1)
    {
        int n = recv(client, buffer, 1024, 0);
        printf("[SERVER] # recv %d bytes\n", n);

        sleep(1);
    }

    close(client);
#endif
    close(fd);

    return 0;
}
