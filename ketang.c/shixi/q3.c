#include <stdio.h>
#include <time.h>

int ans[8], used[9];    
void solve(int cnt){
    if(cnt==8){
        for(int i=0;i<8;i++) printf("%d ", ans[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=8;i++){ 
        if(used[i]==0){ 
            ans[cnt]=i; 
            used[i]=1;
            solve(cnt+1); 
            used[i]=0;
        } 
    }
}

int main(){
    solve(0);
}