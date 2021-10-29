#include <iostream>
using namespace std;


int increment(int &number)
{
    // 111
    int index = 0;
    int temp = number;
    while ( temp & 1 )
    {
        index++;
        temp = temp >> 1;
        number = number & (number - 1);
    }
    number = number | (1 << index);
    return number;
}


int main()
{
    int number = 14;
    cout << increment(number);
    return 0;
}