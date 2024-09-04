#include <iostream>
void countingSort(int arr[], int n) {
    int maxVal = arr[0];
    
    for(int i = 1; i < n; i++)
        if(arr[i] > maxVal)
            maxVal = arr[i];

    int count[maxVal+1] = 0;

    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    // change arr[] so that arr[] contains sorted characters
    int index = 0;
    for(int i = 0; i <= maxVal; i++)
        for(int j = 0; j < count[i]; j++)
            arr[index++] = i;
}