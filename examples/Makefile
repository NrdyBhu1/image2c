ifdef OS
	CC		= ../bin/image2c.exe
else
	CC		= ../bin/image2c
endif

all install: wallpaper1 wallpaper2

wallpaper1: Wallpaper1.jpg
	$(CC) Wallpaper1.jpg > Wallpaper1.h

wallpaper2: Wallpaper2.png
	$(CC) Wallpaper2.png > Wallpaper2.h
