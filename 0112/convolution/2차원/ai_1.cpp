#include <stdio.h>
#include <stdlib.h>

class Neuron{
	private:
		int padding, stride;
	public:
		Neuron();
		~Neuron();
		int** convolution(int M_size, int F_size, int **M, int**F);
		int** resize(int **M, int size);
};

Neuron::Neuron(){
	this->padding=1;
	this->stride=1;
}
Neuron::~Neuron(){
	printf("\n\n...END...\n");
}

int** Neuron::resize(int **M, int size){
	int **M_1;
	M_1=(int**)malloc(sizeof(int*)*(size+2));
	for(int i=0;i<size+2;i++){
		*(M_1+i)=(int*)malloc(sizeof(int)*(size+2));
		**M_1={0,};
	}
	for (int j=0;j<size;j++){
		for (int k=0;k<size;k++){
			M_1[j+1][k+1]=M[j][k];
		}
	}
	return M_1;
}
int** Neuron::convolution(int M_size, int F_size, int **M, int **F){
	int **M_conv=this->resize(M, M_size);
	int **result;
	int buf=0;
	int r_size=(M_size-F_size+2*this->padding)/this->stride+1;
	result=(int**)malloc(sizeof(int*)*r_size);
	for (int r=0;r<r_size;r++){
		*(result+r)=(int*)malloc(sizeof(int)*r_size);
	}
	printf("\nStart Convolution!!!\n");
	for (int i=0;i<r_size;i++){
		for (int j=0;j<r_size;j++){
		// result MATRIX & M_conv MATRIX control
			for (int k=0;k<F_size;k++){
				for (int l=0;l<F_size;l++){
				// FILTER matlix control
					buf+=M_conv[k+i][l+j]*F[k][l];
				}
			}
			if(buf<0) result[i][j]=0;
			else if(buf>255) result[i][j]=255;
			else result[i][j]=buf;
			buf=0;
			printf(" %d",result[i][j]);
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
	// Convolution
	Neuron nn;
	result=nn.convolution(M_size,F_size,M,F);
	// Print result
	int size;
	size=sizeof(*result[0]);
	printf("\n#----- Result -----#\n");
	for (int r=0;r<size;r++){
		for (int c=0;c<size;c++){
			printf(" %d ",result[r][c]);
		}
		printf("\n");
	}
	return 0;
}

