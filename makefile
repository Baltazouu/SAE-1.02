##
##	SAE 1.02 - Comparaison d'approches algorithmiques
##	file: Makefile
##	authors: Alexandre Agostinho
##	(credits: https://riptutorial.com/makefile/example/21376/building-from-different-source-folders-to-different-target-folders)
##

## Structure:
##   .
##   |-- build
##   |   |-- bin
##   |   |   | -- src1.o
##   |   |   | -- src1.d
##   |   |   | -- src2.o
##   |   |   | -- src2.d
##   |   |   ` -- ...
##   |   `-- target
##   |-- compile_flags.txt
##   |-- include
##   |   |-- inc1
##   |   |-- inc2
##   |   |-- ...
##   |   |-- target.h
##   |   `-- ...
##   |-- target --> ./build/target
##   `-- src
##       |-- fold1
##       |   | -- src1.c
##       |   | -- src2.c
##       |   ` -- ...
##       |-- fold2
##       |-- fold3
##       `-- ...
##


# Set project directories
PROJDIR  := $(realpath $(CURDIR)/.)
SRCDIR   := $(PROJDIR)/src
INCDIR   := $(PROJDIR)/include
BUILDDIR := $(PROJDIR)/build
BINDIR   := $(BUILDDIR)/bin

# Name of the final executables
TARGET := sae1.02

# Verbose the commands
VERBOSE := TRUE

# List the source directories
DIRS      := affichages menus part1 part2 part3 part4
SRCDIRS    = $(foreach dir, $(DIRS), $(addprefix $(SRCDIR)/, $(dir)))
#INCDIRS    = $(foreach dir, $(DIRS), $(addprefix $(INCDIR)/, $(dir)))

# generate GCC param
INCLUDES = -I$(INCDIR) #$(foreach dir, $(INCDIRS), $(addprefix -I, $(dir)))
CFLAGS   = $(INCLUDES) -MP -Wall
LDFLAGS  =
LDLIBS   = -lncurses

# add source dirs to VPATH
VPATH = $(SRCDIRS)

# create list of sources, objects and deps
SOURCES = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
OBJS    = $(patsubst %.c, $(BINDIR)/%.o, $(notdir $(SOURCES)))
DEPS    = $(OBJS:.o=.d)

# name the compiler
CC := gcc

# OS specific part
ifeq ($(OS), Windows_NT)
	RM        = del /F /Q
	RMDIR     = -RMDIR /S /Q
	MKDIR     = -mkdir
	ERRIGNORE = 2>NUL || true
	SEP       =\\
else
	RM        = rm -rf
	RMDIR     = rm -rf
	MKDIR     = mkdir -p
	ERRIGNORE = 2>/dev/null
	SEP       =/
endif

# rm space after sep
PSEP = $(strip $(SEP))

# hide or not the calls depending of VERBOSE
ifeq ($(VERBOSE), TRUE)
	HIDE =
else
	HIDE = @
endif

define generateRule
$(1): $(2)
	@echo "[-] Building $$@"
	$(HIDE)$(CC) -c $$(CFLAGS) -o $$(subst /,$$(PSEP),$$@) $$(subst /,$$(PSEP),$$<) -MMD
endef

.PHONY: all clean directories doc clflags

all: directories $(TARGET)

$(TARGET): $(OBJS)
	@echo "[-] Linking $@"
	$(HIDE)$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(BINDIR)/%.o: %.c
	@echo "[-] Building $@"
	$(HIDE)$(CC) -c $(CFLAGS) -o $(subst /,$(PSEP),$@) $(subst /,$(PSEP),$<) -MMD

# include dependencies
-include $(DEPS)

# gen rule
#$(eval $(call generateRules, $(OBJS), $(SOURCES)))

# make dirs
directories:
	$(HIDE)$(MKDIR) $(subst /,$(PSEP),$(BINDIR))

# clean objects, deps and executable
clean:
	$(HIDE)$(RMDIR) $(subst /,$(PSEP),$(BUILDDIR)) $(ERRIGNORE)
	$(HIDE)$(RM) $(TARGET) $(ERRIGNORE)
	@echo "[-] Cleaning done."

# gen the Doxygen doc
doc:
	@echo "[-] Generate doc..."
	$(HIDE)doxygen
	@echo -e "\n[-] PATH TO THE DOC:\n${PWD}/html/index.html"

# gen the compile flags for clang
clflags: compile_flags.txt

compile_flags.txt:
	@echo "[-] Generate $@..."
	$(HIDE)echo -e "$(foreach inc, $(INCLUDES), $(addprefix \n, $(inc)))" > $@
