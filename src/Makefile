CC=clang++
CPPFLAGS=-std=c++17 -Wall -I./include
LFLAGS=
LIBS=
LIBS_TEST=-lgtest -lgtest_main

SRC=\
	interpreter.cc
HEADER=\
	include/ebpf.h \
	include/ebpf_inst.h \
	include/interpreter.h
MAIN = ebpfr.cc

SRC_OBJ=$(SRC:.cc=.o)
MAIN_OBJ =$(MAIN:.cc=.o)
TARGET = ebpfr 
TEST_TARGET = test

TEST_SRC=
TEST_OBJ=$(TEST_SRC:.cc=.o)

.PHONY: all
all: $(SRC_OBJ) $(MAIN_OBJ)
	$(CC) $(LFLAGS) -o $(TARGET) $^ $(LIBS)

.PHONY: test
test: $(SRC_OBJ) $(TEST_OBJ)
	$(CC) $(LFLAGS) -o $(TEST_TARGET) $^ $(LIBS) $(LIBS_TEST) -pthread


$(SRC_OBJ): %.o: %.cc $(HEADER)
	$(CC) $(CPPFLAGS) -o $(<:.cc=.o) -c $<

$(MAIN_OBJ): %.o: %.cc
	$(CC) $(CPPFLAGS) -o $(<:.cc=.o) -c $<

$(TEST_OBJ): %.o: %.cc $(HEADER)
	$(CC) $(CPPFLAGS) -o $(<:.cc=.o) -c $<

.PHONY: format
format: $(SRC) $(HEADER) $(TEST_SRC) $(MAIN)
	clang-format -i $^

.PHONY: clean
clean:
	rm -f $(SRC_OBJ) $(TEST_OBJ) $(MAIN_OBJ) $(TARGET) $(TEST_TARGET)
