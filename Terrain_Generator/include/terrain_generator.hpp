#ifndef TERRAIN_GENERATOR_HPP
#define TERRAIN_GENERATOR_HPP

#include <vector>
#include "perlin_noise.hpp"

struct TerrainConfig {
    int width;
    int height;
    double scale;
    int octaves;
    double persistence;

    TerrainConfig(int w = 80, int h = 40, double s = 0.02, int oct = 6, double pers = 0.6);
};

class TerrainGenerator {
private:
    PerlinNoise noiseGenerator;
    TerrainConfig config;
    std::vector<std::vector<double>> heightMap;

    void generateHeightMap();
    void normalizeHeightMap();

public:
    explicit TerrainGenerator(const TerrainConfig& cfg);

    void regenerate(const TerrainConfig& newConfig);
    void displayTerrain() const;
    void displayTerrainWithDetails() const;
    void displayLegend() const;
    void printStats() const;

    const std::vector<std::vector<double>>& getHeightMap() const;
    const TerrainConfig& getConfig() const;
};

#endif
