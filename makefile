BIN_PATH := ./bin
EXAMPLE_PATH := ./example
EXAMPLE_TARGET := example
WARNING := -Wall -Wextra
CXX_FLAGS := -std=c++17 -O3 -march=native
CXX_FLAGS_WIN := -std=c++17 -O3 -static
CXX := g++
CXX_WIN := x86_64-w64-mingw32-g++
RELEASE_FLAGS := $(CXX_FLAGS)
RELEASE_FLAGS_WIN := $(CXX_FLAGS_WIN)
DEBUG_FLAGS := $(CXX_FLAGS) $(WARNING) -DDEBUG

.PHONY: all build-linux debug clean build-win

all: clean build-linux build-win

build-linux: $(BIN_PATH)/$(EXAMPLE_TARGET)

build-win: $(BIN_PATH)/$(EXAMPLE_TARGET).exe

debug: $(BIN_PATH)/$(EXAMPLE_TARGET)_DEBUG

clean:
	rm -rf $(BIN_PATH)

$(BIN_PATH)/$(EXAMPLE_TARGET): $(EXAMPLE_PATH)/example-main.cpp | $(BIN_PATH)
	$(CXX) $(RELEASE_FLAGS) -o $@ $<

$(BIN_PATH)/$(EXAMPLE_TARGET).exe: $(EXAMPLE_PATH)/example-main.cpp | $(BIN_PATH)
	$(CXX_WIN) $(RELEASE_FLAGS_WIN) -o $@ $<

$(BIN_PATH)/$(EXAMPLE_TARGET)_DEBUG: $(EXAMPLE_PATH)/example-main.cpp | $(BIN_PATH)
	$(CXX) $(DEBUG_FLAGS) -o $@ $<

$(BIN_PATH):
	mkdir -p $(BIN_PATH)
