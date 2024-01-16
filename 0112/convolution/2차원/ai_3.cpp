#include <stdio.h>
#include <stdlib.h>

class Neuron{
	private:
		int padding, stride1, stride2;
		int M_size, F_size;
		int C_size_1, C_size_2;
	public:
		Neuron();
		~Neuron();
		void setPS(int pad, int str1, int str2, int M, int F);
		int** convolution(int **M, int**F);
		int** resize(int **M);
};

Neuron::Neuron(){
	this->padding=1;
	this->stride1=1;
	this->stride2=1;
}
Neuron::~Neuron(){
	printf("\n\n...END...\n");
}
void Neuron::setPS(int pad, int str1, int str2, int M, int F){
	this->padding=pad;
	this->stride1=str1;
	this->stride2=str2;
	this->M_size=M;
	this->F_size=F;
	// size check
	this-> C_size_1=(this->M_size-this->F_size+2*this->padding)/this->stride2+1;
	this-> C_size_2=(this->M_size-this->F_size+2*this->padding)/this->stride1+1;
	if (C_size_1<M_size) {printf("\nPadding and stride value ERROR!!!\n"); abort();}
	if (C_size_2<M_size) {printf("\nPadding and stride value ERROR!!!\n"); abort();}
	// Stirde value check
	int check1=0, check2=0;
	for (int i=1;i<=F_size;i++){
		if(F_size%i==0){
			if(M_size%i==0){
			       if(i==this->stride1) check1++;
			       if(i==this->stride2) check2++;
			}
		}
	}
	if(check1==0||check2==0) {printf("\nStride size ERROR!!!\n"); abort();}
}
int** Neuron::resize(int **M){
	int **M_1;
	M_1=(int**)malloc(sizeof(int*)*(this->M_size+2*this->padding));
	for(int i=0;i<this->M_size+2;i++){
		*(M_1+i)=(int*)malloc(sizeof(int)*(this->M_size+2*this->padding));
		**M_1={0,};
	}
	for (int j=0;j<this->M_size;j++){
		for (int k=0;k<this->M_size;k++){
			M_1[j+this->padding][k+this->padding]=M[j][k];
		}
	}
	return M_1;
}
int** Neuron::convolution(int **M, int **F){
	int **M_conv=this->resize(M);
	int **result;
	int buf=0;
	result=(int**)malloc(sizeof(int*)*this->C_size_2);
	for (int r=0;r<this->C_size_2;r++){
		*(result+r)=(int*)malloc(sizeof(int)*this->C_size_1);
	}
	printf("\n  Start Convolution!!!\n");
	for (int i=0;i<this->C_size_2;i++){
		for (int j=0;j<this->C_size_1;j++){
		// result MATRIX & M_conv MATRIX control
			for (int k=0;k<F_size;k++){
				for (int l=0;l<F_size;l++){
				// FILTER matlix control
					buf+=M_conv[i*this->stride1+k][j*this->stride2+l]*F[k][l];
				}
			}
			if(buf<0) result[i][j]=0;
			else if(buf>255) result[i][j]=255;
			else result[i][j]=buf;
			buf=0;
			printf(" %3d",result[i][j]);
		}
		printf("\n");
	}
	return result;
}

int main(){
	int **M;//MATRIX
	int **F;//FILTER
	int **result;
		
	int M_size, F_size;
	printf("ENTER size of Matrix: ");
	scanf("%d",&M_size);
	printf("ENTER size of Filter: ");
	scanf("%d",&F_size);

	M=(int**)malloc(sizeof(int*)*M_size);
	F=(int**)malloc(sizeof(int*)*F_size);

	// Enter MATRIX data
	printf("ENTER number of Matrix.. Format is ");
	for (int i=0;i<M_size;i++){
		printf("[ ]");
	}
	printf("\n");
	for (int m=0;m<M_size;m++){
		*(M+m)=(int*)malloc(sizeof(int)*M_size);
		printf("#%d->  ",m);
		scanf("%d %d %d %d",&M[m][0],&M[m][1],&M[m][2],&M[m][3]);
	}
	// Enter FILTER data
	printf("ENTER number of Filter.. Format is ");
	for (int i=0;i<F_size;i++){
		printf("[ ]");
	}
	printf("\n");
	for (int f=0;f<F_size;f++){
		*(F+f)=(int*)malloc(sizeof(int)*F_size);
		printf("#%d->  ",f);
		scanf("%d %d %d",*(F+f),*(F+f)+1,*(F+f)+2);
	}

	// Enter padding and Stride value
	int pad, str1, str2;
	printf("ENTER number of padding[ ] stride[ ][ ]: ");
	scanf("%d %d %d",&pad, &str1, &str2);
	// Convolution
	Neuron nn;
	nn.setPS(pad,str1,str2,M_size,F_size);
	result=nn.convolution(M,F);
	// Print result
	int size;
	size=sizeof(*result[0]);
	printf("\n  #----- Result -----#\n");
	for (int r=0;r<size;r++){
		for (int c=0;c<size;c++){
			printf(" %3d ",result[r][c]);
		}
		printf("\n");
	}
	return 0;
}

