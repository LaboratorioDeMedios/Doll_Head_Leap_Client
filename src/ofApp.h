#pragma once

#include "ofMain.h"
#include "ofxLeapMotion.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define PORT 12345


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void exit();
    
    ofxLeapMotion leap;
	vector <ofxLeapMotionSimpleHand> simpleHands;
    
    vector <int> fingersFound;
    
	ofEasyCam cam;
	ofLight l1;
	ofLight l2;
	ofMaterial m1;
    
    ofxOscSender sender;
    
    
};
