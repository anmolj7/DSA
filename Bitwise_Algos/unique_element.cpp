#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

/*
    Unique element in an array where all elements occur k times except one
    Problem link: https://www.geeksforgeeks.org/find-unique-element-element-occurs-k-times-except-one/
*/

int answer(int *arr, int n, int k)
{
    vector<int> ARR(32, 0);
    for (int i = 0; i < n; i++)
    {
        int number = arr[i];
        // We wanna go over every single bit of the number, and add them
        int index = 31;
        while (number != 0)
        {
            ARR[index] += number & 1;
            number = number >> 1;
            index--;
        }
    }

    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (ARR[i] % k != 0)
        {
            ans += pow(2, 31 - i);
        }
    }
    return ans;
}

int main()
{
    int k = 3;
    int arr[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 5, 6, 6, 6, 100, 100, 100, 1024, 1024, 1024};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "The answer is: " << answer(arr, size, k) << endl;

    return 0;
}