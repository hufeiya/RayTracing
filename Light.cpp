//
// Created by hufeiya on 16-1-2.
//

#include "Light.h"
#include <cmath>
/**
 * 用Phong模型计算光照
 * */
RGBf Light::Phong(Vector3 hitPoint, Vector3 eye, Vector3 normalVec,RGBf surfaceColor) {
    //初始化自带环境光照
    RGBf result = RGBf(0.1,0.1,0.1)+surfaceColor;
    //计算泛光
    Vector3 l = (this->positon - hitPoint).normalize();
    float floodStrength = l*normalVec;
    floodStrength = floodStrength > 0 ? floodStrength : 0;
    RGBf floodLight = this->strength*floodStrength;
    result = result + floodLight;
    //计算高光
    float highStrength = (eye-hitPoint).normalize()*(l*-1 + normalVec*2*(l*normalVec));
    highStrength = highStrength > 0? pow(highStrength,phongExponent) : 0;
    result = strength * highStrength + result;
    return result.preventOverFlow();
}
