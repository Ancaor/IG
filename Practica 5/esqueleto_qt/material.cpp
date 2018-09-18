#include "material.h"

Material::Material()
{

}

//**************************************************************************
// Constructor que asigna las componentes del material
//***************************************************************************

Material::Material(GLfloat *mat)
{
    material_ambiente[0] = mat[0];
    material_ambiente[1] = mat[1];
    material_ambiente[2] = mat[2];
    material_ambiente[3] = mat[3];

    material_difuso[0] = mat[4];
    material_difuso[1] = mat[5];
    material_difuso[2] = mat[6];
    material_difuso[3] = mat[7];

    material_especular[0] = mat[8];
    material_especular[1] = mat[9];
    material_especular[2] = mat[10];
    material_especular[3] = mat[11];

    brillo = mat[12];
}

//**************************************************************************
// Activa el material
//***************************************************************************


void Material::enable_material()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambiente);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_difuso);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_especular);
    glMaterialf(GL_FRONT, GL_SHININESS, brillo * 128);
}



