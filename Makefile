CC ?= clang
CFLAGS := -std=c99 -Wall -Werror -O3
CFLAGS += $(shell pkg-config sdl2 --cflags)
LDFLAGS := $(shell pkg-config sdl2 --libs)

BIN_DIR := bin
OBJ_DIR := build
SRC_DIR := src
DESTDIR ?= /usr/local/bin

TARGET_NAME := jade-test
TARGET := $(BIN_DIR)/$(TARGET_NAME)

SRC := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/Jade/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
DEP := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.d, $(SRC))

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(@D)
	@printf "  LD $(notdir $@)\n"
	@$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@printf "  CC $<\n"
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP)

.PHONY: install
install: $(TARGET)
	@install -m 755 $(TARGET) $(DESTDIR)

.PHONY: format
format:
	@clang-format -i $(SRC)

.PHONY: clean
clean:
	@rm -rf $(BIN_DIR) $(OBJ_DIR)
