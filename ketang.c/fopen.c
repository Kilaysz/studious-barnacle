#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file = fopen("ha1o.txt", "r");
    const char *filename = "ha1o.txt";
char line[256]; 
    if(file==NULL){
        printf("無法打開檔案 %s\n", filename);
        return 1; // 返回非零值表示程式出錯
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
}