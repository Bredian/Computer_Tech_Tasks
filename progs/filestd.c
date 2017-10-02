#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
	FILE * in = fopen("in.txt","r");
    if(in==NULL){
        perror("in.txt error");
        exit(-1);
    }
	FILE * out = fopen("out.txt","w+");
    if(out==NULL){
        perror("out.txt error");
        exit(-2);
    }
    char symbol;
	while(feof(in)==0){
		
		if(symbol>='a' && symbol<='z'){
			symbol=toupper(symbol);
			fprintf(out,"%c",symbol);
		}
		else fprintf(out,"%c",symbol);
		symbol=fgetc(in);
	}
	fclose(in);
	fclose(out);
	return 0;
}
