#include "esfera_textura.h"


//**************************************************************************
// Constructor por defecto.
//***************************************************************************

Esfera_Textura::Esfera_Textura()
{
    divisiones--;
    tama_perfil = divisiones;

    Vertices.resize(1);
    Vertices[0]=_vertex3f(0,-0.5,0);
    this->RevolucionPorBarrido_Z(0,180);

    this->RevolucionPorBarrido_Y(0,360);
    this->GeneraSuperficieTextura();
    this->calculaNormales();
}

//**************************************************************************
// Constructor por parámetros.
//***************************************************************************

Esfera_Textura::Esfera_Textura(int d, float r)
{
    divisiones = d;
    tama_perfil = divisiones;

    Vertices.resize(1);
    Vertices[0]=_vertex3f(0,-r,0);
    this->RevolucionPorBarrido_Z(0,180);

    this->RevolucionPorBarrido_Y(0,360);
    this->GeneraSuperficieTextura();
    this->calculaNormales();
}

//**************************************************************************
// Carga una textura
//***************************************************************************

void Esfera_Textura::cargarTextura(QString path)
{
    // carga de una imagen
    if (textura.load(path)==false) cout << "Image not loaded" << endl;
    // reflejo vertical
    textura=textura.mirrored(false,true);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // parametros de aplicacion de la textura
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    // asignacion de la textura
    glTexImage2D(GL_TEXTURE_2D,0,4,textura.width(),textura.height(),0,GL_BGRA,GL_UNSIGNED_BYTE,textura.bits());
}


//**************************************************************************
// Dibuja la esfera con la textura sin iluminación.
//***************************************************************************

void Esfera_Textura::drawTextura()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(1,1,1);

    float x_imagen = 0;
    float y_imagen = 0;
    float salto_img_y = 1.0/divisiones;
    float salto_img_x = 1.0/divisiones;

    int v1, v2, v3;

    if(textura_habilitada)
        glEnable(GL_TEXTURE_2D);
    else
        glDisable(GL_TEXTURE_2D);

    glBegin(GL_TRIANGLES);


    for(int i = 0; i < divisiones; i++){
        x_imagen = 0;
        for(int j = 0; j < divisiones; j++){
            v1 = j*(divisiones+1) + i;
            v2 = (j+1)*(divisiones+1) + i;
            v3 = j*(divisiones+1) + 1 + i;

            glTexCoord2f(x_imagen,y_imagen);
            glVertex3f(Vertices[v1].x,Vertices[v1].y,Vertices[v1].z);
            glTexCoord2f(x_imagen+salto_img_x,y_imagen);
            glVertex3f(Vertices[v2].x,Vertices[v2].y,Vertices[v2].z);
            glTexCoord2f(x_imagen,y_imagen+salto_img_y);
            glVertex3f(Vertices[v3].x,Vertices[v3].y,Vertices[v3].z);

            v1 = (j+1)*(divisiones+1) + i;
            v2 = (j+1)*(divisiones+1) + i + 1;
            v3 = j*(divisiones+1) + 1 + i ;

            glTexCoord2f(x_imagen+salto_img_x,y_imagen);
            glVertex3f(Vertices[v1].x,Vertices[v1].y,Vertices[v1].z);
            glTexCoord2f(x_imagen+salto_img_x,y_imagen+salto_img_y);
            glVertex3f(Vertices[v2].x,Vertices[v2].y,Vertices[v2].z);
            glTexCoord2f(x_imagen,y_imagen+salto_img_y);
            glVertex3f(Vertices[v3].x,Vertices[v3].y,Vertices[v3].z);

            x_imagen = salto_img_x*(j + 1);
        }

        y_imagen = salto_img_y*(i + 1);
    }

    glEnd();

    glDisable(GL_TEXTURE_2D);

}

//**************************************************************************
// Dibuja la esfera con la textura con iluminación FLAT
//***************************************************************************

void Esfera_Textura::draw_Triangles_Iluminacion_Flat(Material material)
{
    glEnable(GL_LIGHTING);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(1,1,1);

    float x_imagen = 0;
    float y_imagen = 0;
    float salto_img_y = 1.0/divisiones;
    float salto_img_x = 1.0/divisiones;
    int n_superficie = 0;

    int v1, v2, v3;

    if(textura_habilitada)
        glEnable(GL_TEXTURE_2D);
    else
        glDisable(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);
    material.enable_material();

    glBegin(GL_TRIANGLES);


    for(int i = 0; i < divisiones; i++){
        x_imagen = 0;
        for(int j = 0; j < divisiones; j++){
            v1 = j*(divisiones+1) + i;
            v2 = (j+1)*(divisiones+1) + i;
            v3 = j*(divisiones+1) + 1 + i;

            glNormal3f(Normales[n_superficie].x, Normales[n_superficie].y, Normales[n_superficie].z);
            glTexCoord2f(x_imagen,y_imagen);
            glVertex3f(Vertices[v1].x,Vertices[v1].y,Vertices[v1].z);
            glTexCoord2f(x_imagen+salto_img_x,y_imagen);
            glVertex3f(Vertices[v2].x,Vertices[v2].y,Vertices[v2].z);
            glTexCoord2f(x_imagen,y_imagen+salto_img_y);
            glVertex3f(Vertices[v3].x,Vertices[v3].y,Vertices[v3].z);

            n_superficie++;
            v1 = (j+1)*(divisiones+1) + i;
            v2 = (j+1)*(divisiones+1) + i + 1;
            v3 = j*(divisiones+1) + 1 + i ;

            glNormal3f(Normales[n_superficie].x, Normales[n_superficie].y, Normales[n_superficie].z);
            glTexCoord2f(x_imagen+salto_img_x,y_imagen);
            glVertex3f(Vertices[v1].x,Vertices[v1].y,Vertices[v1].z);
            glTexCoord2f(x_imagen+salto_img_x,y_imagen+salto_img_y);
            glVertex3f(Vertices[v2].x,Vertices[v2].y,Vertices[v2].z);
            glTexCoord2f(x_imagen,y_imagen+salto_img_y);
            glVertex3f(Vertices[v3].x,Vertices[v3].y,Vertices[v3].z);

            n_superficie++;

            x_imagen = salto_img_x*(j + 1);
        }

        y_imagen = salto_img_y*(i + 1);
    }

    glEnd();
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

}


//**************************************************************************
// Dibuja la esfera con la textura con iluminación SMOOTH
//***************************************************************************
void Esfera_Textura::draw_Triangles_Iluminacion_Smooth(Material material)
{
    glEnable(GL_LIGHTING);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(1,1,1);

    float x_imagen = 0;
    float y_imagen = 0;
    float salto_img_y = 1.0/divisiones;
    float salto_img_x = 1.0/divisiones;

    int v1, v2, v3;

    if(textura_habilitada)
        glEnable(GL_TEXTURE_2D);
    else
        glDisable(GL_TEXTURE_2D);

    glShadeModel(GL_SMOOTH);
    material.enable_material();

    glBegin(GL_TRIANGLES);


    for(int i = 0; i < divisiones; i++){
        x_imagen = 0;
        for(int j = 0; j < divisiones; j++){
            v1 = j*(divisiones+1) + i;
            v2 = (j+1)*(divisiones+1) + i;
            v3 = j*(divisiones+1) + 1 + i;

            glNormal3f(Normales_V[v1].x, Normales_V[v1].y, Normales_V[v1].z);
            glTexCoord2f(x_imagen,y_imagen);
            glVertex3f(Vertices[v1].x,Vertices[v1].y,Vertices[v1].z);

            glNormal3f(Normales_V[v2].x, Normales_V[v2].y, Normales_V[v2].z);
            glTexCoord2f(x_imagen+salto_img_x,y_imagen);
            glVertex3f(Vertices[v2].x,Vertices[v2].y,Vertices[v2].z);

            glNormal3f(Normales_V[v3].x, Normales_V[v3].y, Normales_V[v3].z);
            glTexCoord2f(x_imagen,y_imagen+salto_img_y);
            glVertex3f(Vertices[v3].x,Vertices[v3].y,Vertices[v3].z);

            v1 = (j+1)*(divisiones+1) + i;
            v2 = (j+1)*(divisiones+1) + i + 1;
            v3 = j*(divisiones+1) + 1 + i ;

            glNormal3f(Normales_V[v1].x, Normales_V[v1].y, Normales_V[v1].z);
            glTexCoord2f(x_imagen+salto_img_x,y_imagen);
            glVertex3f(Vertices[v1].x,Vertices[v1].y,Vertices[v1].z);

            glNormal3f(Normales_V[v2].x, Normales_V[v2].y, Normales_V[v2].z);
            glTexCoord2f(x_imagen+salto_img_x,y_imagen+salto_img_y);
            glVertex3f(Vertices[v2].x,Vertices[v2].y,Vertices[v2].z);

            glNormal3f(Normales_V[v3].x, Normales_V[v3].y, Normales_V[v3].z);
            glTexCoord2f(x_imagen,y_imagen+salto_img_y);
            glVertex3f(Vertices[v3].x,Vertices[v3].y,Vertices[v3].z);

            x_imagen = salto_img_x*(j + 1);
        }

        y_imagen = salto_img_y*(i + 1);
    }

    glEnd();
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

}

void Esfera_Textura::setTextura(bool check)
{
    textura_habilitada = check;

}
