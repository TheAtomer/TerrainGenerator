/**
 * Demo 04: Large Scale Features
 * 演示大型地形特征生成
 */

#include "terrain_generator.hpp"
#include <iostream>

int main() {
    std::cout << "=== Demo 04: Large Scale Features ===\n" << std::endl;
    std::cout << "Configuration: Very low scale (0.01)\n\n";

    TerrainConfig config(80, 30, 0.01, 5, 0.5);
    TerrainGenerator terrain(config);

    terrain.displayTerrain();
    terrain.displayLegend();
    terrain.printStats();

    std::cout << "\n\nTips:\n";
    std::cout << "- Use very low scale (0.005-0.015) for large features\n";
    std::cout << "- This creates sweeping landscapes with big continents and oceans\n";
    std::cout << "- Great for world maps or large game maps\n";

    return 0;
}
