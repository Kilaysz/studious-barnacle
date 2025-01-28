#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Homework6_1(){
    srand((unsigned)time(NULL));
    int N, a[200000];
    N = rand()%(200001-5000)+5000;
    printf("%d\n", N);
    for(int i=0; i<N;i++){
        a[i]=rand()%(200001-5000)+5000;
        if(i<N-1){
        printf("%d ", a[i]);
        } else {
        printf("%d\n", a[i]);
        }
    }
    for (int i = N-1; i >= 0; i--){
        if(i!=0){
        printf("%d ", a[i]);
        } else {
        printf("%d", a[i]);        
        }
    }
    
}

void Homework6_2(){
    srand((unsigned)time(NULL));
    int N, a[200000], k, i = 0;
    N = rand()%(200001-5000)+5000;
    printf("%d\n", N);
    while(i<N-1){
        redo:
        k=rand()%N+1;        
        if(a[k-1]==1){
            goto redo;
        }
        if(i<N-2){
        printf("%d ", k);
        } else {
        printf("%d\n", k);
        }
        a[k-1]=1;
        i++;
    }
    for (int j = N-1; j >= 0; j--){
        if(a[j]==0){
            printf("%d", j+1);
            break;
        }    
    }

}


void Homework6_3(){
    srand((unsigned)time(NULL));
    long long int N, QueryTimes, a, c; 
    N = (rand()%50000)+50000;
    printf("%lld\n", N);
    long long int b[N+5], prefix_sum[N+5];
    for(int i = 1; i<=N; i++){
        b[i]=rand()%1000000000+1;
        if(i<N){
        printf("%lld ", b[i]);
        } else {
        printf("%lld\n", b[i]);
        }
        prefix_sum[i] = prefix_sum[i-1]+b[i];
    }
    QueryTimes = (rand()%50000)+50000;
    long long int result[QueryTimes+1];
    printf("%lld\n", QueryTimes);
    for(int i = 1;i<=QueryTimes;i++){ 
        redo:
        a = rand()%N+1;
        c = rand()%N+1;
        if(c<=a){
            goto redo;
        }         
        printf("%lld %lld\n", a, c);
        result[i]=prefix_sum[c]-prefix_sum[a-1];   
    }
    for(int i =1;i<=QueryTimes;i++){
        if(i<QueryTimes){
        printf("%lld\n", result[i]);
        } else {
        printf("%lld", result[i]);
        }
    }

}

void Homework6_4(){
    srand((unsigned)time(NULL));
    int row, column;
    row = rand()%(1001-500)+500;
    column = rand()%(1001-500)+500;
    printf("%d %d\n", row, column);
    int matrix[row+1][column+1];
    for(int i = 1;i<=row;i++){
        for(int j = 1; j<=column;j++){
        matrix[i][j]=rand()%(1001-500)+500;
        if(j!=column){
        printf("%d ", matrix[i][j]);
        } else {
        printf("%d\n", matrix[i][j]);
        }
        }
    }
    int a, b, c, d, temp;
    for(int i = 1;i<=5;i++){
        a = rand()%row+1;
        b = rand()%column+1;
        c = rand()%row+1;
        d = rand()%column+1;
        printf("%d %d %d %d\n", a, b, c, d);
        temp = matrix[c][d];
        matrix[c][d]=matrix[a][b];
        matrix[a][b]=temp;
    }
    for(int i = 1;i<=row;i++){
        for(int j = 1; j<=column;j++){
        if(j != column){
        printf("%d ", matrix[i][j]);
        } else {
        printf("%d", matrix[i][j]);
        }
        }
        if(i!=row){
        printf("\n");
        }
    }
}

int main(){
    int opt;
    scanf("%d", &opt);
    if(opt==1){
        Homework6_1();
    } else if(opt==2){
        Homework6_2();
    } else if(opt==3){
        Homework6_3();
    } else {
        Homework6_4();
    }
    return 0;
}