COMPILER_FLAGS = -g -stdlib=libc++ -std=c++0x
LIB_FLAGS = -I/Library/Frameworks/SFML.framework/Headers -framework Foundation -framework SFML -framework sfml-system -framework sfml-window -framework sfml-graphics -framework sfml-network
SPECIAL_FILES = Sources/ResourcePath.mm
CPP_FILES = $(wildcard Sources/*.cpp)
CREATION_PATH = TestApp/Contents/MacOS/game

all:
	g++ -o $(CREATION_PATH) $(COMPILER_FLAGS) $(LIB_FLAGS) $(SPECIAL_FILES) $(CPP_FILES)
