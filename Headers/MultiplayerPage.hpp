//
//  MultiplayerPage.hpp
//  GamerServerClientCombo
//
//  Created by Thomas Redding on 10/2/15.
//  Copyright © 2015 Thomas Redding. All rights reserved.
//

#ifndef MultiplayerPage_cpp
#define MultiplayerPage_cpp

#include "Page.hpp"

class MultiplayerPage : public Page {
public:
	MultiplayerPage(int *currentPageNumber, sf::RenderWindow *w, sf::Font *myFont);
	bool keyPressed(sf::Keyboard::Key keyCode) {return true;};
	bool keyReleased(sf::Keyboard::Key keyCode) {return true;};
	bool mouseMoved(int x, int y) {return true;};
	bool mousePressed(sf::Mouse::Button button, int x, int y);
	bool mouseReleased(sf::Mouse::Button button, int x, int y);
	bool mouseWheeled(int delta, int x, int y) {return true;};
	bool resized(unsigned int width, unsigned int height) {return true;};
	bool textEntered(sf::Uint32 character);
	bool otherEvent(sf::Event event) {return true;};
	void closing() {};
	bool draw();
	bool update() {return true;};
	void tcpMessageReceived(std::string message, long timeStamp) {};
	void udpMessageReceived(std::string message, long timeStamp) {};
private:
	Button backButton;
	Button serverButton;
	Button clientButton;
};

#endif /* MultiplayerPage_cpp */
