#include "ofMain.h"
#include "ofAppGlutWindow.h"

#include "ofxAbsoluteFrame.h"

ofxAbsoluteFrame absoluteFrame;

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int);
};

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(0);
    ofSetColor(ofColor::white);
    
    ofSetFrameRate(60);
    absoluteFrame.setup(60.0f);
}

//--------------------------------------------------------------
void ofApp::update()
{
    absoluteFrame.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ostringstream oss;
    oss << "this is absolute frame based on time since app launched   : "
    << absoluteFrame.getFrame() << endl;
    oss << "this is incremented frame in each ofBaseApp::update method: "
    << ofGetFrameNum();
    ofDrawBitmapString(oss.str(), ofPoint(38.0f, 26.0f));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int)
{
    absoluteFrame.reset();
}

//--------------------------------------------------------------
int main(){
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 580, 60, OF_WINDOW);
	ofRunApp(new ofApp());
}
