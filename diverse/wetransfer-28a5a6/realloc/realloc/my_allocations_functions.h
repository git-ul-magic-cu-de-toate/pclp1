#ifndef __MY_ALLOCATIONS_FUNCTIONS
#define __MY_ALLOCATIONS_FUNCTIONS

void *my_malloc(size_t dim) {
    dim += sizeof(size_t);
    void *p = malloc(dim * sizeof(char));
    *(int *) p = dim;
    return (void *)((int *)p + 1);
}

void *my_calloc(size_t dim) {
    dim += sizeof(size_t);
    void *p = malloc(dim * sizeof(char));
    *(int *) p = dim;
    
    size_t i;
    for (i = 1; i <= dim; i++) {
    	*((char *)p+i) = 0;
    }
    return (void *)((int *)p + 1);
}
void my_free(void *p) {
    p = (void *)((int *)p - 1);
    free(p);
}


int  get_size(void *p) {
    return * ((int *)p - 1);
}

void my_realloc(void  *p, int dim) {
    int old = get_size(p);
    char *v = (char *)my_malloc(old * sizeof(char));
    memcpy(v, p, old);
    p = (void *) my_malloc (dim * sizeof(char));
    memcpy(p, v, old);
}


#endif /* __MY_ALLOCATIONS_FUNCTIONS */