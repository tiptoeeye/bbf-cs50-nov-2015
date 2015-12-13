##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ProblemSet1
ConfigurationName      :=Debug
WorkspacePath          := "C:\bbf-cs50-nov-2015\_MykolaKozin\CS50_Workspace"
ProjectPath            := "C:\bbf-cs50-nov-2015\_MykolaKozin\CS50_Workspace\ProblemSet1"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=nkozin
Date                   :=11/12/2015
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="ProblemSet1.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)c:/bbf-cs50-nov-2015/_INCLUDES  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/mario.c$(ObjectSuffix) $(IntermediateDirectory)/greedy.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/_INCLUDES_cs50.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/mario.c$(ObjectSuffix): mario.c $(IntermediateDirectory)/mario.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/bbf-cs50-nov-2015/_MykolaKozin/CS50_Workspace/ProblemSet1/mario.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mario.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mario.c$(DependSuffix): mario.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mario.c$(ObjectSuffix) -MF$(IntermediateDirectory)/mario.c$(DependSuffix) -MM "mario.c"

$(IntermediateDirectory)/mario.c$(PreprocessSuffix): mario.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mario.c$(PreprocessSuffix) "mario.c"

$(IntermediateDirectory)/greedy.c$(ObjectSuffix): greedy.c $(IntermediateDirectory)/greedy.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/bbf-cs50-nov-2015/_MykolaKozin/CS50_Workspace/ProblemSet1/greedy.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/greedy.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/greedy.c$(DependSuffix): greedy.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/greedy.c$(ObjectSuffix) -MF$(IntermediateDirectory)/greedy.c$(DependSuffix) -MM "greedy.c"

$(IntermediateDirectory)/greedy.c$(PreprocessSuffix): greedy.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/greedy.c$(PreprocessSuffix) "greedy.c"

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/bbf-cs50-nov-2015/_MykolaKozin/CS50_Workspace/ProblemSet1/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/_INCLUDES_cs50.c$(ObjectSuffix): ../../../_INCLUDES/cs50.c $(IntermediateDirectory)/_INCLUDES_cs50.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/bbf-cs50-nov-2015/_INCLUDES/cs50.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/_INCLUDES_cs50.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/_INCLUDES_cs50.c$(DependSuffix): ../../../_INCLUDES/cs50.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/_INCLUDES_cs50.c$(ObjectSuffix) -MF$(IntermediateDirectory)/_INCLUDES_cs50.c$(DependSuffix) -MM "../../../_INCLUDES/cs50.c"

$(IntermediateDirectory)/_INCLUDES_cs50.c$(PreprocessSuffix): ../../../_INCLUDES/cs50.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/_INCLUDES_cs50.c$(PreprocessSuffix) "../../../_INCLUDES/cs50.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


