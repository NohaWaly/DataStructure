//Noha Mostafa 20160262 Group IS_CS_3
//Nurhan Ihab  20160265  Group IS_CS_3
//Mostafa Weal 20160247  Group IS_CS_3


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node
{
    string functiontype;
    int start;
    int mid;
    int ending;
    node(string func, int s,int e,int m = 0)
    {
        functiontype = func;
        start = s;
        mid = m;
        ending = e;
    }

};

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

void merging(int arr[], int left, int middle, int right)
{
    //divide the array two halves
    int leftArrSize = middle - left + 1;
    int rightArrSize = right - middle;
    int *leftarr= new int[leftArrSize];
    int *rightarr = new int[rightArrSize];

    //assiging values to arrays
    for (int i = 0; i < leftArrSize; i++)
    {
        leftarr[i] = arr[left + i];
    }
    for (int j = 0; j < rightArrSize; j++)
    {
        rightarr[j] = arr[middle + j+1];
    }

    // merge the two arrys again in a sorted way
    int k = left, i = 0, j = 0;
    while (i < leftArrSize && j < rightArrSize)
    {
        if (leftarr[i] < rightarr[j])
        {
            arr[k++] = leftarr[i++];
        }
        else
        {
            arr[k++] = rightarr[j++];
        }
    }

    //complete puting elements if on of two arrays has finished before the other
    while (i < leftArrSize)
    {
        arr[k++] = leftarr[i++];
    }
    while (j < rightArrSize)
    {
        arr[k++] = rightarr[j++];
    }

}

void mergeSort(int arr[], int l, int r)
{

    node n("mergesort",l,r);
    stack <node> calls;

    calls.push(n);
    while(!calls.empty())
    {
        node call = calls.top();
        calls.pop();
        if(call.start >= call.ending)
        {
            continue;
        }
        if(call.functiontype != "merge")
        {
            int m = (call.start+call.ending)/2;
            node newnode1("mergesort",call.start, m);
            node newnode2("mergesort",m + 1,call.ending);
            node newnode3("merge",call.start,call.ending, m);
            calls.push(newnode3);
            calls.push(newnode2);
            calls.push(newnode1);
        }
        else
        {
            merging(arr,call.start,call.mid, call.ending);
        }
    }


}


int main()
{
    int arr[] = {20,7,3,3,44,5,2,0};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}

