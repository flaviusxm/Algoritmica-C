CC = gcc
CFLAGS = -Wall -Wextra
TARGET = main_exec.exe

LDFLAGS = -lpsapi

MAIN_SRC = main_exec.c
INFO_SRC = info_lib/info_module.c
INFO_HEADER = info_lib/info_module.h
SORT_SRC = sort_lib/sort_module.c  
SORT_HEADER = sort_lib/sort_module.h

all: $(TARGET)

$(TARGET): $(MAIN_SRC) info_module.dll sort_module.dll
	$(CC) $(CFLAGS) -o $(TARGET) $(MAIN_SRC) -L. -linfo_module -lsort_module $(LDFLAGS)

info_module.dll: $(INFO_SRC) $(INFO_HEADER)
	$(CC) $(CFLAGS) -shared -o info_module.dll $(INFO_SRC)

sort_module.dll: $(SORT_SRC) $(SORT_HEADER)
	$(CC) $(CFLAGS) -shared -o sort_module.dll $(SORT_SRC)

clean:
	rm -f $(TARGET) *.dll *.o

help:
	@echo "=== Algoritmica-C ==="
	@echo "make       - Compileaza tot proiectul"
	@echo "make clean - Sterge fisierele compilate"
	@echo "make help  - Afiseaza acest ajutor"

.PHONY: all clean help