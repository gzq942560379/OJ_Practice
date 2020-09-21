SRC_DIR = $(shell find . -type d)

vpath %.cpp $(SRC_DIR)

SRC = $(foreach d,$(SRC_DIR), $(wildcard $(d)/*.cpp) )

TEST_SRC = $(wildcard $(SRC_DIR)/*.cpp)
TEST_OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(TEST_SRC) )
TEST_BIN = $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%, $(TEST_SRC) )

$(TEST_OBJ) : $(OBJ_DIR)/%.o : %.cpp
	$(CC) -c -o $@ $^ $(CFLAGS)

$(TEST_BIN) : $(BIN_DIR)/% : $(OBJ_DIR)/%.o
	$(CC) -o $@ $^ $(CFLAGS) 

test :: $(TEST_BIN)