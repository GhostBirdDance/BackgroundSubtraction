#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.initGrabber(ofGetScreenWidth(), ofGetScreenHeight());
    background.setLearningTime(1000);
    background.setThresholdValue(30);
    
    mask.setupShaderFromFile(GL_FRAGMENT_SHADER, "mask.frag");
    mask.linkProgram();
    automataShader.setupShaderFromFile(GL_FRAGMENT_SHADER, "automata.frag");
    automataShader.linkProgram();

    buffer.allocate(1024,768, GL_RGB);

}
void ofApp::renderFrame(int width, int height) {
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
    glTexCoord2f(width, 0); glVertex3f(width, 0, 0);
    glTexCoord2f(width, height); glVertex3f(width, height, 0);
    glTexCoord2f(0, height);  glVertex3f(0,height, 0);
    glEnd();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    grabber.update();
    
    if (grabber.isFrameNew()){
        background.update(grabber, thresholded);
        thresholded.update();
    }
    
    buffer.dst->begin();
    automataShader.begin();
    automataShader.setUniformTexture("src", buffer.src->getTexture(), 1);
    automataShader.setUniform1i("born", 0);
    automataShader.setUniform4i("born1", 1,0,1,0);
    automataShader.setUniform4i("born2", 1, 0, 1, 0);
    automataShader.setUniform1i("survive", 0);
    automataShader.setUniform4i("survive1", 1,0,1,0);
    automataShader.setUniform4i("survive2", 1, 0, 1, 0);
    renderFrame(buffer.dst->getWidth(), buffer.dst->getHeight());
    buffer.dst->end();
    buffer.swap();
    automataShader.end();

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    mask.begin();
    mask.setUniformTexture("mask", thresholded.getTexture(), 1);
    grabber.draw(0,0);
    mask.end();
    buffer.src->draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' ') {
        background.reset();
    }
    if (key == 'u') {
        buffer.src->begin();
        thresholded.draw(0,0);
        buffer.src->end();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
