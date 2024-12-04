#include <stdio.h>
int main() 
{ 
    int i, j, k,n;
    int arr[100];
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    for (i = 1; i < n; i++) 
    {
        k = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > k) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
