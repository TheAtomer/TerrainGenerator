/**
 * Demo 01: Basic Terrain Generation
 * 演示基本的地形生成功能
 */

#include "terrain_generator.hpp"
#include <iostream>

int main() {
    std::cout << "=== Demo 01: Basic Terrain Generation ===\n" << std::endl;

    TerrainConfig config(80, 30, 0.03, 5, 0.5);
    TerrainGenerator terrain(config);

    std::cout << "Basic terrain with default parameters:\n";
    terrain.displayTerrain();
    terrain.displayLegend();
    terrain.printStats();

    return 0;
}
