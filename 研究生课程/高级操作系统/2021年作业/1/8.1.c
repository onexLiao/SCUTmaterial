//Program 8.1: fork()

/*
运行命令：
./8.1
./8.1 > temp.out
cat temp.out
以上运行结果不同，猜测是因为输出为文件时没有清空缓冲区，导致fork时把缓冲区的数据复制了。
*/

#include<sys/types.h>
#include"apue.h"

int glob = 6;/* external variable in initialized data */
char buf[] = "a write to stdout\n";
int main(void) {
    int var;/* automatic variable on the stack */
    pid_t pid;
    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
        err_sys("write error");
    printf("before fork\n");/* we don't flush stdout */
    //添加了清空缓冲区的操作后运行结果一致
    //fflush(stdout);
    if ( (pid = fork()) < 0)err_sys("fork error");
    else if (pid == 0) {/* child */
        glob++;/* modify variables */
        var++;
    } else
    sleep(2);/* parent */
    printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
    //exit(0)
    _exit(0);
}
