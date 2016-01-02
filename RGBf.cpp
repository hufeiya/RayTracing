//
// Created by hufeiya on 16-1-2.
//

#include "RGBf.h"

RGBf::RGBf(float d, float d1, float d2) {
    this->r = d;
    this->g = d1;
    this->b = d2;
}

RGBf RGBf::operator*(float value) {
    return RGBf(this->r*value, this->g*value, this->b*value);
}

RGBf RGBf::operator+(RGBf &n) {
    return RGBf(r+n.r, g+n.g,b+n.b);
}

RGBf RGBf::preventOverFlow() {
    float rr = r > 1? 1:r;
    float gg = g > 1? 1:g;
    float bb = b > 1? 1:b;
    return RGBf(rr, gg, bb);
}

RGBf::RGBf() {

}
