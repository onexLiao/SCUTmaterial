//高级操作系统作业3

//TCP客户端（测试用）

//gcc -std=gnu17 -pthread client.c -o client

//参考 https://blog.csdn.net/earbao/article/details/16114943

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>

int err=0;

int processError(int fd)
{
    err=errno;
    close(fd);
    return -1;
}
int mylink(struct sockaddr*saddr,size_t saddr_len)
{
    int skt=socket(saddr->sa_family,SOCK_STREAM,IPPROTO_TCP);
    if(skt<0)return processError(skt);
    if(connect(skt,saddr,saddr_len)<0)return processError(skt);
    return skt;
}

int linkByIp(const char*ip,uint16_t port)
{
    struct sockaddr_in addr={.sin_family=AF_INET,.sin_port=htons(port)};
    /* memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_port=htons(port); */
    if(inet_pton(AF_INET,ip,&addr.sin_addr)!=1)return -1;
    return mylink((struct sockaddr*)&addr,sizeof(addr));
}

int linkByName(const char*name,uint16_t port)
{
    struct addrinfo sinfo={.ai_flags=AI_ADDRCONFIG,.ai_family=AF_INET,.ai_socktype=SOCK_STREAM};
    struct addrinfo*rinfo=NULL;
    /* memset(&sinfo,0,sizeof(sinfo));
    sinfo.ai_flags=AI_ADDRCONFIG;
    sinfo.ai_family=AF_INET;
    sinfo.ai_socktype=SOCK_STREAM; */
    int e=getaddrinfo(name,NULL,&sinfo,&rinfo);
    if(e!=0){
        printf("%s\n",gai_strerror(e));
        return -1;
    }
    ((struct sockaddr_in*)(rinfo->ai_addr))->sin_port=htons(port);
    int s=mylink(rinfo->ai_addr,rinfo->ai_addrlen);
    freeaddrinfo(rinfo);
    return s;
}

void request(int skt)
{
    const char HELLO_MSG[]="Hello, server!\n";
    const size_t BUF_SIZE=1024;
    char buf[BUF_SIZE];
    send(skt,HELLO_MSG,sizeof(HELLO_MSG),0);
    recv(skt,buf,BUF_SIZE,0);
    printf("Receive from server: %s\n",buf);
    close(skt);
}

int main()
{
    const char HOST[]="localhost";
    const uint16_t PORT=2333;
    int s=linkByName(HOST,PORT);
    if(s<0){
        printf("network error: %s\n",strerror(err));
        return 1;
    }
    request(s);
    return 0;
}
