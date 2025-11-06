#include <iostream>
#include <vector>
using namespace std;
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
void merge(int a[], int l, int m, int r, int n) {
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = 0, j = 0, k = l;
    while (i < x.size() && j < y.size()) {
        if (x[i] < y[j])
            a[k++] = x[i++];
        else
            a[k++] = y[j++];
    }
    while (i < x.size())
        a[k++] = x[i++];
    while (j < y.size())
        a[k++] = y[j++];
    cout << "Sau khi gop [" << l << ", " << m << "] va [" << m +]()
