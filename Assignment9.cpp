#include<iostream>
using namespace std;

class heapSort
{
public:
    void heapify(int arr[], int n, int root);
    void heapalgo(int arr[], int n);
};

void heapSort::heapify(int arr[], int n, int root)
{
    int largest = root;
    int lc = 2 * root + 1;
    int rc = 2 * root + 2;

    if (lc < n && arr[lc] > arr[largest])
    {
        largest = lc;
    }
    if (rc < n && arr[rc] > arr[largest])
    {
        largest = rc;
    }
    if (largest != root)
    {
        int temp = arr[largest];
        arr[largest] = arr[root];
        arr[root] = temp;

        cout << "Heapify: ";
        for (int i = 0; i < n; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        heapify(arr, n, largest);
    }
}

void heapSort::heapalgo(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        cout << "Iteration " << n - i << ": ";
        for (int j = 0; j < n; ++j)
        {
            cout << arr[j] << " ";
        }
        cout << endl;

        heapify(arr, i, 0);
    }
}

int main()
{
    cout << "How many numbers do you want to sort?" << endl;
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the numbers: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    heapSort H;
    H.heapalgo(arr, n);
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
