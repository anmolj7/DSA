/*

    Problem statement: reverse a given array in 0(n) time!
    problem link: https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

*/
#include <bits/stdc++.h>
using namespace std;


void reverse(vector<int> &arr, int n)
{
    for(int i=0; i<n/2; i++)
        swap(arr[i], arr[n-i-1]);
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (auto &i : arr)
        cin >> i;

    reverse(arr, n);

    for (auto i: arr)
        cout << i << " ";
    cout << endl;


    return 0;
}