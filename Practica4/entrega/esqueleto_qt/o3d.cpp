#include "o3d.h"

O3D::O3D()
{

}

void O3D::drawLines()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    unsigned int i;

    glBegin(GL_TRIANGLES);
     glColor3f(1,0,0);
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

    unsigned int i;

    glBegin(GL_TRIANGLES);
    glColor3f(0,0,1);
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
    for(i=0;i<triangles.size();i++){
        if(i % 2 == 0)
            glColor3f(0,0,1);
        else
            glColor3f(1,0.5,0);

        glVertex3f(vertices[triangles[i]._0].x,vertices[triangles[i]._0].y,vertices[triangles[i]._0].z);
        glVertex3f(vertices[triangles[i]._1].x,vertices[triangles[i]._1].y,vertices[triangles[i]._1].z);
        glVertex3f(vertices[triangles[i]._2].x,vertices[triangles[i]._2].y,vertices[triangles[i]._2].z);
    }
    glEnd();
}

void O3D::calcularNormalesCaras()
{
    normalCaras.resize(triangles.size());

    for(unsigned int i=0; i<triangles.size(); i++){
        _vertex3f a = vertices[triangles[i]._0];
        _vertex3f b = vertices[triangles[i]._1];
        _vertex3f c = vertices[triangles[i]._2];

        _vertex3f r1 = c-b;
        _vertex3f r2 = a-b;

        normalCaras[i]=(r1.cross_product(r2).normalize());
    }
   // cout << endl << endl;

}

void O3D::drawNormalesCaras()
{
    glPolygonMode(GL_BACK,GL_POINT);

    unsigned int i;

    glBegin(GL_POINTS);
    glColor3f(1,0,0);
    for(i=0;i<normalCaras.size();i++){
      //  cout << normalCaras[i].z;
        glVertex3fv((GLfloat *) &normalCaras[i]);
    }
    glEnd();
}

void O3D::calcularNormalesVertices()
{
    if(normalCaras.empty())
        calcularNormalesCaras();

    normalVertices.resize(vertices.size());

    for(unsigned int i=0; i<triangles.size(); i++){
        int v1 = triangles[i]._0;
        int v2 = triangles[i]._1;
        int v3 = triangles[i]._2;

        normalVertices[v1] += normalCaras[i];
        normalVertices[v2] += normalCaras[i];
        normalVertices[v3] += normalCaras[i];
    }
    for(unsigned int i=0;i<vertices.size();i++){
        normalVertices[i] = (normalVertices[i]).normalize();///carasVertice[i]).normalize();
    }


}

void O3D::drawFillIluminado(Material material , bool iluminacion)
{

    if(iluminacion)
        glEnable(GL_LIGHTING);

    material.enable();

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_FLAT);


    glBegin(GL_TRIANGLES);
    for(unsigned int i=0;i<triangles.size();i++){
        glNormal3fv((GLfloat*) &normalCaras[i]);
        glVertex3f(vertices[triangles[i]._0].x,vertices[triangles[i]._0].y,vertices[triangles[i]._0].z);
        glVertex3f(vertices[triangles[i]._1].x,vertices[triangles[i]._1].y,vertices[triangles[i]._1].z);
        glVertex3f(vertices[triangles[i]._2].x,vertices[triangles[i]._2].y,vertices[triangles[i]._2].z);
    }
    glEnd();

    glDisable(GL_LIGHTING);
}

void O3D::drawFillIluminadoSuave(Material material, bool iluminacion)// GLfloat mat_ambient[], GLfloat mat_diffuse[], GLfloat mat_specular[], float shininess)
{

    if(iluminacion)
        glEnable(GL_LIGHTING);

    material.enable();

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_SMOOTH);

    glBegin(GL_TRIANGLES);
    for(unsigned int i=0;i<triangles.size();i++){
        glNormal3fv((GLfloat* ) &normalVertices[triangles[i]._0]);
        glVertex3f(vertices[triangles[i]._0].x,vertices[triangles[i]._0].y,vertices[triangles[i]._0].z);
        glNormal3fv((GLfloat* ) &normalVertices[triangles[i]._1]);
        glVertex3f(vertices[triangles[i]._1].x,vertices[triangles[i]._1].y,vertices[triangles[i]._1].z);
        glNormal3fv((GLfloat* ) &normalVertices[triangles[i]._2]);
        glVertex3f(vertices[triangles[i]._2].x,vertices[triangles[i]._2].y,vertices[triangles[i]._2].z);
    }
    glEnd();
    glDisable(GL_LIGHTING);

}

void O3D::drawNormalesVertices()
{
    glPolygonMode(GL_BACK,GL_LINE);

    unsigned int i;

    glBegin(GL_LINES);
    glColor3f(1,0,0);
    for(i=0;i<normalVertices.size();i++){
        glVertex3fv((GLfloat*) &vertices[i]);
        glVertex3fv((GLfloat *) &normalVertices[i]);
    }
    glEnd();
}


