/**
 * Demo 02: Smooth Plains
 * 演示如何生成平滑的平原地形
 */

#include "terrain_generator.hpp"
#include <iostream>

int main() {
    std::cout << "=== Demo 02: Smooth Plains ===\n" << std::endl;
    std::cout << "Configuration: Low octaves (3), low persistence (0.4)\n\n";

    TerrainConfig config(80, 30, 0.02, 3, 0.4);
    TerrainGenerator terrain(config);

    terrain.displayTerrain();
    terrain.displayLegend();
    terrain.printStats();

    std::cout << "\n\nTips:\n";
    std::cout << "- Use low octaves (2-4) for smooth terrain\n";
    std::cout << "- Use low persistence (0.3-0.5) for less detail\n";
    std::cout << "- This is great for flat landscapes with gentle rolling hills\n";

    return 0;
}
