/*
* GL05IdleFunc.cpp: Translation and Rotation
* Transform primitives from their model spaces to world space (Model Transform).
*/
#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>
# define PI 3.14159265358979323846

using namespace std;
//fish
GLfloat fishPosition =fishPosition;
GLfloat fishSpeed = 0.01;
GLfloat wavePosition = wavePosition;
GLfloat wavePosition2 = wavePosition2;
GLfloat waveSpeed = 0.01;
//man
int i;
float _move = -1.8f; // Starting horizontal position
bool moving = true; // Control movement
float radius9 =0.10f;
int triangleAmount = 100; //# of lines used to draw circle
GLfloat twicePi = 2.0f * PI;

GLfloat cloudSpeed = 0.01;
GLfloat cloudPosition = cloudPosition;
bool showFishAnimation = true;
bool fishIsHooked = true;
//bool ShowSceneAnimation= false;

//Last Scene
//int i;
float _movee = -1.8f; // Starting horizontal position
bool mooving = true;

/* Initialize OpenGL Graphics */
void initGL() {
 // Set "clearing" or background color
 glClearColor(0.0f, 0.5f, 1.0f, 0.0f); // Black and opaque
}

int currentScene = 1;  // 1 = Village, 2 = Fishing, 3 = Night Scene

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void DrawFish() {
 //glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
 //glMatrixMode(GL_MODELVIEW); // To operate on Model-View matrix
 //glLoadIdentity(); // Reset the model-view matrix
 glLineWidth(3.0f);
 glScalef(0.3f, 0.3f, 0.7f); // Scaling



 glPushMatrix(); // Save model-view matrix setting
//GLfloat angle = 0.0f; // Current rotational angle of the shapes
//GLfloat tx=0.0;
//GLfloat ty=0.0;
  glTranslatef(fishPosition, 0.0f,0.0f); // Translate
   // glRotatef(angle,0.0f,1.0f, 0.0f); // rotate by angle in degrees
     glBegin(GL_POLYGON);
        //fish body
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.5f, -0.3f);
        glVertex2f(0.2f, -0.3f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(-0.5f, 0.3f);
    glEnd();

     glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-01.0f, 0.2f);
        glVertex2f(-01.0f, -0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, 0.3f);
        glVertex2f(-0.45f, 0.6f);
        glVertex2f(0.02f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, -0.3f);
        glVertex2f(-0.45f, -0.6f);
        glVertex2f(0.02f, -0.3f);
    glEnd();

     // Eye
    glPointSize(7.0f);
    glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.3f, 0.1f);
    glEnd();

     glBegin(GL_LINES);
      glLineWidth(10.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.20f, -0.3f);
        glVertex2f(0.20f, 0.3f);
    glEnd();


    // Second Fish
     glTranslatef(2.0, 2.0,0.0f); // Translate
   // glRotatef(angle,0.0f,1.0f, 0.0f); // rotate by angle in degrees
     glBegin(GL_POLYGON);
        //fish body
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.5f, -0.3f);
        glVertex2f(0.2f, -0.3f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(-0.5f, 0.3f);
    glEnd();

     glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-01.0f, 0.2f);
        glVertex2f(-01.0f, -0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, 0.3f);
        glVertex2f(-0.45f, 0.6f);
        glVertex2f(0.02f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, -0.3f);
        glVertex2f(-0.45f, -0.6f);
        glVertex2f(0.02f, -0.3f);
    glEnd();

     // Eye
    glPointSize(7.0f);
    glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.3f, 0.1f);
    glEnd();

     glBegin(GL_LINES);
      glLineWidth(10.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.20f, -0.3f);
        glVertex2f(0.20f, 0.3f);
    glEnd();


// third fish

 glTranslatef(1.0,-3.0,0.0f); // Translate
   // glRotatef(angle,0.0f,1.0f, 0.0f); // rotate by angle in degrees
     glBegin(GL_POLYGON);
        //fish body
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.5f, -0.3f);
        glVertex2f(0.2f, -0.3f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(-0.5f, 0.3f);
    glEnd();

     glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-01.0f, 0.2f);
        glVertex2f(-01.0f, -0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, 0.3f);
        glVertex2f(-0.45f, 0.6f);
        glVertex2f(0.02f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, -0.3f);
        glVertex2f(-0.45f, -0.6f);
        glVertex2f(0.02f, -0.3f);
    glEnd();

     // Eye
    glPointSize(7.0f);
    glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.3f, 0.1f);
    glEnd();

     glBegin(GL_LINES);
      glLineWidth(10.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.20f, -0.3f);
        glVertex2f(0.20f, 0.3f);
    glEnd();



//4th fish
 glTranslatef(-6.0, 3.0,0.0f); // Translate
   // glRotatef(angle,0.0f,1.0f, 0.0f); // rotate by angle in degrees
     glBegin(GL_POLYGON);
        //fish body
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.5f, -0.3f);
        glVertex2f(0.2f, -0.3f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(-0.5f, 0.3f);
    glEnd();

     glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-01.0f, 0.2f);
        glVertex2f(-01.0f, -0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, 0.3f);
        glVertex2f(-0.45f, 0.6f);
        glVertex2f(0.02f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, -0.3f);
        glVertex2f(-0.45f, -0.6f);
        glVertex2f(0.02f, -0.3f);
    glEnd();

     // Eye
    glPointSize(7.0f);
    glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.3f, 0.1f);
    glEnd();

     glBegin(GL_LINES);
      glLineWidth(10.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.20f, -0.3f);
        glVertex2f(0.20f, 0.3f);
    glEnd();

    //5th fish
 glTranslatef(-2.0, -2.5,0.0f); // Translate
   // glRotatef(angle,0.0f,1.0f, 0.0f); // rotate by angle in degrees
     glBegin(GL_POLYGON);
        //fish body
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.5f, -0.3f);
        glVertex2f(0.2f, -0.3f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(-0.5f, 0.3f);
    glEnd();

     glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-01.0f, 0.2f);
        glVertex2f(-01.0f, -0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, 0.3f);
        glVertex2f(-0.45f, 0.6f);
        glVertex2f(0.02f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, -0.3f);
        glVertex2f(-0.45f, -0.6f);
        glVertex2f(0.02f, -0.3f);
    glEnd();

     // Eye
    glPointSize(7.0f);
    glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.3f, 0.1f);
    glEnd();

     glBegin(GL_LINES);
      glLineWidth(10.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.20f, -0.3f);
        glVertex2f(0.20f, 0.3f);
    glEnd();

    glPopMatrix();
       //glutSwapBuffers();
}

void updateFish(int value)
  {

    fishPosition += fishSpeed;
    if
    (fishPosition > 14.0f)
        fishPosition = -8.5f;

        //fishSpeed = -01.0;
    glutPostRedisplay();
    glutTimerFunc(3, updateFish, 0);
//    glTranslatef(100, updateFish, 0);
}

///////////////////////////////////////////////////////////////////////////////////////////Fishing Scene
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glScalef(0.8f, 0.5f, 0.7f);

    // Sky
    glBegin(GL_QUADS);
      glColor3f(0.0f, 0.7f, 1.0f);
      glVertex2f(-5.0f, 5.0f);
      glVertex2f(5.0f, 5.0f);
      glVertex2f(5.0f, -0.2f);
      glVertex2f(-5.0f, -0.2f);
    glEnd();

// Sun
glPopMatrix();
glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
float sunX = -1.3f;  // Move right
float sunY = 1.7f;   // Move up
float sunRadius = 0.3f; // Increase size

glBegin(GL_POLYGON);
for (int i = 0; i < 100; i++) {
    float angle = (i * 2 * M_PI) / 100;
    glVertex2f(sunX + sunRadius * cos(angle), sunY + sunRadius * sin(angle));
}
glEnd();

  // Cloud 1
    glPushMatrix();
    glTranslatef(cloudPosition, 0.0f, 0.0f); // Cloud moving
    glColor3f(1.0f, 1.0f, 1.0f);
    float cloudX = 1.5f, cloudY = 1.3f, cloudRadius = 0.12f;
    for (int i = 0; i < 5; i++) {
        float offsetX = (i - 2) * 0.1f;
        float offsetY = (i % 2 == 0) ? 0.1f : 0.0f;
        glBegin(GL_POLYGON);
        for (int j = 0; j < 100; j++) {
            float angle = (j * 2 * M_PI) / 100;
            glVertex2f(cloudX + offsetX + cloudRadius * cos(angle),
                       cloudY + offsetY + cloudRadius * sin(angle));
        }
        glEnd();
    }
    glPopMatrix();

      // Cloud 2
    glPushMatrix();
    glTranslatef(cloudPosition-2.9, 0.2f, 0.0f); // Cloud moving

    for (int i = 0; i < 5; i++) {
        float offsetX = (i - 2) * 0.1f;
        float offsetY = (i % 2 == 0) ? 0.1f : 0.0f;
        glBegin(GL_POLYGON);
        for (int j = 0; j < 100; j++) {
            float angle = (j * 2 * M_PI) / 100;
            glVertex2f(cloudX + offsetX + cloudRadius * cos(angle),
                       cloudY + offsetY + cloudRadius * sin(angle));
        }
        glEnd();
    }
    glPopMatrix();
      // Cloud 2
    glPushMatrix();
    glTranslatef(cloudPosition-3.9, 0.4f, 0.0f); // Cloud moving

    for (int i = 0; i < 5; i++) {
        float offsetX = (i - 2) * 0.1f;
        float offsetY = (i % 2 == 0) ? 0.1f : 0.0f;
        glBegin(GL_POLYGON);
        for (int j = 0; j < 100; j++) {
            float angle = (j * 2 * M_PI) / 100;
            glVertex2f(cloudX + offsetX + cloudRadius * cos(angle),
                       cloudY + offsetY + cloudRadius * sin(angle));
        }
        glEnd();
    }
    glPopMatrix();
     // Cloud 2
    glPushMatrix();
    glTranslatef(cloudPosition-2.2, -0.2f, 0.0f); // Cloud moving

    for (int i = 0; i < 5; i++) {
        float offsetX = (i - 2) * 0.1f;
        float offsetY = (i % 2 == 0) ? 0.1f : 0.0f;
        glBegin(GL_POLYGON);
        for (int j = 0; j < 100; j++) {
            float angle = (j * 2 * M_PI) / 100;
            glVertex2f(cloudX + offsetX + cloudRadius * cos(angle),
                       cloudY + offsetY + cloudRadius * sin(angle));
        }
        glEnd();
    }
    glPopMatrix();
    // Cloud 3
    glPushMatrix();
    glTranslatef(cloudPosition - 3.5f, 0.0f, 0.0f);
    for (int i = 0; i < 5; i++) {
        float offsetX = (i - 2) * 0.1f;
        float offsetY = (i % 2 == 0) ? 0.1f : 0.0f;
        glBegin(GL_POLYGON);
        for (int j = 0; j < 100; j++) {
            float angle = (j * 2 * M_PI) / 100;
            glVertex2f(cloudX + offsetX + cloudRadius * cos(angle),
                       cloudY + offsetY + cloudRadius * sin(angle));
    }
    glEnd();
}
    glPopMatrix();








    // Land (Green)
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.7f, 0.2f);
    glVertex2f(-2.5f, 0.2f);  // Moved further left
    glVertex2f(0.0f, -0.0f);
    glVertex2f(0.0f, -2.0f);
    glVertex2f(-2.5f, -2.0f); // Moved further left
glEnd();



    // River
   glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.3f, 0.9f);
    glVertex2f(0.0f, -0.2f);
    glVertex2f(2.5f, -0.2f);  // Increased width in +x
    glVertex2f(2.5f, -2.0f); // Increased width in +x
    glVertex2f(1.0f, -1.8f); // Shifted right
    glVertex2f(0.0f, -1.5f);
glEnd();



	// Scaling factor
GLfloat scale = 2.5f;


// Vertical shift (move tree up)
GLfloat yOffset = 0.2f;
///wave

glPushMatrix();
glTranslatef(wavePosition, -1.0f, 0.0f); // Adjusted position inside the river

glColor3ub(173, 216, 230);
glBegin(GL_TRIANGLES);
glVertex2f(0.2f, -0.5f);
glVertex2f(0.8f, -0.5f);
glVertex2f(0.5f, -0.4f);
glEnd();

glColor3ub(173, 216, 230);
glBegin(GL_TRIANGLES);
glVertex2f(1.2f, -0.5f);
glVertex2f(1.8f, -0.5f);
glVertex2f(1.5f, -0.4f);
glEnd();

glColor3ub(173, 216, 230);
glBegin(GL_TRIANGLES);
glVertex2f(2.0f, -0.5f);
glVertex2f(2.5f, -0.5f);
glVertex2f(2.25f, -0.4f);

glEnd();

glPopMatrix();

//wave 2
glPushMatrix();
glTranslatef(wavePosition+0.5, -0.2f, 0.0f); // Adjusted position inside the river

glColor3ub(173, 216, 230);
glBegin(GL_TRIANGLES);
glVertex2f(0.2f, -0.5f);
glVertex2f(0.8f, -0.5f);
glVertex2f(0.5f, -0.4f);
glEnd();

glColor3ub(173, 216, 230);
glBegin(GL_TRIANGLES);
glVertex2f(1.2f, -0.5f);
glVertex2f(1.8f, -0.5f);
glVertex2f(1.5f, -0.4f);
glEnd();

glColor3ub(173, 216, 230);
glBegin(GL_TRIANGLES);
glVertex2f(2.0f, -0.5f);
glVertex2f(2.5f, -0.5f);
glVertex2f(2.25f, -0.4f);
glEnd();

glPopMatrix();
/// Drawing Tree

// Drawing Log Shape (Tree Trunk)
glBegin(GL_POLYGON);
glColor3f(0.4f, 0.3f, 0.1f); // Light chocolate

glVertex2f(scale * -0.43f, scale * (-0.30f + yOffset));
glVertex2f(scale * -0.46f, scale * (-0.37f + yOffset));
glVertex2f(scale * -0.46f, scale * (-0.31f + yOffset));
glVertex2f(scale * -0.55f, scale * (-0.35f + yOffset));
glVertex2f(scale * -0.49f, scale * (-0.30f + yOffset));
glVertex2f(scale * -0.47f, scale * (-0.26f + yOffset));
glVertex2f(scale * -0.46f, scale * (-0.20f + yOffset));
glVertex2f(scale * -0.48f, scale * (-0.10f + yOffset));
glVertex2f(scale * -0.50f, scale * (-0.05f + yOffset));
glVertex2f(scale * -0.46f, scale * (-0.09f + yOffset));
glVertex2f(scale * -0.46f, scale * (-0.05f + yOffset));
glVertex2f(scale * -0.44f, scale * (-0.05f + yOffset));
glVertex2f(scale * -0.43f, scale * (-0.09f + yOffset));
glVertex2f(scale * -0.40f, scale * (-0.05f + yOffset));
glVertex2f(scale * -0.38f, scale * (-0.05f + yOffset));
glVertex2f(scale * -0.39f, scale * (-0.10f + yOffset));
glVertex2f(scale * -0.39f, scale * (-0.15f + yOffset));
glVertex2f(scale * -0.38f, scale * (-0.20f + yOffset));
glVertex2f(scale * -0.38f, scale * (-0.26f + yOffset));
glVertex2f(scale * -0.37f, scale * (-0.30f + yOffset));
glVertex2f(scale * -0.32f, scale * (-0.35f + yOffset));
glVertex2f(scale * -0.39f, scale * (-0.31f + yOffset));
glVertex2f(scale * -0.38f, scale * (-0.37f + yOffset));

glEnd();

/// Drawing tree leaves (scaled and moved up)
GLfloat leafPositions[][2] = {
    {-0.44f, 0.14f}, // Center leaf
    {-0.62f, 0.10f}, // Left leaf
    {-0.51f, 0.23f}, // Top-left leaf
    {-0.36f, 0.20f}, // Top-right leaf
    {-0.24f, 0.11f}, // Right leaf
    {-0.36f, 0.01f}, // Bottom-right leaf
    {-0.53f, 0.02f}  // Bottom-left leaf
};

for (int j = 0; j < 7; j++) {
    GLfloat x = scale * leafPositions[j][0];
    GLfloat y = scale * (leafPositions[j][1] + yOffset); // Move up

    glColor3f(0.0f, 1.0f, 0.0f); // Green

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of circle

    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(x + (scale * radius9 * cos(i * twicePi / triangleAmount)),
                   y + (scale * radius9 * sin(i * twicePi / triangleAmount)));
    }

    glEnd();
}



    // Man moving on land
    glPushMatrix();
      glTranslatef(_move, 0.0f, 0.0f);

      // Body
      glBegin(GL_POLYGON);
        glColor3f(0.8f, 0.5f, 0.3f);
        glVertex2f(-0.15f, 0.3f);
        glVertex2f(0.15f, 0.3f);
        glVertex2f(0.15f, -0.1f);
        glVertex2f(-0.15f, -0.1f);
      glEnd();

      // Neck
      glBegin(GL_QUADS);
        glColor3f(1.0f, 0.8f, 0.6f); // Skin color
        glVertex2f(-0.05f, 0.42f);
        glVertex2f(0.05f, 0.42f);
        glVertex2f(0.05f, 0.38f);
        glVertex2f(-0.05f, 0.38f);
      glEnd();

      // Head
      glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.8f, 0.6f);
        for (int i = 0; i < 200; i++) {
          float angle = (i * 2 * M_PI) / 200;
          float r = 0.15;
          glVertex2f(r * cos(angle), r * sin(angle) + 0.45f);
        }
      glEnd();

      // Cap
      glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < 100; i++) {
          float angle = (i * M_PI) / 100;
          float r = 0.15;
          glVertex2f(r * cos(angle), r * sin(angle) + 0.52f);
        }
      glEnd();

      // Eyes
      glPointSize(5.0f);
      glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.05f, 0.47f);
        glVertex2f(0.05f, 0.47f);
      glEnd();

      // Nose (a short vertical line)
      glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.46f);
        glVertex2f(0.0f, 0.42f);
      glEnd();

      // Mouth (a simple straight line for a smile)
      glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.04f, 0.40f);
        glVertex2f(0.04f, 0.40f);
      glEnd();

      // Arms
      glBegin(GL_QUADS);
        glColor3f(0.8f, 0.5f, 0.3f);
        // Right Arm (holding the bucket)
        glVertex2f(-0.15f, 0.2f);
        glVertex2f(-0.4f, 0.0f); // Adjusted to connect to the bucket handle
        glVertex2f(-0.38f, -0.02f);
        glVertex2f(-0.13f, 0.18f);
        // Left Arm (holding the fishing rod)
        glVertex2f(0.15f, 0.2f);
        glVertex2f(0.35f, 0.2f);
        glVertex2f(0.33f, 0.18f);
        glVertex2f(0.13f, 0.18f);
      glEnd();

      // Hands as small circles
      // For the right arm (person's right hand, drawn on the left side)
      glColor3f(1.0f, 0.8f, 0.6f);
      glBegin(GL_POLYGON);
        // Place the hand at the bucket handle's midpoint (-0.4f, 0.0f)
        float leftHandRadius = 0.03f;
        float leftHandCenterX = -0.4f;
        float leftHandCenterY = 0.0f;
        for (int i = 0; i < 20; i++) {
          float angle = i * 2 * M_PI / 20;
          glVertex2f(leftHandCenterX + leftHandRadius * cos(angle),
                     leftHandCenterY + leftHandRadius * sin(angle));
        }
      glEnd();

      // For the left arm (person's left hand, drawn on the right side)
      glColor3f(1.0f, 0.8f, 0.6f);
      glBegin(GL_POLYGON);
        // Place the hand at the tip of the left arm quad (near (0.35, 0.2))
        float rightHandRadius = 0.03f;
        float rightHandCenterX = 0.35f;
        float rightHandCenterY = 0.2f;
        for (int i = 0; i < 20; i++) {
          float angle = i * 2 * M_PI / 20;
          glVertex2f(rightHandCenterX + rightHandRadius * cos(angle),
                     rightHandCenterY + rightHandRadius * sin(angle));
        }
      glEnd();

      // Legs
      glBegin(GL_QUADS);
        glColor3f(0.8f, 0.5f, 0.3f);
        // Left Leg
        glVertex2f(-0.08f, -0.1f);
        glVertex2f(-0.12f, -0.1f);
        glVertex2f(-0.12f, -0.5f);
        glVertex2f(-0.08f, -0.5f);
        // Right Leg
        glVertex2f(0.08f, -0.1f);
        glVertex2f(0.12f, -0.1f);
        glVertex2f(0.12f, -0.5f);
        glVertex2f(0.08f, -0.5f);
      glEnd();

      // Fishing Rod
      glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.35f, 0.2f);
        glVertex2f(1.0f, 0.8f);
      glEnd();

      // Fishing Line
      glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(1.0f, 0.8f);
        glVertex2f(0.9f, -0.4f);
      glEnd();

    // Fishing Hook as a Triangle drawn with three separate lines:
      //1st line
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.92f, -0.45f);  // Point b
        glVertex2f(0.9f, -0.4f);    // Point A
        glEnd();
      // 2nd line:
          glBegin(GL_LINES);
          glColor3f(0.0f, 0.0f, 0.0f);
          glVertex2f(0.88f, -0.45f);  // Point c
          glVertex2f(0.92f, -0.45f);  // Point b
          glEnd();
      //3rd line
          glBegin(GL_LINES);
          glColor3f(0.0f, 0.0f, 0.0f);
          glVertex2f(0.88f, -0.45f);  // Point c
          glVertex2f(0.88f, -0.42f);  // Point d
          glEnd();

      // Bucket (held by the right arm)
      glBegin(GL_QUADS);
        glColor3f(0.5f, 0.35f, 0.05f);
        glVertex2f(-0.5f, -0.2f);
        glVertex2f(-0.3f, -0.2f);
        glVertex2f(-0.32f, -0.45f);
        glVertex2f(-0.48f, -0.45f);
      glEnd();

      // Bucket Handle
      glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.5f, -0.2f);
        glVertex2f(-0.4f, 0.0f);
        glVertex2f(-0.3f, -0.2f);
      glEnd();



    glPopMatrix();
   // glutSwapBuffers();
   glutPostRedisplay();
}


void update(int value) {
    if (moving) {
        _move += 0.01f;
        if (_move >= -0.3f) {
            moving = false; // Stop movement in the middle
        }
    }
     cloudPosition += cloudSpeed;
    if (cloudPosition > 5.0f){
        cloudPosition = -3.0f;
    }
    wavePosition += waveSpeed;
    if(wavePosition > 1.0){
            wavePosition=-0.2;
    }
    wavePosition2 += waveSpeed;
    if(wavePosition2 > 1.0){
            wavePosition2=-0.2;
    }
    //glutSwapBuffers();
    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}



///////////////////////////////////////////////////////////////////////////////////////////////Hooked fish

void HookedFish() {
 //glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
 //glMatrixMode(GL_MODELVIEW); // To operate on Model-View matrix
 //glLoadIdentity(); // Reset the model-view matrix
 glLineWidth(4.0f);
 glScalef(0.3f, 0.3f, 0.7f); // Scaling
GLfloat angle = 45;

 glPushMatrix(); // Save the current transformation state
//glTranslatef(fishPosition, 0.0f, 0.0f); // Move fish
glRotatef(angle, 0.0f, 0.0f, 1.0f); // Rotate only this fish
//glScalef(0.3f, 0.3f, 0.7f); // Scaling
 glTranslatef(-3.0, -0.2,0.0f);


//Hooked fishhh
glBegin(GL_POLYGON);
        //fish body
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.5f, -0.3f);
        glVertex2f(0.2f, -0.3f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(-0.5f, 0.3f);
    glEnd();

     glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-01.0f, 0.2f);
        glVertex2f(-01.0f, -0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, 0.3f);
        glVertex2f(-0.45f, 0.6f);
        glVertex2f(0.02f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, -0.3f);
        glVertex2f(-0.45f, -0.6f);
        glVertex2f(0.02f, -0.3f);
    glEnd();

     // Eye
    glPointSize(7.0f);
    glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.3f, 0.1f);
    glEnd();

     glBegin(GL_LINES);
      glLineWidth(10.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.20f, -0.3f);
        glVertex2f(0.20f, 0.3f);
    glEnd();

// Hook Line (straight and long)
glBegin(GL_LINES);
    glVertex2f(12.0f, 13.5f); // Start point of the line (left of the frame)
    glVertex2f(0.6f, 0.1f);  // End point (straight horizontal line, longer)
glEnd();

      // Fishing Hook as a Triangle drawn with three separate lines:
      // First line: from point A to point B
      glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.6f, 0.1f); // Start point of the line (left of the frame)
  glVertex2f(0.6f, -0.08f);  // End point (straight horizontal line, longer)
glEnd();
      // Second line: from point B to point C
        glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.6f, -0.08f); // Start point of the line (left of the frame)
  glVertex2f(0.45f, -0.05f);  // End point (straight horizontal line, longer)
glEnd();


glPopMatrix();


 glPushMatrix(); // Save model-view matrix setting
//GLfloat angle = 0.0f; // Current rotational angle of the shapes
//GLfloat tx=0.0;
//GLfloat ty=0.0;
  glTranslatef(fishPosition, 0.0f,0.0f); // Translate
   // glRotatef(angle,0.0f,1.0f, 0.0f); // rotate by angle in degrees
     glBegin(GL_POLYGON);
        //fish body
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.5f, -0.3f);
        glVertex2f(0.2f, -0.3f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(-0.5f, 0.3f);
    glEnd();

     glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-01.0f, 0.2f);
        glVertex2f(-01.0f, -0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, 0.3f);
        glVertex2f(-0.45f, 0.6f);
        glVertex2f(0.02f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, -0.3f);
        glVertex2f(-0.45f, -0.6f);
        glVertex2f(0.02f, -0.3f);
    glEnd();

     // Eye
    glPointSize(7.0f);
    glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.3f, 0.1f);
    glEnd();

     glBegin(GL_LINES);
      glLineWidth(10.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.20f, -0.3f);
        glVertex2f(0.20f, 0.3f);
    glEnd();

        // Second Fish
     glTranslatef(2.0, 2.0,0.0f); // Translate
   // glRotatef(angle,0.0f,1.0f, 0.0f); // rotate by angle in degrees
     glBegin(GL_POLYGON);
        //fish body
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.5f, -0.3f);
        glVertex2f(0.2f, -0.3f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(-0.5f, 0.3f);
    glEnd();

     glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-01.0f, 0.2f);
        glVertex2f(-01.0f, -0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, 0.3f);
        glVertex2f(-0.45f, 0.6f);
        glVertex2f(0.02f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, -0.3f);
        glVertex2f(-0.45f, -0.6f);
        glVertex2f(0.02f, -0.3f);
    glEnd();

     // Eye
    glPointSize(7.0f);
    glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.3f, 0.1f);
    glEnd();

     glBegin(GL_LINES);
      glLineWidth(10.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.20f, -0.3f);
        glVertex2f(0.20f, 0.3f);
    glEnd();


// third fish

 glTranslatef(1.0,-3.0,0.0f); // Translate
   // glRotatef(angle,0.0f,1.0f, 0.0f); // rotate by angle in degrees
     glBegin(GL_POLYGON);
        //fish body
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.5f, -0.3f);
        glVertex2f(0.2f, -0.3f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(-0.5f, 0.3f);
    glEnd();

     glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-01.0f, 0.2f);
        glVertex2f(-01.0f, -0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, 0.3f);
        glVertex2f(-0.45f, 0.6f);
        glVertex2f(0.02f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, -0.3f);
        glVertex2f(-0.45f, -0.6f);
        glVertex2f(0.02f, -0.3f);
    glEnd();

     // Eye
    glPointSize(7.0f);
    glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.3f, 0.1f);
    glEnd();

     glBegin(GL_LINES);
      glLineWidth(10.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.20f, -0.3f);
        glVertex2f(0.20f, 0.3f);
    glEnd();



//4th fish
 glTranslatef(-6.0, 3.0,0.0f); // Translate
   // glRotatef(angle,0.0f,1.0f, 0.0f); // rotate by angle in degrees
     glBegin(GL_POLYGON);
        //fish body
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.5f, -0.3f);
        glVertex2f(0.2f, -0.3f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(-0.5f, 0.3f);
    glEnd();

     glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.6f, 0.0f);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-01.0f, 0.2f);
        glVertex2f(-01.0f, -0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, 0.3f);
        glVertex2f(-0.45f, 0.6f);
        glVertex2f(0.02f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.30f, -0.3f);
        glVertex2f(-0.45f, -0.6f);
        glVertex2f(0.02f, -0.3f);
    glEnd();

     // Eye
    glPointSize(7.0f);
    glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.3f, 0.1f);
    glEnd();

     glBegin(GL_LINES);
      glLineWidth(10.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.20f, -0.3f);
        glVertex2f(0.20f, 0.3f);
    glEnd();



    glPopMatrix();
       //glutSwapBuffers();
}

void updateHFish(int value)
  {

    fishPosition += fishSpeed;
    if
    (fishPosition > 14.0f)
        fishPosition = -8.5f;

        //fishSpeed = -01.0;
    glutPostRedisplay();
    glutTimerFunc(3, updateHFish, 0);
//    glTranslatef(100, updateFish, 0);


}


/*void update(int value) {
fishSpeed += .02;
if(fishSpeed > 1.3)
{
fishSpeed = -1.0;
}
glutPostRedisplay();
glutTimerFunc(20, update, 0);
glTranslatef(1, 5, 0);
}*/


//glutSwapBuffers(); // Double buffered - swap the front and back buffers
 // Change the rotational angle after each display()
 //angle += 0.02f;

// tx += 0.00099; // Move right
   // if (tx > 7.5f) { // If it moves off the screen to the right
  //      tx = -6.7f; // Reset to the left side
   // }

// tx +=0.00008;
 //ty +=0.0000;

 /*void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

        DrawFish();

    glutSwapBuffers();
}
*/
void drawLastScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glScalef(0.8f, 0.5f, 0.7f);

    // Sky
    glBegin(GL_QUADS);
      glColor3f(0.0f, 0.7f, 1.0f);
      glVertex2f(-5.0f, 5.0f);
      glVertex2f(5.0f, 5.0f);
      glVertex2f(5.0f, -0.2f);
      glVertex2f(-5.0f, -0.2f);
    glEnd();

// Sun
glPopMatrix();
glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
float sunX = -1.3f;  // Move right
float sunY = 1.7f;   // Move up
float sunRadius = 0.3f; // Increase size

glBegin(GL_POLYGON);
for (int i = 0; i < 100; i++) {
    float angle = (i * 2 * M_PI) / 100;
    glVertex2f(sunX + sunRadius * cos(angle), sunY + sunRadius * sin(angle));
}
glEnd();

  // Cloud 1
    glPushMatrix();
    glTranslatef(cloudPosition, 0.0f, 0.0f); // Cloud moving
    glColor3f(1.0f, 1.0f, 1.0f);
    float cloudX = 1.5f, cloudY = 1.3f, cloudRadius = 0.12f;
    for (int i = 0; i < 5; i++) {
        float offsetX = (i - 2) * 0.1f;
        float offsetY = (i % 2 == 0) ? 0.1f : 0.0f;
        glBegin(GL_POLYGON);
        for (int j = 0; j < 100; j++) {
            float angle = (j * 2 * M_PI) / 100;
            glVertex2f(cloudX + offsetX + cloudRadius * cos(angle),
                       cloudY + offsetY + cloudRadius * sin(angle));
        }
        glEnd();
    }
    glPopMatrix();

      // Cloud 2
    glPushMatrix();
    glTranslatef(cloudPosition-2.9, 0.2f, 0.0f); // Cloud moving

    for (int i = 0; i < 5; i++) {
        float offsetX = (i - 2) * 0.1f;
        float offsetY = (i % 2 == 0) ? 0.1f : 0.0f;
        glBegin(GL_POLYGON);
        for (int j = 0; j < 100; j++) {
            float angle = (j * 2 * M_PI) / 100;
            glVertex2f(cloudX + offsetX + cloudRadius * cos(angle),
                       cloudY + offsetY + cloudRadius * sin(angle));
        }
        glEnd();
    }
    glPopMatrix();
      // Cloud 2
    glPushMatrix();
    glTranslatef(cloudPosition-3.9, 0.4f, 0.0f); // Cloud moving

    for (int i = 0; i < 5; i++) {
        float offsetX = (i - 2) * 0.1f;
        float offsetY = (i % 2 == 0) ? 0.1f : 0.0f;
        glBegin(GL_POLYGON);
        for (int j = 0; j < 100; j++) {
            float angle = (j * 2 * M_PI) / 100;
            glVertex2f(cloudX + offsetX + cloudRadius * cos(angle),
                       cloudY + offsetY + cloudRadius * sin(angle));
        }
        glEnd();
    }
    glPopMatrix();
     // Cloud 2
    glPushMatrix();
    glTranslatef(cloudPosition-2.2, -0.2f, 0.0f); // Cloud moving

    for (int i = 0; i < 5; i++) {
        float offsetX = (i - 2) * 0.1f;
        float offsetY = (i % 2 == 0) ? 0.1f : 0.0f;
        glBegin(GL_POLYGON);
        for (int j = 0; j < 100; j++) {
            float angle = (j * 2 * M_PI) / 100;
            glVertex2f(cloudX + offsetX + cloudRadius * cos(angle),
                       cloudY + offsetY + cloudRadius * sin(angle));
        }
        glEnd();
    }
    glPopMatrix();
    // Cloud 3
    glPushMatrix();
    glTranslatef(cloudPosition - 3.5f, 0.0f, 0.0f);
    for (int i = 0; i < 5; i++) {
        float offsetX = (i - 2) * 0.1f;
        float offsetY = (i % 2 == 0) ? 0.1f : 0.0f;
        glBegin(GL_POLYGON);
        for (int j = 0; j < 100; j++) {
            float angle = (j * 2 * M_PI) / 100;
            glVertex2f(cloudX + offsetX + cloudRadius * cos(angle),
                       cloudY + offsetY + cloudRadius * sin(angle));
    }
    glEnd();
}
    glPopMatrix();







    // Land (Green)
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.7f, 0.2f);
    glVertex2f(-2.5f, 0.2f);  // Moved further left
    glVertex2f(0.0f, -0.0f);
    glVertex2f(0.0f, -2.0f);
    glVertex2f(-2.5f, -2.0f); // Moved further left
glEnd();



    // River
   glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.3f, 0.9f);
    glVertex2f(0.0f, -0.2f);
    glVertex2f(2.5f, -0.2f);  // Increased width in +x
    glVertex2f(2.5f, -2.0f); // Increased width in +x
    glVertex2f(1.0f, -1.8f); // Shifted right
    glVertex2f(0.0f, -1.5f);
glEnd();



	// Scaling factor
GLfloat scale = 2.5f;


// Vertical shift (move tree up)
GLfloat yOffset = 0.2f;
///wave

glPushMatrix();
glTranslatef(wavePosition, -1.0f, 0.0f); // Adjusted position inside the river

glColor3ub(173, 216, 230);
glBegin(GL_TRIANGLES);
glVertex2f(0.2f, -0.5f);
glVertex2f(0.8f, -0.5f);
glVertex2f(0.5f, -0.4f);
glEnd();

glColor3ub(173, 216, 230);
glBegin(GL_TRIANGLES);
glVertex2f(1.2f, -0.5f);
glVertex2f(1.8f, -0.5f);
glVertex2f(1.5f, -0.4f);
glEnd();

glColor3ub(173, 216, 230);
glBegin(GL_TRIANGLES);
glVertex2f(2.0f, -0.5f);
glVertex2f(2.5f, -0.5f);
glVertex2f(2.25f, -0.4f);

glEnd();

glPopMatrix();

//wave 2
glPushMatrix();
glTranslatef(wavePosition+0.5, -0.2f, 0.0f); // Adjusted position inside the river

glColor3ub(173, 216, 230);
glBegin(GL_TRIANGLES);
glVertex2f(0.2f, -0.5f);
glVertex2f(0.8f, -0.5f);
glVertex2f(0.5f, -0.4f);
glEnd();

glColor3ub(173, 216, 230);
glBegin(GL_TRIANGLES);
glVertex2f(1.2f, -0.5f);
glVertex2f(1.8f, -0.5f);
glVertex2f(1.5f, -0.4f);
glEnd();

glColor3ub(173, 216, 230);
glBegin(GL_TRIANGLES);
glVertex2f(2.0f, -0.5f);
glVertex2f(2.5f, -0.5f);
glVertex2f(2.25f, -0.4f);
glEnd();

glPopMatrix();
/// Drawing Tree

// Drawing Log Shape (Tree Trunk)
glBegin(GL_POLYGON);
glColor3f(0.4f, 0.3f, 0.1f); // Light chocolate

glVertex2f(scale * -0.43f, scale * (-0.30f + yOffset));
glVertex2f(scale * -0.46f, scale * (-0.37f + yOffset));
glVertex2f(scale * -0.46f, scale * (-0.31f + yOffset));
glVertex2f(scale * -0.55f, scale * (-0.35f + yOffset));
glVertex2f(scale * -0.49f, scale * (-0.30f + yOffset));
glVertex2f(scale * -0.47f, scale * (-0.26f + yOffset));
glVertex2f(scale * -0.46f, scale * (-0.20f + yOffset));
glVertex2f(scale * -0.48f, scale * (-0.10f + yOffset));
glVertex2f(scale * -0.50f, scale * (-0.05f + yOffset));
glVertex2f(scale * -0.46f, scale * (-0.09f + yOffset));
glVertex2f(scale * -0.46f, scale * (-0.05f + yOffset));
glVertex2f(scale * -0.44f, scale * (-0.05f + yOffset));
glVertex2f(scale * -0.43f, scale * (-0.09f + yOffset));
glVertex2f(scale * -0.40f, scale * (-0.05f + yOffset));
glVertex2f(scale * -0.38f, scale * (-0.05f + yOffset));
glVertex2f(scale * -0.39f, scale * (-0.10f + yOffset));
glVertex2f(scale * -0.39f, scale * (-0.15f + yOffset));
glVertex2f(scale * -0.38f, scale * (-0.20f + yOffset));
glVertex2f(scale * -0.38f, scale * (-0.26f + yOffset));
glVertex2f(scale * -0.37f, scale * (-0.30f + yOffset));
glVertex2f(scale * -0.32f, scale * (-0.35f + yOffset));
glVertex2f(scale * -0.39f, scale * (-0.31f + yOffset));
glVertex2f(scale * -0.38f, scale * (-0.37f + yOffset));

glEnd();

/// Drawing tree leaves (scaled and moved up)
GLfloat leafPositions[][2] = {
    {-0.44f, 0.14f}, // Center leaf
    {-0.62f, 0.10f}, // Left leaf
    {-0.51f, 0.23f}, // Top-left leaf
    {-0.36f, 0.20f}, // Top-right leaf
    {-0.24f, 0.11f}, // Right leaf
    {-0.36f, 0.01f}, // Bottom-right leaf
    {-0.53f, 0.02f}  // Bottom-left leaf
};

for (int j = 0; j < 7; j++) {
    GLfloat x = scale * leafPositions[j][0];
    GLfloat y = scale * (leafPositions[j][1] + yOffset); // Move up

    glColor3f(0.0f, 1.0f, 0.0f); // Green

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of circle

    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(x + (scale * radius9 * cos(i * twicePi / triangleAmount)),
                   y + (scale * radius9 * sin(i * twicePi / triangleAmount)));
    }

    glEnd();
}



    // Man moving on land
    glPushMatrix();
      glTranslatef(_movee, -0.5f, -1.2f);

      // Body
      glBegin(GL_POLYGON);
        glColor3f(0.8f, 0.5f, 0.3f);
        glVertex2f(-0.15f, 0.3f);
        glVertex2f(0.15f, 0.3f);
        glVertex2f(0.15f, -0.1f);
        glVertex2f(-0.15f, -0.1f);
      glEnd();

      // Neck
      glBegin(GL_QUADS);
        glColor3f(1.0f, 0.8f, 0.6f); // Skin color
        glVertex2f(-0.05f, 0.42f);
        glVertex2f(0.05f, 0.42f);
        glVertex2f(0.05f, 0.38f);
        glVertex2f(-0.05f, 0.38f);
      glEnd();

      // Head
      glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.8f, 0.6f);
        for (int i = 0; i < 200; i++) {
          float angle = (i * 2 * M_PI) / 200;
          float r = 0.15;
          glVertex2f(r * cos(angle), r * sin(angle) + 0.45f);
        }
      glEnd();

      // Cap
      glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 0; i < 100; i++) {
          float angle = (i * M_PI) / 100;
          float r = 0.15;
          glVertex2f(r * cos(angle), r * sin(angle) + 0.52f);
        }
      glEnd();

      // Eyes
      glPointSize(5.0f);
      glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.05f, 0.47f);
        glVertex2f(0.05f, 0.47f);
      glEnd();

      // Nose (a short vertical line)
      glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.46f);
        glVertex2f(0.0f, 0.42f);
      glEnd();

      // Mouth (a simple straight line for a smile)
      glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.04f, 0.40f);
        glVertex2f(0.04f, 0.40f);
      glEnd();

      // Arms
      glBegin(GL_QUADS);
        glColor3f(0.8f, 0.5f, 0.3f);
        // Right Arm (holding the bucket)
        glVertex2f(-0.15f, 0.2f);
        glVertex2f(-0.4f, 0.0f); // Adjusted to connect to the bucket handle
        glVertex2f(-0.38f, -0.02f);
        glVertex2f(-0.13f, 0.18f);
        // Left Arm (holding the fishing rod)
        glVertex2f(0.15f, 0.2f);
        glVertex2f(0.35f, 0.2f);
        glVertex2f(0.33f, 0.18f);
        glVertex2f(0.13f, 0.18f);
      glEnd();

      // Hands as small circles
      // For the right arm (person's right hand, drawn on the left side)
      glColor3f(1.0f, 0.8f, 0.6f);
      glBegin(GL_POLYGON);
        // Place the hand at the bucket handle's midpoint (-0.4f, 0.0f)
        float leftHandRadius = 0.03f;
        float leftHandCenterX = -0.4f;
        float leftHandCenterY = 0.0f;
        for (int i = 0; i < 20; i++) {
          float angle = i * 2 * M_PI / 20;
          glVertex2f(leftHandCenterX + leftHandRadius * cos(angle),
                     leftHandCenterY + leftHandRadius * sin(angle));
        }
      glEnd();

      // For the left arm (person's left hand, drawn on the right side)
      glColor3f(1.0f, 0.8f, 0.6f);
      glBegin(GL_POLYGON);
        // Place the hand at the tip of the left arm quad (near (0.35, 0.2))
        float rightHandRadius = 0.03f;
        float rightHandCenterX = 0.35f;
        float rightHandCenterY = 0.2f;
        for (int i = 0; i < 20; i++) {
          float angle = i * 2 * M_PI / 20;
          glVertex2f(rightHandCenterX + rightHandRadius * cos(angle),
                     rightHandCenterY + rightHandRadius * sin(angle));
        }
      glEnd();

      // Legs
      glBegin(GL_QUADS);
        glColor3f(0.8f, 0.5f, 0.3f);
        // Left Leg
        glVertex2f(-0.08f, -0.1f);
        glVertex2f(-0.12f, -0.1f);
        glVertex2f(-0.12f, -0.5f);
        glVertex2f(-0.08f, -0.5f);
        // Right Leg
        glVertex2f(0.08f, -0.1f);
        glVertex2f(0.12f, -0.1f);
        glVertex2f(0.12f, -0.5f);
        glVertex2f(0.08f, -0.5f);
      glEnd();

         // Fishing Rod
      glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.35f, 0.2f);
        glVertex2f(0.7f, 1.1f);
      glEnd();

      // Fishing Line
      glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.7f, 1.1f);
        glVertex2f(0.7f, 0.2f);
      glEnd();

    // Fishing Hook as a Triangle drawn with three separate lines:
      //1st line
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.72f, 0.15f);  // Point b
        glVertex2f(0.7f, 0.2f);    // Point A
        glEnd();
      // 2nd line:
          glBegin(GL_LINES);
          glColor3f(0.0f, 0.0f, 0.0f);
          glVertex2f(0.70f, 0.15f);  // Point c
          glVertex2f(0.72f, 0.15f);  // Point b
          glEnd();
      //3rd line
        //  glBegin(GL_LINES);
        //  glColor3f(0.0f, 0.0f, 0.0f);
        //  glVertex2f(0.88f, -0.45f);  // Point c
        //  glVertex2f(0.88f, -0.42f);  // Point d
        //  glEnd();

      // Bucket (held by the right arm)
      glBegin(GL_QUADS);
        glColor3f(0.5f, 0.35f, 0.05f);
        glVertex2f(-0.5f, -0.2f);
        glVertex2f(-0.3f, -0.2f);
        glVertex2f(-0.32f, -0.45f);
        glVertex2f(-0.48f, -0.45f);
      glEnd();
      // Bucket (held by the right arm)
      glBegin(GL_QUADS);
        glColor3f(0.5f, 0.35f, 0.05f);
        glVertex2f(-0.5f, -0.2f);
        glVertex2f(-0.3f, -0.2f);
        glVertex2f(-0.32f, -0.45f);
        glVertex2f(-0.48f, -0.45f);
      glEnd();

      // Bucket Handle
      glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.5f, -0.2f);
        glVertex2f(-0.4f, 0.0f);
        glVertex2f(-0.3f, -0.2f);
      glEnd();


// Caught  Fish (Mouth at 0.70f, 0.15f)
glBegin(GL_POLYGON);
// Fish body (Vertical)
glColor3f(1.0f, 0.6f, 0.0f);
glVertex2f(0.70f, -0.175f + 0.025f);
glVertex2f(0.625f, -0.125f + 0.025f);
glVertex2f(0.625f, 0.05f + 0.025f);
glVertex2f(0.70f, 0.125f + 0.025f);
glVertex2f(0.775f, 0.05f + 0.025f);
glVertex2f(0.775f, -0.125f + 0.025f);
glEnd();

glBegin(GL_TRIANGLES);
// Tail (Vertical)
glColor3f(1.0f, 0.6f, 0.0f);
glVertex2f(0.70f, -0.175f + 0.025f);
glVertex2f(0.75f, -0.25f + 0.025f);
glVertex2f(0.65f, -0.25f + 0.025f);
glEnd();

glBegin(GL_TRIANGLES);
// Left Fin
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.625f, -0.075f + 0.025f);
glVertex2f(0.55f, -0.1125f + 0.025f);
glVertex2f(0.625f, 0.005f + 0.025f);
glEnd();

glBegin(GL_TRIANGLES);
// Right Fin
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.775f, -0.075f + 0.025f);
glVertex2f(0.85f, -0.1125f + 0.025f);
glVertex2f(0.775f, 0.005f + 0.025f);
glEnd();

// Eye (Adjusted Position)
glPointSize(3.0f);
glBegin(GL_POINTS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.725f, 0.075f + 0.025f);
glEnd();

glBegin(GL_LINES);
    glLineWidth(2.5f);  // Adjusted thickness
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.62f, 0.06f);  // Left point of the smaller horizontal line (further right)
    glVertex2f(0.77f, 0.06f);  // Right point of the smaller horizontal line (further right)
glEnd();


/* Fishing Hook Line (Above the Fish)
glBegin(GL_LINES);
glLineWidth(10.0f);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.70f, 0.125f + 0.025f);
glVertex2f(0.70f, 0.25f + 0.025f);
glEnd();

*/


    glPopMatrix();
   // glutSwapBuffers();
   glutPostRedisplay();
}


void updates(int value) {
    if (mooving) {
        _movee = 0.01f;
        if (_movee >= -0.5f) {
            mooving = false; // Stop movement in the middle
        }
    }
    glutSwapBuffers();
    glutPostRedisplay();
    glutTimerFunc(60, updates, 0);
}



void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    switch (currentScene) {
        case 1: DrawFish(); break;
        case 2: drawScene(); break;
        case 3: HookedFish(); break;
        case 4: drawLastScene();break;
    }
glutPostRedisplay();
    glutSwapBuffers();
}

// Keyboard Function
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            currentScene = 1;  // Switch to Village Scene
            break;
        case 'b':
            currentScene = 2;  // Switch to Fishing Scene
            break;
        case 'c':
            currentScene = 3;  // Switch to Fishing Scene
            break;
        case 'd':
            currentScene = 4;  // Switch to Night Scene
            break;
        case '5':
            fishSpeed = 0.0f;
            break;
        case '6':
            fishSpeed += 0.001f;  // Move up
            break;
        case '4':
            fishSpeed -= 0.001f;  // Move up
            break;
        case '2':
            moving = 0.0f;  // Move up
            break;
        case '1':
            moving = -0.001f;  // Move up
            break;
        case '3':
            moving += 0.001f;  // Move up
            break;

    }
glutSwapBuffers();
    glutPostRedisplay();
}



void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1; // Prevent divide-by-zero error

    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping area to match the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (width >= height) {
        // If the window is wider than it is tall, adjust width
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    } else {
        // If the window is taller than it is wide, adjust height
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }

    glMatrixMode(GL_MODELVIEW);
}
void idle() {
 glutPostRedisplay(); // Post a re-paint request to activate display()
}

/* Main function: GLUT runs as a console application starting at main() */
// Main Function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Switch Interfaces with 'A,B,C,D' Key");



    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-2, 2, -2, 2);
    glMatrixMode(GL_MODELVIEW);
glutDisplayFunc(drawScene);
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(16, updateFish, 0);
  glutTimerFunc(20, update, 0);
  //glutTimerFunc(20, updates, 0);


  glutReshapeFunc(reshape);
   glMatrixMode(GL_PROJECTION);
glutPostRedisplay();
initGL();
    glutMainLoop();
    return 0;
}
