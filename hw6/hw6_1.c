#include <stdio.h>

void Homework6_1(){
    int N, a[200000];
    scanf("%d", &N);
    for(int i=0; i<N;i++){
        scanf("%d", &a[i]);
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
    int N, a[200000], k;
    scanf("%d", &N);
    for(int i=0;i<N-1;i++){
        scanf("%d", &k);
        a[k-1]=1;
    }
    for (int j = N-1; j >= 0; j--){
        if(a[j]==0){
            printf("%d", j+1);
            break;
        }    
    }

}


void Homework6_3(){
    int N; 
    scanf("%d", &N);
    long long int b[N+1], QueryTimes, a, c, prefix_sum[N+1];
    for(int i = 1; i<=N; i++){
        scanf("%lld", &b[i]);
        prefix_sum[i] = prefix_sum[i-1]+b[i];
    }
    scanf("%lld", &QueryTimes);
    long long int result[QueryTimes+1];
    for(int i = 1;i<=QueryTimes;i++){ 
        scanf("%lld %lld", &a, &c);
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
    int row, column;
    scanf("%d %d", &row, &column);
    int matrix[row+1][column+1];
    for(int i = 1;i<=row;i++){
        for(int j = 1; j<=column;j++){
        scanf("%d", &matrix[i][j]);
        }
    }
    int a, b, c, d, temp;
    for(int i = 1;i<=5;i++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
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