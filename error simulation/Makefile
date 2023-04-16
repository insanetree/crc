SRCDIR=src
HDIR=h
BUILDDIR=build
DEPDIR=build/dep
OBJDIR=build/obj

EXE=build/error

CPPSRC=$(wildcard $(SRCDIR)/*.c)
CPPOBJ=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(CPPSRC))
CPPDEP=$(patsubst $(SRCDIR)/%.c,$(DEPDIR)/%.d,$(CPPSRC))

CPP=gcc
CPPFLAGS=-I$(HDIR) -g

all: $(EXE)

run: all
	./$(EXE)

$(EXE): $(CPPOBJ)
	$(CPP) $(CPPFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CPP) $(CPPFLAGS) -c -o $@ $<

$(DEPDIR)/%.d: $(SRCDIR)/%.cpp
	mkdir -p $(DEPDIR)
	$(CPP) $(CPPFLAGS) -MM -MT $(OBJDIR)/$*.o $< > $@

include $(CPPDEP)

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(DEPDIR)/*.d
	rm -f $(EXE)

.PHONY: clean
