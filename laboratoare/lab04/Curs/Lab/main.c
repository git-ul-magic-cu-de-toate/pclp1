#include <stdio.h>
#include "autentificare.h"

int main(void)
{
    int username, password;

    scanf("%d%d", &username, &password);
    
    login(username, password);    
    
    return 0;
}