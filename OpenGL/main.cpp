#include<stdio.h>
#include<SDL.h>
#include"SDL_opengl.h"


int main(int argc, char* args[]){

    SDL_Init(SDL_INIT_EVERYTHING);
    //memória
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,-1);


    //Nome da Janela
    SDL_WM_SetCaption("DIE RPG", NULL);

    //Tamanho da janela x e y, bits por pixel, modo da janela tipo fullscreen
    SDL_SetVideoMode(600,400, 32, SDL_OPENGL);

    //cor
    glClearColor(1, 1, 1, 1);





    //area exibida
    glViewport(0, 0, 600, 400);

    //sombreamento da janela
    glShadeModel(GL_SMOOTH);

    //2D
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); //desenho geométrico

    //3d
    glDisable(GL_DEPTH_TEST);//

    //logica
    bool executando = true;
    SDL_Event eventos;

    //loop
    while(executando){
        //eventos
        while(SDL_PollEvent(&eventos)){
            //FECHA COM O X DA JANELA
            if(eventos.type == SDL_QUIT){
                executando = false;
            }
            if(eventos.type == SDL_KEYUP && eventos.key.keysym.sym == SDLK_ESCAPE){
                executando = false;
            }


        }


    }



    //renderização
    glClear(GL_COLOR_BUFFER_BIT);//LIMPA O BUFFER


    //inicia matriz de desenho
    glPushMatrix();

    glOrtho(0,600, 400, 0, -1, 1);//tamanho da matriz

    //cor
    //glColor3d(1 ou 0)
    //glColor3f(decimais)
    //glColor3ub(R, G, B) -0 ate 255
    //glColor4ub(R, G, B, A) 0 ate 255

    glColor4ub(255, 0, 0, 255); //vermelho
    //iniciar função do desenho
    glBegin(GL_LINES);//GL_POINTS, GL_LINES, GL_LINES_LOOP, GL_QUADS, GL_TRIANGLE, GL_POLIGON

    glVertex2f(50, 50);//primeiro ponto
    glVertex2f(550, 350);//segundo ponto
    glVertex2f(550, 50);
    glVertex2f(50, 350);
    glVertex2f(50, 350);
    glVertex2f(50, 50);
    glVertex2f(50, 50);
    glVertex2f(550, 50 );
    glVertex2f(550, 50);
    glVertex2f(550, 350);
    glVertex2f(550, 350);
    glVertex2f(50, 350);
    glEnd();


    //fecha a matriz
    glPopMatrix();


    //animação
    SDL_GL_SwapBuffers();




    SDL_Quit();

return 0;
}
