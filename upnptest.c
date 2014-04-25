#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "miniupnpc.h"
#include "upnpcommands.h"

struct UPNPDev*  g_devlist = NULL;
struct UPNPUrls* g_urls    = NULL;
struct IGDdatas* g_data    = NULL;

char g_lanaddr[16] = {0};

//forward declaration
int SetUp(void);
int TearDown(void);
int GetPortMappingNum(void);  //not supported by all routers
int GetPortMappingByIndex(unsigned int index);
int GetPortMapping(unsigned int extPort, const char* protocol);
int AddPortMapping(unsigned int extPort, unsigned int intPort, const char* protocol, const char* intClient);



int SetUp(void)
{
    int error = 0;
    g_devlist = upnpDiscover(1000, NULL, NULL, 0, 0, &error);

    if(!g_devlist)
    {
        printf("no upnp device list\n");
        return -1;
    }

    g_urls = (struct UPNPUrls*)malloc(sizeof(struct UPNPUrls));
    g_data = (struct IGDdatas*)malloc(sizeof(struct IGDdatas));
    if(!g_urls || !g_data)
    {
        printf("malloc failed\n");
        return -1;
    }
    memset(g_urls, 0, sizeof(struct UPNPUrls));
    memset(g_data, 0, sizeof(struct IGDdatas));

    int result = UPNP_GetValidIGD(g_devlist, g_urls, g_data, g_lanaddr, sizeof(g_lanaddr));

    if(result == 1)
    {
        printf("%d, %s\n", result, g_urls->controlURL);
    }
    else if(result == 2)
    {
        printf("%d, %s\n", result, g_urls->controlURL);
    }
    else if(result == 3)
    {
        printf("%d, %s\n", result, g_urls->controlURL);
    }
    else
    {
        printf("no valid IGD\n");
        return -1;
    }

    printf("local address: %s\n", g_lanaddr);

    return 0;
}

int TearDown(void)
{
    if(g_urls)
    {
        free(g_urls);
        g_urls = NULL;
    }
    if(g_data)
    {
        free(g_data);
        g_data = NULL;
    }
    if(g_devlist)
    {
        freeUPNPDevlist(g_devlist);
        g_devlist = NULL;
    }

    return 0;
}

int AddPortMapping(unsigned int extPort, unsigned int intPort, const char* protocol, const char* intClient)
{
    char myextPort[6]      = {0};
    char myintPort[6]      = {0};
    char desc[80]          = {0};
    char leaseDuration[16] = {0};

    sprintf(myextPort, "%d", extPort);
    sprintf(myintPort, "%d", intPort);
    sprintf(desc, "%s", "my_upnp_test");
    sprintf(leaseDuration, "%d", 0);

    printf("***extPort:%s, intPort:%s, %s, %s***\n", myextPort, myintPort, intClient, protocol);
    printf("***%s, %s***\n", desc, leaseDuration);

    int result = UPNP_AddPortMapping(g_urls->controlURL, g_data->first.servicetype, 
                                     myextPort, myintPort, intClient, desc, protocol, NULL, leaseDuration);

    if(0 == result)
    {
        printf("add port mapping ok\n");
    }
    else
    {
        printf("add port mapping failed: %d\n", result);
    }

    return 0;
}

int DeletePortMapping()
{
    return 0;
}

//not supported by all routers
int GetPortMappingNum(void)
{
    unsigned int num = 0;
    if(0 == UPNP_GetPortMappingNumberOfEntries(g_urls->controlURL, g_data->first.servicetype, &num))
    {
        printf("current port mapping num = %d\n", num);
    }
    else
    {
        printf("get port mapping num failed\n");
    }
    return 0;
}

int GetPortMappingByIndex(unsigned int index)
{
    char myindex[8]    = {0};  //IN
    sprintf(myindex, "%d", index);

    printf("***%s***\n", myindex);

    char extPort[6]    = {0};  //OUT
    char intClient[16] = {0};  //OUT
    char intPort[6]    = {0};  //OUT
    char protocol[4]   = {0};  //OUT
    char desc[80]      = {0};  //OUT
    char enabled[4]    = {0};  //OUT
    char rHost[64]     = {0};  //OUT
    char duration[16]  = {0};  //OUT

    int result = UPNP_GetGenericPortMappingEntry(g_urls->controlURL, g_data->first.servicetype, 
                                                 myindex, 
                                                 extPort, intClient, intPort, protocol, desc, enabled, rHost, duration);
    if(0 == result)
    {
        printf("extPort:%s, intPort:%s, %s, %s\n", extPort, intPort, intClient, protocol);
        printf("%s, %s, duration:%s, rHost:%s\n", desc, enabled ? "enabled" : "disabled", duration, rHost);
    }
    else
    {
        printf("get port mapping index %d failed\n", index);
    }

    return 0;
}

int GetPortMapping(unsigned int extPort, const char* protocol)
{
    char myextPort[6] = {0};  //IN
    sprintf(myextPort, "%d", extPort);
    printf("***%s, %s***\n", myextPort, protocol);

    char intClient[16]     = {0};  //OUT
    char intPort[6]        = {0};  //OUT
    char desc[80]          = {0};  //OUT
    char enabled[4]        = {0};  //OUT
    char leaseDuration[16] = {0};  //OUT

    int result = UPNP_GetSpecificPortMappingEntry(g_urls->controlURL, g_data->first.servicetype, 
                                                  myextPort, protocol, NULL, 
                                                  intClient, intPort, desc, enabled, leaseDuration);
    if(0 == result)
    {
        printf("extPort:%s, intPort:%s, %s, %s\n", myextPort, intPort, intClient, protocol);
        printf("%s, %s, duration:%s\n", desc, enabled ? "enabled" : "disabled", leaseDuration);
    }
    else
    {
        printf("get port mapping[%s, %s] failed: %d\n", myextPort, protocol, result);
    }

    return 0;
}

int main()
{
    printf("hello world\n");

    if(SetUp() < 0)
    { 
        TearDown();
        return -1;
    }

    GetPortMappingNum();

    //int i = 0;
    //for(i=0; i<30; i++)
    //{
    //    GetPortMappingByIndex(i);
    //}

    GetPortMapping(16738, "TCP");
    GetPortMapping(16738, "UDP");

    AddPortMapping(16738, 16738, "TCP", g_lanaddr);
    AddPortMapping(16738, 16738, "UDP", g_lanaddr);
    AddPortMapping(16738, 16738, "TCP", "192.168.1.120");
    AddPortMapping(16738, 16738, "UDP", "192.168.1.120");

    TearDown();

    return 0;
}
