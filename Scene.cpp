//
// Created by hufeiya on 16-1-2.
//

#include "Scene.h"
#include "Sphere.h"
#include "Ground.h"

//载入场景，自定义几个物体
void Scene::createScene() {

    viewPoint = new Vector3(100,200,100);
    light = new Light();
    light->setPositon(Vector3(0,-100,300));

    //创建地板
    Ground* ground = new Ground();
    ground->setGround(Vector3(0,0,-200));
    pSurfaces[num++] = (Surface *) ground;

    //新建一个球
    Sphere * sphere1 = new Sphere();
    sphere1->setCenter(Vector3(0,-300,0));
    sphere1->setRadius(50);
    ((Surface*)sphere1)->setColor(RGBf(0,0,0.3));
    pSurfaces[num++] = (Surface *) sphere1;

    //新建第二个球
    Sphere * sphere2 = new Sphere();
    sphere2->setCenter(Vector3(100,-400,0));
    sphere2->setRadius(50);
    ((Surface*)sphere2)->setColor(RGBf(0.3,0,0));
    pSurfaces[num++] = (Surface *) sphere2;

    //新建第3个球
    Sphere * sphere3 = new Sphere();
    sphere3->setCenter(Vector3(-100,-200,0));
    sphere3->setRadius(50);
    ((Surface*)sphere3)->setColor(RGBf(0,0.3,0));
    pSurfaces[num++] = (Surface *) sphere3;

    //新建第4个球
    Sphere * sphere4 = new Sphere();
    sphere4->setCenter(Vector3(-300,-1000,0));
    sphere4->setRadius(50);
    pSurfaces[num++] = (Surface *) sphere4;

    //新建第5个球
    Sphere * sphere5 = new Sphere();
    sphere5->setCenter(Vector3(0,-200,100));
    sphere5->setRadius(50);
    ((Surface*)sphere1)->setColor(RGBf(0,0,0.3));
    pSurfaces[num++] = (Surface *) sphere5;


}

/**
 * 构造函数，决定能存储几个对象*/
Scene::Scene(int sum) {
    this->sum = sum;
    pSurfaces = new Surface*[sum];
}

Scene::~Scene() {
    delete viewPoint;
    delete light;
    delete []pSurfaces;
}
