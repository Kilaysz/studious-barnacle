#include <stdio.h>
#include <string.h>

void areAnagrams(char str1[], char str2[]) {
    int b=0, count[100];
    if(strlen(str1)!=strlen(str2)){
        printf("No");
        return;
    }
    for (int i = 0; i < strlen(str1); i++) {
        count[str1[i]-'a']++;
        count[str2[i]-'a']--;
    }
    for (int i = 0; i < strlen(str1); i++) {
        if(count[i]==0){
            b++;
        }
    }
    if(b == strlen(str1)){
        printf("Yes");
        return;
    } else {
        printf("No");
        return;
    }


}

int main() {
    char str1[100], str2[100];
    
    scanf("%s", str1);
    
    scanf("%s", str2);

    areAnagrams(str1, str2);

    return 0;
}