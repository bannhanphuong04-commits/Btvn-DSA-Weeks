#include <iostream>
using namespace std;
void selection_sort(int A[], int n) {
    for (int i = 0; i < n-1; i++) {
       int min = i;
       for (int j = i + 1; j < n; j++) {
           if (A[j] < A[min])
               min = j;
       }
    if (min != i) {
        int t = A[i];
        A[i] = A[min];
        A[min] = t;
       }
    }
 }
int main() {
    int A[100] = { 3,10,1,23,103,34,17,53,64,71}, n;
    cin >> n;
     selection_sort(A, n);
     for (int i = 0; i < n; i++)
         cout << A[i] << " ";
    return 0;
} 
