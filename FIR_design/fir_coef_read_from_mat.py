import sys
import scipy.io

if len(sys.argv) < 2:
    print("Usage: python fir_coef_read_from_mat.py <mat_file_path>")
    sys.exit(1)
mat_file_path = sys.argv[1]
mat = scipy.io.loadmat(mat_file_path)

fir_coefficient = mat['Num'][0]

with open("fir_coef.h","w") as f:
    f.write("#ifndef __FIR_COEFFICIENT_H__\n")
    f.write("#define __FIR_COEFFICIENT_H__\n")
    f.write(f"#define taps {len(fir_coefficient)}\n")
    f.write("static const float coefficients[taps] = {")
    for i in range(len(fir_coefficient)):
        if i % 4 == 0:
            f.write("\n")
        f.write(f"{fir_coefficient[i]},")
    f.write("};\n")
    f.write("#endif")
    f.close()
