#include <stdio.h>

int even(int a){
	if(a%2==0) printf(" 짝수 입니다.\n");
	else printf(" 짝수가 아닙니다.\n");
}

int sosu(int a, int b){
	int count=0;
	for (int i=1;i<a;i++){
		if(a%i==0) count++;
	}
	if (count==1) {if(b) printf(" 소수입니다.\n"); return 1;}
	else {if(b) printf(" 소수가 아닙니다.\n"); return 0;}
}

int zegop(int a){
	for (int i=1;i<a;i++){
		if(a/i==i) {printf(" %d의 제곱수입니다.\n", i); break;}
	}
	printf(" 제곱수가 아닙니다.\n");
	return 0;
}

int main(){
	int a, i;
	printf("ENTER the number: ");
	scanf("%d",&a);
	printf("\n ### %d는?\n\n",a);
	even(a);
	if(!sosu(a, 1)){
		printf("  --> %d보다 작은 수 중 가장 큰 소수는 ",a);
		for (i=a;i>0;i--){
			if(sosu(i, 0)) break;
		}
		printf("%d 입니다.\n",i);
	}
	zegop(a);
	return 0;
}
