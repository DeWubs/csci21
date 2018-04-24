#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
/*this will take the last element as a pivot, place the pivot at the correct position
in the sorted array, then place all that are smaller to the left and the rest to the right
*/
int par(int arr[], int low, int high){
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = par(arr, low, high);
 
        // sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayArray(int arry[], int n){
    for (int i=0; i<n; ++i)
        cout << arry[i] << " ";
    cout << "\n";
}

int main(){
    int arr[] = {100, 70, 58, 39, 1, 5, 20, 44, 26};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    cout << "sorted array" << endl;
    displayArray(arr, n);
    return 0;
}