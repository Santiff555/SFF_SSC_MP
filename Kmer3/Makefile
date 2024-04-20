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
TARGETDIR_kmer3=dist/debug/MinGw-Windows


all: $(TARGETDIR_kmer3)/kmer3

## Target: kmer0
OBJS_kmer3 =  \
	$(TARGETDIR_kmer3)/kmer3.o \
	$(TARGETDIR_kmer3)/KmerFreq.o \
	$(TARGETDIR_kmer3)/ArrayKmerFreqFunctions.o \
	$(TARGETDIR_kmer3)/Profile.o \
	$(TARGETDIR_kmer3)/main.o
USERLIBS_kmer3 = $(SYSLIBS_kmer3) 
DEPLIBS_kmer3 =  
LDLIBS_kmer3 = $(USERLIBS_kmer3)


# Link or archive
$(TARGETDIR_kmer3)/kmer3: $($(TARGETDIR_kmer3)) $(OBJS_kmer3) $(DEPLIBS_kmer3)
	$(LINK.cc) $(CCFLAGS_kmer3) $(CPPFLAGS_kmer3) -o $@ $(OBJS_kmer3) $(LDLIBS_kmer3)


# Compile source files into .o files
$(TARGETDIR_kmer3)/kmer3.o: $(TARGETDIR_kmer3) src/Kmer.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer3) $(CPPFLAGS_kmer3) -o $@ src/Kmer.cpp

$(TARGETDIR_kmer3)/KmerFreq.o: $(TARGETDIR_kmer3) src/KmerFreq.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer3) $(CPPFLAGS_kmer3) -o $@ src/KmerFreq.cpp

$(TARGETDIR_kmer3)/ArrayKmerFreqFunctions.o: $(TARGETDIR_kmer3) src/ArrayKmerFreqFunctions.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer3) $(CPPFLAGS_kmer3) -o $@ src/ArrayKmerFreqFunctions.cpp

$(TARGETDIR_kmer3)/Profile.o: $(TARGETDIR_kmer3) src/Profile.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer3) $(CPPFLAGS_kmer3) -o $@ src/Profile.cpp

$(TARGETDIR_kmer3)/main.o: $(TARGETDIR_kmer3) src/main.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer3) $(CPPFLAGS_kmer3) -o $@ src/main.cpp



#### Clean target deletes all generated files ####
clean:
	rm -f \
		$(TARGETDIR_kmer3)/kmer3 \
		$(TARGETDIR_kmer3)/kmer3.o \
	        $(TARGETDIR_kmer3)/ArrayKmerFreqFunctions.o \
		$(TARGETDIR_kmer3)/main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_kmer3)


# Create the target directory (if needed)
$(TARGETDIR_kmer3):
	mkdir -p $(TARGETDIR_kmer3)



# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-amd64-Windows

