#include "marco.h"

marco::marco()
{

}

marco::marco(int n , float ancho , float alto)
{
    /*
    float x=0;
    float y=0;


    vertices.push_back(_vertex3f(x,y,0.0));


 for(float i=1.0;i<=n;i++){
     y=i/n;
     for(int j=1.0;j<=n;j++){
        x=j/n;
        vertices.push_back(_vertex3f(x,y,0.0));
     }

 }

// cout << n<<endl;
*/
    this->n = n;
    float tama = 1.0;
    float x_min=-(ancho*0.5);
  //  float x_max=(tama*0.5);
    float y_min=-(alto*0.5);
  //  float y_max=(tama*0.5);

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

void marco::drawTextura(vector<float> porcion_textura, vector<int> porcion_marco)
{

    for(int i=0;i<porcion_textura.size();i++)
        cout << i << "  " << porcion_textura[i] << endl;


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


    /*

    int saltos_marco_x = porcion_marco[3] - porcion_marco[1];
    int saltos_marco_y = porcion_marco[2] - porcion_marco[0];

    int posicion_inicial_marco = (porcion_marco[0]*(n))+porcion_marco[1];

    float distancia_x_textura = porcion_textura[3] - porcion_textura[1];
    float distancia_y_textura = porcion_textura[2] - porcion_textura[0];

    float salto_x_textura = distancia_x_textura / saltos_marco_x;
    float salto_y_textura = distancia_y_textura / saltos_marco_y;

    cout << salto_x_textura<<endl;
    cout << salto_y_textura << endl;
*/
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


/*
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0,0);
    glVertex3f(vertices[0].x,vertices[0].y,0);
    glTexCoord2f(0.5,0);
    glVertex3f(vertices[n].x,vertices[n].y,0);

    glTexCoord2f(0,0.5);
    glVertex3f(vertices[vertices.size()-1-n].x,vertices[vertices.size()-1-n].y,0);

    glTexCoord2f(0,0.5);
    glVertex3f(vertices[vertices.size()-1-n].x,vertices[vertices.size()-1-n].y,0);
    glTexCoord2f(0.5,0);
    glVertex3f(vertices[n].x,vertices[n].y,0);
    glTexCoord2f(0.5,0.5);
    glVertex3f(vertices[vertices.size()-1].x,vertices[vertices.size()-1].y,0);
    glEnd();

    */

    /*


    float fila_imagen_inicial = porcion_textura[0];
    float columna_imagen_inicial = porcion_textura[1];
    float fila_imagen_final = porcion_textura[2];
    float columna_imagen_final = porcion_textura[3];

    float fila_marco_inicial = porcion_marco[0];
    float columna_marco_inicial = porcion_marco[1];
    float fila_marco_final = porcion_marco[2];
    float columna_marco_final = porcion_marco[3];

    int numero_quads = fila_marco_final - fila_marco_inicial;
    float distancia = fila_imagen_final-fila_imagen_inicial;
    float distancia_columna = columna_imagen_final - columna_imagen_inicial;
    float salto_columna = distancia_columna / numero_quads;
    float salto = distancia / numero_quads;

    vector<vector<float>> puntos_textura;
    vector<int> puntos;

    for(int i=0; i<=numero_quads;i++){
        for(int j=0; j<=numero_quads;j++){
            float y = fila_imagen_inicial + (j*salto);
            float x = columna_imagen_inicial + (i*salto_columna);
            vector<float> aux = {x,y};
            puntos_textura.push_back(aux);

            int punto = (fila_marco_inicial + i)+((columna_marco_inicial+j)*(n+1));
            //int col_marco = columna_marco_inicial + j;
            puntos.push_back(punto);
           // puntos_marco.push_back(punto);

        }
    }
    glEnable(GL_TEXTURE_2D);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
   // cout << "RECIEN ENTRADO\n";

    //for(int i=0;i<vertices.size();i++)
  //      cout << vertices[i].x << " " << vertices[i].y << endl;

    for(int i=0; i<numero_quads;i++){
        for(int j=0; j<numero_quads;j++){
              // vector<float> aux_tex = puntos_textura[i*(numero_quads)+j];
            vector<float> aux_tex = puntos_textura[((numero_quads+1)*i)+j];
               //int aux_marco = puntos[i*(numero_quads+1)+j];
               int aux_marco = puntos[((numero_quads+1)*i)+j];
               glTexCoord2f(aux_tex[0],aux_tex[1]);
               glVertex3f(vertices[aux_marco].x,vertices[aux_marco].y,0);

  //             cout << "tex coor 1  "<< i<< " " << j << " : " << aux_tex[0] << " , " << aux_tex[1] << endl;
  //             cout << "vertex coor 1  "<< i<< " " << j << " : " <<"aux_marco=" <<aux_marco <<" "<< vertices[aux_marco].x << " , " << vertices[aux_marco].y << endl;


              // aux_tex = puntos_textura[((j+1)*(numero_quads+1))+i];
              // aux_marco = puntos[((j+1)*(numero_quads+1))+i];
               aux_tex = puntos_textura[(numero_quads+1)+j+((numero_quads+1)*i)];
               aux_marco = puntos[(numero_quads+1)+j+((numero_quads+1)*i)];
               glTexCoord2f(aux_tex[0],aux_tex[1]);
               glVertex3f(vertices[aux_marco].x,vertices[aux_marco].y,0);

  //             cout << "tex coor 2  "<< i<< " " << j << " : " << aux_tex[0] << " , " << aux_tex[1] << endl;
  //             cout << "vertex coor 2  "<< i<< " " << j << " : "<<"aux_marco=" <<aux_marco <<" " << vertices[aux_marco].x << " , " << vertices[aux_marco].y << endl;

               //aux_tex = puntos_textura[(i+1)+(j*(numero_quads+1))];
               aux_tex = puntos_textura[1+j+((numero_quads+1)*i)];
               //aux_marco = puntos[numero_quads + (2*i) +j];
                aux_marco = puntos[1+j+((numero_quads+1)*i)];

               glTexCoord2f(aux_tex[0],aux_tex[1]);
               glVertex3f(vertices[aux_marco].x,vertices[aux_marco].y,0);

  //             cout << "tex coor 3  "<< i<< " " << j << " : " << aux_tex[0] << " , " << aux_tex[1] << endl;
  //              cout << "vertex coor 3  "<< i<< " " << j << " : " <<"aux_marco=" <<aux_marco <<" "<< vertices[aux_marco].x << " , " << vertices[aux_marco].y << endl;


                // IMPARES

                //aux_tex = puntos_textura[(i+1)+(j*(numero_quads+1))];
                aux_tex = puntos_textura[1+j+((numero_quads+1)*i)];
                //aux_marco = puntos[numero_quads + (2*i) +j];
                 aux_marco = puntos[1+j+((numero_quads+1)*i)];

                glTexCoord2f(aux_tex[0],aux_tex[1]);
                glVertex3f(vertices[aux_marco].x,vertices[aux_marco].y,0);


                aux_tex = puntos_textura[(numero_quads+1)+j+((numero_quads+1)*i)];
                aux_marco = puntos[(numero_quads+1)+j+((numero_quads+1)*i)];
                glTexCoord2f(aux_tex[0],aux_tex[1]);
                glVertex3f(vertices[aux_marco].x,vertices[aux_marco].y,0);

                aux_tex = puntos_textura[1+(numero_quads+1)+((numero_quads+1)*i)+j];
                aux_marco = puntos[1+(numero_quads+1)+((numero_quads+1)*i)+j];
                glTexCoord2f(aux_tex[0],aux_tex[1]);
                glVertex3f(vertices[aux_marco].x,vertices[aux_marco].y,0);

        }

    }
    glEnd();
    glDisable(GL_TEXTURE_2D);


    */
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


