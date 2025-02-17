#include <stdio.h>


void countFrequency(int arr[], int n) {
    
    int visited[n];

    
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    
    for (int i = 0; i < n; i++) {
     
        if (visited[i] == 1)
            continue;

        
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1; 
            }
        }

        
        if (visited[i] == 0)
            printf("%d occurs %d times\n", arr[i], count);
    }
}

int main() {
    int n;

    
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    
    printf("Frequency of elements:\n");
    countFrequency(arr, n);

    return 0;
}