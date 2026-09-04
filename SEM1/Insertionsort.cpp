#include <iostream>
#include <random>



void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}




int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 10);
    int arr[10];
    

    for (int n = 0; n < 10; ++n)
    {
        std::cout << distrib(gen) << ' ';
        std::cout << '\n';
    }

    
    InsertionSort(arr, 10);

    for (int n = 0; n < 10; ++n)
    {
        std::cout << arr[n] << ' ';
    }




    std::cout << '\n';
}