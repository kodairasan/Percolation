#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include "UnionFind.hpp"

using namespace std;

// 格子サイズ
const int GRID_SIZE = 300;
// 試行回数
const int NUM_TRIALS = 10;

// 2つのサイト間に結合を生成する
void connectBonds(UnionFind &unionFind, int gridSize, double bondProbability, mt19937 &randomGenerator)
{
    uniform_real_distribution<> distribution(0.0, 1.0);

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if (i + 1 < gridSize && distribution(randomGenerator) < bondProbability)
            {
                unionFind.merge(i * gridSize + j, (i + 1) * gridSize + j);
            }
            if (j + 1 < gridSize && distribution(randomGenerator) < bondProbability)
            {
                unionFind.merge(i * gridSize + j, i * gridSize + j + 1);
            }
        }
    }
}

int simulateBondPercolation(int gridSize, double bondProbability)
{
    UnionFind unionFind(gridSize * gridSize);
    random_device rd;
    mt19937 randomGenerator(rd());

    connectBonds(unionFind, gridSize, bondProbability, randomGenerator);

    return unionFind.get_max_size();
}

int main()
{
    vector<double> bondProbabilities = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    vector<double> percolationProbabilities;

    for (double bondProbability : bondProbabilities)
    {
        double averageMaxSize = 0;
        double percolationProbability = 0;
        int totalMaxSize = 0;

        for (int j = 0; j < NUM_TRIALS; j++)
        {
            int maxSize = simulateBondPercolation(GRID_SIZE, bondProbability);
            totalMaxSize += maxSize;
        }

        averageMaxSize = (double)totalMaxSize / NUM_TRIALS;
        percolationProbability = averageMaxSize / (GRID_SIZE * GRID_SIZE);

        cout << "p = " << bondProbability << ", average_max_size = " << averageMaxSize << ", percolation_probability = " << percolationProbability << endl;
        percolationProbabilities.push_back(percolationProbability);
    }

    ofstream outputfile("percolation_probability.txt");
    for (int i = 0; i < bondProbabilities.size(); i++)
    {
        outputfile << bondProbabilities[i] << " " << percolationProbabilities[i] << endl;
    }

    return 0;
}