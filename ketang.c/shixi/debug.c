#include <stdio.h>
int main(){
int i, K1, K2, K3;
char b, c;
i = scanf("%d%d%d%c", &K1, &K2, &K3, &b); 
if (b!='\n'){
while ((c = getchar()) != '\n' && c != EOF);
}
printf("%d", i);
}