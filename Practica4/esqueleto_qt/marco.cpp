#include "marco.h"

marco::marco()
{

}

marco::marco(int n , float ancho , float alto)
{
    this->n = n;
    float tama = 1.0;
    float x_min=-(ancho*0.5);
    float y_min=-(alto*0.5);

    float x,y;

    float salto_x = ancho/n;
    float salto_y = alto/n;
    for(int i=0;i<=n;i++){
        y= y_min + (i*salto_y);
        for(int j=0;j<=n;j++){
            x = x_min + (j*salto_x);
            vertices.push_back(_vertex3f(x,y,0.0));
        }
    }


    for(int i=0;i<=n-1;i++){

        for(int j=0;j<n;j++){
            //Triangulo par
            triangles.push_back(_vertex3i(  ((j*(n+1))+i)%vertices.size() , ((j*(n+1))+(i+1))%vertices.size(),(((j+1)*(n+1))+i )%vertices.size()) );
            //Triangulo Impar
            triangles.push_back(_vertex3i(  (((j+1)*(n+1))+(i+1))%vertices.size() , (((j+1)*(n+1))+i)%vertices.size() , ((j*(n+1))+(i+1))%vertices.size() ) );
        }
    }

}

void marco::cargarImagen(string path)
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
 * Dada porcion de textura y porcion del marco de N x N aplica la textura.
 *
*/


void marco::drawTextura(vector<float> porcion_textura, vector<int> porcion_marco)
{


    int pos_x_marco_min = porcion_marco[1];
    int pos_x_marco_max = porcion_marco[3];
    int pos_y_marco_min = porcion_marco[0];
    int pos_y_marco_max = porcion_marco[2];

    float pos_x_tex_min = porcion_textura[1];
    float pos_x_tex_max = porcion_textura[3];
    float pos_y_tex_min = porcion_textura[0];
    float pos_y_tex_max = porcion_textura[2];

    float x_textura = pos_x_tex_min;
    float y_textura = pos_y_tex_min;
    float salto_y = (pos_y_tex_max - pos_y_tex_min) / (pos_y_marco_max - pos_y_marco_min);
    float salto_x = (pos_x_tex_max - pos_x_tex_min) / (pos_x_marco_max - pos_x_marco_min);

    int v1,v2,v3;


    glEnable(GL_TEXTURE_2D);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);


    for(int i=pos_y_marco_min; i < pos_y_marco_max; i++){
        x_textura = pos_x_tex_min;
        for(int j=pos_x_marco_min; j < pos_x_marco_max; j++){

            v1 = i * (n+1) +j;
            v2 = v1+1;
            v3 = v1 +(n+1);

            glTexCoord2f(x_textura,y_textura);
            glVertex3f(vertices[v1].x,vertices[v1].y,vertices[v1].z);

            glTexCoord2f(x_textura + salto_x,y_textura);
            glVertex3f(vertices[v2].x,vertices[v2].y,vertices[v2].z);

            glTexCoord2f(x_textura,y_textura + salto_y);
            glVertex3f(vertices[v3].x,vertices[v3].y,vertices[v3].z);

            v1 = v2;
            v2 = v1 +(n+1);
            v3 = v2-1;

            glTexCoord2f(x_textura + salto_x,y_textura);
            glVertex3f(vertices[v1].x,vertices[v1].y,vertices[v1].z);

            glTexCoord2f(x_textura + salto_x,y_textura + salto_y);
            glVertex3f(vertices[v2].x,vertices[v2].y,vertices[v2].z);

            glTexCoord2f(x_textura,y_textura + salto_y);
            glVertex3f(vertices[v3].x,vertices[v3].y,vertices[v3].z);

            x_textura =  pos_x_tex_min + salto_x*(j - pos_x_marco_min +1);
        }

        y_textura = pos_y_tex_min + salto_y*(i - pos_y_marco_min + 1);

    }



    glEnd();
    glDisable(GL_TEXTURE_2D);


}

void marco::drawFillIluminado(vector<float> porcion_textura, vector<int> porcion_marco, Material material, bool iluminacion)
{
    if(normalCaras.empty())
        calcularNormalesCaras();


    if(iluminacion)
        glEnable(GL_LIGHTING);




    int pos_x_marco_min = porcion_marco[1];
    int pos_x_marco_max = porcion_marco[3];
    int pos_y_marco_min = porcion_marco[0];
    int pos_y_marco_max = porcion_marco[2];

    float pos_x_tex_min = porcion_textura[1];
    float pos_x_tex_max = porcion_textura[3];
    float pos_y_tex_min = porcion_textura[0];
    float pos_y_tex_max = porcion_textura[2];

    float x_textura = pos_x_tex_min;
    float y_textura = pos_y_tex_min;
    float salto_y = (pos_y_tex_max - pos_y_tex_min) / (pos_y_marco_max - pos_y_marco_min);
    float salto_x = (pos_x_tex_max - pos_x_tex_min) / (pos_x_marco_max - pos_x_marco_min);

    int v1,v2,v3;

    int index=0;

    material.enable();
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_FLAT);


    glEnable(GL_TEXTURE_2D);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);


    for(int i=pos_y_marco_min; i < pos_y_marco_max; i++){
        x_textura = pos_x_tex_min;
        for(int j=pos_x_marco_min; j < pos_x_marco_max; j++){

            v1 = i * (n+1) +j;
            v2 = v1+1;
            v3 = v1 +(n+1);

            glNormal3fv((GLfloat*) &normalCaras[index]);
            glTexCoord2f(x_textura,y_textura);
            glVertex3f(vertices[v1].x,vertices[v1].y,vertices[v1].z);

            glTexCoord2f(x_textura + salto_x,y_textura);
            glVertex3f(vertices[v2].x,vertices[v2].y,vertices[v2].z);

            glTexCoord2f(x_textura,y_textura + salto_y);
            glVertex3f(vertices[v3].x,vertices[v3].y,vertices[v3].z);

            v1 = v2;
            v2 = v1 +(n+1);
            v3 = v2-1;

            glNormal3fv((GLfloat*) &normalCaras[index+1]);
            glTexCoord2f(x_textura + salto_x,y_textura);
            glVertex3f(vertices[v1].x,vertices[v1].y,vertices[v1].z);

            glTexCoord2f(x_textura + salto_x,y_textura + salto_y);
            glVertex3f(vertices[v2].x,vertices[v2].y,vertices[v2].z);

            glTexCoord2f(x_textura,y_textura + salto_y);
            glVertex3f(vertices[v3].x,vertices[v3].y,vertices[v3].z);

            x_textura =  pos_x_tex_min + salto_x*(j - pos_x_marco_min +1);
            index+=2;
        }

        y_textura = pos_y_tex_min + salto_y*(i - pos_y_marco_min + 1);

    }



    glEnd();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);

}

void marco::drawFillIluminadoSuave(vector<float> porcion_textura, vector<int> porcion_marco,Material material , bool iluminacion)
{
    if(normalVertices.empty())
        calcularNormalesVertices();

    if(iluminacion)
        glEnable(GL_LIGHTING);

    int pos_x_marco_min = porcion_marco[1];
    int pos_x_marco_max = porcion_marco[3];
    int pos_y_marco_min = porcion_marco[0];
    int pos_y_marco_max = porcion_marco[2];

    float pos_x_tex_min = porcion_textura[1];
    float pos_x_tex_max = porcion_textura[3];
    float pos_y_tex_min = porcion_textura[0];
    float pos_y_tex_max = porcion_textura[2];

    float x_textura = pos_x_tex_min;
    float y_textura = pos_y_tex_min;
    float salto_y = (pos_y_tex_max - pos_y_tex_min) / (pos_y_marco_max - pos_y_marco_min);
    float salto_x = (pos_x_tex_max - pos_x_tex_min) / (pos_x_marco_max - pos_x_marco_min);

    int v1,v2,v3;

    int index=0;

    material.enable();
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_SMOOTH);


    glEnable(GL_TEXTURE_2D);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);


    for(int i=pos_y_marco_min; i < pos_y_marco_max; i++){
        x_textura = pos_x_tex_min;
        for(int j=pos_x_marco_min; j < pos_x_marco_max; j++){

            v1 = i * (n+1) +j;
            v2 = v1+1;
            v3 = v1 +(n+1);

            glNormal3fv((GLfloat*) &normalVertices[triangles[index]._0]);
            glTexCoord2f(x_textura,y_textura);
            glVertex3f(vertices[v1].x,vertices[v1].y,vertices[v1].z);

            glNormal3fv((GLfloat*) &normalVertices[triangles[index]._1]);
            glTexCoord2f(x_textura + salto_x,y_textura);
            glVertex3f(vertices[v2].x,vertices[v2].y,vertices[v2].z);

            glNormal3fv((GLfloat*) &normalVertices[triangles[index]._2]);
            glTexCoord2f(x_textura,y_textura + salto_y);
            glVertex3f(vertices[v3].x,vertices[v3].y,vertices[v3].z);

            v1 = v2;
            v2 = v1 +(n+1);
            v3 = v2-1;

            glNormal3fv((GLfloat*) &normalVertices[triangles[index+1]._0]);
            glTexCoord2f(x_textura + salto_x,y_textura);
            glVertex3f(vertices[v1].x,vertices[v1].y,vertices[v1].z);

            glNormal3fv((GLfloat*) &normalVertices[triangles[index+1]._1]);
            glTexCoord2f(x_textura + salto_x,y_textura + salto_y);
            glVertex3f(vertices[v2].x,vertices[v2].y,vertices[v2].z);

            glNormal3fv((GLfloat*) &normalVertices[triangles[index+1]._2]);
            glTexCoord2f(x_textura,y_textura + salto_y);
            glVertex3f(vertices[v3].x,vertices[v3].y,vertices[v3].z);

            x_textura =  pos_x_tex_min + salto_x*(j - pos_x_marco_min +1);
            index+=2;
        }

        y_textura = pos_y_tex_min + salto_y*(i - pos_y_marco_min + 1);

    }



    glEnd();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
}


