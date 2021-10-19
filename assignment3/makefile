all: TMA3Question1.exe TMA3Question2.exe TMA3Question3.exe

debug: CPPFLAGS += -DDEBUG -g
debug: all

TMA3Question1.exe: TMA3Question1.cpp
	g++ $(CPPFLAGS) TMA3Question1.cpp -o TMA3Question1.exe

TMA3Question2.exe: TMA3Question2.cpp
	g++ $(CPPFLAGS) TMA3Question2.cpp -o TMA3Question2.exe

TMA3Question3.exe: TMA3Question3.cpp
	g++ $(CPPFLAGS) TMA3Question3.cpp -o TMA3Question3.exe

#Remove executibles.
rmexe:
	rm TMA3Question?.exe
