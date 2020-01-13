
output:
	yt build

m1:
	cp build/bbc-microbit-classic-gcc/source/task3-combined.hex /media/$(USER)/MICROBIT

m2:
	cp build/bbc-microbit-classic-gcc/source/task3-combined.hex /media/$(USER)/MICROBIT1

init:
	yt target bbc-microbit-classic-gcc

clean:
	yt clean
