//
// Created by hufeiya on 15-12-30.
//

#ifndef LIGHTTRACING_RAY_H
#define LIGHTTRACING_RAY_H


#include "Vector3.h"

class Ray {
public:
    Vector3 e = Vector3(0, 0, 0);
    Vector3 d = Vector3(0, 0, 0);
    Ray(Vector3 e,Vector3 n);
};


#endif //LIGHTTRACING_RAY_H
