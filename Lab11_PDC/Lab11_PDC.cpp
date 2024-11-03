#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

void floydWarshall(int n, std::vector<std::vector<int>>& dist) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    std::string inputFileName, outputFileName;
    std::cout << "Enter input file name: ";
    std::cin >> inputFileName;
    std::cout << "Enter output file name: ";
    std::cin >> outputFileName;

    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }

    int n, m;
    inputFile >> n >> m;

    // Initialize the distance matrix with INF and 0 on the diagonal
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    // Read edges and fill the distance matrix
    for (int i = 0; i < m; ++i) {
        int v, u, w;
        inputFile >> v >> u >> w;
        dist[v][u] = w;
    }
    inputFile.close();

    // Run Floyd-Warshall algorithm
    floydWarshall(n, dist);

    // Output results to the console and the output file
    std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "Error opening output file!" << std::endl;
        return 1;
    }

    std::cout << "Shortest distances between every pair of vertices:\n";
    outputFile << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                std::cout << "INF ";
                outputFile << "INF ";
            }
            else {
                std::cout << dist[i][j] << " ";
                outputFile << dist[i][j] << " ";
            }
        }
        std::cout << "\n";
        outputFile << "\n";
    }

    outputFile.close();
    std::cout << "Results have been written to " << outputFileName << std::endl;

    return 0;
}
