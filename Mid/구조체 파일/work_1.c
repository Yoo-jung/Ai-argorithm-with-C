#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
	char name[50];
	int math, science, social;
	double average;
}St;

void avg(St *S){
	(*S).average=( (*S).math+(*S).science+(*S).social )/3.0;
}	

int main(){
	int n;

	printf("Number of student: ");
	scanf("%d", &n);

	St *S =(St*)malloc(sizeof(St)*n);
	
	for (int i=0;i<n;i++){
		printf("Enter name: ");
		scanf("%s",(*(S+i)).name);
		printf("Enter math science social socore: ");
		scanf("%d %d %d",&((*(S+i)).math), &(*(S+i)).science, &((*(S+i))).social);
		avg(&(*(S+i)));
	}

	FILE *fp;
	fp = fopen("./student.txt", "w");
	fprintf(fp, "Student %d\n", n);
	for (int i=0; i<n; i++){
		fprintf(fp,"Student %s %d, %d, %d, %.2f\n",
			(*(S+i)).name,(*(S+i)).math,(*(S+i)).science,(*(S+i)).social,(*(S+i)).average);
	}
	free(S);
	return 0;
}
