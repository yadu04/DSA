#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bubblesort(int arr[], int n) {  
      if(n==1)
          return;
        int yes = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] <arr[i - 1]) {   // descending order
                swap(arr[i], arr[i - 1]);
                yes = 1;
            }
        }
        if(yes==0)
            return;
        bubblesort(arr, n - 1);
    }


int main() {
    int arr[5] = {5, 9, 1, 0, 2};

    bubblesort(arr, 5);

    cout << "The sorted order of the given array:" << endl;
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    return 0;
}
