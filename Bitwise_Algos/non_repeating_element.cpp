#include <iostream>
using namespace std;

/*
    Given an array, where all the numbers appear twice, and only 1 number appears once. Find that number
*/


int unique_number(int* arr, int n)
{
    // We can use the XOR property to find the answer without having to use a hashmap 
    // XOR's property which we're going to use is the fact that 
    // a^a = 0, and a^0=a, and the fact that a^b^c is commutative
    int res = 0;
    for(int i=0; i<n; i++)
    {
        res = res ^ arr[i];
    }
    return res;
}

int main()
{

    int arr[] = {1, 1, 2, 3, 2, 4, 4, 5, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The number which appears only once is: " << unique_number(arr, n) << endl;

    return 0;
}