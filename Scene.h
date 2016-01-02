//
// Created by hufeiya on 16-1-2.
//

#ifndef LIGHTTRACING_SCENE_H
#define LIGHTTRACING_SCENE_H


#include "Surface.h"

class Scene {
private:
    Surface ** pSurfaces;
    int num = 0;
    int sum = 0;
public:
    Scene(int sum);
    void createScene();

    Surface **getPSurfaces() const {
        return pSurfaces;
    }

    void setPSurfaces(Surface **pSurfaces) {
        Scene::pSurfaces = pSurfaces;
    }

    int getNum() const {
        return num;
    }

    void setNum(int num) {
        Scene::num = num;
    }

    int getSum() const {
        return sum;
    }

    void setSum(int sum) {
        Scene::sum = sum;
    }
};


#endif //LIGHTTRACING_SCENE_H
