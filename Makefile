t10:	main.o Student.o 
	g++ -o p8 main.o Student.o

main.o:	main.cc Student.h List.h 
	g++ -c main.cc

Student.o:	Student.cc Student.h
	g++ -c Student.cc

clean:
	rm -f *.o t10
