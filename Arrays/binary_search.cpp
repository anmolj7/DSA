/*

    Given a sorted array, tell if the given element exists in that or not!

*/
#include <bits/stdc++.h>
using namespace std;


int bin_search(vector<int> arr, int n, int element)
{
    int low = 0;
    int high = n-1;
    int mid = (low+high)/2;

    while (low < high)
    {
        if (arr[mid] == element)
        {
            return mid;
        }

        else if (arr[mid] > element)
        {
            high = mid-1;
        }

        else 
        {
            low = mid+1;
        }
    }

    return -1;

}



int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (auto &i : arr)
        cin >> i;

    int k;
    cin >> k;
    int ans = bin_search(arr, n, k);
    if ( ans != 1 ) 
    {
        cout << ans;
    }
    else 
    {
        cout << "element not in the list";
    }

    return 0;
}