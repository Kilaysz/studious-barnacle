#include <stdio.h>

int gcf(int a, int b){
    int i,j,k;
    if (a>b){
        i = b;
        j = a;
    } else{
        i = a;
        j = b;
    }
    for(k=i;k>=1;k--){
        if(i%k==0 && j%k==0){
            return k;
            break;
        }   
    }
}

int main(){
    int num1, num2, dem1, dem2;
    scanf("%d/%d+%d/%d", &num1, &dem1, &num2, &dem2);
    int result_num, result_dem, resnum_sim, resdem_sim;
    result_num = dem2*num1+dem1*num2; 
    result_dem = dem1*dem2; 
    resnum_sim = result_num/gcf(result_num, result_dem);
    resdem_sim = result_dem/gcf(result_num, result_dem);
    if(resnum_sim<resdem_sim){
        printf("%d/%d", resnum_sim, resdem_sim); 
    } else if (resnum_sim>resdem_sim){
        int x, y;
        x = resnum_sim/resdem_sim;
        y = resnum_sim%resdem_sim;
        printf("%d %d/%d", x, y, resdem_sim);
    } else {
        printf("1");
    }
}