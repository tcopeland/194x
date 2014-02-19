A clone of the 2D top-to-bottom scroller "1942".

#### You are playing 194x

From a terminal:

```bash
make
./194x
```

#### You are modifying 194x

Make sure you using the clang on OS X, not some random GCC version which you installed in /usr/local.  Otherwise you might get errors about a lack of support for `-fpascal-strings` and the inability of GCC to find an Objective-C compiler.

Docs on my machine are at file:///Users/tomcopeland/src/SDL2-2.0.1/Xcode/XcodeDocSet/html/index.html. I generated them with:

```bash
cd /Users/tomcopeland/src/SDL2-2.0.1/Xcode/XcodeDocSet && doxygen
```

#### TODO 

* Menu state's quit label should quit game when clicked
* Implement state - paused
* SpriteParameters should know how many images a sprite series is composed of, vs Player.cpp dividing ticks by 3
* Fire bullet when player hits spacebar
* Make sound when player fires bullet
* Enemy plane onscreen, not affected by bullets
* Enemy plane moves
* Enemy plane disappears when hit by bullet
* Enemy plane explodes when hit by bullet
* Score appears at the top of the screen
* Score increments when enemy destroyed
* Enemy plane shoots
* Enemy bullet affects player sprite
* Destruction of enemy plane leaves power up

#### Some helpful links:

http://www.sdltutorials.com/sdl-tutorial-basics
http://wiki.libsdl.org/moin.fcg/SDL1.2Tutorials
http://wiki.libsdl.org/moin.fcg/Tutorials
http://lazyfoo.net/SDL_tutorials/lesson01/index2.php
http://www.siteduzero.com/forum/sujet/sdl-conflicting-types-for-a-function-53095

Art:

http://www.widgetworx.com/widgetworx/portfolio/spritelib.html
http://opengameart.org/art-search?keys=ww2

Demo:

http://www.dailymotion.com/video/xyr530_1942-arcade-demo_videogames
