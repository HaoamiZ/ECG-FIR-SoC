#include "define.h"
#include "FIR.h"
#include "Pan_Tompkins_detect.h"

#define MIN(a,b) ((a)<(b)?(a):(b))

SignalPoint ecg_signal[] = {
    {1973, 66505},
    {1967, 66506},
    {1967, 66507},
    {1965, 66508},
    {1976, 66509},
    {1978, 66510},
    {1978, 66511},
    {1969, 66512},
    {1964, 66513},
    {1964, 66514},
    {1983, 66515},
    {1983, 66516},
    {1991, 66517},
    {1991, 66518},
    {1988, 66519},
    {1984, 66520},
    {1994, 66521},
    {1994, 66522},
    {1998, 66523},
    {1998, 66524},
    {1977, 66525},
    {1977, 66526},
    {1991, 66527},
    {1998, 66528},
    {1998, 66529},
    {1991, 66530},
    {1991, 66531},
    {1985, 66532},
    {1989, 66533},
    {1997, 66534},
    {1998, 66535},
    {1998, 66536},
    {1988, 66537},
    {1988, 66538},
    {1993, 66539},
    {2005, 66540},
    {2015, 66541},
    {2013, 66542},
    {2002, 66543},
    {1994, 66544},
    {2008, 66545},
    {2018, 66546},
    {2014, 66547},
    {2007, 66548},
    {2007, 66549},
    {2015, 66550},
    {2015, 66551},
    {2024, 66552},
    {2026, 66553},
    {2024, 66554},
    {2018, 66555},
    {2011, 66556},
    {2017, 66557},
    {2029, 66558},
    {2042, 66559},
    {2042, 66560},
    {2039, 66561},
    {2045, 66562},
    {2045, 66563},
    {2056, 66564},
    {2037, 66565},
    {2037, 66566},
    {2021, 66567},
    {2013, 66568},
    {2043, 66569},
    {2043, 66570},
    {2059, 66571},
    {2069, 66572},
    {2063, 66573},
    {2051, 66574},
    {2054, 66575},
    {2062, 66576},
    {2062, 66577},
    {2058, 66578},
    {2058, 66579},
    {2054, 66580},
    {2058, 66581},
    {2068, 66582},
    {2071, 66583},
    {2073, 66584},
    {2070, 66585},
    {2076, 66586},
    {2090, 66587},
    {2120, 66588},
    {2148, 66589},
    {2159, 66590},
    {2124, 66591},
    {2124, 66592},
    {2098, 66593},
    {2095, 66594},
    {2088, 66595},
    {2088, 66596},
    {2050, 66597},
    {2030, 66598},
    {2038, 66599},
    {2038, 66600},
    {2039, 66601},
    {2033, 66602},
    {2018, 66603},
    {2007, 66604},
    {2007, 66605},
    {2018, 66606},
    {2027, 66607},
    {2027, 66608},
    {2006, 66609},
    {2006, 66610},
    {2006, 66611},
    {2011, 66612},
    {2009, 66613},
    {2009, 66614},
    {1990, 66615},
    {1990, 66616},
    {1995, 66617},
    {2009, 66618},
    {2022, 66619},
    {2022, 66620},
    {2013, 66621},
    {2002, 66622},
    {2017, 66623},
    {2027, 66624},
    {2027, 66625},
    {2034, 66626},
    {2026, 66627},
    {2015, 66628},
    {2019, 66629},
    {2019, 66630},
    {2025, 66631},
    {2023, 66632},
    {2015, 66633},
    {2023, 66634},
    {2038, 66635},
    {2038, 66636},
    {2046, 66637},
    {2042, 66638},
    {1981, 66639},
    {1946, 66640},
    {1946, 66641},
    {1861, 66642},
    {1861, 66643},
    {1855, 66644},
    {1898, 66645},
    {1989, 66646},
    {1989, 66647},
    {2121, 66648},
    {2471, 66649},
    {2471, 66650},
    {3018, 66651},
    {3447, 66652},
    {3851, 66653},
    {4011, 66654},
    {4011, 66655},
    {4006, 66656},
    {3912, 66657},
    {3162, 66658},
    {2761, 66659},
    {2461, 66660},
    {2237, 66661},
    {2237, 66662},
    {2080, 66663},
    {1991, 66664},
    {1990, 66665},
    {2039, 66666},
    {2030, 66667},
    {2030, 66668},
    {1988, 66669},
    {1988, 66670},
    {1977, 66671},
    {1975, 66672},
    {1976, 66673},
    {1969, 66674},
    {1955, 66675},
    {1949, 66676},
    {1951, 66677},
    {1951, 66678},
    {1943, 66679},
    {1943, 66680},
    {1928, 66681},
    {1928, 66682},
    {1938, 66683},
    {1963, 66684},
    {1966, 66685},
    {1966, 66686},
    {1963, 66687},
    {1958, 66688},
    {1958, 66689},
    {1967, 66690},
    {1970, 66691},
    {1971, 66692},
    {1967, 66693},
    {1964, 66694},
    {1970, 66695},
    {1988, 66696},
    {1988, 66697},
    {1992, 66698},
    {1999, 66699},
    {2011, 66700},
    {2011, 66701},
    {2024, 66702},
    {2036, 66703},
    {2042, 66704},
    {2031, 66705},
    {2020, 66706},
    {2034, 66707},
    {2042, 66708},
    {2042, 66709},
    {2051, 66710},
    {2051, 66711},
    {2051, 66712},
    {2071, 66713},
    {2098, 66714},
    {2120, 66715},
    {2113, 66716},
    {2113, 66717},
    {2104, 66718},
    {2112, 66719},
    {2141, 66720},
    {2141, 66721},
    {2150, 66722},
    {2148, 66723},
    {2148, 66724},
    {2179, 66725},
    {2196, 66726},
    {2196, 66727},
    {2207, 66728},
    {2217, 66729},
    {2217, 66730},
    {2250, 66731},
    {2250, 66732},
    {2267, 66733},
    {2267, 66734},
    {2268, 66735},
    {2270, 66736},
    {2293, 66737},
    {2293, 66738},
    {2298, 66739},
    {2307, 66740},
    {2314, 66741},
    {2326, 66742},
    {2326, 66743},
    {2342, 66744},
    {2352, 66745},
    {2351, 66746},
    {2347, 66747},
    {2347, 66748},
    {2355, 66749},
    {2344, 66750},
    {2318, 66751},
    {2318, 66752},
    {2239, 66753},
    {2221, 66754},
    {2221, 66755},
    {2180, 66756},
    {2180, 66757},
    {2119, 66758},
    {2119, 66759},
    {2081, 66760},
    {2065, 66761},
    {2062, 66762},
    {2062, 66763},
    {2003, 66764},
    {2003, 66765},
    {1963, 66766},
    {1943, 66767},
    {1935, 66768},
    {1920, 66769},
    {1920, 66770},
    {1903, 66771},
    {1896, 66772},
    {1896, 66773},
    {1901, 66774},
    {1902, 66775},
    {1897, 66776},
    {1897, 66777},
    {1890, 66778},
    {1894, 66779},
    {1894, 66780},
    {1894, 66781},
    {1894, 66782},
    {1894, 66783},
    {1886, 66784},
    {1885, 66785},
    {1889, 66786},
    {1889, 66787},
    {1886, 66788},
    {1878, 66789},
    {1877, 66790},
    {1885, 66791},
    {1885, 66792},
};

int main(void)
{
    int signal_length = sizeof(ecg_signal) / sizeof(ecg_signal[0]);
    float *filtered_signal = (float *)malloc(signal_length * sizeof(float));

    uint32_t peaks[MAX_PEAKS];
    int num_peaks = 0; // 检测到的QRS波峰值数量
    float average_heart_rate = 0.0f;
    float sum_intervals = 0.0f;

    for (int i = 0; i < signal_length; ++i)
    {
        filtered_signal[i] = FIR_filter(ecg_signal[i].value);

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
            peaks[num_peaks%MAX_PEAKS]= i + ecg_signal[0].index;
            printf("Peak detected at index %d, value %f\n", i + ecg_signal[0].index, filtered_signal[i]);
            // 计算实时平均心率
            if (num_peaks > 0)
            {
                float sum_intervals = 0.0f;
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

    // Save filtered signal to file
    FILE *file = fopen("./data/filtered_data.csv", "w");
    if (file == NULL)
    {
        fprintf(stderr, "Cannot open file for writing\n");
        free(filtered_signal);
        return 1;
    }
    for (int i = 0; i < signal_length; ++i)
    {
        fprintf(file, "%d,%f\n", i+ecg_signal[0].index, filtered_signal[i]);
    }
    fclose(file);

    free(filtered_signal);

    return 0;
}
