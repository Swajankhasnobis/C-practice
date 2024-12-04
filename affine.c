#include <stdio.h>

// Function to find the modular inverse of 'a' under modulo 26
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // No modular inverse if it returns -1
}

// Function to decrypt an Affine cipher text
void decryptAffineCipher(char* ciphertext, int a, int b) {
    int a_inv = modInverse(a, 26); // Calculate a's modular inverse
    if (a_inv == -1) {
        printf("Inverse of %d under modulo 26 does not exist.\n", a);
        return;
    }

    printf("Decrypted text: ");
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];
        if (ch >= 'A' && ch <= 'Z') { // For uppercase letters
            ch = (a_inv * (ch - 'A' - b + 26)) % 26 + 'A';
        } else if (ch >= 'a' && ch <= 'z') { // For lowercase letters
            ch = (a_inv * (ch - 'a' - b + 26)) % 26 + 'a';
        }
        printf("%c", ch);
    }
    printf("\n");
}

int main() {
    char ciphertext[] = "PWUFFOGWCHFDWIWEJOUUNJORSMDWRHVCMWJUPVCCG";  // Example encrypted text
    int a = 11;  // Multiplicative key
    int b = 4;  // Additive key

    decryptAffineCipher(ciphertext, a, b);
    return 0;
}
