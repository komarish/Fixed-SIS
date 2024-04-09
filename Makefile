
SIS ?= ../logic-synthesis-bin/

CFLAGS += -fpic -I"$(SIS)/include"
LDFLAGS += -L"$(SIS)/lib" -lsis -lm -lreadline

%.o: %.c
	$(CC) -c $@ $(CFLAGS) $<

blif.exe: blif.o
	$(CC) -o $@ $(LDFLAGS) $<

all: blif.exe

clean:
	$(RM) blif.exe blif.o
