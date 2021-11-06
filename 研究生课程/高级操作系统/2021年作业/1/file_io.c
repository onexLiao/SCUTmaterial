//复制文件
//编译命令：gcc -std=c17 -Ofast file_io.c -o file_io
//运行命令示例：./file_io 1 bazelisk bazelisk.bak

//参考
//https://baike.baidu.com/item/fread
//https://blog.csdn.net/rikeyone/article/details/95970499

#include<stdio.h>
#include<stdlib.h>

int main(int argc,char*argv[])
{
    if(argc!=4){
        printf("wrong number of args\n");
        return 1;
    }
    size_t buffersize=atol(argv[1]);
    void*buffer=malloc(buffersize);
    char*inbuf=malloc(buffersize);
    char*outbuf=malloc(buffersize);
    FILE*inFile=fopen(argv[2],"rb");
    FILE*outFile=fopen(argv[3],"wb");
    setvbuf(inFile,inbuf,_IOFBF,buffersize);
    setvbuf(outFile,outbuf,_IOFBF,buffersize);
    size_t s=buffersize;
    while(s==buffersize){
        s=fread(buffer,1,buffersize,inFile);
        fwrite(buffer,s,1,outFile);
    }
    fclose(inFile);
    fclose(outFile);
    free(buffer);
    free(inbuf);
    free(outbuf);
    return 0;
}
