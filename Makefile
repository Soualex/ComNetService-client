export CC=	g++
export CFLAGS=	-W -Wall -ansi -pedantic
export LFLAGS=	-lsfml-network -lsfml-window -lsfml-system
BIN_DIR=	./bin/
SRC_DIR=	./src/
INCLUDE_DIR=	./include/

all: client

debug: CFLAGS += -g3
debug: all

client:
	@(cd $(SRC_DIR) && $(MAKE))
	@(rm -rf bin/)
	@(mkdir bin/)
	@(mv $(SRC_DIR)client $(BIN_DIR))

.PHONY: clean mrproper $(EXEC)

clean:
	@(cd $(SRC_DIR) && $(MAKE) $@)

mrproper: clean
	@(cd $(BIN_DIR) && rm client)
