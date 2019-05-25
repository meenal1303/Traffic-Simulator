CC=g++
CFLAGS=-g -Wall
RM=/bin/rm -f

all:	main
Vechile.o:  Vechile.cpp
	${CC} ${CFLAGS} -c Vechile.cpp
Road.o:  Road.cpp
	${CC} ${CFLAGS} -c Road.cpp
update.o: update.cpp
	${CC} ${CFLAGS} -c update.cpp
vector.o: vector.cpp
	${CC} ${CFLAGS} -c vector.cpp
display1.o: display1.cpp
	${CC} ${CFLAGS} -c display1.cpp
display2.o: display2.cpp
	${CC} ${CFLAGS} -c display2.cpp
opengl_file.o: opengl_file.cpp
	${CC} ${CFLAGS} -c opengl_file.cpp
check_right_left.o: check_right_left.cpp
	${CC} ${CFLAGS} -c check_right_left.cpp
main.o:  main.cpp
	${CC} ${CFLAGS} -c main.cpp -lglut -lGLU -lGL
main: main.o Vechile.o Road.o update.o vector.o check_right_left.o opengl_file.o display1.o display2.o
	${CC} ${CFLAGS} -o main main.o update.o Vechile.o vector.o check_right_left.o display1.o display2.o Road.o opengl_file.o -lglut -lGLU -lGL
clean:
	${RM} *.o main 
	

