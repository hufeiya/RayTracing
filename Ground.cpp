//
// Created by hufeiya on 16-1-2.
//

#include "Ground.h"

bool Ground::hit(Ray *ray, double t0, double t1, Vector3 &hitRec) {
    Vector3 e = ray->e;
    Vector3 d = ray->d - e;
    float t = (ground - e)/d;
    if (t == 0 || t <= t0 || t > t1)
    {
        return false;
    }
    else
    {
        hitRec = e + d*t;
        return true;
    }
}

Vector3 Ground::getNormalVector(Vector3 hitPoint) {
    return Vector3(0, 0, 1);
}
