C_FILES = main.c FIR.c Pan_Tompkins_detect.c
C_HEADERS = FIR.h Pan_Tompkins_detect.h define.h ./FIR_design/fir_coef.h ./data/ecg_data.h
DESTDIR = .

CC = gcc
CFLAGS = -Wall -O2 -I. -I./data -I./FIR_design
LDFLAGS = 

PYTHON = python

all: run

run: $(DESTDIR)/run.exe
	$(DESTDIR)/run.exe

run.exe: $(C_FILES) $(C_HEADERS)
	$(CC) $(CFLAGS) -o $@ $(C_FILES) $(LDFLAGS)

./FIR_design/fir_coef.h: ./FIR_design/fir_coef_read_from_mat.py ./FIR_design/FIR.mat
	$(PYTHON) ./FIR_design/fir_coef_read_from_mat.py ./FIR_design/FIR.mat

./data/ecg_data.h: ./data/data_format.py ./data/ECGcoe/ECG03.coe
	$(PYTHON) ./data/data_format.py ./data/ECGcoe/ECG03.coe

plot:
	$(PYTHON) ./data/data_plot.py ./data/ECGcoe/ECG01.coe
	$(PYTHON) ./data/data_plot.py ./data/ECGcoe/ECG02.coe
	$(PYTHON) ./data/data_plot.py ./data/ECGcoe/ECG03.coe
	$(PYTHON) ./data/data_plot.py ./data/ECGcoe/ECG01_filtered.coe
	$(PYTHON) ./data/data_plot.py ./data/ECGcoe/ECG02_filtered.coe
	$(PYTHON) ./data/data_plot.py ./data/ECGcoe/ECG03_filtered.coe

clean:
# powershell
#	"rm $(DESTDIR)\run.exe" 
# bash
	rm -f $(DESTDIR)/run.exe
