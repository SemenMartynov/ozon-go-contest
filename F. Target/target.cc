#include <iostream>
#include <bits/stdc++.h>

#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    std::unordered_map<int, int> dominoes;

    int target = -1;
    int bone;
    bool isEmpty = true;
    int cin = open("input.txt", O_RDONLY);
    off_t size = lseek(cin, 0, SEEK_END);
    char *buffer = (char *)mmap(NULL, size, PROT_READ, MAP_PRIVATE, cin, 0);

    // low level read
    int bytes = size;
    char *it = buffer;
    while(bytes > 0) {
        if (*it == '\n' || *it == ' ') {
            if (target == -1)
                target = bone;
            if (!isEmpty && bone < target)
                dominoes[bone] += 1;
            bone = 0;
            it++;
            bytes--;
            isEmpty = true;
        }
        bone *= 10;
        bone += *it - '0';
        it++;
        bytes--;
        isEmpty = false;
    }
    if (!isEmpty && bone < target)
    dominoes[bone] += 1;
    close(cin);
    munmap(buffer, size);

    std::ofstream cout("output.txt");
    for (auto lhs: dominoes) { // O(n)
        auto rhs = dominoes.find(target - lhs.first);
        if (rhs != dominoes.end() && (lhs != *rhs || lhs.second > 1)) {
            //std::cout << lhs.first << " " << (*rhs).first << std::endl;
            cout << 1 << std::endl;
            return 0;
        }
    }

    cout << 0 << std::endl;
    return 0;
}