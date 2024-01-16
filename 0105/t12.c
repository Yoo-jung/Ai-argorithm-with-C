#include <stdio.h>
struct scr{
	char name[50];
	int score[5];
	int total, avr;
	int pass_fail;
};

int main(){
	struct scr a[10];
	for(int i=0;i<2;i++){
		printf("%d 's name: ",i+1);
		scanf("%s",a[i].name);
		printf("math: ");
		scanf("%d",&a[i].score[0]);
		printf("eng: ");
		scanf("%d",&a[i].score[1]);
	}
	strcpy(a[1].name,"Hong");
	printf("#---------------------------------------#\n");
	for(int i=0;i<2;i++){
		printf("%d's name is %s \n",i+1,a[i].name);
		printf("math score is %d\n",a[i].score[0]);
		printf("eng score is %d\n",a[i].score[1]);
		printf("\n");
	}
			
	return 0;
}
