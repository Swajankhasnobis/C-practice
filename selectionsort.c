#include <stdio.h>
int main() {
    int i, j, m, n,temp;
    int arr[100];
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);
    printf("Enter the array elements :\n");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

    for (i = 0; i < n-1; i++) 
    {
        m = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[m])
                m = j;
        temp = arr[m];
        arr[m] = arr[i];
        arr[i] = temp;
    }
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
