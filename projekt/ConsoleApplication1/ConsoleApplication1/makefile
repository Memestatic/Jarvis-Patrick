
#############################
# Generator plikow makefile #
# Krzysztof Siminski, 2022  #
#############################

# STALE:
kompilator=g++
standard=-std=c++20

optRelease=-O3
optDebug=

errors=-pedantic-errors

release=
debug=-g

#rownoleglosc=-fopenmp
rownoleglosc=

release_folder=_release
debug_folder=_debug

#############################

.PHONY : clean $(debug_folder) $(release_folder)

# opcje uruchomienia projektu:

release : $(release_folder) $(release_folder)/main
	./$(release_folder)/main
	./$(release_folder)/main -i wejscie -o wyjscie -n 1234 -w 34
	./$(release_folder)/main -o wyjscie -i wejscie -n 1234 -w 34
	./$(release_folder)/main  -w 34 -o wyjscie -i wejscie -n 1234
# nieprawidłowe:
	./$(release_folder)/main -q wejscie -o wyjscie -n 1234 -w 34
	./$(release_folder)/main -i wejscie -o wyjscie -n 1234 
	./$(release_folder)/main -i wejscie -o wyjscie -n 1234 -w 34 -n 456
	./$(release_folder)/main -i wejscie -o wyjscie -n 1234 34 -w 
	./$(release_folder)/main -o -i -n -w wyjscie wejscie 1234  34

# OK:
	./$(release_folder)/main -i input3.txt -o input3.out -n 5 -w 3	
	./$(release_folder)/main -i input3.txt -o input3.out -n 5 -w 4	
	./$(release_folder)/main -i input5.txt -o input5.out -n 5 -w 3	
	./$(release_folder)/main -i input5.txt -o input5.out -n 5 -w 4	
	./$(release_folder)/main -i input2.txt -o input2.out -n 3 -w 1	
	
	


debug : $(debug_folder) $(debug_folder)/main
	valgrind --leak-check=yes ./$(debug_folder)/main

# utworzenie folderow:

$(release_folder) : 
	mkdir -p $(release_folder)
$(debug_folder) : 
	mkdir -p $(debug_folder)

# kompilacja zrodel:

$(release_folder)/funkcje.o : funkcje.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/funkcje.o : funkcje.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/main.o : main.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/main.o : main.cpp
	$(kompilator) $(standard) $(debug) $(optyDebug) $(rownoleglosc) $(errors) -c -o $@ $^

# linkowanie:

$(release_folder)/main : $(release_folder)/main.o $(release_folder)/funkcje.o 
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -o $@ $^

$(debug_folder)/main : $(debug_folder)/main.o $(debug_folder)/funkcje.o 
	$(kompilator) $(standard) $(debug) $(optDebug) $(rownoleglosc) $(errors) -o $@ $^

# usuniecie plikow skompilowanych:

clean : 
	if [ -d $(debug_folder)      ] ; then rm -r $(debug_folder)   ; fi
	if [ -d $(release_folder)    ] ; then rm -r $(release_folder) ; fi;


