all: TMA2Question1.exe TMA2Question2.exe TMA2Question3.exe TMA2Question4.exe

debug: CPPFLAGS += -DDEBUG -g
debug: all

TMA2Question1.exe: TMA2Question1.cpp
	g++ $(CPPFLAGS) TMA2Question1.cpp -o TMA2Question1.exe

TMA2Question2.exe: TMA2Question2.cpp
	g++ $(CPPFLAGS) TMA2Question2.cpp -o TMA2Question2.exe

TMA2Question3.exe: TMA2Question3.cpp
	g++ $(CPPFLAGS) TMA2Question3.cpp -o TMA2Question3.exe

TMA2Question4.exe: TMA2Question4.cpp
	g++ $(CPPFLAGS) TMA2Question4.cpp -o TMA2Question4.exe

#Remove executibles.
rmexe:
	rm TMA2Question?.exe
