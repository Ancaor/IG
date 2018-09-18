#include "escena.h"

Escena::Escena()
{
    ply1.ReadPLY("beethoven.ply");
    ply2.ReadPLY("beethoven.ply");
    ply3.ReadPLY("beethoven.ply");
    ply4.ReadPLY("beethoven.ply");
    ply5.ReadPLY("beethoven.ply");
    ply6.ReadPLY("beethoven.ply");
    ply7.ReadPLY("beethoven.ply");
    ply8.ReadPLY("beethoven.ply");
    ply9.ReadPLY("beethoven.ply");
    ply10.ReadPLY("beethoven.ply");
    ply11.ReadPLY("beethoven.ply");
    ply12.ReadPLY("beethoven.ply");
    ply13.ReadPLY("beethoven.ply");
    ply14.ReadPLY("beethoven.ply");
    ply15.ReadPLY("beethoven.ply");
    ply16.ReadPLY("beethoven.ply");
}

void Escena::draw(int modo)
{

        //PLY (beethoven)
        glPushMatrix();
            glLoadName(1);
            glTranslatef(-4.5, 6, 0);
            glScalef(0.2,0.2,0.2);
            switch(modo){
                case 0: ply1.draw_Points(); break;
                case 1: ply1.draw_Lines(); break;
                case 2: ply1.draw_Triangles(); break;
                case 3: ply1.draw_Chess(); break;
            }
        glPopMatrix();

        //PLY (beethoven)
        glPushMatrix();
            glLoadName(2);
            glTranslatef(-1.5, 6, 0);
            glScalef(0.2,0.2,0.2);
            switch(modo){
                case 0: ply2.draw_Points(); break;
                case 1: ply2.draw_Lines(); break;
                case 2: ply2.draw_Triangles(); break;
                case 3: ply2.draw_Chess(); break;
            }
        glPopMatrix();

        //PLY (beethoven)
        glPushMatrix();
            glLoadName(3);
            glTranslatef(1.5, 6, 0);
            glScalef(0.2,0.2,0.2);
            switch(modo){
                case 0: ply3.draw_Points(); break;
                case 1: ply3.draw_Lines(); break;
                case 2: ply3.draw_Triangles(); break;
                case 3: ply3.draw_Chess(); break;
            }
        glPopMatrix();

        glPushMatrix();
            glLoadName(4);
            glTranslatef(4.5, 6, 0);
            glScalef(0.2,0.2,0.2);
            switch(modo){
                case 0: ply4.draw_Points(); break;
                case 1: ply4.draw_Lines(); break;
                case 2: ply4.draw_Triangles(); break;
                case 3: ply4.draw_Chess(); break;
            }
        glPopMatrix();

        glPushMatrix();
            glLoadName(5);
            glTranslatef(-4.5, 2, 0);
            glScalef(0.2,0.2,0.2);
            switch(modo){
                case 0: ply5.draw_Points(); break;
                case 1: ply5.draw_Lines(); break;
                case 2: ply5.draw_Triangles(); break;
                case 3: ply5.draw_Chess(); break;
            }
        glPopMatrix();

        glPushMatrix();
            glLoadName(6);
            glTranslatef(-1.5, 2, 0);
            glScalef(0.2,0.2,0.2);
            switch(modo){
                case 0: ply6.draw_Points(); break;
                case 1: ply6.draw_Lines(); break;
                case 2: ply6.draw_Triangles(); break;
                case 3: ply6.draw_Chess(); break;
            }
        glPopMatrix();

        glPushMatrix();
            glLoadName(7);
            glTranslatef(1.5, 2, 0);
            glScalef(0.2,0.2,0.2);
            switch(modo){
                case 0: ply7.draw_Points(); break;
                case 1: ply7.draw_Lines(); break;
                case 2: ply7.draw_Triangles(); break;
                case 3: ply7.draw_Chess(); break;
            }
        glPopMatrix();

        glPushMatrix();
            glLoadName(8);
            glTranslatef(4.5, 2, 0);
            glScalef(0.2,0.2,0.2);
            switch(modo){
                case 0: ply8.draw_Points(); break;
                case 1: ply8.draw_Lines(); break;
                case 2: ply8.draw_Triangles(); break;
                case 3: ply8.draw_Chess(); break;
            }
        glPopMatrix();

        glPushMatrix();
            glLoadName(9);
            glTranslatef(-4.5, -2, 0);
            glScalef(0.2,0.2,0.2);
            switch(modo){
                case 0: ply9.draw_Points(); break;
                case 1: ply9.draw_Lines(); break;
                case 2: ply9.draw_Triangles(); break;
                case 3: ply9.draw_Chess(); break;
            }
        glPopMatrix();

        glPushMatrix();
            glLoadName(10);
            glTranslatef(-1.5, -2, 0);
            glScalef(0.2,0.2,0.2);
            switch(modo){
                case 0: ply10.draw_Points(); break;
                case 1: ply10.draw_Lines(); break;
                case 2: ply10.draw_Triangles(); break;
                case 3: ply10.draw_Chess(); break;
            }
        glPopMatrix();

        glPushMatrix();
            glLoadName(11);
            glTranslatef(1.5, -2, 0);
            glScalef(0.2,0.2,0.2);
            switch(modo){
                case 0: ply11.draw_Points(); break;
                case 1: ply11.draw_Lines(); break;
                case 2: ply11.draw_Triangles(); break;
                case 3: ply11.draw_Chess(); break;
            }
        glPopMatrix();

        glPushMatrix();
            glLoadName(12);
            glTranslatef(4.5, -2, 0);
            glScalef(0.2,0.2,0.2);
            switch(modo){
                case 0: ply12.draw_Points(); break;
                case 1: ply12.draw_Lines(); break;
                case 2: ply12.draw_Triangles(); break;
                case 3: ply12.draw_Chess(); break;
            }
        glPopMatrix();

        glPushMatrix();
            glLoadName(13);
            glTranslatef(-4.5, -6, 0);
            glScalef(0.2,0.2,0.2);
            switch(modo){
                case 0: ply13.draw_Points(); break;
                case 1: ply13.draw_Lines(); break;
                case 2: ply13.draw_Triangles(); break;
                case 3: ply13.draw_Chess(); break;
            }
        glPopMatrix();

        glPushMatrix();
            glLoadName(14);
            glTranslatef(-1.5, -6, 0);
            glScalef(0.2,0.2,0.2);
            switch(modo){
                case 0: ply14.draw_Points(); break;
                case 1: ply14.draw_Lines(); break;
                case 2: ply14.draw_Triangles(); break;
                case 3: ply14.draw_Chess(); break;
            }
        glPopMatrix();

        glPushMatrix();
            glLoadName(15);
            glTranslatef(1.5, -6, 0);
            glScalef(0.2,0.2,0.2);
            switch(modo){
                case 0: ply15.draw_Points(); break;
                case 1: ply15.draw_Lines(); break;
                case 2: ply15.draw_Triangles(); break;
                case 3: ply15.draw_Chess(); break;
            }
        glPopMatrix();

        glPushMatrix();
            glLoadName(16);
            glTranslatef(4.5, -6, 0);
            glScalef(0.2,0.2,0.2);
            switch(modo){
                case 0: ply16.draw_Points(); break;
                case 1: ply16.draw_Lines(); break;
                case 2: ply16.draw_Triangles(); break;
                case 3: ply16.draw_Chess(); break;
            }
        glPopMatrix();
}

void Escena::setColor(_vertex4f color, int figura)
{
    switch(figura){
        case 1: ply1.setColor(color.x, color.y, color.z, color.w); break;
        case 2: ply2.setColor(color.x, color.y, color.z, color.w); break;
        case 3: ply3.setColor(color.x, color.y, color.z, color.w); break;
        case 4: ply4.setColor(color.x, color.y, color.z, color.w); break;
        case 5: ply5.setColor(color.x, color.y, color.z, color.w); break;
        case 6: ply6.setColor(color.x, color.y, color.z, color.w); break;
    case 7: ply7.setColor(color.x, color.y, color.z, color.w); break;
    case 8: ply8.setColor(color.x, color.y, color.z, color.w); break;
    case 9: ply9.setColor(color.x, color.y, color.z, color.w); break;
    case 10: ply10.setColor(color.x, color.y, color.z, color.w); break;
    case 11: ply11.setColor(color.x, color.y, color.z, color.w); break;
    case 12: ply12.setColor(color.x, color.y, color.z, color.w); break;
    case 13: ply13.setColor(color.x, color.y, color.z, color.w); break;
    case 14: ply14.setColor(color.x, color.y, color.z, color.w); break;
    case 15: ply15.setColor(color.x, color.y, color.z, color.w); break;
    case 16: ply16.setColor(color.x, color.y, color.z, color.w); break;
    }
}

void Escena::setColor(_vertex4f color)
{
    ply1.setColor(color.x, color.y, color.z, color.w);
    ply2.setColor(color.x, color.y, color.z, color.w);
    ply3.setColor(color.x, color.y, color.z, color.w);
    ply4.setColor(color.x, color.y, color.z, color.w);
    ply5.setColor(color.x, color.y, color.z, color.w);
    ply6.setColor(color.x, color.y, color.z, color.w);
    ply7.setColor(color.x, color.y, color.z, color.w);
    ply8.setColor(color.x, color.y, color.z, color.w);
    ply9.setColor(color.x, color.y, color.z, color.w);
    ply10.setColor(color.x, color.y, color.z, color.w);
    ply11.setColor(color.x, color.y, color.z, color.w);
    ply12.setColor(color.x, color.y, color.z, color.w);
    ply13.setColor(color.x, color.y, color.z, color.w);
    ply14.setColor(color.x, color.y, color.z, color.w);
    ply15.setColor(color.x, color.y, color.z, color.w);
    ply16.setColor(color.x, color.y, color.z, color.w);
}
