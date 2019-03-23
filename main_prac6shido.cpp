//Semestre 2019 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Barbara Marmolejo Fernandez										******//
//************* 	no lo termine :(					******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int luna = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
int neptuno = 0;
float camaraZ = 0.0;
float camaraX = 0.0;
float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glRotatef(angleY, 0.0f, 1.0f, 0.0f);
	glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

	glPushMatrix(); //Sistema Solar

	glPushMatrix(); //Encapsulando al sol
	glRotatef(sol / 4, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0f, 1.0f, 0.0f);	//Sol amarillo
	glutSolidSphere(5, 20, 20);  //Draw Sun (radio,H,V);
	glPopMatrix();
	//-------------------------------------------------------------------------------
	//Mercurio
	glPushMatrix(); 
	glRotatef(mercurio, 0.0, 1.0, 0.0); //gira conforme al sol
	glTranslatef(7.0, 0, 0);
	glColor3f(1.0f, 0.4f, 0.7f);
	glRotatef(mercurio, 0.0, 1.0, 0.0);
	glutSolidSphere(.5, 15, 15);
	glPopMatrix();
	//----------------------------------------------------------------------------------
	//Venus
	glPushMatrix(); 
	glRotatef(venus, 0.0, 1.0, 0.0);
	glTranslatef(14.0, 0, 0);
	glColor3f(0.5f, 0.4f, 0.5f);
	glRotatef(venus, 0.0, 1.0, 0.0);
	glutSolidSphere(1.0, 15, 15);
	glPopMatrix();
	//--------------------------------------------------------------------------------------------
	//Tierra
	glPushMatrix();
	glRotatef(tierra, 0.0, 1.0, 0.0);
	glTranslatef(21.0, 0, 0);
	glColor3f(0.1f, 0.5f, 0.9f);
	glRotatef(tierra, 0.0, 1.0, 0.0);
	glutSolidSphere(1.3, 15, 15);
	//Luna
	glPushMatrix(); 
	glRotatef(luna, 0.0, 1.0, 0.0);
	glTranslatef(2.50, 0, 0);
	glColor3f(0.7f, 0.7f, 0.7f);
	glRotatef(luna, 0.0, 1.0, 0.0);
	glutSolidSphere(.3, 15, 15);
	glPopMatrix();
	glPopMatrix();
	//---------------------------------------------------------------------------------------------
	//Marte
	glPushMatrix();
	glRotatef(marte, 0.0, 1.0, 0.0);
	glTranslatef(28.0, 0, 0);
	glColor3f(0.5f, 0.09f, 0.05f);
	glRotatef(marte, 0.0, 1.0, 0.0);
	glutSolidSphere(1.1, 15, 15);
	//luna
	glPushMatrix(); 
	glRotatef(luna, 0.0, 1.0, 0.0);
	glTranslatef(2.50, 0, 0);
	glColor3f(0.7f, 0.7f, 0.7f);
	glRotatef(luna, 0.0, 1.0, 0.0);
	glutSolidSphere(.5, 15, 15);
	glPopMatrix();
	glPopMatrix();
	//------------------------------------------------------------------------------------------
	//Jupiter
	glPushMatrix();
	glRotatef(jupiter, 0.0, 1.0, 0.0);
	glTranslatef(35.0, 0, 0);
	glColor3f(0.9f, 0.6f, 0.3f);
	glRotatef(jupiter, 0.0, 1.0, 0.0);
	glutSolidSphere(3.5, 15, 15);
	//luna
	glPushMatrix(); 
	glRotatef(luna, 0.0, 1.0, 0.0);
	glTranslatef(4.50, 0, 0);
	glColor3f(0.7f, 0.7f, 0.7f);
	glRotatef(luna, 0.0, 1.0, 0.0);
	glutSolidSphere(.3, 15, 15);
	glPopMatrix();
	glPopMatrix();
	
}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;
		mercurio = (mercurio - 10) % 360;
		venus = (venus - 8) % 360;
		tierra = (tierra - 6) % 360;
		luna = (luna + 20) % 360;
		marte = (marte - 5) % 360;
		jupiter = (jupiter - 4) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 200.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}
void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
		//glutFullScreen ( ); // Full Screen Mode
		//break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
		//glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
		//break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}
