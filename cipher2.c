#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *str = (char *)malloc(100 * sizeof(char)); 
    if (str == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter string sequence: ");
    scanf("%s", str);

    char alph[26];
    int freq[26] = {0};
    for (int i = 0; i < 26; i++) 
    {
        alph[i] = 'A' + i; 
    }

    int l = strlen(str);

   
    for (int i = 0; i < l; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            freq[str[i] - 'A']++;
        }
    }

   
    int max_index = 0;
    for (int i = 1; i < 26; i++) {
        if (freq[i] > freq[max_index]) {
            max_index = i;
        }
    }

   
    int key = (max_index >= ('E' - 'A')) ? max_index - ('E' - 'A') : 26 - (('E' - 'A') - max_index);

    
    char *res = (char *)malloc((l + 1) * sizeof(char)); 
    if (res == NULL) {
        printf("Memory allocation failed.\n");
        free(str);
        return 1;
    }

    for (int i = 0; i < l; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            res[i] = ((str[i] - 'A' - key + 26) % 26) + 'A';
        } else {
            res[i] = str[i]; 
        }
    }
    res[l] = '\0';

    printf("Decrypted message: %s\n", res);

    
    free(str);
    free(res);

    return 0;
}