SRCDIR = ./src/
HEADERSDIR = ./headers

Main : Main.o Car.o Controls.o Debug.o Graphics.o Locate.o Points.o Road.o Words.o
	g++ Main.o Car.o Controls.o Debug.o Graphics.o Locate.o Points.o Road.o Words.o -o Main

Main.o :
	g++ Survival-Race.cpp -I $(HEADERSDIR) -c -o Main.o

Car.o :
	g++ $(SRCDIR)Car.cpp -I $(HEADERSDIR) -c

Controls.o :
	g++ $(SRCDIR)Controls.cpp -I $(HEADERSDIR) -c

Debug.o :
	g++ $(SRCDIR)Debug.cpp -I $(HEADERSDIR) -c

Graphics.o :
	g++ $(SRCDIR)Graphics.cpp -I $(HEADERSDIR) -c

Locate.o :
	g++ $(SRCDIR)Locate.cpp -I $(HEADERSDIR) -c

Points.o :
	g++ $(SRCDIR)Points.cpp -I $(HEADERSDIR) -c

Road.o :
	g++ $(SRCDIR)Road.cpp -I $(HEADERSDIR) -c

Words.o :
	g++ $(SRCDIR)Words.cpp -I $(HEADERSDIR) -c

clean :
	del Main.exe *.o