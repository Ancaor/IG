#include "marcodetexturas.h"

MarcoDeTexturas::MarcoDeTexturas()
{

}


//**************************************************************************
// Cargo una textura
//***************************************************************************

void MarcoDeTexturas::cargarTextura(QString path)
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
// Dibuja el marco con la textura sin iluminación
//***************************************************************************

void MarcoDeTexturas::drawTextura(float *pos_img, int *pos_marco)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(1,1,1);
    int x_min_marco = pos_marco[0];
    int x_max_marco = pos_marco[1];
    int y_min_marco = pos_marco[2];
    int y_max_marco = pos_marco[3];

    float x_min_img = pos_img[0];
    float x_max_img = pos_img[1];
    float y_min_img = pos_img[2];
    float y_max_img = pos_img[3];

    float x_imagen = x_min_img;
    float y_imagen = y_min_img;
    float salto_img_y = (y_max_img - y_min_img) / (y_max_marco - y_min_marco);
    float salto_img_x = (x_max_img - x_min_img) / (x_max_marco - x_min_marco);

    int v1, v2, v3;

    if(textura_habilitada)
        glEnable(GL_TEXTURE_2D);
    else
        glDisable(GL_TEXTURE_2D);

    glBegin(GL_TRIANGLES);


    for(int i = y_min_marco; i < y_max_marco; i++){
        x_imagen = x_min_img;
        for(int j = x_min_marco; j < x_max_marco; j++){
            //triangulo par
            v1 = i*(divisiones_ancho+1) + j;
            v2 = v1+1;
            v3 = v1 + divisiones_ancho+1;

            glTexCoord2f(x_imagen,y_imagen);
            glVertex3f(Vertices[v1].x,Vertices[v1].y,0);
            glTexCoord2f(x_imagen+salto_img_x,y_imagen);
            glVertex3f(Vertices[v2].x,Vertices[v2].y,0);
            glTexCoord2f(x_imagen,y_imagen+salto_img_y);
            glVertex3f(Vertices[v3].x,Vertices[v3].y,0);

            //triangulo impar
            v1 = i*(divisiones_ancho+1) + j+ 1;
            v2 = v1 + divisiones_ancho+1;
            v3 = v2-1;

            glTexCoord2f(x_imagen+salto_img_x,y_imagen);
            glVertex3f(Vertices[v1].x,Vertices[v1].y,0);
            glTexCoord2f(x_imagen+salto_img_x,y_imagen+salto_img_y);
            glVertex3f(Vertices[v2].x,Vertices[v2].y,0);
            glTexCoord2f(x_imagen,y_imagen+salto_img_y);
            glVertex3f(Vertices[v3].x,Vertices[v3].y,0);

            x_imagen = x_min_img + salto_img_x*(j - x_min_marco + 1);
        }

        y_imagen = y_min_img + salto_img_y*(i - y_min_marco + 1);
    }

    glEnd();

    glDisable(GL_TEXTURE_2D);

}

//**************************************************************************
// Dibuja el marco con la textura con iluminación FLAT
//***************************************************************************


void MarcoDeTexturas::draw_Triangles_Iluminacion_Flat(float *pos_img, int *pos_marco, Material material)
{

    glEnable(GL_LIGHTING);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(1,1,1);
    int x_min_marco = pos_marco[0];
    int x_max_marco = pos_marco[1];
    int y_min_marco = pos_marco[2];
    int y_max_marco = pos_marco[3];

    float x_min_img = pos_img[0];
    float x_max_img = pos_img[1];
    float y_min_img = pos_img[2];
    float y_max_img = pos_img[3];

    float x_imagen = x_min_img;
    float y_imagen = y_min_img;
    float salto_img_y = (y_max_img - y_min_img) / (y_max_marco - y_min_marco);
    float salto_img_x = (x_max_img - x_min_img) / (x_max_marco - x_min_marco);

    int v1, v2, v3;

    if(textura_habilitada)
        glEnable(GL_TEXTURE_2D);
    else
        glDisable(GL_TEXTURE_2D);

    glShadeModel(GL_FLAT);
    material.enable_material();
    glBegin(GL_TRIANGLES);

    for(int i = y_min_marco; i < y_max_marco; i++){
        x_imagen = x_min_img;
        for(int j = x_min_marco; j < x_max_marco; j++){
            //triangulo par
            v1 = i*(divisiones_ancho+1) + j;
            v2 = v1+1;
            v3 = v1 + divisiones_ancho+1;
            glNormal3f(Normales[i].x, Normales[i].y, Normales[i].z);
            glTexCoord2f(x_imagen,y_imagen);
            glVertex3f(Vertices[v1].x,Vertices[v1].y,0);
            glTexCoord2f(x_imagen+salto_img_x,y_imagen);
            glVertex3f(Vertices[v2].x,Vertices[v2].y,0);
            glTexCoord2f(x_imagen,y_imagen+salto_img_y);
            glVertex3f(Vertices[v3].x,Vertices[v3].y,0);

            //triangulo impar
            v1 = i*(divisiones_ancho+1) + j+ 1;
            v2 = v1 + divisiones_ancho+1;
            v3 = v2-1;
            glNormal3f(Normales[i].x, Normales[i].y, Normales[i].z);
            glTexCoord2f(x_imagen+salto_img_x,y_imagen);
            glVertex3f(Vertices[v1].x,Vertices[v1].y,0);
            glTexCoord2f(x_imagen+salto_img_x,y_imagen+salto_img_y);
            glVertex3f(Vertices[v2].x,Vertices[v2].y,0);
            glTexCoord2f(x_imagen,y_imagen+salto_img_y);
            glVertex3f(Vertices[v3].x,Vertices[v3].y,0);

            x_imagen = x_min_img + salto_img_x*(j - x_min_marco + 1);
        }

        y_imagen = y_min_img + salto_img_y*(i - y_min_marco + 1);
    }

    glEnd();

    glDisable(GL_TEXTURE_2D);

    glDisable(GL_LIGHTING);

}

//**************************************************************************
// Dibuja el marco con la textura con iluminación SMOOTH
//***************************************************************************


void MarcoDeTexturas::draw_Triangles_Iluminacion_Smooth(float *pos_img, int *pos_marco, Material material)
{

    glEnable(GL_LIGHTING);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(1,1,1);
    int x_min_marco = pos_marco[0];
    int x_max_marco = pos_marco[1];
    int y_min_marco = pos_marco[2];
    int y_max_marco = pos_marco[3];

    float x_min_img = pos_img[0];
    float x_max_img = pos_img[1];
    float y_min_img = pos_img[2];
    float y_max_img = pos_img[3];

    float x_imagen = x_min_img;
    float y_imagen = y_min_img;
    float salto_img_y = (y_max_img - y_min_img) / (y_max_marco - y_min_marco);
    float salto_img_x = (x_max_img - x_min_img) / (x_max_marco - x_min_marco);

    int v1, v2, v3;

    if(textura_habilitada)
        glEnable(GL_TEXTURE_2D);
    else
        glDisable(GL_TEXTURE_2D);

    glShadeModel(GL_SMOOTH);
    material.enable_material();
    glBegin(GL_TRIANGLES);

    for(int i = y_min_marco; i < y_max_marco; i++){
        x_imagen = x_min_img;
        for(int j = x_min_marco; j < x_max_marco; j++){
            //triangulo par
            v1 = i*(divisiones_ancho+1) + j;
            v2 = v1+1;
            v3 = v1 + divisiones_ancho+1;
            glNormal3f(Normales[i].x, Normales[i].y, Normales[i].z);
            glTexCoord2f(x_imagen,y_imagen);
            glVertex3f(Vertices[v1].x,Vertices[v1].y,0);
            glNormal3f(Normales[i].x, Normales[i].y, Normales[i].z);
            glTexCoord2f(x_imagen+salto_img_x,y_imagen);
            glVertex3f(Vertices[v2].x,Vertices[v2].y,0);
            glNormal3f(Normales[i].x, Normales[i].y, Normales[i].z);
            glTexCoord2f(x_imagen,y_imagen+salto_img_y);
            glVertex3f(Vertices[v3].x,Vertices[v3].y,0);

            //triangulo impar
            v1 = i*(divisiones_ancho+1) + j+ 1;
            v2 = v1 + divisiones_ancho+1;
            v3 = v2-1;
            glNormal3f(Normales[i].x, Normales[i].y, Normales[i].z);
            glTexCoord2f(x_imagen+salto_img_x,y_imagen);
            glVertex3f(Vertices[v1].x,Vertices[v1].y,0);
            glNormal3f(Normales[i].x, Normales[i].y, Normales[i].z);
            glTexCoord2f(x_imagen+salto_img_x,y_imagen+salto_img_y);
            glVertex3f(Vertices[v2].x,Vertices[v2].y,0);
            glNormal3f(Normales[i].x, Normales[i].y, Normales[i].z);
            glTexCoord2f(x_imagen,y_imagen+salto_img_y);
            glVertex3f(Vertices[v3].x,Vertices[v3].y,0);

            x_imagen = x_min_img + salto_img_x*(j - x_min_marco + 1);
        }

        y_imagen = y_min_img + salto_img_y*(i - y_min_marco + 1);
    }

    glEnd();

    glDisable(GL_TEXTURE_2D);

    glDisable(GL_LIGHTING);

}

//**************************************************************************
// Redimensiona el tablero, cambiando numero de divisiones y tamaño.
//***************************************************************************

void MarcoDeTexturas::setTablero(float width, float height, int dw, int dh)
{
    ancho =  width;
    alto = height;
    divisiones_alto = dh;
    divisiones_ancho = dw;
    generaTablero();
    calculaNormales();
}

//**************************************************************************
// Genera los puntos del tablero y la superficie
//***************************************************************************

void MarcoDeTexturas::generaTablero()
{
    float salto_ancho = ancho / divisiones_ancho;
    float salto_alto = alto / divisiones_alto;

    float inicio_ancho = -ancho/2;
    float inicio_alto = -alto/2;

    Vertices.clear();
    Superficie.clear();

    float x = inicio_ancho;
    float y = inicio_alto;

    for(int i = 0; i <= divisiones_alto; i++){
        y = inicio_alto + i*salto_alto;
        for(int j = 0; j <= divisiones_ancho; j++){
            x = inicio_ancho + j*salto_ancho;
            Vertices.push_back(_vertex3f(x, y, 0));
        }
    }

    for(int i = 0; i <= divisiones_ancho-1; i++){
         for(int j = 0; j < divisiones_alto; j++){
            Superficie.push_back(_vertex3i((j*(divisiones_alto+1)+i)%Vertices.size(), (j*(divisiones_alto+1)+i+1)%Vertices.size(), ((j+1)*(divisiones_alto+1) + i)%Vertices.size() ));
            Superficie.push_back(_vertex3i(((j+1)*(divisiones_alto+1) + i)%Vertices.size(), (j*(divisiones_alto+1) +i+1)%Vertices.size(), ((j+1)*(divisiones_alto+1)+i+1)%Vertices.size() ));
        }
    }

}

void MarcoDeTexturas::setTextura(bool check)
{
    textura_habilitada = check;

}
