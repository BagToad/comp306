all: TMA4Question1.exe TMA4Question2.exe TMA4Question3.exe

debug: CPPFLAGS += -DDEBUG -g
debug: all

TMA4Question1.exe: TMA4Question1.cpp
	g++ $(CPPFLAGS) TMA4Question1.cpp -o TMA4Question1.exe

TMA4Question2.exe: TMA4Question2.cpp
	g++ $(CPPFLAGS) TMA4Question2.cpp -o TMA4Question2.exe

TMA4Question3.exe: TMA4Question3.cpp
	g++ $(CPPFLAGS) TMA4Question3.cpp -o TMA4Question3.exe

#Remove executibles.
rmexe:
	rm TMA4Question?.exe
