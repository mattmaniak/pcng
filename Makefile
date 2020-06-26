TARGET = pcng
APPEXTENSION = app
APP = $(TARGET).$(APPEXTENSION)

LANGSTD = c++11
CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=$(LANGSTD)
GTESTFLAGS = -lgtest -lgtest_main -pthread

SRCDIR = src
TESTDIR = test
OBJDIR = obj

OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, \
       $(wildcard $(SRCDIR)/*.cpp))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.h test analyze
	mkdir -p $(OBJDIR)
	$(CC) $(CPPFLAGE) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	mv $(TARGET) $(APP)

.PHONY: analyze
analyze:
	astyle \
	--style=kr \
	--indent=spaces=4 \
	--align-pointer=name \
	--align-reference=name \
	--convert-tabs \
	--attach-namespaces \
	--max-code-length=100 \
	--max-instatement-indent=120 \
	--pad-header \
	--pad-oper \
	$(TESTDIR)/* \
	$(SRCDIR)/*

	$(RM) $(TESTDIR)/*.orig $(SRCDIR)/*.orig

.PHONY: test
test:
	$(CC) $(CFLAGS) $(TESTDIR)/$(TARGET)_unittest.cpp $(GTESTFLAGS) \
	-o $(TARGET).test.$(APPEXTENSION)
	./$(TARGET).test.$(APPEXTENSION)

.PHONY: clean
clean:
	$(RM) -r $(TARGET)* $(OBJDIR)
