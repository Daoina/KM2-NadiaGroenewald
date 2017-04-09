#include "ofApp.h"


void ofApp::setup(){
    image.load("shib.jpg");
    
    for (int y = 0; y < MESH_HEIGHT; y++) {
        for (int x = 0; x < MESH_WIDTH; x++){
            
            ofPoint vertex = ofPoint((x - MESH_WIDTH/2) * MESH_SIZE,
                                     (y - MESH_HEIGHT/2) * MESH_SIZE, 0);
            
            mesh.addVertex(vertex);
            
            ofPoint texCoord = ofPoint(x* (IMAGE_WIDTH/IMAGE_WIDTH),
                                       y * (IMAGE_HEIGHT/IMAGE_HEIGHT));
            mesh.addTexCoord(texCoord);
        }
    }
    
    for (int y = 0; y < MESH_HEIGHT -1; y++) {
        for (int x = 0; x < MESH_WIDTH -1; x++){
            int vertex1 = x + MESH_WIDTH * y;
            int vertex2 = x + 1 + MESH_WIDTH * y;
            int vertex3 = x + MESH_WIDTH * (y +1);
            int vertex4 = x + 1 + MESH_WIDTH * (y +1);
            
            mesh.addTriangle(vertex1, vertex2, vertex3);
            mesh.addTriangle(vertex4, vertex4, vertex3);
        }
    }
}


void ofApp::update(){
    for (int y = 0; y < MESH_HEIGHT; y++) {
        for (int x = 0; x < MESH_WIDTH; x++){
            int i = x + MESH_WIDTH * y;
            
            ofPoint vertex = mesh.getVertex(i);
            
            vertex.z = ofNoise(x * 0.05,
                               y * 0.05,
                               ofGetElapsedTimeMillis() * 0.5) *100;
            
            mesh.setVertex(i, vertex);
        }
    }
}


void ofApp::draw(){
    ofBackground(ofColor::black);
    cam.setVFlip(true);
    cam.begin();
    
    image.bind();
    mesh.draw();
    image.unbind();
    
    cam.end();
}
