//
// Created by hufeiya on 16-1-2.
//

#ifndef LIGHTTRACING_RGBF_H
#define LIGHTTRACING_RGBF_H


class RGBf {
public:
    float r;
    float g;
    float b;
    RGBf();
    RGBf preventOverFlow();
    RGBf(float, float,float);
    RGBf operator+(RGBf& n);
    RGBf operator*(float value);
    RGBf operator/(int value);
    bool operator<(RGBf n);
};


#endif //LIGHTTRACING_RGBF_H
