SRC_DIR = .
TARGET = bitmap hash list tokenizer
MAIN = testlib

build: build.core
	gcc -c main.c -o $(BUILD_DIR)/main.o
	gcc -o $(SRC_DIR)/$(MAIN) $(BUILD_DIR)/*.o


build.core: $(addsuffix .o, $(TARGET))


include $(SRC_DIR)/rules.mk
