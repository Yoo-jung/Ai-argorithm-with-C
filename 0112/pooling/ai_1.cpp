#include <stdio.h>
#include <stdlib.h>

class Neuron{
	private:
		int padding, strider, stridec;
		int M_sizer, M_sizec, F_size;
		int C_size_r, C_size_c;
	public:
		Neuron();
		~Neuron();
		void setPS(int pad, int strr, int strc, int Mr, int Mc, int F);
		int** convolution(int **M, int**F);
		int** pooling(int **M, int F, int mode);
		int** resize(int **M);
};

Neuron::Neuron(){
	this->padding=1;
	this->strider=1;//가로
	this->stridec=1;//세로
}
Neuron::~Neuron(){
	printf("\n\n...END...\n");
}
void Neuron::setPS(int pad, int strr, int strc, int Mr, int Mc, int F){
	this->padding=pad;
	this->strider=strr;
	this->stridec=strc;
	this->M_sizer=Mr;
	this->M_sizec=Mc;
	this->F_size=F;
	// Convolution size check
	double row=(this->M_sizer-this->F_size+2*this->padding)/this->stride2+1;
	double col=(this->M_sizec-this->F_size+2*this->padding)/this->stride1+1;
	if((int)row/1!=row && (int)col/1!=row){printf("\n Convolution size ERROR!!!\n"); abort();}
	// size check
	this->C_size_r=(int)row;//세로
	this->C_size_c=(int)col;//가로
	if(pad){
		if (C_size_r<M_sizer) {printf("\nPadding and stride value ERROR!!!\n"); abort();}
		if (C_size_c<M_sizec) {printf("\nPadding and stride value ERROR!!!\n"); abort();}
	}
	// Stirde value check
	int checkr=0, checkc=0;
	for (int i=1;i<=F_size;i++){
		if(F_size%i==0){
			if(M_sizer%i==0){
			       if(i==this->strider) checkr++;
			}
			if(M_sizec%i==0){
			       if(i==this->stridec) checkc++;
			}
		}
	}
	if(checkr==0||checkc==0) {printf("\nStride size ERROR!!!\n"); abort();}
}
int** Neuron::resize(int **M){
	int **M_1;
	M_1=(int**)malloc(sizeof(int*)*(this->M_sizer+2*this->padding));
	for(int i=0;i<this->M_sizer+2;i++){
		*(M_1+i)=(int*)malloc(sizeof(int)*(this->M_sizec+2*this->padding));
		**M_1={0,};
	}
	for (int j=0;j<this->M_sizer;j++){
		for (int k=0;k<this->M_sizec;k++){
			M_1[j+this->padding][k+this->padding]=M[j][k];
		}
	}
	return M_1;
}
int** Neuron::convolution(int **M, int **F){
	int **M_conv=this->resize(M);
	int **result;
	int buf=0;
	result=(int**)malloc(sizeof(int*)*this->C_size_r);
	for (int r=0;r<this->C_size_r;r++){
		*(result+r)=(int*)malloc(sizeof(int)*this->C_size_c);
	}
	printf("\n  Start Convolution!!!\n");
	for (int i=0;i<this->C_size_r;i++){
		for (int j=0;j<this->C_size_c;j++){
		// result MATRIX & M_conv MATRIX control
			for (int k=0;k<F_size;k++){
				for (int l=0;l<F_size;l++){
				// FILTER matlix control
					buf+=M_conv[i*this->strider+k][j*this->stridec+l]*F[k][l];
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
int** Neuron::pooling(int **M, int F, int mode){
	int **result;
	int buf=0;
	result=(int**)malloc(sizeof(int*)*this->C_size_r);
	for (int r=0;r<this->C_size_r;r++){
		*(result+r)=(int*)malloc(sizeof(int)*this->C_size_c);
	}
	if(mode==0){ //MAX Pooling
		for(int i=0;i<this->C_size_r;i++){
			for(int j=0;j<this->C_size_c;j++){
				//Filter matlix control
				for (int k=0;k<F;k++){
					for (int l=0;l<F;l++){
						if(M[i*this->strider+k][j*this->stridec+l]>=buf) buf=M[i*this->strider+k][j*this->stridec+l];
					}
				}
				result[i][j]=buf;
				buf=0;
			printf(" %3d",result[i][j]);
		}
		printf("\n");
		}
	}
	else{ //AVERAGE Pooling
		for(int i=0;i<this->C_size_r;i++){
			for(int j=0;j<this->C_size_c;j++){
				//Filter matlix control
				for (int k=0;k<F;k++){
					for (int l=0;l<F;l++){
						buf += M[i*this->strider+k][j*this->stridec+l];
					}
				}
				if (buf%(F*F)>=0.5) result[i][j]=(int)buf/(F*F)+1;
				else result[i][j]=(int)buf/(F*F);
				buf=0;
			//printf(" %3d",result[i][j]);
		}
		//printf("\n");
		}
	}
	return result;
}
int main(){
	int **M;//MATRIX
	int **F;//FILTER
	int **result;
	int time;
	
	printf("What time? ");
	scanf("%d",&time);
	int ***Result;
	Result=(int***)malloc(sizeof(int**)*time);
	// time번 반복
	for(int t=0;t<time;t++){
		
		int M_size_r, M_size_c, F_size;//row:행(세로), col:열(가로)
		printf("ENTER size of Matrix[row][col]: ");
		scanf("%d %d",&M_size_r, &M_size_c);
		printf("ENTER size of Filter: ");
		scanf("%d",&F_size);

		M=(int**)malloc(sizeof(int*)*M_size_r);
		F=(int**)malloc(sizeof(int*)*F_size);
		
		// Enter MATRIX data
		printf("ENTER number of Matrix.. Format is ");
		for (int i=0;i<M_size_c;i++){
			printf("[ ]");
		}
		printf("\n");
		for (int m=0;m<M_size_r;m++){
			*(M+m)=(int*)malloc(sizeof(int)*M_size_c);
			printf("#%d->  ",m);
			scanf("%d %d %d %d",&M[m][0],&M[m][1],&M[m][2],&M[m][3]);
		}
		
		// Enter padding and Stride value
		int pad=0, strr, strc;
		printf("ENTER number of stride[ ][ ]: ");
		scanf("%d %d", &strr, &strc);
		// Convolution
		Neuron nn;
		nn.setPS(pad,strr,strc,M_size_r,M_size_c,F_size);
		int mode;
		printf("Pooling mode 0->MAX, 1->AVER : ");
		scanf("%d",&mode);
		//result=nn.convolution(M,F);
		result=nn.pooling(M,F_size,mode);
		// Print result
		int sizer, sizec;
		sizer=sizeof(result)/sizeof(int);
		sizec=sizeof(*result)/sizeof(int);
		printf("\n  #----- Result -----#\n");
		for (int r=0;r<sizer;r++){
			for (int c=0;c<sizec;c++){
				printf(" %3d ",result[r][c]);
			}
			printf("\n");
		}
		Result[t]=result;
	}
	return 0;
}
