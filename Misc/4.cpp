#include <cstdlib>
#include <iostream>

using namespace std;

int main(void) {
    int arr[5] = {6,5,4,3,2};
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if(arr[i] > arr[j])
            {
                int x = arr[i];
                arr[i] = arr[j];
                arr[j] = x;
            }
        }
        
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    
    

}