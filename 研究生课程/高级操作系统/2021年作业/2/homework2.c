//第2次课堂作业

//启动线程计算2*N

#include<stdio.h>
#include<pthread.h>

void*calculate(void*ptr_n)
{
    printf("%d\n",2*(*(int*)ptr_n));
    return NULL;
}

int main()
{
    int n;
    pthread_t th;
    while(scanf("%d",&n)!=EOF){
        if(pthread_create(&th,NULL,calculate,&n)!=0){
            printf("pthread error\n");
            return 1;
        }
        pthread_join(th,NULL);
    }
    return 0;
}
