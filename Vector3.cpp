//
// Created by hufeiya on 15-12-30.
//


#include "Vector3.h"
#include <cmath>
Vector3::Vector3(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3 Vector3::operator+(Vector3 vector3) {
    return Vector3(this->x+vector3.x, this->y+vector3.y,this->z+vector3.z);
}

Vector3 Vector3::operator-(Vector3 vector3) {
    return Vector3(this->x-vector3.x, this->y-vector3.y,this->z-vector3.z);
}

double Vector3::operator*(Vector3 vector3) {
    return this->x*vector3.x+this->y*vector3.y+this->z*vector3.z;
}

Vector3 Vector3::operator*(double t) {
    return Vector3(this->x*t, this->y*t, this->z*t);
}

Vector3::Vector3(const Vector3& vector3) {
    x = vector3.x;
    y = vector3.y;
    z = vector3.z;
}

/**
 * 单位化法向量
 * */
Vector3 Vector3::normalize() {
    float denominator =  sqrt(x*x+y*y+z*z);
    return Vector3(x/denominator, y/denominator, z/denominator);
}

float Vector3::operator/(Vector3 vector3) {

    return z/vector3.z;
}
