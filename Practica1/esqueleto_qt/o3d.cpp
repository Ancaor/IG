#include "o3d.h"

O3D::O3D()
{

}

void O3D::drawLines()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glColor3f(1,0,0);
    unsigned int i;

    glBegin(GL_TRIANGLES);
    for(i=0;i<triangles.size();i++){
        glVertex3f(vertices[triangles[i]._0].x,vertices[triangles[i]._0].y,vertices[triangles[i]._0].z);
        glVertex3f(vertices[triangles[i]._1].x,vertices[triangles[i]._1].y,vertices[triangles[i]._1].z);
        glVertex3f(vertices[triangles[i]._2].x,vertices[triangles[i]._2].y,vertices[triangles[i]._2].z);
    }
    glEnd();
}

void O3D::drawFill()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glColor3f(0,0,1);
    unsigned int i;

    glBegin(GL_TRIANGLES);
    for(i=0;i<triangles.size();i++){
        glVertex3f(vertices[triangles[i]._0].x,vertices[triangles[i]._0].y,vertices[triangles[i]._0].z);
        glVertex3f(vertices[triangles[i]._1].x,vertices[triangles[i]._1].y,vertices[triangles[i]._1].z);
        glVertex3f(vertices[triangles[i]._2].x,vertices[triangles[i]._2].y,vertices[triangles[i]._2].z);
    }
    glEnd();
}

void O3D::drawAjedrez()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    unsigned int i;

    glBegin(GL_TRIANGLES);
    for(i=0;i<triangles.size()-1;i+=2){
        glColor3f(0,0,1);
        glVertex3f(vertices[triangles[i]._0].x,vertices[triangles[i]._0].y,vertices[triangles[i]._0].z);
        glVertex3f(vertices[triangles[i]._1].x,vertices[triangles[i]._1].y,vertices[triangles[i]._1].z);
        glVertex3f(vertices[triangles[i]._2].x,vertices[triangles[i]._2].y,vertices[triangles[i]._2].z);

        glColor3f(1,0.5,0);
        glVertex3f(vertices[triangles[i+1]._0].x,vertices[triangles[i+1]._0].y,vertices[triangles[i+1]._0].z);
        glVertex3f(vertices[triangles[i+1]._1].x,vertices[triangles[i+1]._1].y,vertices[triangles[i+1]._1].z);
        glVertex3f(vertices[triangles[i+1]._2].x,vertices[triangles[i+1]._2].y,vertices[triangles[i+1]._2].z);
    }
    glEnd();
}
