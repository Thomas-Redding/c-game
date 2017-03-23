# c-game

This is a um... game in C++ using SFML. I'd recommend ignoring this repo, because I have absolutely no idea whether/where I'll be going from here. So far, the main accomplishment is a LAN multiplayer lag compensation framework, which *should* make a wide variety of multiplayer 2d games easier to make.

Currently the repo is set up to develop a MacOS app, including the SFML frameworks. To compile changes to the code, simply run the provided Makefile. This will overwrite TestApp/Contents/MacOS/game. If you want to include additional resources (images, sounds, fonts, etc.), then put those in TestApp/Contents/Resources.

You can test the app by simply running TestApp/Contents/MacOS/game; however, if you add the extension ".app" to TestApp, the OS should interpret the folder as an application, and you should be able to run it on any computer running a modern version of macOS.
