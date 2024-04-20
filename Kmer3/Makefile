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
TARGETDIR_kmer2=dist/debug/MinGw-Windows


all: $(TARGETDIR_kmer2)/kmer2

## Target: kmer0
OBJS_kmer2 =  \
	$(TARGETDIR_kmer2)/Kmer2.o \
	$(TARGETDIR_kmer2)/KmerFreq.o \
	$(TARGETDIR_kmer2)/ArrayKmerFreqFunctions.o \
	$(TARGETDIR_kmer2)/Profile.o \
	$(TARGETDIR_kmer2)/main.o
USERLIBS_kmer2 = $(SYSLIBS_kmer2) 
DEPLIBS_kmer2 =  
LDLIBS_kmer2 = $(USERLIBS_kmer2)


# Link or archive
$(TARGETDIR_kmer2)/kmer2: $($(TARGETDIR_kmer2)) $(OBJS_kmer2) $(DEPLIBS_kmer2)
	$(LINK.cc) $(CCFLAGS_kmer2) $(CPPFLAGS_kmer2) -o $@ $(OBJS_kmer2) $(LDLIBS_kmer2)


# Compile source files into .o files
$(TARGETDIR_kmer2)/Kmer2.o: $(TARGETDIR_kmer2) src/Kmer.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer2) $(CPPFLAGS_kmer2) -o $@ src/Kmer.cpp

$(TARGETDIR_kmer2)/KmerFreq.o: $(TARGETDIR_kmer2) src/KmerFreq.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer2) $(CPPFLAGS_kmer2) -o $@ src/KmerFreq.cpp

$(TARGETDIR_kmer2)/ArrayKmerFreqFunctions.o: $(TARGETDIR_kmer2) src/ArrayKmerFreqFunctions.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer2) $(CPPFLAGS_kmer2) -o $@ src/ArrayKmerFreqFunctions.cpp

$(TARGETDIR_kmer2)/Profile.o: $(TARGETDIR_kmer2) src/Profile.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer2) $(CPPFLAGS_kmer2) -o $@ src/Profile.cpp

$(TARGETDIR_kmer2)/main.o: $(TARGETDIR_kmer2) src/main.cpp
	$(COMPILE.cc) $(CCFLAGS_kmer2) $(CPPFLAGS_kmer2) -o $@ src/main.cpp



#### Clean target deletes all generated files ####
clean:
	rm -f \
		$(TARGETDIR_kmer2)/kmer2 \
		$(TARGETDIR_kmer2)/Kmer2.o \
	        $(TARGETDIR_kmer2)/ArrayKmerFreqFunctions.o \
		$(TARGETDIR_kmer2)/main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_kmer2)


# Create the target directory (if needed)
$(TARGETDIR_kmer2):
	mkdir -p $(TARGETDIR_kmer2)



# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-amd64-Windows

