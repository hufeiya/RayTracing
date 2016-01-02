//
// Created by hufeiya on 15-12-30.
//

#ifndef LIGHTTRACING_SURFACE_H
#define LIGHTTRACING_SURFACE_H


#include "Vector3.h"
#include "Ray.h"
#include "RGBf.h"

class Surface {
protected:
    RGBf color = RGBf(0,0,0);//材质颜色
public:
    virtual bool hit(Ray* ray,double t0,double t1,Vector3& hitRec) = 0;
    virtual Vector3 getNormalVector(Vector3 hitPoint) = 0;
    void setColor(RGBf targetColor);

    const RGBf &getColor() const {
        return color;
    }
};


#endif //LIGHTTRACING_SURFACE_H
