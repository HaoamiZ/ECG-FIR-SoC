C_FILES = $(wildcard *.c)
C_HEADERS = $(wildcard *.h)
DESTDIR = .

CC = gcc
CFLAGS = -Wall -O2 -I.
LDFLAGS =

PYTHON = python

all: run

run: $(DESTDIR)/run.exe
	$(DESTDIR)/run.exe

run.exe: $(C_FILES) $(C_HEADERS)
	$(CC) $(CFLAGS) -o $@ $(C_FILES) $(LDFLAGS)

plot: ./data/data.csv ./data/filtered_data.csv
	$(PYTHON) ./data/data_plot.py ./data/data.csv
	$(PYTHON) ./data/data_plot.py ./data/filtered_data.csv

clean:
# powershell
	"rm $(DESTDIR)\run.exe" 
# bash
# rm -f $(DESTDIR)/run.exe
