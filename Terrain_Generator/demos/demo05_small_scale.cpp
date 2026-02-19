/**
 * Demo 05: Small Scale Details
 * 演示小型细节生成
 */

#include "terrain_generator.hpp"
#include <iostream>

int main() {
    std::cout << "=== Demo 05: Small Scale Details ===\n" << std::endl;
    std::cout << "Configuration: High scale (0.08)\n\n";

    TerrainConfig config(80, 30, 0.08, 6, 0.6);
    TerrainGenerator terrain(config);

    terrain.displayTerrain();
    terrain.displayLegend();
    terrain.printStats();

    std::cout << "\n\nTips:\n";
    std::cout << "- Use high scale (0.05-0.1) for small details\n";
    std::cout << "- This creates intricate, busy terrain\n";
    std::cout << "- Great for local area maps or detailed regions\n";

    return 0;
}
