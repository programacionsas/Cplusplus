CXX = g++


default: demo

demo: demo.cpp character.o encounter.o
	${CXX} $< -o $@ character.o encounter.o

character.o: character.cpp character.hpp
	${CXX} -c $< -o $@

encounter.o: encounter.cpp encounter.hpp
	${CXX} -c $< -o $@

.PHONY:
clean:
	${RM} *.o demo