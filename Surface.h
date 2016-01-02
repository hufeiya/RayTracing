//
// Created by hufeiya on 15-12-30.
//

#ifndef LIGHTTRACING_SURFACE_H
#define LIGHTTRACING_SURFACE_H


#include "Vector3.h"
#include "Ray.h"

class Surface {
protected:
    virtual bool hit(Ray* ray,double t0,double t1,Vector3& hitRec) = 0;
};


#endif //LIGHTTRACING_SURFACE_H