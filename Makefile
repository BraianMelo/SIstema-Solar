# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -I./include

# Diretórios
SRCDIR = ./src
INCDIR = ./include
OBJDIR = ./obj
BINDIR = ./bin

# Arquivos fontes
SOURCES = $(SRCDIR)/Programa.c $(SRCDIR)/Sistema_Solar.c $(SRCDIR)/Planetas.c

# Arquivos objeto
OBJECTS = $(OBJDIR)/Programa.o $(OBJDIR)/Sistema_Solar.o $(OBJDIR)/Planetas.o

# Nome do executável
TARGET = $(BINDIR)/Sistema_Solar.elf

# Regra padrão
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) $(OBJECTS) -o $(TARGET) -lGL -lGLU -lglut

# Regra para compilar arquivos .c em .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/Sistema_Solar.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para criar o diretório de objetos se não existir
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regra para criar o diretório bin se não existir
$(BINDIR):
	mkdir -p $(BINDIR)

# Regra de limpeza
clean:
	rm -rf $(OBJDIR) $(BINDIR)
