#include <stdio.h>
#include <stdlib.h>
int n,m;
struct Table {
    char name[20];
    int transfertime;
    int arrivaltime;
}table[1000];
int find(char *name) {
    for(int i=1;i<=n;i++) {
        if(strcmp(table[i].name,name)) return i;
    }
    return -1;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s%d", table[i].name,&table[i].transfertime);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {

    }
    printf("\n");
    return 0;
}
