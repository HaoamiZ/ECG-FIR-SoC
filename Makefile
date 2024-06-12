C_FILES = main.c FIR.c Pan_Tompkins_detect.c
C_HEADERS = FIR.h Pan_Tompkins_detect.h define.h ./FIR_design/fir_coef.h ./data/ecg_data.h
DESTDIR = .

DEST_ECG_SIGNAL ?= ECG01

CC ?= gcc
CFLAGS = -Wall -O2 -I. -I./data -I./FIR_design
LDFLAGS = 

PYTHON ?= python

all: cleanall run plot

run: $(DESTDIR)/run.exe
	$(DESTDIR)/run.exe 2>&1 | tee ./data/ECGcoe/$(DEST_ECG_SIGNAL).log
	mv ./data/ECGcoe/ECG_filtered.coe ./data/ECGcoe/$(DEST_ECG_SIGNAL)_filtered.coe

run.exe: $(C_FILES) $(C_HEADERS)
	$(CC) $(CFLAGS) -o $@ $(C_FILES) $(LDFLAGS)

./FIR_design/fir_coef.h: ./FIR_design/fir_coef_read_from_mat.py ./FIR_design/FIR.mat
	$(PYTHON) $< ./FIR_design/FIR.mat $@

./data/ecg_data.h: ./data/data_format.py ./data/ECGcoe/$(DEST_ECG_SIGNAL).coe
	$(PYTHON) $< ./data/ECGcoe/$(DEST_ECG_SIGNAL).coe $@

plot:
	$(PYTHON) ./data/data_plot.py ./data/ECGcoe/$(DEST_ECG_SIGNAL).coe
	$(PYTHON) ./data/data_plot.py ./data/ECGcoe/$(DEST_ECG_SIGNAL)_filtered.coe

cleanall:
	rm -f $(DESTDIR)/run.exe
	rm -f ./FIR_design/fir_coef.h
	rm -f ./data/ecg_data.h
	rm -f ./data/ECGcoe/$(DEST_ECG_SIGNAL).log
	rm -f ./data/ECGcoe/$(DEST_ECG_SIGNAL)_filtered.coe
	rm -f ./data/ECGcoe/$(DEST_ECG_SIGNAL)_filtered.png
