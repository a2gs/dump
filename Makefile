CC = cc
AR = ar
RANLIB = ranlib

SRCDIR = ./src
INCDIR = ./inc
BINDIR = ./bin

CFLAGS = -g -Wall

RM = /bin/rm -f

OBJ = $(BINDIR)/liba2gs_ToolBox_Dump.o
SOURCES = $(SRCDIR)/dump.c
LIB = $(BINDIR)//liba2gs_ToolBox_Dump.a

all: $(OBJ)

$(OBJ): $(SOURCES)
	$(CC) -c -o$(OBJ) -I$(INCDIR) $(SOURCES) $(CFLAGS)
	$(AR) rc $(LIB) $(OBJ)
	$(RANLIB) $(LIB)

clean:
	$(RM) $(BINDIR)/*
