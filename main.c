#include "define.h"
#include "FIR.h"
#include "Pan_Tompkins_detect.h"
#include "ecg_data.h"

#define MIN(a,b) ((a)<(b)?(a):(b))

void Filter(SignalPoint* signal,float *filtered_signal,int signal_length){
    for (int i = 0; i < signal_length; ++i)
    {
        filtered_signal[i] = FIR_filter(signal[i].value);
    }
}

float calculate_heart_rate(float *filtered_signal,int signal_length){
    uint32_t peaks[MAX_PEAKS];
    int num_peaks = 0; // 检测到的QRS波峰值数量
    float sum_intervals = 0.0f;
    float average_heart_rate = 0.0f;

    for (int i = 0; i < signal_length; ++i)
    {
        double result = filtered_signal[i];
        double bandpass;
        double integral;
        double square;

        bandpass = result;
        result = Derivative(result);
        result = Squar(result);
        square = result;
        result = MovingWindowIntegral(result);
        integral = result;

        // 检测QRS波峰
        SignalPoint peak = ThresholdCalculate(i, filtered_signal[i], bandpass, square, integral);

        // 记录QRS波峰
        if (peak.index != -1)
        {
            peaks[num_peaks%MAX_PEAKS]= i;
            printf("Peak detected at index %d, value %f\n", i, filtered_signal[i]);
            // 计算实时平均心率
            if (num_peaks > 0)
            {
                sum_intervals = 0.0f;
                for (int i = num_peaks%MAX_PEAKS; i > 0; i--) {
                    sum_intervals += peaks[i] - peaks[i-1];
                }
                if (num_peaks > MAX_PEAKS-1) {
                    sum_intervals += peaks[0] - peaks[MAX_PEAKS-1];
                    for (int i = MAX_PEAKS-1; i > num_peaks%MAX_PEAKS+1; i--) {
                        sum_intervals += peaks[i] - peaks[i-1];
                    }
                }
                average_heart_rate = 60.0f * (float)SAMPLING_RATE / (sum_intervals / (MIN(num_peaks,MAX_PEAKS-1))); // 计算平均心率（次/分钟）
                printf("Average heart rate: %f\n", average_heart_rate);
            }
            num_peaks++;
        }
    }
    return average_heart_rate;
}

int main(void)
{
    int signal_length = sizeof(ecg_signal) / sizeof(ecg_signal[0]);
    float *filtered_signal = (float *)malloc(signal_length * sizeof(float));
    float average_heart_rate = 0.0f;

    // Signal filtering
    Filter(ecg_signal, filtered_signal, signal_length);

    // Heart rate calculation
    average_heart_rate = calculate_heart_rate(filtered_signal,signal_length);

    // Save filtered signal to file
    FILE *file = fopen("./data/ECGcoe/ECG_filtered.coe", "w");
    if (file == NULL)
    {
        fprintf(stderr, "Cannot open file for writing\n");
        free(filtered_signal);
        return 1;
    }
    fprintf(file, "memory_initialization_radix=10;\n");
    fprintf(file,"memory_initialization_vector=\n");
    for (int i = 0; i < signal_length-1; ++i)
    {
        fprintf(file, "%f,\n", filtered_signal[i]);
    }
    fprintf(file, "%f;\n", filtered_signal[signal_length-1]);
    fclose(file);

    free(filtered_signal);

    return 0;
}
