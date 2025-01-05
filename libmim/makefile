OBJ:=libmim
CXXFLAGS=-O3 -std=c++20 -DDEBUG -Wno-psabi
#CXXFLAGS=-O0 -g -std=c++20 -DDEBUG -Wno-psabi
CPPS:=$(wildcard *.cpp)
HS:=$(wildcard *.h)
OBJS:=$(patsubst %.cpp, %.o, $(CPPS))
INC:=

all: ${OBJ}.o

%.o: %.cpp
	$(CXX) -fPIC -Wno-psabi -c ${CXXFLAGS} $^ -pthread ${INC} -o $@

${OBJ}.o: ${OBJS}
	ld -r ${DOBJS} ${OBJS} -o ${OBJ}.o

clean:
	$(RM) -f *.o

.PHONY: clean all

