mandelbrot: mandelbrot.cpp stb_image_write.o imageLib.o 
	g++ mandelbrot.cpp stb_image_write.o imageLib.o -o mandelbrot
stb_image_write.o: stb_image_write.cpp
	g++ stb_image_write.cpp -c
stb_image_write.cpp: stb_image_write.h
	touch stb_image_write.cpp
	echo "#define STB_IMAGE_WRITE_IMPLEMENTATION\n" > stb_image_write.cpp
	echo "#include \"stb_image_write.h\"" >> stb_image_write.cpp
imageLib.o: imageLib.cpp
	g++ imageLib.cpp -c
clean:
	rm mandelbrot stb_image_write.o imageLib.o
