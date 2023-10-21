#include <iostream>
#include <ios>
#include<limits>
#include <tuple>

using namespace std;

tuple<double, double> entry_error_handler()
{
    double lowerLimit, upperLimit;

    while (true)
    {
        try
        {
            cout <<"Please input the lower limit: ";
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
            cout << "Error: lower and upper limits must be a number with decimal point. Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

return make_tuple(lowerLimit, upperLimit);
}

int main()
{
    double a, b;

    tie(a, b) = entry_error_handler();
    cout << a << " " << b << endl;
}