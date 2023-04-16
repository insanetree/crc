SRCDIR=src
HDIR=h
DEPDIR=build/dep
OBJDIR=build/obj

EXE=build/crc

CPPSRC=$(wildcard $(SRCDIR)/*.cpp)
CPPOBJ=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(CPPSRC))
CPPDEP=$(patsubst $(SRCDIR)/%.cpp,$(DEPDIR)/%.d,$(CPPSRC))

CPP=g++
CPPFLAGS=-I$(HDIR) -g

all: $(EXE)

run: all
	./$(EXE)

$(EXE): $(CPPOBJ)
	$(CPP) $(CPPFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

$(DEPDIR)/%.d: $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -MM -MT $(OBJDIR)/$*.o $< > $@

include $(CPPDEP)

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(DEPDIR)/*.d
	rm -f $(EXE)

.PHONY: clean
