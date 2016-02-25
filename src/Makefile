EXE=tldrer

CXX=g++
CXXFLAGS=-W -Wall -Wextra -Werror -std=gnu++11 -ggdb3 -O0

LINKER=g++
LINKERFLAGS=-std=gnu++11
LINKS=

OBJS=main.o msg.o path.o section.o title.o description.o examples.o references.o tldr.o

all: $(EXE) $(OBJS)

$(EXE): $(OBJS)
	$(LINKER) $(LINKERFLAGS) $(LINKS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(EXE) $(OBJS)

