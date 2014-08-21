#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int g_fd;
struct in_addr g_addr;
char g_host[64];
char g_send_buffer[1024];
char g_recv_buffer[1024];
int g_ret_status;

int get_ret_status(void)
{
    return g_ret_status;
}

int open_http_connection(const char* host)
{
    if(!host) return -1;

    printf("open_http_connection: host=%s\n", host);

    if(inet_aton(host, &g_addr) == 0)
    {
        struct hostent* info = gethostbyname(host);
        if(!info)
        {
            printf("invalid host name\n");
            return -1;
        }
        else
        {
            memcpy(&g_addr, info->h_addr_list[0], sizeof(struct in_addr));
        }
    }

    strncpy(g_host, host, sizeof(g_host));

    g_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(g_fd < 0)
    {
        printf("create socket failed\n");
        return -1;
    }

    struct sockaddr_in addr;

    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = g_addr.s_addr;
    addr.sin_port = htons(80);

    if(connect(g_fd, (const struct sockaddr*)&addr, sizeof(struct sockaddr_in)) < 0)
    {
        printf("connect failed\n");
        return -1;
    }

    return 0;
}

void close_http_connection(void)
{
    if(g_fd > 0)
    {
        close(g_fd);
        g_fd = -1;
    }
}

int send_http_request(const char* method, const char* url)
{
    memset(g_send_buffer, 0, sizeof(g_send_buffer));

    // HTTP数据包
    snprintf(g_send_buffer, sizeof(g_send_buffer), "%s %s HTTP/1.1\r\nHost:%s\r\n\r\n", method, url, g_host);

    int send_buffer_size = strlen(g_send_buffer);

    const char* ptr = g_send_buffer;
    while(send_buffer_size > 0)
    {
        int n = send(g_fd, ptr, send_buffer_size, 0);

        if(n < 0)
        {
            printf("send_http_request failed\n");
            return -1;
        }

        send_buffer_size -= n;
        ptr += n;
    }

    return 0;
}

int process_recv_msg(const char* msg)
{
    char version[32] = {0};
    char status[32] = {0};
    int i = 0;

    //过滤空格
    while(*msg && *msg == ' ')
        msg++;

    while(*msg && *msg != ' ')
        version[i++] = *msg++;

    while(*msg && *msg == ' ')
        msg++;

    i = 0;
    while(*msg && *msg != ' ')
        status[i++] = *msg++;

    g_ret_status = atoi(status);

    printf("version = %s, status = %s(%d)\n", version, status, g_ret_status);

    return 0;
}

int wait(void)
{
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(g_fd, &rfds);

    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    int ret = select(g_fd+1, &rfds, NULL, NULL, &tv);
    if(ret < 0)
    {
        printf("select failed\n");
    }
    else if(ret == 0)
    {
        printf("select no data\n");
    }
    else if(FD_ISSET(g_fd, &rfds))
    {
        //char recv_buffer[1024] = {0};
        memset(g_recv_buffer, 0, sizeof(g_recv_buffer));

        int n = recv(g_fd, g_recv_buffer, sizeof(g_recv_buffer), 0);
        if(n < 0)
        {
            printf("recv failed\n");
            return -1;
        }

        process_recv_msg(g_recv_buffer);
    }

    return 0;
}


int main()
{
    //const char* host = "119.188.143.184";
    const char* url = "http://119.188.143.184/g?dt=1332&ov=4.3&ppid=&net=1&crshid=&k=20210202f5452f04d6d63114a334b6e8&v=5.6&tvid=&t=4&s=3&tt=2877&qyid=359478055577345&p=GPhone&sdkt=&crshmsg=&ua=SM-G7106&st=4&po=&qt=879&restype=";

    //int fd = open_http_connection(inet_addr(host), htons(80));

    //printf("open http connection: %d\n", fd);

    //send_http_request(fd, "GET", url);

    //wait(fd);

    //close_http_connection(fd);

    if(open_http_connection("119.188.143.184") == 0)
        printf("open_http_connection ok\n");

    send_http_request("GET", "xxx");

    wait();

    int retry = 2;

    while(get_ret_status() != 200 && retry > 0)
    {
        printf("test, %d\n", retry);

        close_http_connection();

        if( 0 == open_http_connection("119.188.143.184"))
            printf("open_http_connection ok\n");

        send_http_request("GET", "xxx");
        wait();

        retry--;
        printf("end, %d\n", retry);
    }

    close_http_connection();

    return 0;
}
