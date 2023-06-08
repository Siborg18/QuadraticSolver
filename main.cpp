#include <complex>
#include <iostream>
#include <math.h>
#include <utility>
#include <vector>
#include <string>

// general equation x = (-b +/- sqrt(b^2 -4ac)) / 2a

std::vector<float> UserInput ()
{   
    std::vector<float> inputs{};
    // take user input in terms of a, b, c
    return inputs;
}

int complexSolutionRequired(float a, float b, float c)
{
    if ((pow(b, 2) - 4 * a * c) < 0)
    {
        return -1;
    }
    else if ((pow(b, 2) - 4 * a * c) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

std::pair<double, double> findTwoRealParts(float a, float b, float c)
{
    double x1 {};
    double x2 {};
    double x {pow(b, 2) - 4 * a * c};
    x1 = (-b + sqrt(x)) / (2*a);
    x2 = (-b - sqrt(x)) / (2*a);
    std::pair<double, double> pairOutput {x1, x2};
    return pairOutput;
}

std::pair<double, double> findOneRealOneImaginary(float a, float b, float c)
{
    std::complex<double> x {};
    std::complex<double> imaginaryX {pow(b, 2) - 4 * a * c};
    x = (static_cast<double>(-b) + sqrt(imaginaryX)) / static_cast<double>(2*a);
    std::pair<double, double> pairOutput {imag(x), real(x)};
    return pairOutput;
    // bug with the first part of the imaginary part being negative
}

int main()
{
   
    double a {8};
    double b {25};
    double c {13};
    int solutionRequired {complexSolutionRequired(a, b, c)};
    std::pair<double, double> outcomeA;
    std::pair<double, double> outcomeB;
    switch (solutionRequired)
    {
    case -1:
        std::cout << "Two complex solutions" << std::endl;
        outcomeB = findOneRealOneImaginary(a, b, c);
        std::cout << "x1: " << outcomeB.second  << " x2: " << outcomeB.first << 'i' << std::endl;
        return -1;
    case 0:
        std::cout << "One complex, one real solution" << std::endl;
        outcomeB = findOneRealOneImaginary(a, b, c);
        std::cout << "x1: " << outcomeB.second  << " x2: " << outcomeB.first << 'i' << std::endl;
        return 0;
    case 1:
        std::cout << "Two real solutions" << std::endl;
        outcomeA = findTwoRealParts(a, b, c);
        std::cout << "x1: " << outcomeA.first << " x2: " << outcomeA.second << std::endl;
        return 1;
    default:    
        std::cout << "Error" << std::endl;
    }

    return 0;
}