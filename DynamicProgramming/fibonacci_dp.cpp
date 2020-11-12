#include <iostream>

using namespace std;

int fibonacciDp(int n) {
    int arr[n + 1];
    arr[0] = 0; arr[1] = 1;

    for(int i = 2; i <= n; i++)
        arr[i] = arr[i - 1] + arr[i - 2];
    
    return arr[n];
}

int fibonacciRecursive(int i) {
    if(i == 0)
        return 0;
    
    if(i == 1)
        return 1;
    
    return fibonacciRecursive(i - 1) + fibonacciRecursive(i - 2);
}

int main() {
    cout << fibonacciDp(10) << endl;
    cout << fibonacciRecursive(10) << endl;
}