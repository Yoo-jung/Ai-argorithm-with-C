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
		int** convolution(int **M, int **F);
		int** pooling(int **M, int F, int mode);
		int** resize(int **M);
		int sizer();
		int sizec();
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
	// size check
	this-> C_size_r=(this->M_sizer-this->F_size+2*this->padding)/this->strider+1;//세로
	this-> C_size_c=(this->M_sizec-this->F_size+2*this->padding)/this->stridec+1;//가로
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
	for(int i=0;i<this->M_sizer+2*this->padding;i++){
		*(M_1+i)=(int*)malloc(sizeof(int)*(this->M_sizec+2*this->padding));
		//**M_1={0,};
		for (int ii=0;ii<this->M_sizec+2*this->padding;ii++){
			M_1[i][ii]=0;
		}
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
			else result[i][j]=(int)buf;
			buf=0;
			//printf(" %3d",result[i][j]);
		}
		//printf("\n");
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
int Neuron::sizer(){
	return this->C_size_r;
}
int Neuron::sizec(){
	return this->C_size_c;
}
