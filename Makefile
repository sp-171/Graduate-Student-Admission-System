#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, student.o, domestic.o, international.o, toefl.o and stu_sort.o to executable main
main: main.o student.o domestic.o international.o stu_sort.o toefl.o
	g++ -g -o main main.o student.o domestic.o international.o stu_sort.o toefl.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c student.cpp

#compile the domestic.cpp to domestic.o
domestic.o: domestic.cpp
	g++ -g -c domestic.cpp

#compile the international.cpp to international.o
international.o: international.cpp
	g++ -g -c international.cpp

#compile the stu_sort.cpp to stu_sort.o
stu_sort.o: stu_sort.cpp
	g++ -g -c stu_sort.cpp

# #compile the toefl.cpp to toefl.o
# toefl.o: toelf.cpp
# 	g++ -g -c toefl.cpp

#remove built files
clean:
	rm -rf main main.o student.o domestic.o international.o stu_sort.o toefl.o *~
