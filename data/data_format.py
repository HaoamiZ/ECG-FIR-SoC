import sys

if len(sys.argv) < 2:
    print("Usage: python data_format.py <data_file_path>")
    sys.exit(1)
input_filename = sys.argv[1]
output_filename = 'ecg_data.h'

# 打开文件读取内容
with open(input_filename, 'r') as file:
    lines = file.readlines()

# 格式化数据并写入文件
with open(output_filename, 'w') as output_file:
    output_file.write("#include \"define.h\"\n")
    output_file.write("SignalPoint ecg_signal[] = {\n")
    for index,line in enumerate(lines[2:], start=1):
        # 去除行尾的换行符
        line = line.rstrip('\n')
        # 去除逗号和分号
        line = line.replace(',', '')
        if ';' not in line:
            output_file.write(f"{{{line},{index}}},\n")
        else:
            line = line.replace(';', '')
            output_file.write(f"{{{line},{index}}},\n")
            break
    output_file.write("};")

print(f"Formatted data has been written to {output_filename}")
