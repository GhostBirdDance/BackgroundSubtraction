#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.initGrabber(ofGetScreenWidth(), ofGetScreenHeight());
    background.setLearningTime(1000);
    background.setThresholdValue(30);
    
    mask.setupShaderFromFile(GL_FRAGMENT_SHADER, "mask.frag");
    mask.linkProgram();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    grabber.update();
    
    if (grabber.isFrameNew()){
        background.update(grabber, thresholded);
        thresholded.update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    mask.begin();
    mask.setUniformTexture("mask", thresholded.getTexture(), 1);
    grabber.draw(0,0);
    mask.end();
    thresholded.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' ') {
        background.reset();
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
