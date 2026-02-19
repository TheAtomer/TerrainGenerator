#include "terrain_generator.hpp"
#include <iostream>
#include <string>

int main() {
    std::cout << "=== Random Terrain Generator ===\n" << std::endl;

    TerrainConfig config(80, 30, 0.03, 5, 0.5);
    TerrainGenerator terrain(config);

    std::cout << "Basic Terrain (Solid Blocks):\n";
    terrain.displayTerrain();
    terrain.displayLegend();
    terrain.printStats();

    std::cout << "\n" << std::string(60, '=') << "\n";

    std::cout << "\nDetailed Terrain (Variable Density Blocks):\n";
    terrain.displayTerrainWithDetails();

    std::cout << "\n" << std::string(60, '=') << "\n";

    std::cout << "\nRough Terrain (Regenerated):\n";
    TerrainConfig roughConfig(80, 30, 0.05, 3, 0.7);
    terrain.regenerate(roughConfig);
    terrain.displayTerrain();
    terrain.printStats();

    return 0;
}
