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
    //Create some nice colours (3 floats per pixel) from data -10..+10
    /*float* pixels = new float[size*3];
    for(int i=0;i<size;i++) {
        colour(10.0-((i*20.0)/size),&pixels[i*3]);
    }*/
    //RGBf*pixels = test();
    //float* rawPixels = (float*)pixels;
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
            //依次遍历场景中的物体，这里暂时只有一个球
            for(int k = 0; k < scene.getNum();k++)
            {
                Sphere *sphere = (Sphere *) scene.getPSurfaces()[k];
                Vector3 hitRec = Vector3(0,0,0);
                if(sphere->hit(&ray,0,1000,hitRec))
                {
                    RGBf rgBf = light.Phong(hitRec,viewPoint,(hitRec-sphere->getCenter()).normalize());
                    rgBfs[i*window_height+j] = rgBf;
                }
            }
        }
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //http://msdn2.microsoft.com/en-us/library/ms537062.aspx
    //glDrawPixels writes a block of pixels to the framebuffer.

    glDrawPixels(window_width,window_height,GL_RGB,GL_FLOAT,rgBfs);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(window_width, window_height);
    glutCreateWindow("OpenGL glDrawPixels demo");

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