
# glutapp makefile v1.0 - F. S. Velazquez 2012

SOURCES := $(shell echo $(./)*.cpp)
DEPENDS = $(SOURCES:.cpp=.d)
OBJECTS = $(SOURCES:.cpp=.o)
OS := $(shell uname)
PROGRAM = glutapp

#######################################################################

# OPTFLAGS = -g  # for debug
OPTFLAGS =  -O3 -s
CC       = g++
CFLAGS   = -Wall -Wno-format $(OPTFLAGS)

ifeq ($(strip $(OS)),Darwin)
	LDFLAGS = -framework GLUT -framework OpenGL
else
	LDFLAGS = -lGL -lglut
endif

#######################################################################

all: $(PROGRAM)

$(PROGRAM):$(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

clean:
	$(RM) $(OBJECTS) $(DEPENDS)
	$(RM) $(PROGRAM)
	$(RM) *~

#######################################################################

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

%.d: %.cpp
	$(CC) -MM $(CFLAGS) $< > $@

#######################################################################

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPENDS)
endif

#######################################################################
