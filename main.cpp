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

unsigned int window_width = 512, window_height = 512;
const int size=window_width*window_height;



void display()
{
    RGBf *rgBfs = new RGBf[window_width*window_height];
    //设置视点
    Vector3 viewPoint = Vector3(100,200,100);
    Vector3 u = Vector3(1,0,0);
    Vector3 v = Vector3(0,-1,0);
    Vector3 w = Vector3(0,0,1);
    double l=0,r=100,b=0,t=100;
    Light light;
    light.setPositon(Vector3(0,-100,300));
    Scene scene = Scene(10);
    scene.createScene();
    for(int i = 0; i < window_height;i++)
    {
        for(int j = 0; j < window_width;j++)
        {
            Ray ray = Ray(viewPoint,Vector3(j*100.0f/512.0f,0,i*100.0f/512.0f));
            //依次遍历场景中的物体
            for(int k = 0; k < scene.getNum();k++)
            {
                Surface *surface =  scene.getPSurfaces()[k];
                Vector3 hitRec = Vector3(0,0,0);
                if(surface->hit(&ray,0,100,hitRec))
                {
                    RGBf rgBf = light.Phong(hitRec,viewPoint,surface->getNormalVector(hitRec),surface->getColor());
                    rgBfs[i*window_height+j] = rgBf;
                }
            }
        }
    }
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