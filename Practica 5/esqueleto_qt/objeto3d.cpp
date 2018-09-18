#include "objeto3d.h"

Objeto3D::Objeto3D()
{
    color = _vertex4f(1,0,0,1);
    color_lineas = _vertex4f(0,0,1,1);
}



//*************************************************************************
// Dibuja las lineas del objeto
//*************************************************************************

void Objeto3D::draw_Lines()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glPointSize(4);
    glColor3f(color_lineas.x,color_lineas.y, color_lineas.z);
    glBegin(GL_TRIANGLES);
        for(unsigned int i = 0; i < Superficie.size(); i++){
            glVertex3fv((GLfloat *) &Vertices[Superficie[i]._0]);
            glVertex3fv((GLfloat *) &Vertices[Superficie[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Superficie[i]._2]);
        }
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}


void Objeto3D::draw_Normales_Caras()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

    glPointSize(4);
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
        for(unsigned int i = 0; i < Normales.size(); i++){
            glVertex3fv((GLfloat *) &Normales[i]);
        }
    glEnd();

}

void Objeto3D::draw_Normales_Vertices()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glPointSize(4);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
        for(unsigned int i = 0; i < Normales_V.size(); i++){
            glVertex3fv((GLfloat *) &Vertices[i]);
            glVertex3fv((GLfloat *) &Normales_V[i]);
        }
    glEnd();

}


//*************************************************************************
// Dibuja la superficie (con triangulos) del objeto.
//*************************************************************************

void Objeto3D::draw_Triangles()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(color.x,color.y,color.z);
    glBegin(GL_TRIANGLES);
        for(unsigned int i = 0; i < Superficie.size(); i++){
            glVertex3fv((GLfloat *) &Vertices[Superficie[i]._0]);
            glVertex3fv((GLfloat *) &Vertices[Superficie[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Superficie[i]._2]);
        }
    glEnd();

}



//*************************************************************************
// Dibuja la superficie en modo Ajedrez
//*************************************************************************

void Objeto3D::draw_Chess()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glBegin(GL_TRIANGLES);
        for(unsigned int i = 0; i < Superficie.size(); i++){
            if(i%2==0)
                glColor3f(color.x,color.y,color.z);
            else
                glColor3f(color.y,color.x,color.z);

            glVertex3fv((GLfloat *) &Vertices[Superficie[i]._0]);
            glVertex3fv((GLfloat *) &Vertices[Superficie[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Superficie[i]._2]);
        }
    glEnd();
}


//*************************************************************************
// Dibuja la superficie (con triangulos) del objeto con iluminación plana.
//*************************************************************************

void Objeto3D::
draw_Triangles_Iluminacion_Flat(Material mat)
{

    mat.enable_material();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glShadeModel(GL_FLAT);
    glEnable(GL_LIGHTING);

    glBegin(GL_TRIANGLES);
        for(unsigned int i = 0; i < Superficie.size(); i++){
            glNormal3f(Normales[i].x, Normales[i].y, Normales[i].z);
            glVertex3fv((GLfloat *) &Vertices[Superficie[i]._0]);
            glVertex3fv((GLfloat *) &Vertices[Superficie[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Superficie[i]._2]);
        }
    glEnd();

    glDisable(GL_LIGHTING);


}


//*************************************************************************
// Dibuja la superficie (con triangulos) del objeto con iluminación suavizada.
//*************************************************************************


void Objeto3D::draw_Triangles_Iluminacion_Smooth(Material mat)
{


    mat.enable_material();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);

    glBegin(GL_TRIANGLES);
        for(unsigned int i = 0; i < Superficie.size(); i++){
            glNormal3f(Normales_V[Superficie[i]._0].x, Normales_V[Superficie[i]._0].y, Normales_V[Superficie[i]._0].z);
            glVertex3fv((GLfloat *) &Vertices[Superficie[i]._0]);
            glNormal3f(Normales_V[Superficie[i]._1].x, Normales_V[Superficie[i]._1].y, Normales_V[Superficie[i]._1].z);
            glVertex3fv((GLfloat *) &Vertices[Superficie[i]._1]);
            glNormal3f(Normales_V[Superficie[i]._2].x, Normales_V[Superficie[i]._2].y, Normales_V[Superficie[i]._2].z);
            glVertex3fv((GLfloat *) &Vertices[Superficie[i]._2]);
        }
    glEnd();
    glDisable(GL_LIGHTING);
}


void Objeto3D::calculaNormales()
{
    calculaNormalesSuperficie();
    calculaNormalesVertices();
}

void Objeto3D::calculaNormalesSuperficie()
{
    Normales.resize(Superficie.size());
    _vertex3f vector1, vector2;

    for(unsigned int i = 0; i < Superficie.size(); i++){
        vector1(Vertices[Superficie[i]._0].x - Vertices[Superficie[i]._1].x, Vertices[Superficie[i]._0].y - Vertices[Superficie[i]._1].y,Vertices[Superficie[i]._0].z - Vertices[Superficie[i]._1].z );
        vector2(Vertices[Superficie[i]._0].x - Vertices[Superficie[i]._2].x, Vertices[Superficie[i]._0].y - Vertices[Superficie[i]._2].y,Vertices[Superficie[i]._0].z - Vertices[Superficie[i]._2].z );

        Normales[i]=_vertex3f(vector1.cross_product(vector2).normalize());
    }

}

void Objeto3D::calculaNormalesVertices(){
    Normales_V.resize(Vertices.size());

    for(unsigned int i = 0; i < Superficie.size(); i++){
        Normales_V[Superficie[i]._0] += Normales[i];
        Normales_V[Superficie[i]._1] += Normales[i];
        Normales_V[Superficie[i]._2] += Normales[i];
    }

    for(unsigned int i = 0; i < Normales_V.size(); i++){
        Normales_V[i] = _vertex3f(Normales_V[i].normalize());
    }
}

void Objeto3D::setColor(float r, float g, float b, float alpha)
{
    color = _vertex4f(r, g, b, alpha);
    color_lineas = _vertex4f(b,g,r, alpha);
    color_vertices = _vertex4f(g,r,b, alpha);

}
