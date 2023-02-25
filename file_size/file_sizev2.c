#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[]){
	if (argc!=2){
		printf("Invalid usage\nSee file_size help");
		return 0;
	}
	if (strcmp(argv[1],"help")){
		FILE *fp;
		if((fp =fopen(argv[1],"r"))==NULL){
			printf("FILE cannot be accessed\n");
			return 1;
		}
		fseek(fp,0,SEEK_END);
		int size=ftell(fp)*sizeof(char);
//		long long int size_bits=size*8;
		fclose(fp);
//		printf("Size of the file is %d bytes or %Ld bits",size,size_bits);
		printf("Size of the file is %d bytes",size);
	}
	else{
		printf("Usage:\nfile_size <filename>\nReturns size of the file given as a command line argument\nSource Code:\n");
		FILE *fp;
		if((fp =fopen(__FILE__,"r"))==NULL){
			printf("FILE cannot be accessed\n");
			return 1;
		}
		while (!feof(fp)){
			char ch;
			ch=fgetc(fp);
			fputc(ch,stdout);
		}
		fclose(fp);
	}
	return 0;
}