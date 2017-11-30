#include "marco.h"

marco::marco()
{

}

marco::marco(int n)
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
    float x_min=-(tama*0.5);
  //  float x_max=(tama*0.5);
    float y_min=-(tama*0.5);
  //  float y_max=(tama*0.5);

    float x,y;

    float salto = tama/n;

    for(int i=0;i<=n;i++){
        y= y_min + (i*salto);
        for(int j=0;j<=n;j++){
            x = x_min + (j*salto);
            vertices.push_back(_vertex3f(x,y,0.0));
        }
    }


    for(int i=0;i<=n-1;i++){

        for(int j=0;j<n;j++){

            triangles.push_back(_vertex3i( ((j*(n+1))+(i+1))%vertices.size() ,((j*(n+1))+i)%vertices.size() , (((j+1)*(n+1))+i )%vertices.size()) );
            //Triangulo Impar
            triangles.push_back(_vertex3i( (((j+1)*(n+1))+i)%vertices.size() ,(((j+1)*(n+1))+(i+1))%vertices.size() , ((j*(n+1))+(i+1))%vertices.size() ) );
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
    float salto = distancia / numero_quads;

    vector<vector<float>> puntos_textura;
    vector<int> puntos;

    for(int i=0; i<=numero_quads;i++){
        for(int j=0; j<=numero_quads;j++){
            float x = fila_imagen_inicial + (i*salto);
            float y = columna_imagen_inicial + (j*salto);
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
    cout << "RECIEN ENTRADO\n";

    for(int i=0;i<vertices.size();i++)
        cout << vertices[i].x << " " << vertices[i].y << endl;

    for(int i=0; i<numero_quads;i++){
        for(int j=0; j<numero_quads;j++){
              // vector<float> aux_tex = puntos_textura[i*(numero_quads)+j];
            vector<float> aux_tex = puntos_textura[((numero_quads+1)*i)+j];
               //int aux_marco = puntos[i*(numero_quads+1)+j];
               int aux_marco = puntos[((numero_quads+1)*i)+j];
               glTexCoord2f(aux_tex[0],aux_tex[1]);
               glVertex3f(vertices[aux_marco].x,vertices[aux_marco].y,0);

               cout << "tex coor 1  "<< i<< " " << j << " : " << aux_tex[0] << " , " << aux_tex[1] << endl;
               cout << "vertex coor 1  "<< i<< " " << j << " : " <<"aux_marco=" <<aux_marco <<" "<< vertices[aux_marco].x << " , " << vertices[aux_marco].y << endl;


              // aux_tex = puntos_textura[((j+1)*(numero_quads+1))+i];
              // aux_marco = puntos[((j+1)*(numero_quads+1))+i];
               aux_tex = puntos_textura[(numero_quads+1)+j+((numero_quads+1)*i)];
               aux_marco = puntos[(numero_quads+1)+j+((numero_quads+1)*i)];
               glTexCoord2f(aux_tex[0],aux_tex[1]);
               glVertex3f(vertices[aux_marco].x,vertices[aux_marco].y,0);

               cout << "tex coor 2  "<< i<< " " << j << " : " << aux_tex[0] << " , " << aux_tex[1] << endl;
               cout << "vertex coor 2  "<< i<< " " << j << " : "<<"aux_marco=" <<aux_marco <<" " << vertices[aux_marco].x << " , " << vertices[aux_marco].y << endl;

               //aux_tex = puntos_textura[(i+1)+(j*(numero_quads+1))];
               aux_tex = puntos_textura[1+j+((numero_quads+1)*i)];
               //aux_marco = puntos[numero_quads + (2*i) +j];
                aux_marco = puntos[1+j+((numero_quads+1)*i)];

               glTexCoord2f(aux_tex[0],aux_tex[1]);
               glVertex3f(vertices[aux_marco].x,vertices[aux_marco].y,0);

               cout << "tex coor 3  "<< i<< " " << j << " : " << aux_tex[0] << " , " << aux_tex[1] << endl;
                cout << "vertex coor 3  "<< i<< " " << j << " : " <<"aux_marco=" <<aux_marco <<" "<< vertices[aux_marco].x << " , " << vertices[aux_marco].y << endl;


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
}
