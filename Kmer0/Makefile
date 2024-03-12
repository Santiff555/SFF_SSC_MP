## -*- Makefile -*-
##
## User: santy
## Time: 8 mar. 2024 13:04:53
## Makefile created by Oracle Developer Studio.
##
## This file is generated automatically.
##


#### Compiler and tool definitions shared by all build targets #####
CCC = g++
CXX = g++
BASICOPTS = -m64
CCFLAGS = $(BASICOPTS)
CXXFLAGS = $(BASICOPTS)
CCADMIN = 


# Define the target directories.
TARGETDIR_kmer0=dist/debug/MinGw-Windows


all: $(TARGETDIR_kmer0)/kmer0

## Target: kmer0
OBJS_kmer0 =  \
	$(TARGETDIR_kmer0)/Kmer0.o \
	$(TARGETDIR_kmer0)/main.o
USERLIBS_kmer0 = $(SYSLIBS_kmer0) 
DEPLIBS_kmer0 =  
LDLIBS_kmer0 = $(USERLIBS_kmer0)


# Link or archive
$(TARGETDIR_kmer0)/kmer0: $(TARGETDIR_kmer0) $(OBJS_kmer0) $(DEPLIBS_kmer0)
	$(LINK.cc) $(CCFLAGS_kmer0) $(CPPFLAGS_kmer0) -o $@ $(OBJS_kmer0) $(LDLIBS_kmer0)


# Compile source files into .o files
$(TARGETDIR_kmer0)/Kmer0.o: $(TARGETDIR_kmer0) src/Kmer.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer0) $(CPPFLAGS_kmer0) -o $@ src/Kmer.cpp

$(TARGETDIR_kmer0)/main.o: $(TARGETDIR_kmer0) src/main.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer0) $(CPPFLAGS_kmer0) -o $@ src/main.cpp



#### Clean target deletes all generated files ####
clean:
	rm -f \
		$(TARGETDIR_kmer0)/kmer0 \
		$(TARGETDIR_kmer0)/Kmer0.o \
		$(TARGETDIR_kmer0)/main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_kmer0)


# Create the target directory (if needed)
$(TARGETDIR_kmer0):
	mkdir -p $(TARGETDIR_kmer0)



# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-amd64-Windows

