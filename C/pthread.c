#include<pthread.h>
#include<stdio.h>
int sum;
void* runner(void* param)
{
    int i,upper = atoi(param);
    sum  = 0;
    for(i=1;i<=upper;i++)
        sum += i;

    pthread_exit(0);
}

int main(int argc , int *argv[])
{
    pthread_t  pid ;
    pthread_attr_t attr;
    if(argc != 2)
    {
        printf("worng number of arguments");
        return -1;
    }
    if(atoi(argv[1])<0)
    {
        fprintf(stderr,"should enter a positive value");
        return -1;
    }
    pthread_attr_init(&attr);
    pthread_create(&pid,&attr,runner,argv[1]);
    pthread_join(pid,NULL);

    printf("Sum = %d",sum);
}

