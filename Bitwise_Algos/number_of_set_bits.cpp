#include <iostream>
using namespace std;


int way_1(int number)
{
    // While the number isn't zero, keep shifting one bit to the right, and checking 
    // if the last bit is zero or not. We can get the last bit of a number using the & operator
    int count = 0;
    while (number != 0)
    {
        if (number&1 == 1)
        {
            count++;
        }
        number = number >> 1; // Shifting the bits by 1 to right
    }
    return count;
}

int way_2(int number)
{
    // The following trick can be used to unset the least significant bit, meaning the rightmost set bit
    // which makes it faster than the way_1, whereas, the way 1 runs for log_2(n) times, this method would
    // only run till the number of set bits
    int count = 0;
    while (number != 0)
    {
        count++;
        number = number&(number-1);
    }
    return count;
}


int main()
{
    int number;
    cin >> number;

    cout << "Using way_1: " << way_1(number) << endl;
    cout << "Using way_2: " << way_2(number) << endl;

    return 0;
}