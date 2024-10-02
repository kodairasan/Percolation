#include <iostream>
#include <string>
#include <random>
#include "UnionFind.hpp"

using namespace std;

int main()
{
    int n = 100;
    UnionFind uf(n * n);

    uf.merge(0, 1);
    uf.merge(1, 2);

    cout << uf.connected(0, 2) << endl;
    cout << uf.get_max_size() << endl;
}
