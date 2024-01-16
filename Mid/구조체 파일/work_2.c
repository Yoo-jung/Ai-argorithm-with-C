#include <stdio.h>
#include <stdlib.h>

struct Student{
	char name[50];
	int math, science, social;
	double average;
};

typedef struct Student St;

int main(){
	char str[50];
	char str1[50];
	int n;
	
	FILE *fp;
	fp = fopen("./student.txt", "r");
	fscanf(fp,"%s %d",str, &n);
	printf("Student number is %d\n",n);
	printf("#------------------------------------------------#\n");
	printf("Student [Name]: [Math] [Sciece] [Social] -> [Average]\n\n");
	
	St *S = (St*)malloc(sizeof(St)*n);
	int i=0;
	while(i<n){
		if(fscanf(fp,"%s %s %d, %d, %d, %lf",str, (*(S+i)).name,
			&((*(S+i)).math), &((*(S+i)).science), &((*(S+i)).social),
			&((*(S+i)).average))==EOF){printf("READ ERROR!!!"); break;}
		printf("%s %s:   %d   %d   %d  ->  %.2f\n",str,(*(S+i)).name,
				(*(S+i)).math,(*(S+i)).science,(*(S+i)).social,(*(S+i)).average);
		i++;
	}
	
	free(S);
	return 0;
}
