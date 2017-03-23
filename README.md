# c-game

# Set Up

This is a um... game in C++ using SFML. I'd recommend ignoring this repo, because I have absolutely no idea whether/where I'll be going from here. So far, the main accomplishment is a LAN multiplayer lag compensation framework, which *should* make a wide variety of multiplayer 2d games easier to make.

Currently the repo is set up to develop a MacOS app, including the SFML frameworks. To compile changes to the code, simply run the provided Makefile. This will overwrite TestApp/Contents/MacOS/game. If you want to include additional resources (images, sounds, fonts, etc.), then put those in TestApp/Contents/Resources.

You can test the app by simply running TestApp/Contents/MacOS/game; however, if you add the extension ".app" to TestApp, the OS should interpret the folder as an application, and you should be able to run it on any computer running a modern version of macOS.

## Overview of Code

The principle insight here is that singleplayer games are just special cases of multiplayer games, so the framework treats the game as always being multiplayer. Therefore, there are two important threads, the client's and the server's.

We start in main(), which starts three threads:
1. the main thread itself, which simply runs the client's side
2. mainServerThread, which runs the server
3. tcpServerThread, which listens for TCP connections from clients and passes these on to mainServerThread

The three threads communicate through a combination of sockets and two shared objects. Periodically, various classes on the client side reference NetworkClock, which is used to help perform lag compensation. We're going to ignore this Network clock and the 3rd thread (which are both relatively simple) and focus on the client and main server threads.

### Client
The client side consists of a loop that almost exlusively calls methods in the Client class. These methods consist of
1. a variety of methods to respond to user input (mouse moves, key presses, etc.)
2. draw() - which draws to the screen
3. update() - which runs once per frame
4. networkUpdate()

This 4th point bears explaining further. The Client class inherits from NetworkClient, which implements networkUpdate(). This method, in turn, calls tcpMessageReceived() and udpMessageReceived() whenever it receives information from the server. The Client class needs to implement these two methods.

I've organized the Client into a set of Page objects to implement the main menu. Generally when a user performs an action, that information is passed to the currently visible Page. The various Page objects make use of a variety of widgets (TextBox, Button, IpTextBox). The GameClient class inherits from Page and is probably the most intersting page of the lot.

GameClient runs the actual game, but can be largely ignored. Instead, the developer needs to focus on the InputState, Entities, View, and SystemsHandler classes.

The InputState contains the state of the mouse, keyboard, etc. at a particular frame. This information is provided for you.

The Entities class has no methods, but contains the data needed to reconstruct the world at a particular point in the past. This is edited by the SystemsHandler class based on the InputState and server information.

The View and SystemsHandler classes are the ones you will be working the most with. In the former, you need merely implement draw() to draw a particular Entiteis object and resized() to deal with resizing of the window as you desire.

SystemsHandler is where the vast majority of your coding will take place. Once you provide the methods for modifying Entities given user input and world-interaction (AI, physics, etc.), then the lag compensation methods working magically in the background will take care of the rest.

### Server

The server simply sets up the game and then runs magical lag compensation. Implementing SystemsHandler will automatically update your server code too.
