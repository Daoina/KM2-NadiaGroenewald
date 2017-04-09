#pragma once

#include "ofMain.h"

#define MESH_WIDTH 50
#define MESH_HEIGHT 50
#define MESH_SIZE 10

#define IMAGE_WIDTH 350
#define IMAGE_HEIGHT 280

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    ofMesh mesh;
    ofImage image;
    ofEasyCam cam;
};
