IDIR =.
CC=gcc
CFLAGS=-I$(IDIR)
ODIR=obj
LIBS=-lm

_DEPS = car.h race.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = car.o race.o speed_circuit_race.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

race: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

