#pragma comment (lib, "glew32s.lib")
#define GLEW_STATIC
#include<gl/glew.h>
//#include"shader.h"
#include<GL/freeglut.h>

#include<glm/glm.hpp>
#include<glm/ext.hpp>

// Camera Position
float camX, camY, camZ;

//shader shader_main;


void display1()
{
	
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glFlush();
	glutSwapBuffers();
	
}

void processKeys(unsigned char key, int xx, int yy)
{
	switch (key) {

	case 27:
		glutLeaveMainLoop();
		break;

	case 'c':
		printf("Camera Spherical Coordinates (%f, %f, %f)\n", alpha, beta, r);
		break;

	}

	//  uncomment this if not using an idle func
	glutPostRedisplay();
}

void init() {

	

	// some GL settings
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
	glEnable(GL_MULTISAMPLE);
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	//Not neccessary to be written inside init(),usually written in main()

}


int main(int argc, char** argv)
{


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
	glutInitWindowSize(640, 480);
	glutCreateWindow("simple rectangle");


	glewExperimental = true; // Needed in core profile


	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}
	
	
	init();
	// glEnable(GL_DEPTH_TEST);
	

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutDisplayFunc(display1);

	glutMainLoop();

}