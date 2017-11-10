#include<stdio.h>
#include<stdlib.h>

int main(int args,char *argv[]) {
int count = 0;
int c,b;
char ch;
FILE *fp1,*fp2;
unsigned char head[8];
unsigned char signature[8] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};

fp2 = fopen(argv[1],"rb");
fp1 = fp2;
if(fp2==NULL) {
	printf("No File exists \n");
	exit(0);
	}
else {
        fread(head,sizeof(head),1,fp2);
	if (memcmp(signature, head, 8)) 
		printf("IT IS NOT PNG FILE \n");	
	else {
		printf("\n ENTRE THE PORTION OF THE FORMAT U WANT TO SEE \n");
		printf("\n  1: h  for  header format \n");
		printf("\n  2: d  for image data  \n");
		printf("\n  3: a  for both image and data format \n");
		scanf("%c",&ch);
		switch(ch) {
		case 'd':
			while((c=fgetc(fp1))!=EOF ) {
		       		printf("%02X ",c);
			}
			break;
		case 'a':
			while((b==fgetc(fp1))!=EOF) {
				printf("%02X ",b);
			}
			break;

			} 
		}	
	
 	}	
	fclose(fp2);
	return 0;
}

