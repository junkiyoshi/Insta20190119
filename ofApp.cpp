#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	float radius = 35;
	float span = 120;
	for (int x = span * 0.5; x < ofGetWidth(); x += span) {

		for (int y = span * 0.5; y < ofGetHeight(); y += span) {

			for (int i = 0; i < 5; i++) {

				ofBeginShape();
				for (int deg = 0; deg < 360; deg += 1) {

					glm::vec2 base = glm::vec2(x, y) + glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
					float noise_value = ofNoise(base.x * 0.03, base.y * 0.03, ofGetFrameNum() * 0.01);
					float tmp_radius = radius + ofMap(noise_value, 0, 1, 0, 30) * i * 0.2;
				
					ofVertex(glm::vec2(x, y) + glm::vec2(tmp_radius * cos(deg * DEG_TO_RAD), tmp_radius * sin(deg * DEG_TO_RAD)));
				}
				ofEndShape(true);
			}
		}
	}
}
//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}