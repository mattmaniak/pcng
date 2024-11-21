TARGET = pcng
LANGSTD = c++11
CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=$(LANGSTD)
GTESTFLAGS = -lgtest -lgtest_main -pthread

# Qt Coding Style Rules - https://wiki.qt.io/Qt_Coding_Style
ASTYLEFLAGS = --style=kr \
	--indent=spaces=4 \
	--align-pointer=name \
	--align-reference=name \
	--convert-tabs \
	--attach-namespaces \
	--max-code-length=100 \
	--max-instatement-indent=120 \
	--pad-header \
	--pad-oper

SRCDIR = src
TESTDIR = test
OBJDIR = obj

OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, \
       $(wildcard $(SRCDIR)/*.cpp))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.h
	mkdir -p $(OBJDIR)
	$(CC) $(CPPFLAGE) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: debug
debug: test
debug: analyze
debug: $(TARGET)

.PHONY: analyze
analyze:
	astyle \
	$(ASTYLEFLAGS) \
	$(TESTDIR)/* \
	$(SRCDIR)/*

	$(RM) $(TESTDIR)/*.orig $(SRCDIR)/*.orig

.PHONY: test
test:
	$(CC) $(CFLAGS) $(TESTDIR)/$(TARGET)_unittest.cpp $(GTESTFLAGS) \
	-o $(TARGET).test
	./$(TARGET).test

.PHONY: clean
clean:
	$(RM) -r $(TARGET)* $(OBJDIR)
