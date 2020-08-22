#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {
    char termA[1000];    
    char termB[1000];
    char sum[1001];

    std::cin >> termA >> termB;

    size_t lenA = strlen(termA);
    size_t lenB = strlen(termB);
    size_t lenSum = lenA > lenB ? lenA + 1 : lenB + 1;

    int a = 0;
    int b = 0;
    int r = 0;
    int carry = 0;
    for(size_t i = 1; i != lenSum + 1; i++) {
        a = i > lenA ? 0 : termA[lenA - i] - '0';
        b = i > lenB ? 0 : termB[lenB - i] - '0';
        r = a + b + carry;
        carry = 0;

        if (r > 9) {
            r -= 10;
            carry = 1;
        }

        sum[i - 1] = r + '0';
    }

    if (sum[lenSum - 1] == '0') {
        lenSum--;
    }

    for(size_t i = lenSum - 1; i != -1; i--) {
        std::cout << sum[i];
    }
    std::cout << std::endl;
}