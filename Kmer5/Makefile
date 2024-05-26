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
TARGETDIR_kmer4=dist/debug/MinGw-Windows


all: $(TARGETDIR_kmer4)/kmer4

## Target: kmer0
OBJS_kmer4 =  \
	$(TARGETDIR_kmer4)/kmer4.o \
	$(TARGETDIR_kmer4)/KmerFreq.o \
	$(TARGETDIR_kmer4)/ArrayKmerFreqFunctions.o \
	$(TARGETDIR_kmer4)/Profile.o \
	$(TARGETDIR_kmer4)/main.o
USERLIBS_kmer4 = $(SYSLIBS_kmer4) 
DEPLIBS_kmer4 =  
LDLIBS_kmer4 = $(USERLIBS_kmer4)


# Link or archive
$(TARGETDIR_kmer4)/kmer4: $($(TARGETDIR_kmer4)) $(OBJS_kmer4) $(DEPLIBS_kmer4)
	$(LINK.cc) $(CCFLAGS_kmer4) $(CPPFLAGS_kmer4) -o $@ $(OBJS_kmer4) $(LDLIBS_kmer4)


# Compile source files into .o files
$(TARGETDIR_kmer4)/kmer4.o: $(TARGETDIR_kmer4) src/Kmer.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer4) $(CPPFLAGS_kmer4) -o $@ src/Kmer.cpp

$(TARGETDIR_kmer4)/KmerFreq.o: $(TARGETDIR_kmer4) src/KmerFreq.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer4) $(CPPFLAGS_kmer4) -o $@ src/KmerFreq.cpp

$(TARGETDIR_kmer4)/ArrayKmerFreqFunctions.o: $(TARGETDIR_kmer4) src/ArrayKmerFreqFunctions.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer4) $(CPPFLAGS_kmer4) -o $@ src/ArrayKmerFreqFunctions.cpp

$(TARGETDIR_kmer4)/Profile.o: $(TARGETDIR_kmer4) src/Profile.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer4) $(CPPFLAGS_kmer4) -o $@ src/Profile.cpp

$(TARGETDIR_kmer4)/main.o: $(TARGETDIR_kmer4) src/main.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer4) $(CPPFLAGS_kmer4) -o $@ src/main.cpp



#### Clean target deletes all generated files ####
clean:
	rm -f \
		$(TARGETDIR_kmer4)/kmer4 \
		$(TARGETDIR_kmer4)/kmer4.o \
	        $(TARGETDIR_kmer4)/ArrayKmerFreqFunctions.o \
		$(TARGETDIR_kmer4)/main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_kmer4)


# Create the target directory (if needed)
$(TARGETDIR_kmer4):
	mkdir -p $(TARGETDIR_kmer4)



# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-amd64-Windows

