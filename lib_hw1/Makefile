SRC_DIR = .
TARGET = bitmap hash list tokenizer
MAIN_PROG = testlib

build: build.core
	gcc -c main.c -o $(BUILD_DIR)/main.o
	gcc -o $(SRC_DIR)/$(MAIN_PROG) $(BUILD_DIR)/*.o


build.core: $(addsuffix .o, $(TARGET))


include $(SRC_DIR)/rules.mk
