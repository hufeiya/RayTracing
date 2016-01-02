//
// Created by hufeiya on 15-12-30.
//

#ifndef LIGHTTRACING_SPHERE_H
#define LIGHTTRACING_SPHERE_H


#include "Surface.h"

class Sphere: Surface {
private:
    Vector3 center = Vector3(0,0,0);
    double radius = 100;
public:
    bool hit(Ray* ray,double t0,double t1,Vector3& hitRec);

    const Vector3 &getCenter() const {
        return center;
    }

    void setCenter(const Vector3 center) {
        Sphere::center = center;
    }

    double getRadius() const {
        return radius;
    }

    void setRadius(double radius) {
        Sphere::radius = radius;
    }
};


#endif //LIGHTTRACING_SPHERE_H
