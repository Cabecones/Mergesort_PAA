#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Function to merge two sorted halves of the array
void merge(vector<int>& arr, int l, int m, int r)
{
    // sizes of the two halves
    int size1 = m - l + 1;
    int size2 = r - m;

    // create temporary vectors to store the two halves
    vector<int> left(size1);
    vector<int> right(size2);

    // copy the elements from arr to the temporary vectors
    for (int i = 0; i < size1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < size2; j++)
        right[j] = arr[m + 1 + j];

    // initialize indices for the temporary vectors and the original array
    int i = 0, j = 0, k = l;

    // merge the two halves back into the original array
    while (i < size1 && j < size2)
    {
        // choose the smaller of the two elements
        // and put it at the current position in the array
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // put any remaining elements from the left vector back into the array
    while (i < size1)
        arr[k++] = left[i++];

    // put any remaining elements from the right vector back into the array
    while (j < size2)
        arr[k++] = right[j++];
}

// Recursive function to sort the array using merge sort
void mergeSort(vector<int>& arr, int l, int r)
{
    if (l < r)
    {
        // find the middle index
        int m = l + (r - l) / 2;

        // sort the two halves of the array
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // merge the sorted halves
        merge(arr, l, m, r);
    }
}

int main()
{
    // read the numbers from a single line of input
    string line;
    getline(cin, line);

    // create a string stream from the input line
    stringstream ss(line);

    // create a vector to store the elements
    vector<int> arr;

    // read the elements from the input line
    int x;
    while (ss >> x)
        arr.push_back(x);

    // sort the array using merge sort
    mergeSort(arr, 0, arr.size() - 1);

    // print the sorted array
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}
