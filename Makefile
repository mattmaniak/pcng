TARGET = pcng
APPEXTENSION = app
APP = $(TARGET).$(APPEXTENSION)

LANGSTD = c++11
CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=$(LANGSTD)

SRCDIR = src
TESTDIR = test
OBJDIR = obj

OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, \
       $(wildcard $(SRCDIR)/*.cpp))

.PHONY: test
test:
	$(CC) $(CFLAGS) $(TESTDIR)/pcng_unittest.cpp -lgtest -lgtest_main -pthread -o test.$(APPEXTENSION)
	./test.$(APPEXTENSION)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.h
	mkdir -p $(OBJDIR)
	$(CC) $(CPPFLAGE) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	mv $(TARGET) $(APP)

.PHONY: clean
clean:
	$(RM) -r *.$(APPEXTENSION) $(OBJDIR)
