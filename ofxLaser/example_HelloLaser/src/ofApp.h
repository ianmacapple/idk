#pragma once

#include "ofMain.h"
#include "ofxLaserManager.h"
#include "ofxLaserDacEtherdream.h"
#include "ofxLaserDacLaserdock.h"
#include "ofxLaserDacIDN.h"

#include "ofxGui.h"

#define USE_ETHERDREAM
//#define USE_IDN
//#define USE_LASERDOCK

class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed  (int key);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	
	void showLaserEffect(int effectnum);
	
	ofParameter<int> currentLaserEffect;
	int numLaserEffects; 
	
	ofxLaser::Manager laser;
	
#ifdef USE_ETHERDREAM
	ofxLaser::DacEtherdream dac;
#endif
#ifdef USE_IDN
	ofxLaser::DacIDN dac;
#endif
#ifdef USE_LASERDOCK
	ofxLaser::DacLaserdock dac;
#endif
	
	bool drawingShape = false;
	int laserWidth;
	int laserHeight;
    
	std::vector<ofPolyline> polyLines;
		
	float elapsedTime; 

    ofParameter<ofColor> color;
};

