#include <iostream>
using namespace std;
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
int partition(int a[], int l, int r, int n) {
    int p = a[l];
    int i = l - 1, j = r + 1;
    while (1) {
        do {
            ++i;
        } while (a[i] < p);
        do {
            --j;
        } while (a[j] > p);
        if (i < j) {
            swap(a[i], a[j]);
            cout << "Sau khi hoan doi a[" << i << "] va a[" << j << "]: ";
            printArray(a, n);
        }
        else return j;
    }
}

void quick_sort(int a[], int l, int r, int n) {
    if (l >= r) return;
    int t = partition(a, l, r, n);
    quick_sort(a, l, t, n);
    quick_sort(a, t + 1, r, n);
}

int main() {
    int A[100] = {3, 10, 1, 23, 103, 34, 17, 53, 64, 71};
    int n;
    cin >> n;
    cout << "Mang ban dau: ";
    printArray(A, n);

    quick_sort(A, 0, n - 1, n);

    cout << "\nMang sau khi sap xep: ";
    printArray(A, n);
    return 0;
}
