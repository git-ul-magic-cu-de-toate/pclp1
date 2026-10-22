#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int *v,cap,n;
} vector;

void init_vector(vector *a,int nr){
    a->cap=nr;
    a->v=malloc(nr*sizeof(int));
    a->n=0;
}
void adauga_vector(vector *a,int n){
    if(a->cap==a->n){
        a->v=realloc(a->v,2*a->cap*sizeof(int));
        (a->cap)*=2;
    }
    a->n++;
    a->v[a->n-1]=n;
}
void scrie_vector(vector a){
    for(int i=0;i<a.n;i++){
        printf("%d ",a.v[i]);
    }
    printf("\n");
}
int main()
{
    vector vec;
    init_vector(&vec,10);
    for(int i=0;i<=100;i++){
        adauga_vector(&vec,i);
        scrie_vector(vec);
    }
    return 0;
}