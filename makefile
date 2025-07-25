SRC_DIR := ./code
OBJ_DIR := .
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

LDFLAGS := -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CXXFLAGS := -g -Wall -fpermissive -std=c++17 -I/opt/homebrew/include
TARGET := PortScanner

$(TARGET): $(OBJ_FILES)
	g++ -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CXXFLAGS) -c -o $@ $<

run:
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
