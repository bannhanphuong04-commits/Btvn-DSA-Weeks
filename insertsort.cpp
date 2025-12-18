#include <iostream>
using namespace std;

void insertion_sort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int a = A[i], p = i - 1;
        while (p >= 0 && a < A[p]) {
            A[p + 1] = A[p];
            --p;
        }
        A[p + 1] = a;
       
    }
}

int main() {
    int A[100] = { 3,10,1,23,103,34,17,53,64,71 }, n;
    cin >> n;
    insertion_sort(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}