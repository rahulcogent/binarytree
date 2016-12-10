CC=g++
IDIR=include
ODIR=obj
SDIR=src
CFLAGS=-Wall -I$(IDIR) -std=c++11 -g

_DEPS = TreeNode.h BinaryTree.h BinarySearchTree.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = test.o BinaryTree.o BinarySearchTree.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))


all:test

$(ODIR)/%.o:$(SDIR)/%.cpp $(DEPS)
	mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o $(ODIR) test
