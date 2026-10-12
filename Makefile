
CXX = C:/msys64/ucrt64/bin/g++.exe
CXXFLAGS = -Wall -Wextra -std=c++17 -IC:/msys64/ucrt64/include
LDFLAGS = -LC:/msys64/ucrt64/lib -lraylib -lopengl32 -lgdi32 -lwinmm

TARGET = fire-doom-centre.exe
SRC = Fire_algo.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	del $(TARGET)
