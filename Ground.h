//
// Created by hufeiya on 16-1-2.
//

#ifndef LIGHTTRACING_GROUND_H
#define LIGHTTRACING_GROUND_H


#include "Surface.h"

class Ground:Surface {

    Vector3 ground = Vector3(0,0,-400);
public:
    const Vector3 &getGround() const {
        return ground;
    }

    void setGround(const Vector3 ground) {
        Ground::ground = ground;
    }

    bool hit(Ray *ray, double t0, double t1, Vector3 &hitRec);

private:
    virtual Vector3 getNormalVector(Vector3 hitPoint);
};


#endif //LIGHTTRACING_GROUND_H
