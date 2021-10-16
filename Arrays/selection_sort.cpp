/*

    Implement Selection sort

*/
#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr, int n)
{
    /*
    Every single time, find the lowest element, and bring it to the front!
    */
   int low = 0;
   while (low != n-1)
   {
       int current_min = INT_MAX;
       int min_index = low;
       for (int i=low; i<n; i++)
       {
           if ( arr[i] < current_min )
           {
               current_min = arr[i];
               min_index = i;
           }
       }
       swap(arr[low], arr[min_index]);
       cout << "Swapping " << low << " with " << min_index << endl;
       low++;
   }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (auto &i : arr)
        cin >> i;

    selection_sort(arr, n);

    for (auto i: arr)
        cout << i << " ";
    cout << endl;

    return 0;
}