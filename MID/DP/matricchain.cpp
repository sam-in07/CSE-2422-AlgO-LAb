
#include <bits/stdc++.h>
using namespace std;


int minMultRec(vector<int> &arr, int i, int j)
{

    
    if (i + 1 == j)
        return 0;

    int res = INT_MAX;

    
    for (int k = i + 1; k < j; k++)
    {
        int curr = minMultRec(arr, i, k) + minMultRec(arr, k, j) + arr[i] * arr[k] * arr[j];

        res = min(curr, res);
    }

    
    return res;
}

int maxt_multi(vector<int> &arr)
{

    int n = arr.size();
    return minMultRec(arr, 0, n - 1);
}

int main()
{
    int n ;
    cin >> n ; 
    vector<int> arr(n);
    for(int i = 0 ; i<n ; i++) {
        cin >> arr[i];
    }
    cout << maxt_multi(arr);
    return 0;
}
