#include <stdio.h>
/*
double sigma_f(double x, double w, double b){
	return x*w+b;
}
double act (double sigma){
	double y;
	//Linear
	y=sigma;
	//sigmoid
	y=1/(1+exp(-sigma));
	
	 * //ReLU
	if(sigma>=0) y=sigma;
	else y=0;
	return y;
}

int main(){
	double x, y;
	double w, b;//weight & bias
	double sigma;

	sigma = sigma_f(x,w,b);//x만 함수 인자로 사용하고 싶음!!
	y=act(sigma);

	return 0;
}
*/

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
};
double Neuron::feedForward(double x){
	return this->act_f(this->sigma_f(x));
}
void Neuron::printf_f(double x){
	printf("w:%.2f b:%.2f x:%.2f  y:%.4f\n", this->w, this->b, x, this->feedForward(x));
}
void Neuron::setWB(double w, double b){
	this->w=w;
	this->b=b;
}

int main(){
	double x=1,y;

	Neuron nn;

	nn.setWB(1.0,3.0);
	for (x=0.0;x<=3.0;x+=0.5){
		nn.printf_f(x);
	}
	return 0;
}
