#include "Controller.h"
using namespace std;

// constructor
Controller::Controller(unsigned int max, std::initializer_list<Model *> ms)
    : max_steps{max}, models{std::vector<Model *>(ms)} {}

// getters
unsigned int Controller::get_max_steps() const { return max_steps; }
std::vector<Model *> &Controller::get_models() { return models; }

// setters
void Controller::set_max_step(unsigned int max) { max_steps = max; }

#include <iostream>
#include <tuple>

using namespace std;

tuple<double, double> entry_error_handler()
{
    double lowerLimit, upperLimit;

    while (true)
    {
        try
        {
            cout << "Please input the lower limit: ";
            cin >> lowerLimit;
            if (cin.fail())
            {
                throw(lowerLimit);
            }
            cout << "Please input the upper limit: ";
            cin >> upperLimit;
            if (cin.fail())
            {
                throw(upperLimit);
            }
            break;
        }
        catch (double e)
        {
            cout << "\nError: lower and upper limits must be a number with decimal point. Please try again ";
            break;
        }
    }

return make_tuple(lowerLimit, upperLimit);
}