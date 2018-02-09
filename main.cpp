#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>

using namespace std;
//Print Array
void printArray(vector<int> & a_vector, int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", a_vector[i]);

}
//Swap
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//Bubble Sort
void bubbleSort(vector<int> & a_vector, int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (a_vector[j] > a_vector[j+1])
              swap(&a_vector[j], &a_vector[j+1]);
}

//Insertion Sort
void insertionSort(vector<int> & a_vector, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a_vector[i];
        j = i-1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && a_vector[j] > key)
        {
            a_vector[j+1] = a_vector[j];
            j = j-1;
        }
        a_vector[j+1] = key;
    }
}
//Selection Sort
void selectionSort(vector<int> & a_vector, int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (a_vector[j] < a_vector[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&a_vector[min_idx], &a_vector[i]);
    }
}

void merge(vector<int> & a_vector, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = a_vector[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a_vector[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a_vector[k] = L[i];
            i++;
        }
        else
        {
            a_vector[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        a_vector[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        a_vector[k] = R[j];
        j++;
        k++;
    }
}

//Mege Sort
void mergeSort(vector<int> & a_vector, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(a_vector, l, m);
        mergeSort(a_vector, m+1, r);
        merge(a_vector, l, m, r);
    }
}

// Driver program to test above functions
int main()
{
    int num;
    vector<int> a_vector1;
    vector<int> a_vector2;
    vector<int> a_vector3;
    vector<int> a_vector4;
    vector<int> a_vector0;

    vector<int> a_vector_begin;
    vector<int> a_vector_mid;
    vector<int> a_vector_end;
    vector<int> a_vector_partially_sorted;
    vector<int>::iterator i;

    int element;
    const clock_t begin_time = clock();

    std::cout<<"Please input the array size for sorting: ";
    std::cin>>num;
    while (num>0){
        element= rand() % 10 + 1;
        a_vector1.push_back(element);
        num=num-1;
    }
    a_vector0=a_vector1;
    a_vector2=a_vector1;
    a_vector3=a_vector1;
    a_vector4=a_vector1;

   cout<<"Sorting..."<<endl;
   bubbleSort(a_vector0, a_vector0.size());
   //cout<<"Use sorted Large Array as input"<<endl;
   cout<<"Use partially sorted Large Array as input"<<endl;
   cout<<endl;


// for fully sorted one, just set the original vector to the sorted vector.
   // a_vector1=a_vector0;
   // a_vector2=a_vector0;
   // a_vector3=a_vector0;
   // a_vector4=a_vector0;

// // for partially sorted one, combine the sorted vector with the original vector.
    for(i = a_vector0.begin(); i < a_vector0.begin() + num * 0.05; i++)
        a_vector_begin.push_back(*i);
    for(i = a_vector0.begin() + num * 0.95; i != a_vector0.end(); i++)
        a_vector_end.push_back(*i);
    for(i = a_vector0.begin() + num * 0.05; i != a_vector0.begin() + num * 0.95; i++)
        a_vector_mid.push_back(*i);

    a_vector_begin.insert(a_vector_begin.end(),a_vector_mid.begin(),a_vector_mid.end());
    a_vector_begin.insert(a_vector_begin.end(),a_vector_end.begin(),a_vector_end.end());

    a_vector1 = a_vector_begin;
    a_vector2 = a_vector_begin;
    a_vector3 = a_vector_begin;
    a_vector4 = a_vector_begin;
    
    cout<<"Bubble Sort"<<endl;
    cout<<"Before sorting: ";
    //printArray(a_vector1, a_vector1.size());
    cout<<"Omit the input number.";
    cout<<endl;
    clock_t start1 = clock();
    bubbleSort(a_vector1, a_vector1.size());
    clock_t stop1 = clock();
    double elapsed1 = (double)(stop1 - start1) * 1000.0 / CLOCKS_PER_SEC;
    cout<<"After sorting: ";
    //printArray(a_vector1, a_vector1.size());
    cout<<"Omit the output number.";
    cout<<endl;
    printf("Time elapsed in Bubble_Sort is: %f  ms.", elapsed1);
    cout<<endl;
    cout<<"--------------------------"<<endl;

    cout<<"Insertion Sort"<<endl;
    cout<<"Before sorting: ";
    //printArray(a_vector2, a_vector2.size());
    cout<<"Omit the input number.";
    cout<<endl;
    clock_t start2 = clock();
    insertionSort(a_vector2, a_vector2.size());
    clock_t stop2 = clock();
    double elapsed2 = (double)(stop2 - start2) * 1000.0 / CLOCKS_PER_SEC;
    cout<<"After sorting: ";
    //printArray(a_vector2, a_vector2.size());
    cout<<"Omit the output number.";
    cout<<endl;
    printf("Time elapsed in insertion_Sort is: %f ms.", elapsed2);
    cout<<endl;
    cout<<"--------------------------"<<endl;

    cout<<"Selection Sort"<<endl;
    cout<<"Before sorting: ";
    //printArray(a_vector3, a_vector3.size());
    cout<<"Omit the input number.";
    cout<<endl;
    clock_t start3 = clock();
    insertionSort(a_vector3, a_vector3.size());
    clock_t stop3 = clock();
    cout<<"After sorting: ";
    //printArray(a_vector3, a_vector3.size());
    cout<<"Omit the output number.";
    cout<<endl;
    double elapsed3 = (double)(stop3 - start3) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in selection_Sort is: %f ms.", elapsed3);
    cout<<endl;
    cout<<"--------------------------"<<endl;

    cout<<"Merge Sort"<<endl;
    cout<<"Before sorting: ";
    //printArray(a_vector4, a_vector4.size());
    cout<<"Omit the input number.";
    cout<<endl;
    clock_t start4 = clock();
    mergeSort(a_vector4,0,a_vector4.size()-1);
    clock_t stop4 = clock();
    cout<<"After sorting: ";
    //printArray(a_vector4, a_vector4.size());
    cout<<"Omit the output number.";
    cout<<endl;
    double elapsed4 = (double)(stop4 - start4) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in Merge_Sort is: %f ms.", elapsed4);
    cout<<endl;
    cout<<"--------------------------"<<endl;

    return 0;
}