#include <stdio.h>

int f1(int a, int b, int c){
    if (a<b){
        return 50;
    } else {
        return 0;
    }
}
int f2(int a, int b, int c){
    if (a+b<c){
        return 150;
    } else {
        return 0;
    }
}
int f3(int a, int b, int c){
    if(a == c){
        return 100;
    } else {
        return 0;
    }
}
int f4(int a, int b, int c){
    if (a == b && a==c){
        return 300;
    } else{
        return 0;
    }
}
int main(){
int a, b, c;
    scanf("%d-%d-%d", &a, &b, &c);
    printf("%d", f1(a,b,c)+f2(a,b,c)+f3(a,b,c)+f4(a,b,c));
}