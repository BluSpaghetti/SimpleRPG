# Parametri del compilatore
CXX = g++
CXXFLAGS = -std=c++11 -Wall -O3 -static -static-libstdc++

# Nome del .exe finale
TARGET = SimpleRPG

# Percorso dei file sorgente, da separare con spazio
SRCS = src\main.cpp

# Crea file oggetto
OBJS = $(SRCS:.cpp=.o)

# Regola di default: compilazione dell'eseguibile e cancellazione file .o
all: $(TARGET) clean

# Regola per collegare i file oggetto nell'eseguibile di destinazione
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regola per compilare i file .cpp in file .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Pulisce dai file .o
clean:
	del $(OBJS)