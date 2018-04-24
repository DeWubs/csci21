/*
heap sort is based on Binary heap data structure
a hinary heap is a complete binary tree where its items are sorted into an order such that value
in a parent node is greater or smaller than the values in its two children nodes. (max an min heap)
the algorithm
    1. build a max heap from the input data
    2. once that is done the largest item is stored at the root of the heap, replace it with the
        last item of the heap followed by making the size of the heap smaller by one. then "heapify"
        the root of the tree
    3. repeat the above while size > 1
    
heapification must be preformed in the bottom up order
https://www.geeksforgeeks.org/heap-sort/
*/

#include <iostream>
using namespace std;
 
// To heapify a subtree rooted with node i which is
// an index in arry[]. n is size of heap
void heapify(int arry[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left is larger than root
    if (l < n && arry[l] > arry[largest])
        largest = l;
 
    // If right is larger than largest so far
    if (r < n && arry[r] > arry[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arry[i], arry[largest]);
 
        // Recursive, heapify the sub-tree
        heapify(arry, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arry[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arry, n, i);
 
    // One by one take an element from the heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arry[0], arry[i]);
 
        // call max heapify on the reduced heap
        heapify(arry, i, 0);
    }
}
 
/* A function to print array of size n */
void displayArray(int arry[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arry[i] << " ";
    cout << "\n";
}
 
int main()
{
    int arry[] = {100, 1, 53, 20, 6, 5, 21, 55, 15, 32};
    int n = sizeof(arry)/sizeof(arry[0]);
 
    heapSort(arry, n);
 
    cout << "Sorted arryay is \n";
    displayArray(arry, n);
}