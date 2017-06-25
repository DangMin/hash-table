CC = gcc
DEPS = app.h hash.h linkedlist.h
OBJ = app.o hash.o linkedlist.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

app: $(OBJ)
	gcc -o $@ $^

clean:
	rm -f *.o app