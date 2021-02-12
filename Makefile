APP:=		NativeTtt
SOURCE:=	src/*.cpp
BINARY:=	bin/$(APP)
LIBRARIES:=	-lsfml-graphics -lsfml-system -lsfml-window
CXXFLAGS:=	-Wall -s -O3

all: $(BINARY)

run: $(BINARY)
	./$(BINARY)

$(BINARY):
	@echo "Creating binary directory $(BINARY)" 
	rm -rf bin
	mkdir  bin
	@echo "Building sources"
	g++ -o $(BINARY) $(CXXFLAGS) $(SOURCE) $(LIBRARIES)
	@echo "Done."

clear: 
	rm -f $(BINARY)

