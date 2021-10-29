#include <iostream>
using namespace std;


int increment(int &number)
{
    // find the right most unset bit, and flip that, and then, unset all the bits right of that
    if( number & 1 == 0 )
    {
        // it's a even number, we can just return number | 1 
        return number | 1;
    }

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
    int number = 13;
    cout << increment(number);
    return 0;
}