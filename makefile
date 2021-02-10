SRC_DIR := ./src
OBJ_DIR := ./obj
INC_DIR := ./include
SRC_FILES := *.c
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS := -g
CPPFLAGS := -g -I$(INC_DIR)
CXXFLAGS := 
.PHONY: clean run main

main: $(OBJ_FILES)
	@echo Making main program
	gcc $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo Compiling SRC files into Object Files
	gcc $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ_FILES) *.exe

run: main
	./main