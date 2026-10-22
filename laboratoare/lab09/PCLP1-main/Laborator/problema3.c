#include<stdio.h>
#include<time.h>
#include<string.h>
char* timestr(struct tm t,char* time)
{
    char aux[3];
    sprintf(aux,"%02d",t.tm_hour);
    strcat(time,aux);
    strcat(time,":");
    sprintf(aux,"%02d",t.tm_min);
    strcat(time,aux);
    strcat(time,":");
    sprintf(aux,"%02d",t.tm_sec);
    strcat(time,aux);
    return time;
}
int main()
{
    time_t timp=time(NULL);
    struct tm *timpStruct=localtime(&timp);
    char time[10];
    timestr(*timpStruct,time);
    printf("%s\n",time);
    return 0;
}