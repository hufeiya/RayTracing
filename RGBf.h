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
    RGBf operator+(RGBf& b);
    RGBf operator*(float value);
};


#endif //LIGHTTRACING_RGBF_H
