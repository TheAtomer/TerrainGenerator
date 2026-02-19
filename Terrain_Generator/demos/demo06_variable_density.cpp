/**
 * Demo 06: Variable Density Display
 * 演示可变密度方块显示模式
 */

#include "terrain_generator.hpp"
#include <iostream>

int main() {
    std::cout << "=== Demo 06: Variable Density Display ===\n" << std::endl;

    TerrainConfig config(80, 30, 0.03, 5, 0.55);
    TerrainGenerator terrain(config);

    std::cout << "Variable density blocks (different texture densities):\n\n";
    terrain.displayTerrainWithDetails();
    terrain.displayLegend();
    terrain.printStats();

    std::cout << "\n\nBlock Density Guide:\n";
    std::cout << "  \" \" (empty) = lightest\n";
    std::cout << "  \"░\" = light\n";
    std::cout << "  \"▒\" = medium\n";
    std::cout << "  \"▓\" = dark\n";
    std::cout << "  \"█\" (solid) = darkest\n";

    return 0;
}
