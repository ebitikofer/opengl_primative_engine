CC=g++

include ./Makefile.defs

OPTIONS+=-Wall

OBJECTS = $(patsubst %.cc,%,$(wildcard *.cc))
# OBJECTS = $(patsubst %.cc,%.o,$(wildcard *.cc))

all: $(OBJECTS)

# patterns to allow compilation of many c++ or c programs
.c:
	$(CC) $@.c $(InitShader) $(OPTIONS) $(LDLIBS) -o $@

.cc:
	$(CC) $@.cc $(InitShader) $(OPTIONS) $(LDLIBS) -o $@
	# $(CC) $@.cc $(InitShader) engine.o instance.o $(OPTIONS) $(LDLIBS) -o $@

# engine.o: engine.h engine.cc
# 	$(CC) engine.cc -c $(OPTIONS)
#
# instance.o: instance.h instance.cc
# 	$(CC) instance.cc -c $(OPTIONS)

clean:
	rm -f $(OBJECTS) *~

shader:
	$(MAKE) -C angel06/Common InitShader.o
