#include<stdio.h>
#include<stdlib.h>
void calculeaza(int *vim1,int *vi,int n)
{
    vi[0]=1;
    vi[n]=1;
    for(int i=1;i<n;i++)
        vi[i]=vim1[i-1]+vim1[i];
}
int main()
{
    int n,k,*vim1,*vi;
    scanf("%d%d",&n,&k);
    vim1=malloc((n+1)*sizeof(int));
    vi=malloc((n+1)*sizeof(int));
    vim1[0]=1;
    for(int i=1;i<=n;i++){
        if(i%2==1)
            calculeaza(vim1,vi,i);
        else calculeaza(vi,vim1,i+1);
    }
    if(n%2==1)
        printf("%d\n",vi[k]);
    else
        printf("%d\n",vim1[k]);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main(){
        int i, *v, n, cap, nr;
        n = 0;
        cap = 5;
        v = (int*) malloc(cap * sizeof(int));
        scanf("%d", &nr);
        while (nr != 0 ) {
                if (cap == n) {
                        cap *= 2;
                        v = realloc(v, cap * sizeof(int));
                        }
                v[n++] = nr;            
                scanf("%d", &nr);
                }
        for(i = 0; i < n; i++)
                printf("%d ", v[i]);
        return 0;
}
