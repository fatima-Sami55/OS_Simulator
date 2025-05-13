CC = g++
CFLAGS = -Wall -pthread
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
STORAGE_DIR = storage

TASKS = calculator notepad clock calendar create_file delete_file move_file copy_file file_info task_manager music_player number_guessing print_file instruction_guide dice_roller

all: $(BIN_DIR) $(STORAGE_DIR) main $(TASKS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(STORAGE_DIR):
	mkdir -p $(STORAGE_DIR)

main: $(SRC_DIR)/main.cpp $(SRC_DIR)/os.cpp $(SRC_DIR)/tasks.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $^ -o $(BIN_DIR)/os_simulator

$(TASKS): %: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $(BIN_DIR)/$@

clean:
	rm -rf $(BIN_DIR) $(STORAGE_DIR)