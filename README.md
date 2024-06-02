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
│   ├── data.csv # orignal ECG signal data
│   ├── data_format.py # convert original data to c format
│   ├── data_plot.py # plot ECG signal
├── Makefile
├── README.md
```

How to use:
```bash
make
```
BUT now FIR filter is not usefull, because it is not optimized.

## Hardware