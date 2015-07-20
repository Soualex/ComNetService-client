EXEC=		client
SRC= 		Main.cpp
OBJ= 		$(SRC:.cpp=.o)

all: $(EXEC)

client: $(OBJ)
	@echo "Generating client..."
	@$(CC) -o $@ $^ $(LFLAGS)

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o