//NAME : MALIK ABDUL HADI
//REG NO: 200901053
//COURSE : OPERATING SYSTEM
//SECTION: B
#include <iostream>
#include <vector>
#include <thread>

// In this function we are merging two sorted array.
void merge(std::vector<int>& arr, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    std::vector<int> temp(right - left + 1);

    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int i = left; i <= right; i++)
        arr[i] = temp[i - left];
}

// In this function we are sorting an array using merge sort algorithm.
void merge_sort(std::vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Divide the array into 4 threads
        std::thread t1(merge_sort, std::ref(arr), left, mid);
        std::thread t2(merge_sort, std::ref(arr), mid + 1, right);
        std::thread t3(merge_sort, std::ref(arr), left, mid);
        std::thread t4(merge_sort, std::ref(arr), mid + 1, right);
        t1.join();
        t2.join();
        t3.join();
        t4.join();

        // Merge the sorted subarrays
        merge(arr, left, mid, right);
    }
}

int main()
{
    //Taking array size from user.
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    // Taking the array’s element from user.
    std::vector<int> arr(n);
    std::cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    // Calling merge sort function, where we are sorting the array using 4 threads.
    merge_sort(arr, 0, n - 1);

    // Printing the sorted array.
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
