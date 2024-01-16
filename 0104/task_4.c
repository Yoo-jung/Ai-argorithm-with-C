#include <stdio.h>

int even(int a){
	if(a%2==0) printf("%d는 짝수 입니다.\n",a);
	else return 0;
}

int sosu(int a){
	int count=0;
	for (int i=1;i<a;i++){
		if(a%i==0) count++;
	}
	if (count==1) printf("%d는 소수입니다.\n",a);
	else return 0;
}

int zegop(int a){
	for (int i=1;i<a;i++){
		if(a/i==i) printf("%d는 %d의 제곱수입니다.\n",a, i);
	}
	return 0;
}

int main(){
	int a;
	printf("ENTER the number: ");
	scanf("%d",&a);

	even(a);
	sosu(a);
	zegop(a);
	return 0;
}
