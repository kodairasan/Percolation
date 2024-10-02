from unionfind import UnionFind
from random import random
import numpy as np
import matplotlib.pyplot as plt


def bond_percolation(L, p):
    uf = UnionFind(L * L)
    for i in range(L):
        for j in range(L):
            if i + 1 < L and random() < p:
                uf.union(i * L + j, (i + 1) * L + j)
            if j + 1 < L and random() < p:
                uf.union(i * L + j, i * L + j + 1)
    return uf.max_size / L**2


def main():
    x = 20
    trial = 10
    L = np.array([5, 10, 20, 100])
    p = np.linspace(0, 1, x)
    num = list(range(x))
    res = {l: [0] * x for l in L}

    for l in L:
        for i in num:
            tmp = 0
            for _ in range(trial):
                tmp += bond_percolation(l, p[i])
            res[l][i] = tmp / trial

    for l in L:
        plt.plot(p, res[l], label=f"L={l}", marker="o")
    plt.xlabel("p")
    plt.ylabel("S")
    plt.legend()
    plt.show()


if __name__ == "__main__":
    main()
