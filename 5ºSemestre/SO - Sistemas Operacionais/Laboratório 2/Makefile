CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGETS  = hierarquia executa_comando busca_vetor shell

.PHONY: all clean

all: $(TARGETS)

hierarquia: hierarquia.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

executa_comando: executa_comando.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

busca_vetor: busca_vetor.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

shell: shell.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)