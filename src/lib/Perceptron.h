/**
 * @author André Furlan
 * @email ensismoebius@gmail.com
 * This whole project are under GPLv3, for
 * more information read the license file
 *
 * @date 2021-10-03
*/

#ifndef src_lib_NeuralNetwork_h
#define src_lib_NeuralNetwork_h

#include <vector>

namespace Neural
{
    /**
     * @brief 
     * 
     */
    class Perceptron
    {
    private:
        std::vector<float> weights;

        float learnningRate;

        /**
         * @brief The activation function
         * 
         * @param value 
         * @return int 
         */
        static inline float activationFunction(float value);

    public:
        /**
         * @brief Construct a new Perceptron object
         * 
         * @param weightsSize 
         */
        Perceptron(unsigned int weightsSize);
        ~Perceptron();

        void train(std::vector<float> inputs, float target);

        float guess(std::vector<float> inputs);
    };
}

#endif