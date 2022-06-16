CC := g++ -std=c++11

quizMaker.out: main.o functions.o Exam.o Question.o Single_answer.o Multiple_answer.o Short_answer.o
	$(CC) main.o functions.o Exam.o Question.o Single_answer.o Multiple_answer.o Short_answer.o -o quizMaker.out

main.o: functions.hpp Exam.hpp main.cpp
	$(CC) -c main.cpp -o main.o

Exam.o: Exam.hpp functions.hpp Question.hpp Single_answer.hpp Short_answer.hpp Multiple_answer.hpp Exam.cpp
	$(CC) -c Exam.cpp -o Exam.o

Question.o: Question.hpp functions.hpp Question.cpp
	$(CC) -c Question.cpp -o Question.o

Single_answer.o: Single_answer.hpp functions.hpp Question.hpp Single_answer.cpp
	$(CC) -c Single_answer.cpp -o Single_answer.o

Multiple_answer.o: Multiple_answer.hpp functions.hpp Question.hpp functions.hpp Multiple_answer.cpp
	$(CC) -c Multiple_answer.cpp -o Multiple_answer.o

Short_answer.o: Short_answer.hpp functions.hpp Question.hpp Short_answer.cpp
	$(CC) -c Short_answer.cpp -o Short_answer.o

functions.o: functions.hpp functions.cpp
	$(CC) -c functions.cpp -o functions.o

clean:
	rm *.o *.out
