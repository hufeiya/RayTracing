//
// Created by hufeiya on 15-12-30.
//

#include "Sphere.h"
#include <cmath>
bool Sphere::hit(Ray* ray, double t0, double t1, Vector3& hitRec) {
    Vector3 &c = this->center;
    Vector3 &e = ray->e;
    Vector3 d = ray->d-e;
    double delta = (d*(e-c))*(d*(e-c))-(d*d)*((e-c)*(e-c)-radius*radius);
    if(delta <= 0)
    {
        return false;
    }
    double t = (d*-1*(e-c)-sqrt(delta))/(d*d);
    if (t < 0)
    {
        t = (d*-1*(e-c)+sqrt(delta))/(d*d);
    }
    if(t > t0 && t <= t1)
    {
        hitRec = *new Vector3(d*t+e);
        return true;
    }
    else
    {
        return false;
    }


}


