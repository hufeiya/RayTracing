//
// Created by hufeiya on 16-1-2.
//

#ifndef LIGHTTRACING_SCENE_H
#define LIGHTTRACING_SCENE_H


#include "Surface.h"
#include "Light.h"

class Scene {
private:
    Surface ** pSurfaces;
    int num = 0;//物体数目
    int sum = 0;//预分配物体空间
    Vector3 *viewPoint;//视点
    Light *light;//光线
public:
    Light *getLight() const {
        return light;
    }

    void setLight(Light *light) {
        Scene::light = light;
    }

    Vector3 *getViewPoint() const {
        return viewPoint;
    }

    void setViewPoint(Vector3 *viewPoint) {
        Scene::viewPoint = viewPoint;
    }

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

     ~Scene();
};


#endif //LIGHTTRACING_SCENE_H
