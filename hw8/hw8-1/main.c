#include <stdio.h>
#include <stdlib.h>
#include "hw8-1.h"

int main(){
    int*** mp;
    mp = (int***)malloc( 130 * sizeof(int**) );
    
    init(mp);

    int q = 1000;
    while(q--){
        int opt;
        scanf("%d",&opt);
        if( opt == 1 )
        {
            char str[4] = {};
            int val;

            scanf("%s %d",str,&val);

            int* pos = &(mp[str[0]][str[1]][str[2]]);
            modify(pos,val);
        }
        else
        {
            char a[4],b[4];
            scanf("%s %s",a,b);
            int check = query(&mp,a,b);

            printf( ( check == 1 ? "YES\n" : "NO\n" )  );
        }
    }

    return 0;
}