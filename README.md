This library is a mandelbrot viewer. It can render a visualization of the mandelbrot set to a PNG image. 
THis is a learning project writted by a single student outside and ahead of the course content. The code is messy and almost certainly contains undiscovered and/or undocumented bugs. Use at your own risk.

At time of writing there are two pieces of code pulled from external sources.
stb_image_write.h is a single header c library in the public domain that's used to provide the program with image creation capabilities. 
It is available at: https://github.com/nothings/stb
Additionally the color value table from the matplotlib colormap twilight is used to color the image. It has been converted to c++ syntax. No other code from twilight is used. As far as I can tell twilight is liscensed under the bsd-3 liscense, which permits this type of use. The text of that liscense is available in colormaps.cpp.

Things I learned:
This was my first time working with structs and my first time working with classes in years. 
This is also my first experiment with dynamically allocated memory. I found some of the syntax tricky and unintuitive, but in the end I'm fairly happy with the small wrapper library I made.
This was my first time working with makefiles. I found the process reasonably intuitive and easy for a project of this size. I did learn that if a file gets renamed to change that name in the makefile with a find and replace, manual editing is prone to errors.
This was also the first time in a while doing any serious work with git, and my first time doing serious work with git across two machines. 

Areas for improvement:
The ui sucks and there isn't a nice way to put it. currently all values have to be edited in the source code and recompiled. Possible future improvements are to request values from the user at runtime, and accept commandline arguments. Even this solution isn't great as most users, including myself, don't have a great grasp on navigating a complex plane and it isn't readily apparent what coordinates to change to get an interesting region with nice scaling.
An interesting potential user interface would require a radical expansion of the architecture, but might be worth pursuing. Use a library like ncurses to draw a very low resolution fractal to the users terminal. Commands could be entered to pan or zoom a certain ammount relative to the user's current viewing selection. Then a user could issue a command to render a higher resolution image to an image on disk. It might also be possible for a user to enter a command to put a grid onscreen showing relative positons, enabling easy exploration of the fractal up to the limits of the precision avaiable to the program.
The resolution on the fractal also isn't great at the moment. At the interesting regions of higher complexity the pixels next to each other have different enough values that they "jump" in clolor values. This means that the large structure of the fractal can be clearly seen, but the interesting details of the chaotic geometry near the borders of the fractal become and unreadable pixelated mess. 
Unfortunately I'm not entirely sure which approach to take and am currently exploring options to Improve the rendering of chaotic regions. The next atempt will likely be to oversample the region around each pixel and average the results. Unfortunately I'm skeptical this will actuall solve the underlying issue and will significanly increase runtimes.
I'd also like to explore realtime rendering and interactivity, but those introduce significant complexity with shader coding and ui libraries respectively. I don't expect to explore those paths in the near future.

Image gallery:

The first output
![First output](https://github.com/KatieMcQueen/mandelbrotViewerCPP/blob/master/images/firstOutput.png)

The first colormap test
![First color](https://github.com/KatieMcQueen/mandelbrotViewerCPP/blob/master/images/colormapFirstTest.png)

The current final product
![Final](https://github.com/KatieMcQueen/mandelbrotViewerCPP/blob/master/images/twilightBackground.png)
