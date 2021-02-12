APP:=		NativeTtt
SOURCE:=	src/*.cpp
BINARY:=	bin/$(APP)
LIBRARIES:=	-lsfml-graphics -lsfml-system -lsfml-window
CXXFLAGS:=	-Wall -s -O3

all: $(BINARY)

run: $(BINARY)
	./$(BINARY)

$(BINARY):
	rm -rf bin
	mkdir  bin
	g++ -o $(BINARY) $(CXXFLAGS) $(SOURCE) $(LIBRARIES)

clear: 
	rm -f $(BINARY)

