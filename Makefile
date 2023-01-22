appname := verlet_engine

CXX := g++
CXXFLAGS := -std=c++17
LDLIBS := -lsfml-graphics -lsfml-window -lsfml-system

srcfiles := $(shell find . -name "*.cpp")
objfiles := $(subst .cpp,.o,$(srcfiles))

all: $(appname)

$(appname): $(objfiles)
	$(CXX) $(CXXFLAGS) -o $(appname) $(objfiles) $(LDLIBS)

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	rm -f $(objfiles)

distclean: clean
	rm -f *~ .depend

include .depend