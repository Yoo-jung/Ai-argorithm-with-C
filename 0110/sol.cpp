#include <stdio.h>

class Neuron{
	private:
		double w, b;//class외부에서 값을 알 수 없기에 print 명령어를 통해 출력 필요
	public:
		Neuron();
		~Neuron();
		double sigma_f(double x);
		double act_f(double sigma);
		double feedForward(double x);
		void printf_f(double *x, double *y_want);
		void setWB(double w, double b);

		void backProp(double *x, double *y_want);
		double cost(double *x, double *y_want);
};
Neuron::Neuron(){
	this->w=0.0;
	this->b=0.0;
}
Neuron::~Neuron(){
	printf("END...\n");
}
double Neuron::sigma_f(double x){
	return this->w * x + this->b;
}
double Neuron::act_f(double sigma){
	//Linear
	double y=sigma;
	return y;
}
double Neuron::feedForward(double x){
	return this->act_f(this->sigma_f(x));
}
void Neuron::printf_f(double *x, double *y_want){
	for (int i=0;i<3;i++){
		printf("w:%.2f b:%.2f x:%.2f  y:%.6f  :: y:%.2f",
				this->w, this->b, *(x+i), this->feedForward(x[i]),y_want[i]);
	}
}
void Neuron::setWB(double w, double b){
	this->w=w;
	this->b=b;
}
void Neuron::backProp(double *x, double *y_want){
	double alpha=0.1;
	double dEdw=0.0;
	double dEdb=0.0;
	for (int i=0;i<3;i++){
		dEdw += (this->feedForward(x[i])-y_want[i])*1*1*x[i];
		dEdb += (this->feedForward(x[i])-y_want[i])*1*1*1;
	}
	dEdw /=3;
	dEdb /=3;
	this->w-=alpha*dEdw;
	this->b-=alpha*dEdb;
}
double Neuron::cost(double *x, double *y_want){
	double cost=0.0;
	for (int i=0;i<3;i++){
		cost += 0.5*(y_want[i]-this->feedForward(x[i]))*(y_want[i]-this->feedForward(x[i]));
	}
	return cost;
}
int main(){
	double x[3]={1,2,3};
	double y[3]={1,2,3};
	Neuron nn;

	nn.setWB(1.0,3.0);
	//nn.printf_f(x);
	
	for (int i=0;i<500;i++){
		printf("%d->  ",i+1);
		nn.backProp(x,y);
		nn.printf_f(x,y);
		printf("	cost:%.5f\n\n",nn.cost(x,y));
	}
	
	printf("\n#----------------------------------------------------------#\n");
	printf("x:2.5 y_want:2.5 ->> y=%.4f\n",nn.feedForward(2.5));
	return 0;
}
