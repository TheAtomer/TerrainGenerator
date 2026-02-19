#ifndef COLOR_UTILS_HPP
#define COLOR_UTILS_HPP

#include <string>

namespace ColorUtils {

constexpr const char* COLOR_DEEP_WATER = "\033[38;5;18m";
constexpr const char* COLOR_SHALLOW_WATER = "\033[38;5;33m";
constexpr const char* COLOR_SAND = "\033[38;5;229m";
constexpr const char* COLOR_GRASS_LOW = "\033[38;5;22m";
constexpr const char* COLOR_GRASS_MID = "\033[38;5;28m";
constexpr const char* COLOR_GRASS_HIGH = "\033[38;5;34m";
constexpr const char* COLOR_MOUNTAIN_LOW = "\033[38;5;94m";
constexpr const char* COLOR_MOUNTAIN_MID = "\033[38;5;130m";
constexpr const char* COLOR_MOUNTAIN_HIGH = "\033[38;5;145m";
constexpr const char* COLOR_SNOW = "\033[38;5;15m";
constexpr const char* COLOR_RESET = "\033[0m";

enum class TerrainType {
    DEEP_WATER,
    SHALLOW_WATER,
    SAND,
    GRASS_LOW,
    GRASS_MID,
    GRASS_HIGH,
    MOUNTAIN_LOW,
    MOUNTAIN_MID,
    MOUNTAIN_HIGH,
    SNOW
};

struct TerrainInfo {
    TerrainType type;
    const char* color;
};

TerrainType getTerrainType(double height);
const char* getColorByHeight(double height);
TerrainInfo getTerrainInfo(double height);
int getBlockDensityIndex(TerrainType type);

}

#endif
