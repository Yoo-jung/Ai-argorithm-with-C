#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Neuron{
	private:
		double w1, w2, b;//class외부에서 값을 알 수 없기에 print 명령어를 통해 출력 필요
	public:
		Neuron();
		~Neuron();
		double sigma_f(double x1, double x2);
		double act_f(double sigma);
		double feedForward(double x1, double x2);
		void printf_f(double *x1, double *x2, double *y_want, int n);
		void setWB(double *w, double b);

		void backProp(double *x1, double *x2, double *y_want, int n);
		double cost(double *x1, double *x2, double *y_want, int n);
};
Neuron::Neuron(){
	this->w1=0.0;
	this->w2=0.0;
	this->b=0.0;
}
Neuron::~Neuron(){
	printf("\n...END...\n");
}
double Neuron::sigma_f(double x1, double x2){
	return this->w1 * x1 + this->w2 * x2 + this->b;
}
double Neuron::act_f(double sigma){
	//Linear
	//double y=sigma;
	
	//sigmoid
	double y = 1/(1+exp(-sigma));
	return y;
}
double Neuron::feedForward(double x1, double x2){
	return this->act_f(this->sigma_f(x1, x2));
}
void Neuron::printf_f(double *x1,double *x2, double *y_want, int n){
	for (int i=0;i<n;i++){
		printf("	w1:%.2f w2:%.2f b:%.2f :: x:%.2f %.2f  y:%.6f || y_want:%.2f \n",
				this->w1, this->w2, this->b, x1[i],x2[i], this->feedForward(x1[i], x2[i]),
				*(y_want+i));
	}
}
void Neuron::setWB(double *w, double b){
	this->w1=*w;
	this->w2=*(w+1);
	this->b=b;
}
void Neuron::backProp(double *x1,double *x2, double *y_want, int n){
	double alpha=1;
	double dEdw_1=0.0,dEdw_2=0.0;
	double dEdb=0.0;
	
	for (int i=0;i<n;i++){
		if (y_want[i]==0){
			dEdw_1 += (1/(1-this->feedForward(x1[i],x2[i])))
				*(exp(-this->sigma_f(x1[i],x2[i]))/((1+exp(-this->sigma_f(x1[i],x2[i])))*(1+exp(-this->sigma_f(x1[i],x2[i])))))*x1[i];
			dEdw_2 += (1/(1-this->feedForward(x1[i],x2[i])))
				*(exp(-this->sigma_f(x1[i],x2[i]))/((1+exp(-this->sigma_f(x1[i],x2[i])))*(1+exp(-this->sigma_f(x1[i],x2[i])))))*x2[i];
			dEdb += (1/(1-this->feedForward(x1[i],x2[i])))
				*(exp(-this->sigma_f(x1[i],x2[i]))/((1+exp(-this->sigma_f(x1[i],x2[i])))*(1+exp(-this->sigma_f(x1[i],x2[i])))));
		}
		else{
			dEdw_1 += (-1/this->feedForward(x1[i],x2[i]))
				*(exp(-this->sigma_f(x1[i],x2[i]))/((1+exp(-this->sigma_f(x1[i],x2[i])))*(1+exp(-this->sigma_f(x1[i],x2[i])))))*x1[i];
			dEdw_2 += (-1/this->feedForward(x1[i],x2[i]))
				*(exp(-this->sigma_f(x1[i],x2[i]))/((1+exp(-this->sigma_f(x1[i],x2[i])))*(1+exp(-this->sigma_f(x1[i],x2[i])))))*x2[i];
			dEdb += (-1/this->feedForward(x1[i],x2[i]))
				*(exp(-this->sigma_f(x1[i],x2[i]))/((1+exp(-this->sigma_f(x1[i],x2[i])))*(1+exp(-this->sigma_f(x1[i],x2[i])))));
		}

	}
	dEdw_1 /=n;
	this->w1-=alpha*dEdw_1;
	dEdw_2 /=n;
	this->w2-=alpha*dEdw_2;
	this->b-=alpha*dEdb;
}
double Neuron::cost(double *x1,double *x2,double *y_want, int n){
	double cost=0.0;
	for (int i=0;i<n;i++){
		if(y_want[i]==0) cost += -log(1-this->feedForward(x1[i],x2[i]));
		else cost += -log(this->feedForward(x1[i],x2[i]));
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
	double x1[4]={0,0,1,1};
	double x2[4]={0,1,0,1};
	double y[4]={0,0,0,1}; //5가 기준
	n=4;
	Neuron nn;
	double w[2]={1.0, 2.0};
	nn.setWB(w,3.0);

	printf("ENTER Study time: ");
	scanf("%d",&time);
	for (int i=0;i<time;i++){
		printf("%d->  \n",i+1);
		nn.backProp(x1,x2,y,n);
		nn.printf_f(x1,x2,y,n);
		nn.cost(x1,x2,y,n);
	}
	
	double value[2];
	printf("\n#----------------------------------------------------------#\n");
	printf("Input value of x: ");
	scanf("%lf %lf",&value[0], &value[1]);
	printf("x:%.2f %.2f ->> y=%.4f\n",value[0], value[1],nn.feedForward(value[0], value[1]));
	return 0;
}
