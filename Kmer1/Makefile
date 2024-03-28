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
TARGETDIR_kmer1=dist/debug/MinGw-Windows


all: $(TARGETDIR_kmer1)/kmer1

## Target: kmer0
OBJS_kmer1 =  \
	$(TARGETDIR_kmer1)/Kmer1.o \
	$(TARGETDIR_kmer1)/KmerFreq.o \
	$(TARGETDIR_kmer1)/ArrayKmerFreqFunctions.o \
	$(TARGETDIR_kmer1)/main.o
USERLIBS_kmer1 = $(SYSLIBS_kmer1) 
DEPLIBS_kmer1 =  
LDLIBS_kmer1 = $(USERLIBS_kmer1)


# Link or archive
$(TARGETDIR_kmer1)/kmer1: $(TARGETDIR_kmer1) $(OBJS_kmer1) $(DEPLIBS_kmer1)
	$(LINK.cc) $(CCFLAGS_kmer1) $(CPPFLAGS_kmer1) -o $@ $(OBJS_kmer1) $(LDLIBS_kmer1)


# Compile source files into .o files
$(TARGETDIR_kmer1)/Kmer1.o: $(TARGETDIR_kmer1) src/Kmer.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer1) $(CPPFLAGS_kmer1) -o $@ src/Kmer.cpp

$(TARGETDIR_kmer1)/KmerFreq.o: $(TARGETDIR_kmer1) src/KmerFreq.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer1) $(CPPFLAGS_kmer1) -o $@ src/KmerFreq.cpp

$(TARGETDIR_kmer1)/ArrayKmerFreqFunctions.o: $(TARGETDIR_kmer1) src/ArrayKmerFreqFunctions.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer1) $(CPPFLAGS_kmer1) -o $@ src/ArrayKmerFreqFunctions.cpp

$(TARGETDIR_kmer1)/main.o: $(TARGETDIR_kmer1) src/main.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer1) $(CPPFLAGS_kmer1) -o $@ src/main.cpp



#### Clean target deletes all generated files ####
clean:
	rm -f \
		$(TARGETDIR_kmer1)/kmer1 \
		$(TARGETDIR_kmer1)/Kmer1.o \
	        $(TARGETDIR_kmer1)/ArrayKmerFreqFunctions.o \
		$(TARGETDIR_kmer1)/main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_kmer1)


# Create the target directory (if needed)
$(TARGETDIR_kmer1):
	mkdir -p $(TARGETDIR_kmer1)



# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-amd64-Windows

