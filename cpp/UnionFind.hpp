#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include <vector>

class UnionFind
{
public:
    UnionFind() = default;
    explicit UnionFind(size_t n);

    int find(int i);
    void merge(int a, int b);
    bool connected(int a, int b);
    int size(int i);
    int get_max_size();

private:
    std::vector<int> m_parentsOrSize;
    int max_size;
};

#endif