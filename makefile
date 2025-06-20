BIN_PATH := ./bin
EXAMPLE_PATH := ./example
EXAMPLE_TARGET := example
WARNING := -Wall -Wextra
CXX_FLAGS := -std=c++17 -O3 -march=native
CXX := g++
RELEASE_FLAGS := $(CXX_FLAGS)
DEBUG_FLAGS := $(CXX_FLAGS) $(WARNING) -DDEBUG

.PHONY: all build debug clean

all: clean build

build: $(BIN_PATH)/$(EXAMPLE_TARGET)

debug: $(BIN_PATH)/$(EXAMPLE_TARGET)_DEBUG

clean:
	rm -rf $(BIN_PATH)

$(BIN_PATH)/$(EXAMPLE_TARGET): $(EXAMPLE_PATH)/example-main.cpp | $(BIN_PATH)
	$(CXX) $(RELEASE_FLAGS) -o $@ $<

$(BIN_PATH)/$(EXAMPLE_TARGET)_DEBUG: $(EXAMPLE_PATH)/example-main.cpp | $(BIN_PATH)
	$(CXX) $(DEBUG_FLAGS) -o $@ $<

$(BIN_PATH):
	mkdir -p $(BIN_PATH)
