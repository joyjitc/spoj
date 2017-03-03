//SOLVED USING MERGE SORT

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
ull merge(int arr[], int l, int m, int r)
{
     int size = r - l + 1;
     int *a = new int[size];
     int i =l,j=m+1,k;
     ull inv = 0;
     for(k=0;k<size;k++)
     {
     	if(i<=m && j<=r)
     	{
     		if(arr[i]<arr[j])
     		{
     			a[k] = arr[i];
     			i++;
     		}
     		else
     		{
     			a[k] = arr[j];
     			inv += m-i +1;
     			j++;
     		}
     	}
     	else if(i<=m)
     	{
     		a[k] = arr[i];
     			i++;
     	}
     	else if(j<=r)
     	{
     		a[k] = arr[j];
     		j++;
     	}
     }

     k=0;
     i=l;
     while(i<=r)
     {
        arr[i]=a[k];
        i++;
        k++;
     }
     delete[] a;
     return inv;
}
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
ull mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        ull m = l+(r-l)/2;
 
        // Sort first and second halves
        ull x = mergeSort(arr, l, m);
        ull y = mergeSort(arr, m+1, r);
 
        ull z = merge(arr, l, m, r);
        
        return x+y+z;
    }
    else 
    	return 0;
}


/* Driver program to test above functions */
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int size;
    while(t--){

        cin>>size;
        int *arr = new int[size];
        for(int i = 0; i < size ; i++)
            cin>>arr[i];
        cout<<mergeSort(arr, 0, size - 1)<<endl;

    }

	// freopen("assignment_1_input.txt","r",stdin);
	// freopen("assignment_1_output.txt","w",stdout);
	// //freopen("input1.txt","r",stdin);
	// //freopen("output.txt","w",stdout);

	// int size;
	// cin>>size;
	// cout<<"size = "<<size<<endl;
	// int *arr = new int[size];
	// for(int i = 0; i < size ; i++)
	// 	cin>>arr[i];  
	// int arr_size = size; 
 //    //int arr[] = { 9, 12, 3, 1, 6, 8, 2, 5, 14, 13, 11, 7, 10, 4, 0 };
 //    //int arr_size = sizeof(arr)/sizeof(arr[0]);
 //    cout<<"arr_size = "<<arr_size<<endl;
 	
 //    printf("Given array is \n");
 //    printArray(arr, arr_size);
 
    
 //    std::cout<<"\ninversionCount = "<<mergeSort(arr, 0, arr_size - 1)<<std::endl;
 
 //    printf("\nSorted array is \n");
 //    printArray(arr, arr_size);
    return 0;
}