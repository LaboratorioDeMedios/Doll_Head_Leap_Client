#include "ofApp.h"


void ofApp::setup(){

    ofSetFrameRate(60);
    ofSetVerticalSync(true);
	ofSetLogLevel(OF_LOG_VERBOSE);
    
	leap.open();
    
	l1.setPosition(200, 300, 50);
	l2.setPosition(-200, -200, 50);
    
	cam.setOrientation(ofPoint(-20, 0, 0));
    
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);



    
}


void ofApp::update(){
    fingersFound.clear();

    simpleHands = leap.getSimpleHands();

     if(leap.isFrameNew() && simpleHands.size()){
         leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
         leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
         leap.setMappingZ(-150, 150, -200, 200);

      //   for(int i = 0; i < simpleHands.size(); i++){
             
    //     }
    
     }
    
    
    leap.markFrameAsOld(); 	//IMPORTANT! - tell ofxLeapMotion that the frame is no longer new.
}


void ofApp::draw(){

    ofDisableLighting();
    ofSetColor(200);
    ofBackground(0);

	ofDrawBitmapString("hand doll client\nLeap Connected? " + ofToString(leap.isConnected()), 20, 20);

    cam.begin();
    
    ofEnableLighting();
	l1.enable();
	l2.enable();

    

    
    for(int i = 0; i < simpleHands.size(); i++){
    //    simpleHands[i].debugDraw();
        
        
     /*   ofPushMatrix();
        ofTranslate(simpleHands[i].handPos);
        
     
        ofVec3f dir = simpleHands[i].handPos - simpleHands[i].handNormal;
        ofPoint end = simpleHands[i].handPos + dir.scale(5);
        
        ofQuaternion q;
        q.makeRotate(ofPoint(0, -1, 0), simpleHands[i].handNormal); // get hand normal
        
        ofQuaternion a;
        a.makeRotate(ofPoint(0, 1, 0), ofPoint(0, 0, 1));
        q*=a;
        
        ofMatrix4x4 m;
        q.get(m);
        glMultMatrixf(m.getPtr()); // apply the rotation
        
        ofDrawCone(0, 0, 0, 10, 30);
        
        ofPopMatrix();
      */
        
        for(int j = 0; j < simpleHands[i].fingers.size(); j++){
            ofDrawArrow(simpleHands[i].handPos, simpleHands[i].fingers[j].pos, 10);
        }
        

    }
    
    ofVec3f fingerDir;
    
    // i'll only use the first hand's first finger, doesn't matter which one it is.
    if (simpleHands.size() > 0) {
        if (simpleHands[0].fingers.size() > 0) {
            fingerDir = simpleHands[0].fingers[0].pos - simpleHands[0].handPos;
        }
    }
    
    
    
    
    cam.end();
}

void ofApp::exit() {
    leap.close();
}

void ofApp::keyPressed(int key){

}


void ofApp::keyReleased(int key){

}


void ofApp::mouseMoved(int x, int y ){

}


void ofApp::mouseDragged(int x, int y, int button){

}


void ofApp::mousePressed(int x, int y, int button){

}


void ofApp::mouseReleased(int x, int y, int button){

}


void ofApp::windowResized(int w, int h){

}


void ofApp::gotMessage(ofMessage msg){

}


void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
