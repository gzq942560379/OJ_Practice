SRC_DIR = $(shell find . -type d)

vpath %.cpp $(SRC_DIR)

TEST_SRC = $(foreach d,$(SRC_DIR), $(wildcard $(d)/*.cpp) )
TEST_OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(TEST_SRC)))
TEST_BIN = $(patsubst %.cpp, $(BIN_DIR)/%, $(notdir $(TEST_SRC)) )

$(TEST_OBJ) : $(OBJ_DIR)/%.o : %.cpp
	$(CC) -c -o $@ $^ $(CFLAGS)

$(TEST_BIN) : $(BIN_DIR)/% : $(OBJ_DIR)/%.o
	$(CC) -o $@ $^ $(CFLAGS) 

test :: $(TEST_BIN)