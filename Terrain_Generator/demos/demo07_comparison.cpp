/**
 * Demo 07: Multiple Terrain Comparison
 * 演示多个地形生成结果的对比
 */

#include "terrain_generator.hpp"
#include <iostream>
#include <string>

int main() {
    std::cout << "=== Demo 07: Multiple Terrain Comparison ===\n" << std::endl;

    struct TestCase {
        std::string name;
        TerrainConfig config;
    };

    TestCase testCases[] = {
        { "Smooth Plains", TerrainConfig(40, 15, 0.02, 3, 0.4) },
        { "Balanced", TerrainConfig(40, 15, 0.03, 5, 0.55) },
        { "Rugged", TerrainConfig(40, 15, 0.025, 7, 0.75) }
    };

    for (const auto& tc : testCases) {
        std::cout << "\n" << std::string(60, '=') << "\n";
        std::cout << "Terrain: " << tc.name << "\n";
        std::cout << std::string(60, '=') << "\n\n";

        TerrainGenerator terrain(tc.config);
        terrain.displayTerrain();
        terrain.printStats();
    }

    std::cout << "\n\nComparison Complete!\n";
    std::cout << "- Smooth: Great for flat landscapes\n";
    std::cout << "- Balanced: Good all-around terrain\n";
    std::cout << "- Rugged: Perfect for mountainous regions\n";

    return 0;
}
