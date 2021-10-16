/*

    implement bubble sort!

*/
#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr, int n)
{
    /*
        Constantly bring the biggest element to the last!
    */
   int last = n-1;
   while ( last != 0 )
   {
       int current_max = INT_MIN;
       for ( int i=0; i<last; i++)
       {
           if ( arr[i] > arr[i+1] )
           {
               swap(arr[i], arr[i+1]);
           }
       }
       last--;
   }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (auto &i : arr)
        cin >> i;

    bubble_sort(arr, n);

    for (auto i: arr)
        cout << i << " ";
    cout << endl;


    return 0;
}