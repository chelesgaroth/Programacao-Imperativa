#include <stdio.h>

int main() {
    int x,med,i;
    med=0;
    i=0;
    scanf ("%d",&x);
    while (x !=0) {
        med =  med + x;
        i=i+1;
        scanf ("%d",&x);
    }
    med = med/i;
    printf("%d", med);
    return 0;
}