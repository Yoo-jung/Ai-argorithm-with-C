#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Neuron{
	private:
		double w1, w2, b;//class외부에서 값을 알 수 없기에 print 명령어를 통해 출력 필요
	public:
		Neuron();
		~Neuron();
		double sigma_f(double *x);
		double act_f(double sigma);
		double feedForward(double *x);
		void printf_f(double **x, double *y_want, int n);
		void setWB(double *w, double b);

		void backProp(double **x, double *y_want, int n);
		double cost(double **x, double *y_want, int n);
};
Neuron::Neuron(){
	this->w1=0.0;
	this->w2=0.0;
	this->b=0.0;
}
Neuron::~Neuron(){
	printf("\n...END...\n");
}
double Neuron::sigma_f(double *x){
	return this->w1 * x[0] + this->w2 * x[1] + this->b;
}
double Neuron::act_f(double sigma){
	//Linear
	//double y=sigma;
	
	//sigmoid
	double y = 1/(1+exp(-sigma));
	return y;
}
double Neuron::feedForward(double *x){
	return this->act_f(this->sigma_f(x));
}
void Neuron::printf_f(double **x, double *y_want, int n){
	for (int i=0;i<n;i++){
		printf("	w1:%.2f w2:%.2f b:%.2f :: x:%.1f %.1f  y:%.6f || y_want:%.2f \n",
				this->w1, this->w2, this->b, *(*(x+i)),*((*(x+i))+1), this->feedForward(*(x+i)),
				*(y_want+i));
	}
}
void Neuron::setWB(double *w, double b){
	this->w1=*w;
	this->w2=*(w+1);
	this->b=b;
}
void Neuron::backProp(double **x, double *y_want, int n){
	double alpha=1;
	double dEdw_1=0.0,dEdw_2=0.0;
	double dEdb=0.0;
	double sigm,dfds;
	for (int i=0;i<n;i++){
		sigm = this->sigma_f(*(x+i));
		dfds = exp(-sigm)/((1+exp(-sigm))*(1+exp(-sigm)));
		if (y_want[i]==0){
			dEdw_1 += (1/(1-this->feedForward(*(x+i))))*dfds*x[i][0];
			dEdw_2 += (1/(1-this->feedForward(*(x+i))))*dfds*x[i][1];
			dEdb += (1/(1-this->feedForward(*(x+i))))*dfds*1;
		}
		else{
			dEdw_1 += (-1/this->feedForward(*(x+i)))*dfds*x[i][0];
			dEdw_2 += (-1/this->feedForward(*(x+i)))*dfds*x[i][1];
			dEdb += (-1/this->feedForward(*(x+i)))*dfds*1;
		}

	}
	dEdw_1 /=n;
	this->w1-=alpha*dEdw_1;
	dEdw_2 /=n;
	this->w2-=alpha*dEdw_2;
	this->b-=alpha*dEdb;
}
double Neuron::cost(double **x, double *y_want, int n){
	double cost=0.0;
	for (int i=0;i<n;i++){
		if(y_want[i]==0) cost += -log(1-this->feedForward(*(x+i)));
		else cost += -log(this->feedForward(*(x+i)));
	}
	printf("	cost:%.4f\n\n",cost);
	return cost;
}
int main(){
	int n=0, time=0;
	double **x, *y;
	printf("ENTER Number: ");
	scanf("%d",&n);

	x = (double **)malloc(sizeof(double *)*2);
	for (int m=0;m<n;m++){
		*(x+m) = (double *)malloc(sizeof(double)*n);
	}
	y = (double *)malloc(sizeof(double )*n);
	for (int j=0;j<n;j++){
		printf(" ENTER #%d x[ ][ ] y[ ]: ", j);
		scanf("%lf %lf %lf",*(x+j),*(x+j)+1, y+j);
		printf("%f %f\n",x[j][0], x[j][1]);
	}
	n=4;
	Neuron nn;
	double w[2]={1.0, 2.0};
	nn.setWB(w,3.0);

	printf("ENTER Study time: ");
	scanf("%d",&time);
	for (int i=0;i<time;i++){
		printf("%d->  \n",i+1);
		nn.backProp(x,y,n);
		nn.printf_f(x,y,n);
		nn.cost(x,y,n);
	}
	
	double value[2];
	printf("\n#----------------------------------------------------------#\n");
	printf("Input value of x: ");
	scanf("%lf %lf",&value[0], &value[1]);
	printf("x:%.2f %.2f ->> y=%.4f\n",value[0], value[1],nn.feedForward(value));
	return 0;
}
