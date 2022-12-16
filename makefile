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
##   |   |   | -- src2.o
##   |   |   ` -- (...)
##   |   |-- deps
##   |   |   | -- src1.d
##   |   |   | -- src2.d
##   |   |   ` -- (...)
##   |   `-- target
##   |-- compile_flags.txt
##   |-- config.h
##   |-- doc
##   |   `-- html
##   |       ` -- (doxygen output)...
##   |-- include
##   |   |-- inc1
##   |   |-- inc2
##   |   |-- (...)
##   |   |-- target.h
##   |   `-- (...)
##   |-- target --> ./build/target
##   |-- target-test --> ./build/target
##   `-- src
##       |-- main.c
##       |-- fold1
##       |   | -- src1.c
##       |   | -- src2.c
##       |   ` -- (...)
##       |-- fold2
##       |-- fold3
##       `-- (...)
##


# Set project directories
PROJDIR  := $(realpath $(CURDIR)/.)
SRCDIR   := $(PROJDIR)/src
INCDIR   := $(PROJDIR)/include
BUILDDIR := $(PROJDIR)/build
BINDIR   := $(BUILDDIR)/bin
DEPSDIR  := $(BUILDDIR)/deps
DOCDIR   := $(PROJDIR)/doc

# Name of the finals executables
TARGET   := sae1.02
TESTTARG := sae1.02_test

# Gen debug info
DEBUG = TRUE

# Name the main files
MAINF := main.c
TESTF := test.c

# Verbose the commands
VERBOSE := FALSE
DOXOUT  := FALSE
TESTVER := TRUE

# List the source directories
DIRS      := menu part1
SRCDIRS    = $(foreach dir, $(DIRS), $(addprefix $(SRCDIR)/, $(dir)))

# name the compiler
CC := gcc

# generate compiler param
ifeq ($(DEBUG), TRUE)
	DEBUGFLAG = -g
else
	DEBUGFLAG =
endif
INCLUDES = -I$(INCDIR)
CFLAGS   = $(INCLUDES) $(DEBUGFLAG) -Wall
LDFLAGS  =
LDLIBS   =

# add source dirs to VPATH
VPATH = $(SRCDIRS):$(SRCDIR)

# create list of sources, test sources, objects and deps
SOURCES = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
OBJS    = $(patsubst %.c, $(BINDIR)/%.o, $(notdir $(SOURCES)))
DEPS    = $(patsubst %.c, $(DEPSDIR)/%.d, $(notdir $(SOURCES)))

# OS specific part
ifeq ($(OS), Windows_NT)
	RM        = del /F /Q
	RMDIR     = -RMDIR /S /Q
	MKDIR     = -mkdir
	STDINGORE = 1>NUL || true
	ERRIGNORE = 2>NUL || true
	SEP       =\\
else
	RM        = rm -rf
	RMDIR     = rm -rf
	MKDIR     = mkdir -p
	STDINGORE = 1>/dev/null
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

# hide or not the doxygen output
ifeq ($(DOXOUT), TRUE)
	DOXINGORE =
else
	DOXINGORE = $(STDINGORE)
endif

# verbose output of unit testing
ifeq ($(TESTVER), TRUE)
	TESTV = -v
else
	TESTV =
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


.PHONY: build clean directories doc clflags test init run run_test

build: directories $(DEPS) $(TARGET)

test: directories $(DEPS) $(TESTTARG)

# link and create final executable
$(TARGET): $(OBJS) $(BINDIR)/$(MAINF:.c=.o)
	@echo "${BLUE}[-] Linking main${RESET} $@"
	$(HIDE)$(CC) $(LDFLAGS) $(subst /,$(PSEP),$^) $(LDLIBS) -o $(subst /,$(PSEP),$@)

$(TESTTARG): $(OBJS) $(BINDIR)/$(TESTF:.c=.o)
	@echo "${BLUE}[-] Linking tests${RESET} $@"
	$(HIDE)$(CC) $(LDFLAGS) $(subst /,$(PSEP),$^) $(LDLIBS) -o $(subst /,$(PSEP),$@)

#gen output rules
$(BINDIR)/%.o: %.c
	@echo "${LIGHTPURPLE}[-] Building${RESET} $@"
	$(HIDE)$(CC) -c $(CFLAGS) -o $(subst /,$(PSEP),$@) $(subst /,$(PSEP),$<)

#gen deps rules
$(DEPSDIR)/%.d: %.c
	@echo "${PURPLE}[-] Making dependency${RESET} $@"
	$(HIDE)$(CC) $(CFLAGS) -MF"$(subst /,$(PSEP),$@)" -MG -MM -MP -MT"$(subst /,$(PSEP),$(<:.c=.o))" "$(subst /,$(PSEP),$<)"

# make dirs
directories:
	$(HIDE)$(MKDIR) $(subst /,$(PSEP),$(BINDIR))
	$(HIDE)$(MKDIR) $(subst /,$(PSEP),$(DEPSDIR))

run: build
	@echo "${GREEN}[-] Running program...${RESET}"
	@echo
	$(HIDE)./$(TARGET)

run_test: test
	@echo "${GREEN}[-] Running tests...${RESET}"
	@echo
	$(HIDE)./$(TESTTARG) $(TESTV)

# clean objects, deps and executable
clean:
	$(HIDE)$(RMDIR) $(subst /,$(PSEP),$(BUILDDIR)) $(ERRIGNORE)
	$(HIDE)$(RMDIR) $(subst /,$(PSEP),$(DOCDIR)) $(ERRIGNORE)
	$(HIDE)$(RM) $(TARGET) $(ERRIGNORE)
	$(HIDE)$(RM) $(TESTTARG) $(ERRIGNORE)
	@echo "${GREEN}[-] Cleaning done.${RESET}"

# gen the Doxygen doc
doc:
	@echo "${YELLOW}[-] Generate doc...${RESET}"
	$(HIDE)$(MKDIR) $(subst /,$(PSEP),$(DOCDIR))
	$(HIDE)doxygen $(DOXINGORE)
	@echo "\n${YELLOW}[-] PATH TO THE DOC:${RESET}\n$(DOCDIR)/html/index.html"

# gen the compile flags for clang
clflags: compile_flags.txt

compile_flags.txt:
	@echo "${PURPLE}[-] Generate $@...${RESET}"
	$(HIDE)echo "$(foreach inc, $(INCLUDES), $(addprefix \n, $(inc)))" > $@

init:
	$(HIDE)$(MKDIR) $(subst /,$(PSEP),$(SRCDIR))
	$(HIDE)$(MKDIR) $(subst /,$(PSEP),$(INCDIR))
