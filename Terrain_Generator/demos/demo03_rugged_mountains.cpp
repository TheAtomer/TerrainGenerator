/**
 * Demo 03: Rugged Mountains
 * 演示如何生成崎岖的山地地形
 */

#include "terrain_generator.hpp"
#include <iostream>

int main() {
    std::cout << "=== Demo 03: Rugged Mountains ===\n" << std::endl;
    std::cout << "Configuration: High octaves (8), high persistence (0.8)\n\n";

    TerrainConfig config(80, 30, 0.025, 8, 0.8);
    TerrainGenerator terrain(config);

    terrain.displayTerrain();
    terrain.displayLegend();
    terrain.printStats();

    std::cout << "\n\nTips:\n";
    std::cout << "- Use high octaves (6-10) for more detail\n";
    std::cout << "- Use high persistence (0.7-0.9) for rugged terrain\n";
    std::cout << "- This creates jagged mountain peaks and valleys\n";

    return 0;
}
