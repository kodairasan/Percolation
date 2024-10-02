#include <algorithm> // std::max()
#include <utility>   // std::swap()
#include "UnionFind.hpp"

UnionFind::UnionFind(size_t n)
    : m_parentsOrSize(n, -1), max_size(1) {}

int UnionFind::find(int i)
{
    if (m_parentsOrSize[i] < 0)
    {
        return i;
    }
    return (m_parentsOrSize[i] = find(m_parentsOrSize[i]));
}

void UnionFind::merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (-m_parentsOrSize[a] < -m_parentsOrSize[b])
        {
            std::swap(a, b);
        }
        m_parentsOrSize[a] += m_parentsOrSize[b];
        m_parentsOrSize[b] = a;
        max_size = std::max(max_size, -m_parentsOrSize[a]);
    }
}

bool UnionFind::connected(int a, int b)
{
    return (find(a) == find(b));
}

int UnionFind::size(int i)
{
    return -m_parentsOrSize[find(i)];
}

int UnionFind::get_max_size()
{
    return max_size;
}