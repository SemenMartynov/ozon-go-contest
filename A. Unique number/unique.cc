#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

int main(int argc, char *argv[])
{
    std::unordered_map<long long int, long long int> dict;

    std::ifstream cin("input-201.txt");
    std::ofstream cout("input-201.a.txt");

    long long int key;
    while (cin >> key)
    {
        // Complexity: Average case O(1), worst case O(size()).
        dict[key] += 1;
    }

    // Complexity: worst case O(n).
    for (auto rec : dict)
    {
        if (rec.second % 2)
        {
            cout << rec.first << std::endl;
            break;
        }
    }

    return 0;
}