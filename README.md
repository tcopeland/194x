A clone of the 2D top-to-bottom scroller "1942".

#### You are playing 194x

From a terminal:

```bash
make
./194x
```

At the menu screen:

- hit 'p' to play
- hit 'q' to quit

When playing:

- arrow keys move
- spacebar fires

#### You are modifying 194x

Make sure you using the clang on OS X, not some random GCC version which you installed in /usr/local.  Otherwise you might get errors about a lack of support for `-fpascal-strings` and the inability of GCC to find an Objective-C compiler.

Docs on my machine are at file:///Users/tomcopeland/src/SDL2-2.0.1/Xcode/XcodeDocSet/html/index.html.  I generated them with `cd /Users/tomcopeland/src/SDL2-2.0.1/Xcode/XcodeDocSet && doxygen`.

Some not-so-helpful STL docs are at file:///usr/local/gcc-4.9/include/c++/4.9.0/bits/html/index.html; I generated them with `cd /usr/local/gcc-4.9/include/c++/4.9.0/bits/ && doxygen -g && doxygen`.

#### TODO 

* Waves of enemies - e.g, 6 planes come down from upper left and exit on upper right
* * pass a Path object into each Enemy
* Player strike puts game into 'between lives' state
* * explosion is bigger
* * enemies disappear
* * ideally a number of planes decrements
* * * display number of planes remaining
* Enemy plane shoots
* Enemy planes move left/right
* Explosion goes more slowly
* Enemy bullet affects player sprite
* Destruction of enemy plane leaves power up
* * power up types: multiple bullets, faster moves, a bomb, faster rate of fire
* Player has limited number of lives
* Implement 'paused' state
* Pressing 's' (or 'm'?) during gameplay mutes sound

#### Some helpful links:

To add new sounds, record them in audacity and export as type: WAV (Microsoft) signed 16 bit PCM

http://www.sdltutorials.com/sdl-tutorial-basics
http://wiki.libsdl.org/moin.fcg/SDL1.2Tutorials
http://wiki.libsdl.org/moin.fcg/Tutorials
http://lazyfoo.net/SDL_tutorials/lesson01/index2.php
http://www.siteduzero.com/forum/sujet/sdl-conflicting-types-for-a-function-53095
http://wiki.libsdl.org/SDL_Keycode
http://cs.brown.edu/~jak/proglang/cpp/stltut/tut.html

Art:

http://www.widgetworx.com/widgetworx/portfolio/spritelib.html
http://opengameart.org/art-search?keys=ww2

Demo:

http://www.dailymotion.com/video/xyr530_1942-arcade-demo_videogames
