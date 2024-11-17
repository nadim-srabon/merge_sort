#include <stdio.h>
#include <stdlib.h>

int main()
{


   int arr = {2, 4, 6, 3, 8, 9};

   int n = sizeof(arr)/sizeof(arr[0]);

   int low = 0;
   int high = n - 1;

   int mid = (low+high)/2;

   merge(arr,low,high);

    return 0;
}


void divide_merge(int arr[], int low, int high, int mid){


    //Divide Part


    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1+1];
    int right[n2+1];

    for(int i = 0;i<=n1;i++){

            left[i] = arr[low+i];


    }

    for(int j = 0;j<=n2;j++){

            left[j] = arr[low+j];


    }

    left[n1+1] = 64546546;
    right[n2+1] = 9879846;


    //Merged Part

    for(int k = low;k<=high;k++){

        if(left[i]<=right[i]){
            arr[k] = left[i];
            i++;
        }
        else
            arr[k] = right[j];
            j++;
    }

}
void merge(arr,low,high){

    if(low<high){

        int mid = (low=high)/2;
        divide_merge(arr,low,high);
        divide_merge(arr,mid+1,high);
        merge(arr,low,mid,high);
    }



}
