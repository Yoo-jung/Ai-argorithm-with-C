#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Neuron{
	private:
		double w, b;//class외부에서 값을 알 수 없기에 print 명령어를 통해 출력 필요
	public:
		Neuron();
		~Neuron();
		double sigma_f(double x);
		double act_f(double sigma);
		double feedForward(double x);
		void printf_f(double *x, double *y_want, int n);
		void setWB(double w, double b);

		void backProp(double *x, double *y_want, int n);
		double cost(double *x, double *y_want, int n);
};
Neuron::Neuron(){
	this->w=0.0;
	this->b=0.0;
}
Neuron::~Neuron(){
	printf("\n...END...\n");
}
double Neuron::sigma_f(double x){
	return this->w * x + this->b;
}
double Neuron::act_f(double sigma){
	//Linear
	//double y=sigma;
	
	//sigmoid
	double y = 1/(1+exp(-sigma));
	return y;
}
double Neuron::feedForward(double x){
	return this->act_f(this->sigma_f(x));
}
void Neuron::printf_f(double *x, double *y_want, int n){
	for (int i=0;i<n;i++){
		printf("	w:%.2f b:%.2f :: x:%.2f  y:%.6f || y_want:%.2f \n",
				this->w, this->b, *(x+i), this->feedForward(x[i]),
				*(y_want+i));
	}
}
void Neuron::setWB(double w, double b){
	this->w=w;
	this->b=b;
}
void Neuron::backProp(double *x, double *y_want, int n){
	double alpha=1;
	double dEdw=0.0;
	double dEdb=0.0;
	for (int i=0;i<n;i++){
		if (y_want[i]==0){
			dEdw += (1/(1-this->feedForward(x[i])))
				*(exp(-this->sigma_f(x[i]))/((1+exp(-this->sigma_f(x[i])))*(1+exp(-this->sigma_f(x[i])))))*x[i];
			dEdb += (1/(1-this->feedForward(x[i])))
				*(exp(-this->sigma_f(x[i]))/((1+exp(-this->sigma_f(x[i])))*(1+exp(-this->sigma_f(x[i])))));
		}
		else{
			dEdw += (-1/this->feedForward(x[i]))
				*(exp(-this->sigma_f(x[i]))/((1+exp(-this->sigma_f(x[i])))*(1+exp(-this->sigma_f(x[i])))))*x[i];
			dEdb += (-1/this->feedForward(x[i]))
				*(exp(-this->sigma_f(x[i]))/((1+exp(-this->sigma_f(x[i])))*(1+exp(-this->sigma_f(x[i])))));
		}

	}
	dEdw /=n;
	dEdb /=n;
	this->w-=alpha*dEdw;
	this->b-=alpha*dEdb;
}
double Neuron::cost(double *x, double *y_want, int n){
	double cost=0.0;
	for (int i=0;i<n;i++){
		if(y_want[i]==0) cost += -log(1-this->feedForward(x[i]));
		else cost += -log(this->feedForward(x[i]));
	}
	printf("	cost:%.4f\n\n",cost);
	return cost;
}
int main(){
	int n=0, time=0;
	/*double *x, *y;
	int n=0, time=0;
	printf("ENTER Number: ");
	scanf("%d",&n);

	x = (double *)malloc(sizeof(double)*n);
	y = (double *)malloc(sizeof(double)*n);
	for (int j=0;j<n;j++){
		printf(" ENTER x[%d] y[%d]: ", j, j);
		scanf("%lf %lf",x+j, y+j);
	}*/
	double x[6]={1,1.3,2.7,8,9,10};
	double y[6]={0,0,0,1,1,1}; //5가 기준
	n=6;
	Neuron nn;
	nn.setWB(1.0,3.0);

	printf("ENTER Study time: ");
	scanf("%d",&time);
	for (int i=0;i<time;i++){
		printf("%d->  \n",i+1);
		nn.backProp(x,y,n);
		nn.printf_f(x,y,n);
		nn.cost(x,y,n);
	}
	
	double value;
	printf("\n#----------------------------------------------------------#\n");
	printf("Input value of x: ");
	scanf("%lf",&value);
	printf("x:%.4f ->> y=%.4f\n",value,nn.feedForward(value));
	return 0;
}
