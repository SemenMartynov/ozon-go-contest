#include <iostream>
#include <bits/stdc++.h>

#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    /*
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
    for (size_t i = 1; i != lenSum + 1; i++)
    {
        a = i > lenA ? 0 : termA[lenA - i] - '0';
        b = i > lenB ? 0 : termB[lenB - i] - '0';
        r = a + b + carry;
        carry = 0;

        if (r > 9)
        {
            r -= 10;
            carry = 1;
        }

        sum[i - 1] = r + '0';
    }

    if (sum[lenSum - 1] == '0')
    {
        lenSum--;
    }

    for (size_t i = lenSum - 1; i != -1; i--)
    {
        std::cout << sum[i];
    }
    std::cout << std::endl;

    return 0;
    */

    bool isEmpty = true;
    int cin = open("input.txt", O_RDONLY);
    off_t size = lseek(cin, 0, SEEK_END);
    char *buffer = (char *)mmap(NULL, size, PROT_READ, MAP_PRIVATE, cin, 0);

    char *it = buffer;
    size_t lenA = 0;
    while (*it != ' ')
    {
        lenA++;
        it++;
    }
    size_t lenB = size - lenA - 1;
    size_t lenResp = lenA > lenB ? lenA + 1 : lenB + 1;
    char *resp = new char[lenResp];

    int a = 0;
    int b = 0;
    int r = 0;
    int carry = 0;
    for (size_t i = 1; i != lenResp + 1; i++)
    {
        //std::cout << "i=" << i << ", lenA=" << lenA << ", lenB=" << lenB << std::endl;
        a = i > lenA ? 0 : buffer[lenA - i] - '0';
        b = i > lenB ? 0 : buffer[lenA + 1 + lenB - i] - '0'; // '+1' is a space delimiter
        r = a + b + carry;
        carry = 0;

        //std::cout << r << ": a=" << a << ", b=" << b << ", carry=" << carry << std::endl;
        if (r > 9)
        {
            r -= 10;
            carry = 1;
        }

        resp[lenResp - i] = r + '0';
    }

    std::cout << "'";
    for (size_t i = 0; i != lenResp; i++)
    {
        std::cout << resp[i];
    }
    std::cout << "'" << std::endl;
    //std::cout << buffer[lenA-1] << " " << buffer[lenA + lenB - 1] << std::endl;

    close(cin);
    munmap(buffer, size);
    delete (resp);
}