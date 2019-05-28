#include <stdio.h>


int bitsUm (int n,int i) {
    i=1;
    while (n!=1 && n!=0) {
        if (n%2 == 1) i=i+1;
        n= n/2;
    }
    if (n==0) (i=0);
    return i;
}


int main () {
    int n;
    int i;
    scanf("%d",&n);
    printf("%d", bitsUm(n,i));

    return 0;
}