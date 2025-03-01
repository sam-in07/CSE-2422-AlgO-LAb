#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll i , n , m , j , k;


ll getMax(const vector<ll>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// Function to perform counting sort based on the digit represented by exp (10^i)
void countingSort(vector<ll>& arr, int exp) {
    n = arr.size();
    vector<ll> output(n);
    vector<ll> count(10, 0);  
  
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}


void radixSort(vector<ll>& arr) {
  
    ll maxVal = getMax(arr);

    
    for (ll exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}


void printArray(const vector<ll>& arr) {
    for (i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

  
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<ll> v(n);


    cout << "Enter the elements of the array: ";
    for (i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << "Original array: ";
    printArray(v);

    
    radixSort(v);

    cout << "Sorted array: ";
    printArray(v);

    return 0;
}
