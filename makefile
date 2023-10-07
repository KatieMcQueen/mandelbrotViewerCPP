mandelbrot: mandelbrot.cpp stb_image_write.o imageLib.o complexLib.o
	g++ mandelbrot.cpp stb_image_write.o imageLib.o complexLib.o -o mandelbrot -Ofast -Wall -Wextra -Werror
stb_image_write.o: stb_image_write.cpp
	g++ stb_image_write.cpp -c
stb_image_write.cpp: stb_image_write.h
	touch stb_image_write.cpp
	echo "#define STB_IMAGE_WRITE_IMPLEMENTATION\n" > stb_image_write.cpp
	echo "#include \"stb_image_write.h\"" >> stb_image_write.cpp
imageLib.o: imageLib.cpp
	g++ imageLib.cpp -c
complexLib.o: complexLib.cpp
	g++ complexLib.cpp -c
clean:
	rm mandelbrot stb_image_write.o imageLib.o complexLib.o
