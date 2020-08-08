#include "myprocess.h"

void guerprocess()
{
    printf("guerprocess\n");
     pid_t pid = fork();
     //https://blog.csdn.net/kxjrzyk/article/details/81603049
     //fork函数创建两个相同或者不同的进程，在子进程中返回值为0，父进程中返回子进程的pid，如果创建失败返回负数

    if (pid < 0) 
    {
        perror("fork error;");
        exit(1);
    } 
    else if (pid == 0) 
    {
        sleep(5);
        printf ("子进程 : [ pid] = %d , 父进程 [ppid] = %d\n",getpid(),getppid());
        exit(0);

    } 
    else if (pid > 0) 
    {
        // wait(0);
        printf("parent process id %d\n",getpid());
        printf("我是父线程，我先退出一步~\n");
        exit(0);

    }
}
void jiangshiprocess()
{
    printf("jiangshiprocess\n");
    pid_t pid;
    // signal(SIGCHLD, SIG_LGN);
    pid = fork();
    if (pid < 0)
    {
        perror("fork error:");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("我是子进程，我要先退出一步了.\n");
        printf("子进程 id : %d\n" ,getpid());
        exit(0);
    } 
    else 
    {
         
        printf("我是父进程，我先睡2秒\n");
        printf("父进程 id : %d\n" ,getpid());
        sleep(2);
        while(2); //来个死循环，不退出的那种
    }
}