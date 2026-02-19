#ifndef PERLIN_NOISE_HPP
#define PERLIN_NOISE_HPP

#include <vector>

class PerlinNoise {
private:
    std::vector<int> permutation;

    static double fade(double t);
    static double lerp(double t, double a, double b);
    double grad(int hash, double x, double y) const;

public:
    PerlinNoise();

    double noise(double x, double y) const;
    double octaveNoise(double x, double y, int octaves, double persistence) const;
};

#endif
