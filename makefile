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
##   |-- config.h
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
VERBOSE := FALSE

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

# define standard colors
ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif


.PHONY: all clean directories doc clflags

all: directories $(TARGET)

$(TARGET): $(OBJS)
	@echo "${BLUE}[-] Linking${RESET} $@"
	$(HIDE)$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(BINDIR)/%.o: %.c
	@echo "${LIGHTPURPLE}[-] Building${RESET} $@"
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
	@echo "${GREEN}[-] Cleaning done.${RESET}"

# gen the Doxygen doc
doc:
	@echo "${YELLOW}[-] Generate doc...${RESET}"
	$(HIDE)doxygen
	@echo -e "\n${YELLOW}[-] PATH TO THE DOC:${RESET}\n${PWD}/html/index.html"

# gen the compile flags for clang
clflags: compile_flags.txt

compile_flags.txt:
	@echo "${PURPLE}[-] Generate $@...${RESET}"
	$(HIDE)echo "$(foreach inc, $(INCLUDES), $(addprefix \n, $(inc)))" > $@
