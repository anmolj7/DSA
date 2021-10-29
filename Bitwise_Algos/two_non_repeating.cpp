#include <iostream>
#include <vector>
using namespace std;

/*
    Print the two non repeating integers from the array
*/

int right_most_set_bit(int number)
{
    // returns the index of the rightmost set bit from the right
    // for example, (11000100)_2 would return 3
    int count = 0;
    while ((number & 1) == 0)
    {
        count++;
        number = number >> 1; // Shift by 1
    }
    return count;
}

void two_unique(int *arr, int n)
{
    // this time, the result would store the result of the two remaining numbers, instead of a single number
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res ^ arr[i];
    }
    // Find the rightmost set bit
    int right_bit = right_most_set_bit(res);
    cout << right_bit << endl;
    // After finding the index of the rightmost set bit, we need to separate the array into two parts
    // on the basis of that particular shift
    vector<int> left_part;
    vector<int> right_part;

    for (int i = 0; i < n; i++)
    {
        // To check if the nth bit from right is set or not, we can just use the & operator with <<
        // So, we just right shift the number by the index we wanna check, and then just use  & 1 to get
        // the last bit
        int temp = (arr[i] >> right_bit) & 1;
        if (temp == 1)
        {
            left_part.push_back(arr[i]);
        }
        else
        {
            right_part.push_back(arr[i]);
        }
    }

    int left_res = res, right_res = res;
    for (auto i : left_part)
    {
        left_res = left_res ^ i;
    }
    cout << "The first unique number: " << left_res << endl;
    for (auto i : right_part)
    {
        right_res = right_res ^ i;
    }
    cout << "The second unique number: " << right_res << endl;
}

int main()
{
    int arr[] = {1, 1, 2, 3, 4, 4, 5, 5, 6, 7, 6, 7, 3, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    two_unique(arr, n);
    return 0;
}