SOURCES=$(wildcard *.cc)

EXECUTABLES=$(SOURCES:.cc=.o)

all: $(EXECUTABLES)

%.o: %.cc
	g++ -Wall -Wpedantic -Wextra -Werror -o $@ $<

clean:
	rm $(EXECUTABLES)
