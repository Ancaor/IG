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
      //  cout << a.x << ", " << a.y << ", " << a.z << endl;
      //   cout << b.x << ", " << b.y << ", " << b.z << endl;
      //    cout << c.x << ", " << c.y << ", " << c.z << endl;
      //    cout << endl;
        _vertex3f r1 = c-b;
        _vertex3f r2 = a-b;
     //   cout << r1.x << ", " << r1.y << ", " << r1.z << endl;
     //   cout << r2.x << ", " << r2.y << ", " << r2.z << endl;
      //  cout << r1.cross_product(r2).normalize().x<< ", " << r1.cross_product(r2).normalize().y << ", " << r1.cross_product(r2).normalize().z << endl;
        normalCaras[i]=(r1.cross_product(r2).normalize());
    }
   // cout << endl << endl;

}

void O3D::drawNormalesCaras()
{
    glPolygonMode(GL_BACK,GL_POINT);
    glColor3f(1,0,0);
    unsigned int i;

    glBegin(GL_POINTS);
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

void O3D::drawFillIluminado()
{
 /*   glShadeModel(GL_FLAT);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat amb[] = {1,1,1,1.0};
    GLfloat dif[] = {1,1,1,1.0};
    GLfloat spe[] = {1,1,1,1.0};
    GLfloat pos[] = {0.5,0.5,0.0,1.0};


    glLightfv(GL_LIGHT0,GL_AMBIENT, amb);
    glLightfv(GL_LIGHT0,GL_DIFFUSE, dif);
    glLightfv(GL_LIGHT0,GL_SPECULAR, spe);
    glLightfv(GL_LIGHT0,GL_POSITION,pos);

    GLfloat green[] = {0.0,1.0,0.0,1.0};
    GLfloat white[] = {0.0,1.0,0.0,1.0};

    glMaterialfv(GL_FRONT,GL_AMBIENT,green);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,green);
    glMaterialfv(GL_FRONT,GL_SPECULAR,white);
    glMaterialf(GL_FRONT,GL_SHININESS,60.0);
*/
    //glClear(GL_COLOR_BUFFER_BIT);
/*
    GLfloat Luz0[4]={4,0,0,0};
    GLfloat Ambiente[4]={1,1,1,1};
    GLfloat Blanco[4]={1,1,1,1};
    GLfloat Color[4]={0,0.5,0,1};
    GLfloat Color1[4]={0.5,0,0,1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,Ambiente);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
    glMaterialfv(GL_FRONT,GL_AMBIENT,(GLfloat *) &Color1);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,(GLfloat *) &Color);
    glMaterialfv(GL_FRONT,GL_SPECULAR,(GLfloat *) &Blanco);
    glMaterialf(GL_FRONT,GL_SHININESS,100);
    glLightfv(GL_LIGHT0,GL_POSITION,Luz0);
   // glShadeModel(GL_SMOOTH);
    glShadeModel(GL_FLAT);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

*/
   /* GLfloat Ambiente[4]={1,1,1,1};
    GLfloat Blanco[4]={1,1,1,1};
    GLfloat Color[4]={0,0.5,0,1};
    GLfloat Color1[4]={0.5,0,0,1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,Ambiente);

    GLfloat mat[4];
    mat[0] = 0.24725;
      mat[1] = 0.1995;
      mat[2] = 0.0745;
      mat[3] = 1.0;
      glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat);
      mat[0] = 0.75164;
      mat[1] = 0.60648;
      mat[2] = 0.22648;
      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat);
      mat[0] = 0.628281;
      mat[1] = 0.555802;
      mat[2] = 0.366065;
      glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
      glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.4 * 128.0);
    GLfloat Luz0[4]={0,0,0,0};
     glLightfv(GL_LIGHT0,GL_POSITION,Luz0);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
   // glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
   // glColor3f(0,0,1);
    unsigned int i;

glShadeModel(GL_FLAT);
    */


    /*
    FUNCIONA


    GLfloat light_diffuse[] = {1.0,1.0,1.0,1.0};
    GLfloat light0_position[] = {0.3,0.3,1.0,0.0};
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glColor3f(0,0.5,1.0);

    glShadeModel(GL_FLAT);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColorMaterial(GL_FRONT,GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
*/
   /* GLfloat mat[4];
    mat[0] = 0.24725;
      mat[1] = 0.1995;
      mat[2] = 0.0745;
      mat[3] = 1.0;
      glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat);
      mat[0] = 0.75164;
      mat[1] = 0.60648;
      mat[2] = 0.22648;
      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat);
      mat[0] = 0.628281;
      mat[1] = 0.555802;
      mat[2] = 0.366065;
      glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
      glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.4 * 128.0);
   */ GLfloat light_diffuse[] = {1.0,1.0,1.0,1.0};
    GLfloat light0_position[] = {0.3,0.3,1.0,0.0};
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glColor3f(0,0.5,1.0);

    glShadeModel(GL_FLAT);


    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glPopMatrix();
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColorMaterial(GL_FRONT,GL_DIFFUSE);
    //glEnable(GL_COLOR_MATERIAL);



    glBegin(GL_TRIANGLES);
    for(unsigned int i=0;i<triangles.size();i++){
        glNormal3fv((GLfloat*) &normalCaras[i]);
        glVertex3f(vertices[triangles[i]._0].x,vertices[triangles[i]._0].y,vertices[triangles[i]._0].z);
        glVertex3f(vertices[triangles[i]._1].x,vertices[triangles[i]._1].y,vertices[triangles[i]._1].z);
        glVertex3f(vertices[triangles[i]._2].x,vertices[triangles[i]._2].y,vertices[triangles[i]._2].z);
    }
    glEnd();
}

void O3D::drawFillIluminadoSuave(double alfa, double beta, double distancia, Material material, bool lighting, Luz light ){// GLfloat mat_ambient[], GLfloat mat_diffuse[], GLfloat mat_specular[], float shininess)
{
   // GLfloat mat[4];
   /*
    * ORO
    *
    * mat[0] = 0.24725;
      mat[1] = 0.1995;
      mat[2] = 0.0745;
      mat[3] = 1.0;
      glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat);
      mat[0] = 0.75164;
      mat[1] = 0.60648;
      mat[2] = 0.22648;
      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat);
      mat[0] = 0.628281;
      mat[1] = 0.555802;
      mat[2] = 0.366065;
      glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat);
     glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.4 * 128.0);
    */

  //  mat[0] = 0.0215;
    //      mat[1] = 0.1745	;
     //     mat[2] = 0.0215;
     //     mat[3] = 1.0;
          //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
       //   mat[0] = 0.07568;
      //    mat[1] = 0.61424;
      //    mat[2] = 0.07568;
         // glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
      //    mat[0] = 0.633;
      //    mat[1] = 0.727811;
      //    mat[2] = 0.633;
        //  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        material.enable();
        // glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
 //   GLfloat light_diffuse[] = {1.0,1.0,1.0,1.0};
    GLfloat light0_position[] = {0.0,0.0,0.0,1.0};
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  //  glColor3f(0,0.5,1.0);

    glShadeModel(GL_SMOOTH);



  //  glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
    if(lighting)
    glEnable(GL_LIGHTING);
    light.enable();
  //  glEnable(GL_LIGHT0);
   // glColorMaterial(GL_FRONT,GL_DIFFUSE);
    //glEnable(GL_COLOR_MATERIAL);


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

    //glDisable(GL_SHADER);
    glDisable(GL_LIGHTING);
    light.disable();
    // glDisable(GL_LIGHT0);
}}

void O3D::drawNormalesVertices()
{
    glPolygonMode(GL_BACK,GL_LINE);
    glColor3f(1,0,0);
    unsigned int i;

    glBegin(GL_LINES);
    for(i=0;i<normalVertices.size();i++){
        //cout << normalVertices[i].z;
        glVertex3fv((GLfloat*) &vertices[i]);
        glVertex3fv((GLfloat *) &normalVertices[i]);
    }
    glEnd();
}


