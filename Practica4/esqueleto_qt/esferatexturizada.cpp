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

   // calcularNormalesCaras();
   // calcularNormalesVertices();
}

void EsferaTexturizada::generar_objeto_de_revolucion(int angulo){
    SECCIONES--;

    float angulo_radianes = angulo*(M_PI/180.0);

    revolucion_por_barrido_y(angulo_radianes);
    generar_caras();

}

void EsferaTexturizada::cargarImagen(string path)
{

    QString aux = QString::fromStdString(path);

    if (Imagen.load(aux)==false) cout << "Image not loaded" << endl;
    // reflejo vertical
    Imagen=Imagen.mirrored(false,true);
    //
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // parametros de aplicacion de la textura
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    // asignacion de la textura
    glTexImage2D(GL_TEXTURE_2D,0,4,Imagen.width(),Imagen.height(),0,GL_BGRA,GL_UNSIGNED_BYTE,Imagen.bits());
}

void EsferaTexturizada::drawTextura(std::string path_textura,bool cargar_textura)
{



    float pos_x_tex_min = 0.0;
    float pos_x_tex_max = 1.0;
    float pos_y_tex_min = 0.0;
    float pos_y_tex_max = 1.0;

    float x_textura = pos_x_tex_min;
    float y_textura = pos_y_tex_min;
    float salto_y = (pos_y_tex_max - pos_y_tex_min) / PUNTOS_PERFIL;//(pos_y_marco_max - pos_y_marco_min);
    float salto_x = (pos_x_tex_max - pos_x_tex_min) /SECCIONES;//(pos_x_marco_max - pos_x_marco_min);

    int v1,v2,v3;

    //if(cargar_textura)
     //   cargarImagen(path_textura);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

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


            glTexCoord2f(x_textura,y_textura + salto_y);
            glVertex3f(vertices[v1].x,vertices[v1].y,vertices[v1].z);

            glTexCoord2f(x_textura,y_textura);
            glVertex3f(vertices[v2].x,vertices[v2].y,vertices[v2].z);
glTexCoord2f(x_textura + salto_x,y_textura);
            glVertex3f(vertices[v3].x,vertices[v3].y,vertices[v3].z);

            v1 = (((j+1)*PUNTOS_PERFIL)+i)%PUNTOS;
            v2 = (((j+1)*PUNTOS_PERFIL)+(i+1))%PUNTOS;
            v3 = ((j*PUNTOS_PERFIL)+(i+1))%PUNTOS;

            glTexCoord2f(x_textura + salto_x,y_textura);
            glVertex3f(vertices[v1].x,vertices[v1].y,vertices[v1].z);

            glTexCoord2f(x_textura + salto_x,y_textura + salto_y);
            glVertex3f(vertices[v2].x,vertices[v2].y,vertices[v2].z);

            glTexCoord2f(x_textura,y_textura + salto_y);
            glVertex3f(vertices[v3].x,vertices[v3].y,vertices[v3].z);

            x_textura =  pos_x_tex_min + salto_x*(j - 0 +1);
        }

        y_textura = pos_y_tex_min + salto_y*(i - 0 + 1);

    }



    glEnd();
    glDisable(GL_TEXTURE_2D);


}

void EsferaTexturizada::drawFillIluminado(std::string path_textura,bool cargar_textura,Material material, bool iluminacion)
{

    if(normalCaras.empty())
        calcularNormalesCaras();

 //   for(int i=0;i<10;i++)
  //      cout << normalCaras[i]._0 << "  "<< normalCaras[i]._1 << "  " << normalCaras[i]._2 << endl;


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

    //if(cargar_textura)
     //   cargarImagen(path_textura);

    if(iluminacion)
        glEnable(GL_LIGHTING);



    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    glShadeModel(GL_FLAT);

    glEnable(GL_TEXTURE_2D);
    //material.enable();
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

            //glNormal3fv((GLfloat*) &normalCaras[index]);
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

            //glNormal3fv((GLfloat*) &normalCaras[index+1]);
            glNormal3f(normalCaras[index+1].x,normalCaras[index+1].y,normalCaras[index+1].z);
            glTexCoord2f(x_textura + salto_x,y_textura);
            glVertex3f(vertices[v1].x,vertices[v1].y,vertices[v1].z);

            glTexCoord2f(x_textura + salto_x,y_textura + salto_y);
            glVertex3f(vertices[v2].x,vertices[v2].y,vertices[v2].z);

            glTexCoord2f(x_textura,y_textura + salto_y);
            glVertex3f(vertices[v3].x,vertices[v3].y,vertices[v3].z);

            x_textura =  pos_x_tex_min + salto_x*(j - 0 +1);
            index+=2;
        }

        y_textura = pos_y_tex_min + salto_y*(i - 0 + 1);

    }
  //  material.enable();


    glEnd();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);


}


void EsferaTexturizada::drawFillIluminadoSuave(std::string path_textura,bool cargar_textura,Material material , bool iluminacion)
{
    if(normalVertices.empty())
        calcularNormalesVertices();

    if(iluminacion)
        glEnable(GL_LIGHTING);

    /*int pos_x_marco_min = porcion_marco[1];
    int pos_x_marco_max = porcion_marco[3];
    int pos_y_marco_min = porcion_marco[0];
    int pos_y_marco_max = porcion_marco[2];
*/
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

  //  if(cargar_textura)
    //    cargarImagen(path_textura);

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

