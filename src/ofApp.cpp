#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.initGrabber(ofGetScreenWidth(), ofGetScreenHeight());
    background.setLearningTime(45);
    background.setThresholdValue(30);

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
    
    //grabber.draw(0,0);
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
