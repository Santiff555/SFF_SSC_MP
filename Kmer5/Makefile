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
TARGETDIR_kmer5=dist/debug/MinGw-Windows


all: $(TARGETDIR_kmer5)/kmer5


## Target: kmer0
OBJS_kmer5 =  \
	$(TARGETDIR_kmer5)/kmer5.o \
	$(TARGETDIR_kmer5)/KmerFreq.o \
	$(TARGETDIR_kmer5)/ArrayKmerFreqFunctions.o \
	$(TARGETDIR_kmer5)/Profile.o \
	$(TARGETDIR_kmer5)/KmerCounter.o \
	$(TARGETDIR_kmer5)/LEARN.o \
	$(TARGETDIR_kmer5)/metamain.o
USERLIBS_kmer5 = $(SYSLIBS_kmer5) 
DEPLIBS_kmer5 =  
LDLIBS_kmer5 = $(USERLIBS_kmer5)


# Link or archive
$(TARGETDIR_kmer5)/kmer5: $($(TARGETDIR_kmer5)) $(OBJS_kmer5) $(DEPLIBS_kmer5)
	$(LINK.cc) $(CCFLAGS_kmer5) $(CPPFLAGS_kmer5) -o $@ $(OBJS_kmer5) $(LDLIBS_kmer5)


# Compile source files into .o files
$(TARGETDIR_kmer5)/kmer5.o: $(TARGETDIR_kmer5) src/Kmer.cpp 
	$(COMPILE.cc) $(CCFLAGS_kmer5) $(CPPFLAGS_kmer5) -o $@ src/Kmer.cpp

$(TARGETDIR_kmer5)/KmerFreq.o: $(TARGETDIR_kmer5) src/KmerFreq.cpp 
	$(COMPILE.cc) $(CCFLAGS_kmer5) $(CPPFLAGS_kmer5) -o $@ src/KmerFreq.cpp

$(TARGETDIR_kmer5)/ArrayKmerFreqFunctions.o: $(TARGETDIR_kmer5) src/ArrayKmerFreqFunctions.cpp 
	$(COMPILE.cc) $(CCFLAGS_kmer5) $(CPPFLAGS_kmer5) -o $@ src/ArrayKmerFreqFunctions.cpp

$(TARGETDIR_kmer5)/Profile.o: $(TARGETDIR_kmer5) src/Profile.cpp 
	$(COMPILE.cc) $(CCFLAGS_kmer5) $(CPPFLAGS_kmer5) -o $@ src/Profile.cpp

$(TARGETDIR_kmer5)/KmerCounter.o: $(TARGETDIR_kmer5) src/KmerCounter.cpp 
	$(COMPILE.cc) $(CCFLAGS_kmer5) $(CPPFLAGS_kmer5) -o $@ src/KmerCounter.cpp

$(TARGETDIR_kmer5)/LEARN.o: $(TARGETDIR_kmer5) src/LEARN.cpp 
	$(COMPILE.cc) $(CCFLAGS_kmer5) $(CPPFLAGS_kmer5) -o $@ src/LEARN.cpp
 
#$(TARGETDIR_kmer5)/CLASSIFY.o: $(TARGETDIR_kmer5) src/CLASSIFY.cpp 
#	$(COMPILE.cc) $(CCFLAGS_kmer5) $(CPPFLAGS_kmer5) -o $@ src/CLASSIFY.cpp

$(TARGETDIR_kmer5)/metamain.o: $(TARGETDIR_kmer5) src/metamain.cpp 
	$(COMPILE.cc) $(CCFLAGS_kmer5) $(CPPFLAGS_kmer5) -o $@ src/metamain.cpp



#### Clean target deletes all generated files ####
clean:
	rm -f \
		$(TARGETDIR_kmer5)/kmer5\
		$(TARGETDIR_kmer5)/kmer5.o \
	        $(TARGETDIR_kmer5)/ArrayKmerFreqFunctions.o \
		$(TARGETDIR_kmer5)/main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_kmer5)


# Create the target directory (if needed)
$(TARGETDIR_kmer5):
	mkdir -p $(TARGETDIR_kmer5)



# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-amd64-Windows

