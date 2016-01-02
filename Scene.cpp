//
// Created by hufeiya on 16-1-2.
//

#include "Scene.h"
#include "Sphere.h"
#include "Ground.h"

//载入场景，自定义几个物体
void Scene::createScene() {

    //创建地板
    Ground* ground = new Ground();
    ground->setGround(Vector3(0,0,-50));
    pSurfaces[num++] = (Surface *) ground;

    //新建一个球
    Sphere * sphere1 = new Sphere();
    sphere1->setCenter(Vector3(0,-300,0));
    sphere1->setRadius(50);
    pSurfaces[num++] = (Surface *) sphere1;

    //新建第二个球
    Sphere * sphere2 = new Sphere();
    sphere2->setCenter(Vector3(100,-400,0));
    sphere2->setRadius(50);
    pSurfaces[num++] = (Surface *) sphere2;

    //新建第3个球
    Sphere * sphere3 = new Sphere();
    sphere3->setCenter(Vector3(-100,-200,0));
    sphere3->setRadius(50);
    pSurfaces[num++] = (Surface *) sphere3;

    //新建第4个球
    Sphere * sphere4 = new Sphere();
    sphere4->setCenter(Vector3(-300,-1000,0));
    sphere4->setRadius(50);
    pSurfaces[num++] = (Surface *) sphere4;
}

/**
 * 构造函数，决定能存储几个对象*/
Scene::Scene(int sum) {
    this->sum = sum;
    pSurfaces = new Surface*[sum];
}
