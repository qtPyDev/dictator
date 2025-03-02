CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0` -Wall -Wextra -I src/lib
LDFLAGS = `pkg-config --libs gtk+-3.0`

# define platform and output type
PLATFORM = linux
OUT_TYPE = $(if $(findstring windows,$(PLATFORM)),exe,out)

# define directories
SRC_DIR = src
BUILD_DIR = build
DIST_DIR = dist

# define source files
SRC_CJSON = $(SRC_DIR)/lib/cJSON.c
SRC_PROJ_EXPORT = $(SRC_DIR)/proj_export.c
SRC_WINDOW = $(SRC_DIR)/window.c

# define object files
OBJ_CJSON = $(BUILD_DIR)/cJSON.o
OBJ_PROJ_EXPORT = $(BUILD_DIR)/proj_export.o
OBJ_WINDOW = $(BUILD_DIR)/window.o

# define targets
TARGET = $(DIST_DIR)/dictator.$(OUT_TYPE)



all: $(TARGET)

$(TARGET): $(OBJ_WINDOW) $(OBJ_PROJ_EXPORT) $(OBJ_CJSON)
	@mkdir -p $(BUILD_DIR)
	$(CC) $^ $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_CJSON): $(SRC_CJSON)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean

clean:
	rm -rf $(BUILD_DIR)/* $(DIST_DIR)/*
