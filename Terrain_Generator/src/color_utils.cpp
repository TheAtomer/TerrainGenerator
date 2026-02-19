#include "color_utils.hpp"

namespace ColorUtils {

TerrainType getTerrainType(double height) {
    if (height < 0.3) return TerrainType::DEEP_WATER;
    if (height < 0.35) return TerrainType::SHALLOW_WATER;
    if (height < 0.4) return TerrainType::SAND;
    if (height < 0.5) return TerrainType::GRASS_LOW;
    if (height < 0.6) return TerrainType::GRASS_MID;
    if (height < 0.7) return TerrainType::GRASS_HIGH;
    if (height < 0.8) return TerrainType::MOUNTAIN_LOW;
    if (height < 0.9) return TerrainType::MOUNTAIN_MID;
    if (height < 0.95) return TerrainType::MOUNTAIN_HIGH;
    return TerrainType::SNOW;
}

const char* getColorByHeight(double height) {
    if (height < 0.3) return COLOR_DEEP_WATER;
    if (height < 0.35) return COLOR_SHALLOW_WATER;
    if (height < 0.4) return COLOR_SAND;
    if (height < 0.5) return COLOR_GRASS_LOW;
    if (height < 0.6) return COLOR_GRASS_MID;
    if (height < 0.7) return COLOR_GRASS_HIGH;
    if (height < 0.8) return COLOR_MOUNTAIN_LOW;
    if (height < 0.9) return COLOR_MOUNTAIN_MID;
    if (height < 0.95) return COLOR_MOUNTAIN_HIGH;
    return COLOR_SNOW;
}

TerrainInfo getTerrainInfo(double height) {
    TerrainType type = getTerrainType(height);
    const char* color = getColorByHeight(height);
    return { type, color };
}

int getBlockDensityIndex(TerrainType type) {
    switch (type) {
        case TerrainType::DEEP_WATER: return 4;
        case TerrainType::SHALLOW_WATER: return 3;
        case TerrainType::SAND: return 2;
        case TerrainType::GRASS_LOW: return 1;
        case TerrainType::GRASS_MID: return 2;
        case TerrainType::GRASS_HIGH: return 3;
        case TerrainType::MOUNTAIN_LOW: return 2;
        case TerrainType::MOUNTAIN_MID: return 3;
        case TerrainType::MOUNTAIN_HIGH: return 4;
        case TerrainType::SNOW: return 4;
        default: return 0;
    }
}

}
