# ECG-FIR-SoC

A SoC for ECG signal processing with FIR filter.

## Software

FIR and Pan_Tompkins_detect refer to https://github.com/GCY/wxECGAnalyzer.git

```
├── main.c
├── FIR.c # FIR filter implementation
├── FIR.h
├── Pan_Tompkins_detect.c # Use Pan-Tompkins algorithm for detecting QRS complexes
├── Pan_Tompkins_detect.h
├── data
│   ├── ECGcoe # ECG signal data
│   ├── data_format.py # convert ECG signal data to variable in c header file
│   ├── data_plot.py # plot ECG signal
├── FIR_design
│   ├── FIR.mat # FIR filter coefficients design by MATLAB
│   ├── fir_coef_read_from_mat.py # convert FIR filter coefficients to variable in c header file
├── Makefile
├── README.md
```

How to use:
```bash
make run
make plot
make clean
```

## Hardware