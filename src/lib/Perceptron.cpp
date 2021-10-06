#include <random>
#include "Perceptron.h"

Neural::Perceptron::Perceptron(unsigned int weightsSize) : weights(weightsSize)
{

    this->learnningRate = 0.000001;

    for (unsigned int i = 0; i < weightsSize; i++)
    {
        // Generates a value between -1 and 1
        this->weights[i] = ((std::rand() / float(RAND_MAX)) * 2.0) - 1.0;
    }
}

Neural::Perceptron::~Perceptron()
{
}
void Neural::Perceptron::train(std::vector<float> inputs, int target)
{
    int guess = this->guess(inputs);
    int error = target - guess;

    for (unsigned int i = 0; i < this->weights.size(); i++)
    {
        this->weights[i] += error * inputs[i] * this->learnningRate;
    }
}
int Neural::Perceptron::guess(std::vector<float> inputs)
{
    float sum = 0;
    for (unsigned int i = 0; i < this->weights.size(); i++)
    {
        sum += inputs[i] * weights[i];
    }
    int output = this->activationFunction(sum);

    return output;
}

int Neural::Perceptron::activationFunction(float value)
{
    return value >= 0 ? 1 : -1;
}
