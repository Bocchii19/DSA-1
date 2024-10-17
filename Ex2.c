/*Bài 2: Thiết kế giải thuật và cài đặt để tạo ra một mảng số nửa nguyên tố (Blum) nhỏ hơn một số N cho trước và thực hiện hai yêu cầu sau
- Tìm ra tất cả các cặp số Blum có tổng cũng là một số Blum nhỏ hơn N
- Kiểm tra xem một số Blum M có tồn tại trong dãy số Blum được tạo ra hay không.*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 1000 

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int findPrimesMod3(int primes[], int N) {
    int count = 0;
    for (int i = 2; i < N; i++) {
        if (isPrime(i) && (i % 4 == 3)) {
            primes[count++] = i;
        }
    }
    return count;
}

int generateBlumNumbers(int blumNumbers[], int primes[], int primeCount, int N) {
    int count = 0;

    for (int i = 0; i < primeCount; i++) {
        for (int j = i + 1; j < primeCount; j++) {
            int blum = primes[i] * primes[j];
            if (blum < N) {
                blumNumbers[count++] = blum;
            }
        }
    }
    return count;
}

bool contains(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

void findBlumPairsWithBlumSum(int blumNumbers[], int blumCount, int N) {
    printf("Các cặp số Blum có tổng là số Blum nhỏ hơn %d:\n", N);
    for (int i = 0; i < blumCount; i++) {
        for (int j = i + 1; j < blumCount; j++) {
            int sum = blumNumbers[i] + blumNumbers[j];
            if (sum < N && contains(blumNumbers, blumCount, sum)) {
                printf("%d + %d = %d\n", blumNumbers[i], blumNumbers[j], sum);
            }
        }
    }
}

int main() {
    int N = 100; 
    int primes[MAX];  
    int blumNumbers[MAX];

    int primeCount = findPrimesMod3(primes, N);

    int blumCount = generateBlumNumbers(blumNumbers, primes, primeCount, N);

    printf("Các số Blum nhỏ hơn %d: ", N);
    for (int i = 0; i < blumCount; i++) {
        printf("%d ", blumNumbers[i]);
    }
    printf("\n");

    findBlumPairsWithBlumSum(blumNumbers, blumCount, N);

    int M = 21;
    if (contains(blumNumbers, blumCount, M)) {
        printf("%d là số Blum.\n", M);
    } else {
        printf("%d không phải là số Blum.\n", M);
    }

    return 0;
}


