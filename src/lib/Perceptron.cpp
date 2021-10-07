#include <random>
#include "random.h"
#include "Perceptron.h"

Neural::Perceptron::Perceptron(unsigned int weightsSize) :                        //
                                                           weights(++weightsSize) // +1 from bias
{
    this->learnningRate = 0.000002;

    for (unsigned int i = 0; i < weightsSize; i++)
    {
        // Generates a value between -1 and 1
        this->weights[i] = utils::random();
    }
}

Neural::Perceptron::~Perceptron()
{
}
void Neural::Perceptron::train(std::vector<float> inputs, float target)
{
    float guess = this->guess(inputs);
    float error = target - guess;

    // Calculate the new weight for bias (error * 1 * learnningRate)
    this->weights[0] += error * this->learnningRate;

    // Calculate the others new weights (error * input[i - 1] * learnningRate)
    for (unsigned int i = 1; i < this->weights.size(); i++)
    {
        this->weights[i] += error * inputs[i - 1] * this->learnningRate;
    }
}
float Neural::Perceptron::guess(std::vector<float> inputs)
{
    // Sums the bias (1 * first weight)
    float sum = weights[0];

    // Sums the other values
    for (unsigned int i = 1; i < this->weights.size(); i++)
    {
        sum += inputs[i - 1] * weights[i];
    }

    return this->activationFunction(sum);
}

float Neural::Perceptron::activationFunction(float value)
{
    return value >= 0 ? 1 : -1;
}
