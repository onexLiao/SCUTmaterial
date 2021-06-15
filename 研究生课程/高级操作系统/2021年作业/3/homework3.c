//高级操作系统作业3
//多进程TCP服务器

//gcc -std=c17 -pthread homework3.c -o homework3

//参考
//https://www.cnblogs.com/Lune-Qiu/p/9426961.html
//https://baike.baidu.com/item/%E5%83%B5%E5%B0%B8%E8%BF%9B%E7%A8%8B

#include<errno.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<sys/wait.h>

const int WAITING_COUNT=20;
const uint16_t PORT=2333;

int fd;
int err=0;

void processError()
{
    err=errno;
    close(fd);
    fd=-1;
}
void init(uint16_t port)
{
    struct sockaddr_in addr={.sin_family=AF_INET,.sin_port=htons(port),.sin_addr.s_addr=htonl(INADDR_ANY)};
    /* memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_port=htons(port);
    addr.sin_addr.s_addr=htonl(INADDR_ANY); */
    fd=socket(addr.sin_family,SOCK_STREAM,IPPROTO_TCP);
    if(fd<0)processError();
    if(bind(fd,(struct sockaddr*)&addr,sizeof(addr))<0)processError();
    if(listen(fd,WAITING_COUNT)<0)processError();
}

int getLink()
{
    return accept(fd,NULL,NULL);
}

void treat(int skt)
{
    //处理连入的客户机
    const char HELLO_MSG[]="Hello, client!\n";
    const size_t BUF_SIZE=1024;
    char buf[BUF_SIZE];
    size_t rsize=send(skt,HELLO_MSG,sizeof(HELLO_MSG),0);
    size_t wsize=recv(skt,buf,BUF_SIZE,0);
    printf("Receive from client: %s\n",buf);
    close(skt);
}

int serve()
{
    int s;
    pid_t p;
    init(PORT);
    if(fd<0){
        printf("network error\n");
        return 1;
    }
    for(s=getLink();s>=0;s=getLink()){
        p=fork();
        if(p<0){
            printf("fork error\n");
            return 2;
        }else if(p==0){
            treat(s);
            return 0;
        }
    }
    close(fd);
    return 0;
}

int main()
{
    signal(SIGCHLD,SIG_IGN);
    return serve();
    /* pid_t chld=fork();
    if(chld<0){
        printf("fork error\n");
        return 2;
    }else if(chld==0){
        return serve();
    }
    getchar();
    kill(chld,SIGTERM);
    return 0; */
}
