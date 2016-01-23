#include "cube.h"
#include <iostream>
#include <cstring>
using namespace std;

Cube::Cube(float x, float y, float z, int t)
{
	chosen = 0;
	positionX = x;
	positionY = y;
	positionZ = z;
	type = t;
	switch (t)
	{
	case LAND:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 0  ;
			textureY[i] = 0  ;
		}
		break;
	case SAND:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 0  ;
			textureY[i] = 11  ;
		}
		break;
	case WOOD:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 4  ;
			textureY[i] = 2  ;
		}
		break;
	case PIERRE:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 5  ;
			textureY[i] = 0  ;
		}
		break;
	case WATER:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 13  ;
			textureY[i] = 12  ;
		}
		break;
	case BRICK:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 3  ;
			textureY[i] = 0  ;
		}
		break;
	case SNOW:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 2  ;
			textureY[i] = 11  ;
		}
		break;
	case MAGMA:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 15  ;
			textureY[i] = 0  ;
		}
		break;
	case GRASSLAND:
		for(int i = 0;i<6;i++)
		{
			textureX[i] = 2  ;
			textureY[i] = 15  ;
		}
		break;
	default:
		break;
	}

	for(int i = 0; i < 6; i++)
	{
		textureX[i] = 0.0625 * textureX[i];
		textureY[i] = 0.0625 * textureY[i];
	}
}

void Cube::afficheCube()
{
	if(chosen)
	{
		glColor3f(1.0f,0.0f,0.0f); 
		glBegin(GL_LINES);  
			glVertex3f(positionX-0.01,positionY-0.01,positionZ-0.01);     glVertex3f(positionX+1.01,positionY-0.01,positionZ-0.01);  
			glVertex3f(positionX-0.01,positionY-0.01,positionZ-0.01);     glVertex3f(positionX-0.01,positionY+1.01,positionZ-0.01);  
			glVertex3f(positionX-0.01,positionY+1.01,positionZ-0.01);     glVertex3f(positionX+1.01,positionY+1.01,positionZ-0.01);  
			glVertex3f(positionX+1.01,positionY-0.01,positionZ-0.01);     glVertex3f(positionX+1.01,positionY+1.01,positionZ-0.01);  

			glVertex3f(positionX-0.01,positionY-0.01,positionZ+1.01);     glVertex3f(positionX+1.01,positionY-0.01,positionZ+1.01);  
			glVertex3f(positionX-0.01,positionY-0.01,positionZ+1.01);     glVertex3f(positionX-0.01,positionY+1.01,positionZ+1.01);  
			glVertex3f(positionX-0.01,positionY+1.01,positionZ+1.01);     glVertex3f(positionX+1.01,positionY+1.01,positionZ+1.01);  
			glVertex3f(positionX+1.01,positionY-0.01,positionZ+1.01);     glVertex3f(positionX+1.01,positionY+1.01,positionZ+1.01);  

			glVertex3f(positionX-0.01,positionY-0.01,positionZ-0.01);     glVertex3f(positionX-0.01,positionY-0.01,positionZ+1.01);  
			glVertex3f(positionX-0.01,positionY+1.01,positionZ-0.01);     glVertex3f(positionX-0.01,positionY+1.01,positionZ+1.01);  
			glVertex3f(positionX+1.01,positionY-0.01,positionZ-0.01);     glVertex3f(positionX+1.01,positionY-0.01,positionZ+1.01);  
			glVertex3f(positionX+1.01,positionY+1.01,positionZ-0.01);     glVertex3f(positionX+1.01,positionY+1.01,positionZ+1.01); 
		glEnd(); 
	}

	glBegin(GL_QUADS);
		// Devant
		glColor3f(1.0f, 1.0f, 1.0f); // ��ɫ
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.005); glVertex3f(positionX,   positionY+1, positionZ+1);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.005); glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.060); glVertex3f(positionX+1, positionY,   positionZ+1);
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.060); glVertex3f(positionX,   positionY,   positionZ+1);

		// Gauche
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.005); glVertex3f(positionX, positionY+1, positionZ);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.005); glVertex3f(positionX, positionY,   positionZ);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.060); glVertex3f(positionX, positionY,   positionZ+1);
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.060); glVertex3f(positionX, positionY+1, positionZ+1);

		// Droite
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.005); glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.005); glVertex3f(positionX+1, positionY  , positionZ+1);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.060); glVertex3f(positionX+1, positionY  , positionZ);
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.060); glVertex3f(positionX+1, positionY+1, positionZ);

		// Derri��re
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.005); glVertex3f(positionX+1, positionY+1, positionZ);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.005); glVertex3f(positionX+1, positionY  , positionZ);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.060); glVertex3f(positionX  , positionY  , positionZ);
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.060); glVertex3f(positionX  , positionY+1, positionZ);
	
		// Dessus
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.005); glVertex3f(positionX  , positionY+1, positionZ);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.005); glVertex3f(positionX  , positionY+1, positionZ+1);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.060); glVertex3f(positionX+1, positionY+1, positionZ+1);
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.060); glVertex3f(positionX+1, positionY+1, positionZ);

		// Dessous
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.005); glVertex3f(positionX+1,positionY, positionZ+1);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.005); glVertex3f(positionX  ,positionY, positionZ+1);
		glTexCoord2f(textureX[0]+0.060, textureY[0]+0.060); glVertex3f(positionX  ,positionY, positionZ);
		glTexCoord2f(textureX[0]+0.005, textureY[0]+0.060); glVertex3f(positionX+1,positionY, positionZ);

	glEnd();

	
}