#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cauta(int nr,char **cuvinte,char *c)
{
    for(int i=0;i<nr;i++){
        if(strcmp(cuvinte[i],c)==0)
            return i;
    }
    return -1;
}
void adauga(int *nr,char **cuvinte, char *c, int *v,int *cap)
{
    if(*nr==*cap){
        v=realloc(v,2*sizeof(v));
        cuvinte=realloc(cuvinte,2*sizeof(cuvinte));
        for(int i=*cap;i<2*(*cap);i++)
            cuvinte[i]=(char*)malloc(19*sizeof(char));
            (*cap)*=2;
    }
    (*nr)++;
    v[*nr-1]=1;
    strcpy(cuvinte[*nr-1],c);
}
int main()
{
    int n,*v,nr,cap;
    char c[19],**cuvinte;
    nr=0;
    cap=2;
    v=(int*)malloc(cap*sizeof(int));
    scanf("%d ",&n);
    cuvinte=(char**)malloc(cap*sizeof(char*));
    for(int i=0;i<cap;i++)
        cuvinte[i]=(char*)malloc(19*sizeof(char));
    for(int i=0;i<n;i++){
        scanf("%s",c);
        int x=cauta(nr,cuvinte,c);
        if(x!=-1)
             v[x]++;
        else
            adauga(&nr,cuvinte,c,v,&cap);
    }
    for(int i=0;i<nr;i++){
        printf("%s %d\n",cuvinte[i],v[i]);
    }
    return 0;
}