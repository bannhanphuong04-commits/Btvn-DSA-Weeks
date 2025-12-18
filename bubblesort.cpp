#include <iostream>
using namespace std;

void bubble_sort(int A[], int n) {
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n- i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int t = A[j];
                A[j] = A[j + 1];
                A[j + 1] = t;
            }
        }
    }
}

int main() {
    int A[100] = { 3,10,1,23,103,34,17,53,64,71}, n;
    cin >> n;
    bubble_sort(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}