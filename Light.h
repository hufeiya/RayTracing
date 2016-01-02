//
// Created by hufeiya on 16-1-2.
//

#ifndef LIGHTTRACING_LIGHT_H
#define LIGHTTRACING_LIGHT_H


#include "Vector3.h"
#include "RGBf.h"

class Light {
private:
    Vector3 positon = Vector3(0,0,0);
    RGBf strength = RGBf(0.8,0.8,0.8);//默认光强
    int phongExponent = 32;//Phong指数

public:
    int getPhongExponent() const {
        return phongExponent;
    }

    void setPhongExponent(int phongExponent) {
        Light::phongExponent = phongExponent;
    }

public:
    RGBf Phong(Vector3 hitPoint,Vector3 eye,Vector3 normalVec);
    const Vector3 &getPositon() const {
        return positon;
    }

    void setPositon(const Vector3 positon) {
        Light::positon = positon;
    }

    const RGBf &getStrength() const {
        return strength;
    }

    void setStrength(const RGBf strength) {
        Light::strength = strength;
    }
};


#endif //LIGHTTRACING_LIGHT_H
