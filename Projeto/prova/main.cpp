#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>
#include <time.h>
#include <stdio.h>

GLfloat movey = 0;
GLint moveponto = 0;
GLint movecacto = 70;
GLint direcao = 0;
int cont;
int pont = 0;

/*A função chao cría um quadrado para representar o chão */
void chao(){
    glPointSize(5);
    glColor3f(0.9,0.8,0.2);

    glBegin(GL_QUADS);
        glVertex2f(-40, -0);
        glVertex2f(40, 0);
        glVertex2f(40, -40);
        glVertex2f(-40, -40);

    glEnd();
}

/*A função poligono é responsavel pela criação do boneco "dinossauro"*/
void poligono(){
    glBegin(GL_POLYGON);
        glColor3f(0, 0.5, 1);
        glVertex2f(0.2, 0+moveponto); //A variavel "moveponto" adicionara a variavel glVertex2f o que a função "timerPonto" emitir
        glVertex2f(1.6, 0+moveponto);
        glVertex2f(1.6, 0.2+moveponto);
        glVertex2f(1.4, 0.2+moveponto);
        glVertex2f(1.4, 1.0+moveponto);
        glVertex2f(1.6, 1.0+moveponto);
        glVertex2f(1.6, 1.2+moveponto);
        glVertex2f(1.8, 1.2+moveponto);
        glVertex2f(2, 1.6+moveponto);
        glVertex2f(2.2, 1.6+moveponto);
        glVertex2f(2.2, 2.0+moveponto);
        glVertex2f(2.8, 2.4+moveponto);
        glVertex2f(2.8, 2.6+moveponto);
        glVertex2f(3.2, 2.8+moveponto);
        glVertex2f(3.2, 3.6+moveponto);
        glVertex2f(3.0, 3.6+moveponto);
        glVertex2f(3.0, 3.8+moveponto);
        glVertex2f(1.2, 3.8+moveponto);
        glVertex2f(1.2, 3.6+moveponto);
        glVertex2f(1, 3.6+moveponto);
        glVertex2f(1, 2.6+moveponto);
        glVertex2f(0.8, 2.6+moveponto);
        glVertex2f(0.8, 2.4+moveponto);
        glVertex2f(0.4, 2.4+moveponto);
        glVertex2f(0.4, 2.2+moveponto);
        glVertex2f(0, 2.2+moveponto);
        glVertex2f(0, 2+moveponto);
        glVertex2f(-0.2, 2+moveponto);
        glVertex2f(-0.2, 1.8+moveponto);
        glVertex2f(-0.6, 1.8+moveponto);
        glVertex2f(-0.6, 2+moveponto);
        glVertex2f(-0.8, 2+moveponto);
        glVertex2f(-0.8, 2.2+moveponto);
        glVertex2f(-1, 2.2+moveponto);
        glVertex2f(-1, 2.6+moveponto);
        glVertex2f(-1.2, 2.6+moveponto);
        glVertex2f(-1.2, 1.6+moveponto);
    glEnd();
}

/*A função cacto é responsavel pela criação do inimigo "cacto" */
void cacto(){
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
        glVertex2f(6.5+movecacto, 0); //A variavel "movecacto" adicionara a variavel glVertex2f o que a função "timercacto" emitir
        glVertex2f(6.5+movecacto, 1.5);
        glVertex2f(5.5+movecacto, 1.5);
        glVertex2f(5.5+movecacto, 2.5);
        glVertex2f(6+movecacto, 2.5);
        glVertex2f(6+movecacto, 2);
        glVertex2f(6.5+movecacto, 2);
        glVertex2f(6.5+movecacto, 3);
        glVertex2f(7+movecacto, 3);
        glVertex2f(7+movecacto, 1.5);
        glVertex2f(7.5+movecacto, 1.5);
        glVertex2f(7.5+movecacto, 2);
        glVertex2f(8+movecacto, 2);
        glVertex2f(8+movecacto, 1);
        glVertex2f(7+movecacto, 1);
        glVertex2f(7+movecacto, 0);
    glEnd();
}

/*A função toquedino é responsavel pela criação de um quadrado branco, que seus pontos deliminta a hitbox do pressonagem "dino" */
void toquedino(){
    glBegin(GL_QUADS);
        glColor3f(1, 1, 1);
        glVertex2f(-1.2, 3.8+moveponto); //A variavel "moveponto" adicionara a variavel glVertex2f o que a função "timerPonto" emitir
        glVertex2f(-1.2, 0+moveponto);
        glVertex2f(3.2, 0+moveponto);
        glVertex2f(3.2, 3.8+moveponto);
    glEnd();
}

/*A função toquedino é responsavel pela criação de um quadrado branco, que seus pontos deliminta a hitbox do inimigo "cacto" */
void toquecacto(){
    glBegin(GL_QUADS);
        glColor3f(1, 1, 1);
        glVertex2f(5.5+movecacto, 3); //A variavel "moveponto" adicionara a variavel glVertex2f o que a função "timerPonto" emitir
        glVertex2f(5.5+movecacto, 0);
        glVertex2f(8+movecacto, 0);
        glVertex2f(8+movecacto, 3);
    glEnd();
}

/*A função "timerPonto" é responsavel pela animação de pulo para isso o timer decrementa o "moveponto" para representar a animação de pulo*/
void timerPonto(int passo){
    while(moveponto != 0){
            moveponto-=1;
        }
        moveponto = 0;
    glutPostRedisplay();
    if(cont == 0){
        glutTimerFunc(100,timerPonto,10);
        cont = 1;
    }
}

/*A função "timercacto" é responsavel pela animação que da a impreção de movimanto do mapa, para que o cacto se mova o "timercacto"
  decrementa o "movecacto" para representar a animação de movimento*/
void timercacto(int passo){
    if (direcao == 0){
                movecacto--;
                if(movecacto == -5){
                    pont++;
                    printf("sua pontuacao he:  %d\n",pont);

                }
                if (movecacto <= -80) {
                    direcao = 1;
                }
            }
            if (direcao == 1){
                movecacto = 90;
                direcao = 0;
                system("cls");
            }
    glutPostRedisplay();
    glutTimerFunc(10,timercacto,1);
}

/*A função timerColisao é responsavel pela identificação da colizao entre os objetos no mapa para isso ele indentifica quando algum dos pontos
  de um encosta na do outro*/
void timerColisao(int valor) {
    if (valor == 1){
        int topo_dino = 3.8+moveponto;
        int base_dino = 0+moveponto;
        int l_dino = -1.2;
        int r_dino = 3.2;


        int topo_cact = 3;
        int base_cact = 0;
        int l_cact = 5.5+movecacto;
        int r_cact = 8+movecacto;

        if (l_cact < r_dino &&
            r_cact > l_dino &&
            base_cact < topo_dino &&
            topo_cact > base_dino) {
            printf("Voce perdeu ^0^ \n sua pontuacao foi de: %d", pont);
            exit(1);
        }


        glutTimerFunc(25, timerColisao, 1);
    }
}

void gerenciaMouse(int botao, int estado, int x, int y){
    if (botao == GLUT_LEFT_BUTTON){
            if(estado == GLUT_DOWN){
                cont = 0;
                moveponto = 15;
                glutTimerFunc(150,timerPonto,10);
            }else if(estado == GLUT_UP){

            }
    }
    glutPostRedisplay();
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-40,40,-40,40);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

     glPushMatrix();
        toquedino();
        toquecacto();
    glPopMatrix();

    glPushMatrix();
        poligono();
        cacto();
        chao();
    glPopMatrix();

	glFlush();

}

int main(void){

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,400);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,(glutGet(GLUT_SCREEN_HEIGHT)-540)/2);
    glutCreateWindow("Dino glit");
    glutDisplayFunc(desenhaObjetos);
    glutMouseFunc(gerenciaMouse);
    glutTimerFunc(10,timercacto,1);
    glutTimerFunc(25, timerColisao, 1);
    glClearColor(1,1,1,0);
    glutMainLoop();
    system("pause");
    return 1;
}
