//
// Created by hufeiya on 15-12-30.
//

#ifndef LIGHTTRACING_VECTOR3_H
#define LIGHTTRACING_VECTOR3_H


class Vector3 {
public:
    double x;
    double y;
    double z;
    Vector3(double x,double y,double z);
    Vector3(const Vector3& vector3);
    Vector3 operator +(Vector3 vector3);
    Vector3 operator -(Vector3 vector3);
    double operator *(Vector3 vector3);
    float operator /(Vector3 vector3);
    Vector3 operator*(double t);
    Vector3 normalize();
};


#endif //LIGHTTRACING_VECTOR3_H
