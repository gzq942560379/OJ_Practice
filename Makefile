PROJECT_NAME = OJ_Practice

PROJECT_ROOT = $(shell pwd)

SRC_DIR = $(PROJECT_ROOT)/src 
BIN_DIR = $(PROJECT_ROOT)/bin
OBJ_DIR = $(PROJECT_ROOT)/obj

MAKE = make
CC = g++
CFLAGS += -std=c++11
CFLAGS += -g
CFLAGS += -Ofast
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -fPIC
CFLAGS += -Wno-unused-parameter

export PROJECT_NAME PROJECT_ROOT SRC_DIR BIN_DIR OBJ_DIR MAKE CC CFLAGS

.PHONY :  clean test 

test : 
	$(MAKE) -C src $(@F)

clean :
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(BIN_DIR)/*

