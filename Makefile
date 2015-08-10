PROJ=highestAffinityPair
all : $(PROJ)

highestAffinityPair : highestAffinityPair.cpp
	g++ -o $@ -std=c++11 -g -Wall -Wextra $^
clean : 
	rm -rf $(PROJ) *.o *.dSYM
