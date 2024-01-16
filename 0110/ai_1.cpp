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
		void printf_f(double x);
		void setWB(double w, double b);

		void backProp(double x, double y_want);
		double cost(double x, double y_want);
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
void Neuron::printf_f(double x){
	printf("w:%.2f b:%.2f x:%.2f  y:%.6f  :: ", this->w, this->b, x, this->feedForward(x));
}
void Neuron::setWB(double w, double b){
	this->w=w;
	this->b=b;
}
void Neuron::backProp(double x, double y_want){
	double alpha=0.1;
	double dEdw=0.0;
	double dEdb=0.0;
	int n=3;
	for (int i=0;i<n;i++){
		dEdw += (this->feedForward(x)-y_want)*1*1*x;
		dEdb += (this->feedForward(x)-y_want)*1*1*1;
	}
	dEdw /=n;
	dEdb /=n;
	this->w-=alpha*dEdw;
	this->b-=alpha*dEdb;
}
double Neuron::cost(double x, double y_want){
	double cost=0.0;
	for (int i=0;i<3;i++){
		cost += 0.5*(y_want-this->feedForward(x))*(y_want-this->feedForward(x));
	}
	return cost;
}
int main(){
	double x[3]={1,2,3};
	double y[3]={1,2,3};
	Neuron nn;

	nn.setWB(1.0,3.0);
	nn.printf_f(x[0]);
	for (int j=0;j<3;j++){
		for (int i=0;i<10;i++){
			printf("%d->  ",i+1);
			nn.backProp(x[j],y[j]);
			nn.printf_f(x[j]);
			printf("y_want: %.4f  cost: %.4f\n\n",y[j],nn.cost(x[j],y[j]));
		}
	}
	printf("\n#----------------------------------------------------------#\n");
	printf("x:2.5 y_want:2.5 ->> y=%.4f\n",nn.feedForward(2.5));
	return 0;
}
