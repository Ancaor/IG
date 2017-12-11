#include "esferatexturizada.h"

EsferaTexturizada::EsferaTexturizada(){

}

EsferaTexturizada::EsferaTexturizada(int secciones,int angulo, float radio)
{
    SECCIONES = secciones;

    vertices.push_back(_vertex3f(0.0,-(radio/2.0),0.0));
    revolucion_por_barrido_z(M_PI);
    setPuntosPerfil(vertices.size());
    vertices[vertices.size()-1] = _vertex3f(0.0,(radio/2.0),0.0);
    generar_objeto_de_revolucion(angulo);

    calcularNormalesCaras();
    calcularNormalesVertices();
}

/*
    Metodo sobrecargado de O3DR que permite puntos repetidos para poder palicar textura correctamente.
  */
void EsferaTexturizada::generar_objeto_de_revolucion(int angulo){
    SECCIONES--;

    float angulo_radianes = angulo*(M_PI/180.0);

    revolucion_por_barrido_y(angulo_radianes);
    generar_caras();

}

/*
 *  Carga la imagen como textura
 *
*/

void EsferaTexturizada::cargarImagen(string path)
{

    QString aux = QString::fromStdString(path);

    if (Imagen.load(aux)==false) cout << "Image not loaded" << endl;

    // reflejo vertical
    Imagen=Imagen.mirrored(false,true);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // parametros de aplicacion de la textura
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    // asignacion de la textura
    glTexImage2D(GL_TEXTURE_2D,0,4,Imagen.width(),Imagen.height(),0,GL_BGRA,GL_UNSIGNED_BYTE,Imagen.bits());
}

/*
 * Dibuja textura sin ilumimnación
 *
*/


void EsferaTexturizada::drawTextura()
{

    // Se utiliza la textura completa

    float pos_x_tex_min = 0.0;
    float pos_x_tex_max = 1.0;
    float pos_y_tex_min = 0.0;
    float pos_y_tex_max = 1.0;

    float x_textura = pos_x_tex_min;
    float y_textura = pos_y_tex_min;

    float salto_y = (pos_y_tex_max - pos_y_tex_min) / PUNTOS_PERFIL;
    float salto_x = (pos_x_tex_max - pos_x_tex_min) /SECCIONES;

    int v1,v2,v3;


    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1,1,1);

    glBegin(GL_TRIANGLES);

    int i,j;
    int PUNTOS = vertices.size();


    for(i = 0; i < PUNTOS_PERFIL-1 ; i++){
        x_textura = pos_x_tex_min;
        for(j=0; j < SECCIONES ; j++){

            // Triangulos Pares

            v1 = ((j*PUNTOS_PERFIL)+(i+1))%PUNTOS;
            v2 = ((j*PUNTOS_PERFIL)+i)%PUNTOS;
            v3 = (((j+1)*PUNTOS_PERFIL)+i )%PUNTOS;


            glTexCoord2f(x_textura,y_textura + salto_y);
            glVertex3f(vertices[v1].x,vertices[v1].y,vertices[v1].z);

            glTexCoord2f(x_textura,y_textura);
            glVertex3f(vertices[v2].x,vertices[v2].y,vertices[v2].z);

            glTexCoord2f(x_textura + salto_x,y_textura);
            glVertex3f(vertices[v3].x,vertices[v3].y,vertices[v3].z);

            // Triangulos Impares

            v1 = (((j+1)*PUNTOS_PERFIL)+i)%PUNTOS;
            v2 = (((j+1)*PUNTOS_PERFIL)+(i+1))%PUNTOS;
            v3 = ((j*PUNTOS_PERFIL)+(i+1))%PUNTOS;

            glTexCoord2f(x_textura + salto_x,y_textura);
            glVertex3f(vertices[v1].x,vertices[v1].y,vertices[v1].z);

            glTexCoord2f(x_textura + salto_x,y_textura + salto_y);
            glVertex3f(vertices[v2].x,vertices[v2].y,vertices[v2].z);

            glTexCoord2f(x_textura,y_textura + salto_y);
            glVertex3f(vertices[v3].x,vertices[v3].y,vertices[v3].z);

            x_textura =  pos_x_tex_min + salto_x * (j +1 );
        }

        y_textura = pos_y_tex_min + salto_y * (i + 1 );

    }

    glEnd();
    glDisable(GL_TEXTURE_2D);

}


/*
 * Dibula la esfera texturizada con sombreado FLAT
*/


void EsferaTexturizada::drawFillIluminado(Material material, bool iluminacion)
{

    float pos_x_tex_min = 0.0;
    float pos_x_tex_max = 1.0;
    float pos_y_tex_min = 0.0;
    float pos_y_tex_max = 1.0;


    float x_textura = pos_x_tex_min;
    float y_textura = pos_y_tex_min;
    float salto_y = (pos_y_tex_max - pos_y_tex_min) / PUNTOS_PERFIL;
    float salto_x = (pos_x_tex_max - pos_x_tex_min) /SECCIONES;

    int v1,v2,v3;

    // Indice de las Normales
    int index=0;

    if(iluminacion)
        glEnable(GL_LIGHTING);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_FLAT);
    glEnable(GL_TEXTURE_2D);
    material.enable();
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);

    int i,j;
    int PUNTOS = vertices.size();
    for(i = 0; i < PUNTOS_PERFIL-1 ; i++){
        x_textura = pos_x_tex_min;
        for(j=0; j < SECCIONES ; j++){

            v1 = ((j*PUNTOS_PERFIL)+(i+1))%PUNTOS;
            v2 = ((j*PUNTOS_PERFIL)+i)%PUNTOS;
            v3 = (((j+1)*PUNTOS_PERFIL)+i )%PUNTOS;


            glNormal3f(normalCaras[index].x,normalCaras[index].y,normalCaras[index].z);
            glTexCoord2f(x_textura,y_textura + salto_y);
            glVertex3f(vertices[v1].x,vertices[v1].y,vertices[v1].z);

            glTexCoord2f(x_textura,y_textura);
            glVertex3f(vertices[v2].x,vertices[v2].y,vertices[v2].z);
            glTexCoord2f(x_textura + salto_x,y_textura);
            glVertex3f(vertices[v3].x,vertices[v3].y,vertices[v3].z);

            v1 = (((j+1)*PUNTOS_PERFIL)+i)%PUNTOS;
            v2 = (((j+1)*PUNTOS_PERFIL)+(i+1))%PUNTOS;
            v3 = ((j*PUNTOS_PERFIL)+(i+1))%PUNTOS;

            glNormal3f(normalCaras[index+1].x,normalCaras[index+1].y,normalCaras[index+1].z);
            glTexCoord2f(x_textura + salto_x,y_textura);
            glVertex3f(vertices[v1].x,vertices[v1].y,vertices[v1].z);

            glTexCoord2f(x_textura + salto_x,y_textura + salto_y);
            glVertex3f(vertices[v2].x,vertices[v2].y,vertices[v2].z);

            glTexCoord2f(x_textura,y_textura + salto_y);
            glVertex3f(vertices[v3].x,vertices[v3].y,vertices[v3].z);

            x_textura =  pos_x_tex_min + salto_x*(j +1);
            index+=2;
        }

        y_textura = pos_y_tex_min + salto_y*(i + 1);

    }

    glEnd();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);


}


/*
 *  Dibula la esfera texturizada con sombreado SMOOTH
 *
*/


void EsferaTexturizada::drawFillIluminadoSuave(Material material , bool iluminacion)
{

    if(iluminacion)
        glEnable(GL_LIGHTING);

    float pos_x_tex_min = 0.0;
    float pos_x_tex_max = 1.0;
    float pos_y_tex_min = 0.0;
    float pos_y_tex_max = 1.0;

    float x_textura = pos_x_tex_min;
    float y_textura = pos_y_tex_min;
    float salto_y = (pos_y_tex_max - pos_y_tex_min) / PUNTOS_PERFIL;//(pos_y_marco_max - pos_y_marco_min);
    float salto_x = (pos_x_tex_max - pos_x_tex_min) /SECCIONES;//(pos_x_marco_max - pos_x_marco_min);


    int v1,v2,v3;

    int index=0;

    material.enable();

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);


    int i,j;
    int PUNTOS = vertices.size();
    for(i = 0; i < PUNTOS_PERFIL-1 ; i++){
        x_textura = pos_x_tex_min;
        for(j=0; j < SECCIONES ; j++){

            v1 = ((j*PUNTOS_PERFIL)+(i+1))%PUNTOS;
            v2 = ((j*PUNTOS_PERFIL)+i)%PUNTOS;
            v3 = (((j+1)*PUNTOS_PERFIL)+i )%PUNTOS;

            glNormal3fv((GLfloat*) &normalVertices[triangles[index]._0]);
             glTexCoord2f(x_textura,y_textura + salto_y);
            glVertex3f(vertices[v1].x,vertices[v1].y,vertices[v1].z);

            glNormal3fv((GLfloat*) &normalVertices[triangles[index]._1]);
           glTexCoord2f(x_textura,y_textura);
            glVertex3f(vertices[v2].x,vertices[v2].y,vertices[v2].z);

            glNormal3fv((GLfloat*) &normalVertices[triangles[index]._2]);
            glTexCoord2f(x_textura + salto_x,y_textura);
            glVertex3f(vertices[v3].x,vertices[v3].y,vertices[v3].z);

            v1 = (((j+1)*PUNTOS_PERFIL)+i)%PUNTOS;
            v2 = (((j+1)*PUNTOS_PERFIL)+(i+1))%PUNTOS;
            v3 = ((j*PUNTOS_PERFIL)+(i+1))%PUNTOS;

            glNormal3fv((GLfloat*) &normalVertices[triangles[index+1]._0]);
            glTexCoord2f(x_textura + salto_x,y_textura);
            glVertex3f(vertices[v1].x,vertices[v1].y,vertices[v1].z);

            glNormal3fv((GLfloat*) &normalVertices[triangles[index+1]._1]);
            glTexCoord2f(x_textura + salto_x,y_textura + salto_y);
            glVertex3f(vertices[v2].x,vertices[v2].y,vertices[v2].z);

            glNormal3fv((GLfloat*) &normalVertices[triangles[index+1]._2]);
            glTexCoord2f(x_textura,y_textura + salto_y);
            glVertex3f(vertices[v3].x,vertices[v3].y,vertices[v3].z);

            x_textura =  pos_x_tex_min + salto_x*(j - 0 +1);
            index+=2;
        }

        y_textura = pos_y_tex_min + salto_y*(i - 0 + 1);

    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
}

