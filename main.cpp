#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>

#include <iostream>
#include <sstream>
#include "math.h"
#include "Vector3.h"
#include "Ray.h"
#include "RGBf.h"
#include "Scene.h"
#include "Sphere.h"
#include "Light.h"

unsigned int window_width = 768, window_height = 768;
const int size=window_width*window_height;
Scene *scene;

//获取随机浮点数算法，用于分层采样
union FloatRand
{
    struct
    {
        unsigned long Frac:23;
        unsigned long Exp:8;
        unsigned long Signed:1;
    } BitArea;
    float Value;
    unsigned long Binary; /* for debug only */
};
float getFloatRand()
{
    union FloatRand r;

    r.BitArea.Signed = 0;
    r.BitArea.Exp = 1;
    r.BitArea.Frac = (rand() * rand()) % 0x800000;
    if (r.BitArea.Frac == 0x7FFFFF)
        r.BitArea.Exp = rand() % 0x7E;
    else if (r.BitArea.Frac == 0)
        r.BitArea.Exp = rand() % 0x7E + 1;
    else
        r.BitArea.Exp = rand() % 0x7F;

    return r.Value;
}

/**
 * 递归计算光线颜色，包含反射
 **/
RGBf rayColor(Ray& ray,float t0,float t1,Scene *scene)
{
    RGBf rgBf = RGBf(0,0,0);//若无交点，则为黑色
    //依次遍历场景中的物体
    for(int k = 0; k < scene->getNum();k++)
    {
        Surface *surface =  scene->getPSurfaces()[k];
        Vector3 hitRec = Vector3(0,0,0);
        if(surface->hit(&ray,0,t1,hitRec))
        {
            Vector3 normalVec = surface->getNormalVector(hitRec);
            rgBf = scene->getLight()->Phong(hitRec,*scene->getViewPoint(),normalVec,surface->getColor());
            t1 = (hitRec-ray.e)/(ray.d-ray.e);
            if(! (rgBf < RGBf(0.01,0.01,0.01)))//反射光线强度不小于临界值则继续递归
            {
                float cs = 0.4;//反射递减光强
                Vector3 d = ray.d - ray.e;
                Ray newRay = Ray(hitRec,hitRec-(d + normalVec*2*(d*normalVec)));
                rgBf = rayColor(newRay,0.01,100,scene)*cs + rgBf;
            }

        }
    }
    return rgBf;
}

void display()
{
    RGBf *rgBfs = new RGBf[window_width*window_height];
    int n = 4;//采样点
    scene = new Scene(10);
    scene->createScene();
    for(int i = 0; i < window_height-n;i++)
    {
        for(int j = 0; j < window_width-n;j++)
        {
            RGBf rgBf = RGBf(0,0,0);//若无交点，则为黑色
            for(int p = 0;p < n;p++)//反走样
            {
                for(int q = 0;q < n;q++)
                {
                    Ray ray = Ray(*scene->getViewPoint(),Vector3((j+p+getFloatRand())*100.0f/512.0f,0,(i+q+getFloatRand())*100.0f/512.0f));
                    rgBf = rayColor(ray,0.01,100,scene) + rgBf;
                }
            }


            rgBfs[i*window_height+j] = rgBf /(n*n);
        }
    }
    delete scene;
    delete []rgBfs;








    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawPixels(window_width,window_height,GL_RGB,GL_FLOAT,rgBfs);
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(window_width, window_height);
    glutCreateWindow("RayTracing demo by hufeiya");

    glutDisplayFunc(display);
    //glutReshapeFunc(reshape);
    //glutMouseFunc(mouse_button);
    //glutMotionFunc(mouse_motion);
    //glutKeyboardFunc(keyboard);
    //glutIdleFunc(idle);

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    //glPointSize(2);

    glutMainLoop();
}