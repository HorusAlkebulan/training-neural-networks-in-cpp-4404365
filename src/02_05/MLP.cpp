#include "MLP.h"

double frand(){
	return (2.0*(double)rand() / RAND_MAX) - 1.0;
}


// Return a new Perceptron object with the specified number of inputs (+1 for the bias).
Perceptron::Perceptron(size_t inputs, double bias){
	this->bias = bias;
	weights.resize(inputs+1);
	generate(weights.begin(),weights.end(),frand);
}

// Run the perceptron. x is a vector with the input values.
double Perceptron::run(std::vector<double> x){
	x.push_back(bias);
	double sum = inner_product(x.begin(),x.end(),weights.begin(),(double)0.0);
	return sigmoid(sum);
}

// Challenge: Finish the following functions:

void Perceptron::set_weights(std::vector<double> w_init){
	// w_init is a vector of doubles. Organize it as you'd like.
	weights = w_init;
}

double Perceptron::sigmoid(double x){
	// Return the output of the sigmoid function applied to x
	double out = 1.0/(1.0 + exp(-x));
	return out;
}
