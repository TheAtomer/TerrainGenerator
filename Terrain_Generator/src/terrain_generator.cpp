#include "terrain_generator.hpp"
#include "color_utils.hpp"
#include <iostream>
#include <algorithm>
#include <string>

TerrainConfig::TerrainConfig(int w, int h, double s, int oct, double pers)
    : width(w), height(h), scale(s), octaves(oct), persistence(pers) {}

TerrainGenerator::TerrainGenerator(const TerrainConfig& cfg)
    : config(cfg) {
    generateHeightMap();
    normalizeHeightMap();
}

void TerrainGenerator::generateHeightMap() {
    heightMap.resize(config.height, std::vector<double>(config.width));

    for (int y = 0; y < config.height; y++) {
        for (int x = 0; x < config.width; x++) {
            double nx = x * config.scale;
            double ny = y * config.scale;
            heightMap[y][x] = noiseGenerator.octaveNoise(nx, ny, config.octaves, config.persistence);
        }
    }
}

void TerrainGenerator::normalizeHeightMap() {
    double minVal = 1.0, maxVal = -1.0;

    for (const auto& row : heightMap) {
        for (double val : row) {
            minVal = std::min(minVal, val);
            maxVal = std::max(maxVal, val);
        }
    }

    double range = maxVal - minVal;
    if (range == 0) range = 1;

    for (auto& row : heightMap) {
        for (double& val : row) {
            val = (val - minVal) / range;
        }
    }
}

void TerrainGenerator::regenerate(const TerrainConfig& newConfig) {
    config = newConfig;
    generateHeightMap();
    normalizeHeightMap();
}

void TerrainGenerator::displayTerrain() const {
    const char* block = "\u2588";

    for (int y = 0; y < config.height; y++) {
        for (int x = 0; x < config.width; x++) {
            double h = heightMap[y][x];
            const char* color = ColorUtils::getColorByHeight(h);
            std::cout << color << block;
        }
        std::cout << ColorUtils::COLOR_RESET << std::endl;
    }
}

void TerrainGenerator::displayTerrainWithDetails() const {
    const char* blocks[] = { " ", "\u2591", "\u2592", "\u2593", "\u2588" };

    for (int y = 0; y < config.height; y++) {
        for (int x = 0; x < config.width; x++) {
            double h = heightMap[y][x];
            ColorUtils::TerrainInfo info = ColorUtils::getTerrainInfo(h);
            int densityIndex = ColorUtils::getBlockDensityIndex(info.type);
            std::cout << info.color << blocks[densityIndex];
        }
        std::cout << ColorUtils::COLOR_RESET << std::endl;
    }
}

void TerrainGenerator::displayLegend() const {
    std::cout << "\nTerrain Legend:\n";
    std::cout << ColorUtils::COLOR_DEEP_WATER << "\u2588" << ColorUtils::COLOR_RESET << " Deep Water  ";
    std::cout << ColorUtils::COLOR_SHALLOW_WATER << "\u2588" << ColorUtils::COLOR_RESET << " Shallow Water  ";
    std::cout << ColorUtils::COLOR_SAND << "\u2588" << ColorUtils::COLOR_RESET << " Sand  ";
    std::cout << ColorUtils::COLOR_GRASS_LOW << "\u2588" << ColorUtils::COLOR_RESET << " Low Grass  ";
    std::cout << ColorUtils::COLOR_GRASS_MID << "\u2588" << ColorUtils::COLOR_RESET << " Mid Grass\n";
    std::cout << ColorUtils::COLOR_GRASS_HIGH << "\u2588" << ColorUtils::COLOR_RESET << " High Grass  ";
    std::cout << ColorUtils::COLOR_MOUNTAIN_LOW << "\u2588" << ColorUtils::COLOR_RESET << " Low Mountain  ";
    std::cout << ColorUtils::COLOR_MOUNTAIN_MID << "\u2588" << ColorUtils::COLOR_RESET << " Mid Mountain  ";
    std::cout << ColorUtils::COLOR_MOUNTAIN_HIGH << "\u2588" << ColorUtils::COLOR_RESET << " High Mountain  ";
    std::cout << ColorUtils::COLOR_SNOW << "\u2588" << ColorUtils::COLOR_RESET << " Snow Peak\n";
}

void TerrainGenerator::printStats() const {
    double minHeight = 1.0, maxHeight = 0.0, avgHeight = 0.0;
    int totalCells = config.width * config.height;

    for (const auto& row : heightMap) {
        for (double h : row) {
            minHeight = std::min(minHeight, h);
            maxHeight = std::max(maxHeight, h);
            avgHeight += h;
        }
    }
    avgHeight /= totalCells;

    std::cout << "Terrain Statistics:\n";
    std::cout << "Size: " << config.width << "x" << config.height << "\n";
    std::cout << "Min Height: " << minHeight << "\n";
    std::cout << "Max Height: " << maxHeight << "\n";
    std::cout << "Avg Height: " << avgHeight << "\n";
    std::cout << "Parameters - Scale: " << config.scale
              << ", Octaves: " << config.octaves
              << ", Persistence: " << config.persistence << "\n";
}

const std::vector<std::vector<double>>& TerrainGenerator::getHeightMap() const {
    return heightMap;
}

const TerrainConfig& TerrainGenerator::getConfig() const {
    return config;
}
