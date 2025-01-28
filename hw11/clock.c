#include<stdlib.h>
#include<stdio.h>

unsigned long long int begin,end;

unsigned long long int rdtsc()//32-bit
{
	unsigned long long int x;
	asm   volatile ("rdtsc" : "=A" (x));
	return x;
}

int main(){
	FILE* file = fopen("./hw11.c", "r");
	FILE* file2= fopen("./inserted_prefixes.txt", "r");

	begin = rdtsc();
	end = rdtsc();
	
	printf("Execute cycles %llu \n",(end-begin));
}