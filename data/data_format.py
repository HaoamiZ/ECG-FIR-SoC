# 指定输入和输出文件名
input_filename = 'data.csv'
output_filename = 'formatted_data.txt'

# 打开文件读取内容
with open(input_filename, 'r') as file:
    lines = file.readlines()

# 格式化数据并写入文件
with open(output_filename, 'w') as output_file:
    for line in lines:
        parts = line.strip().split(',')
        output_file.write(f"{{{parts[1]},{parts[0]}}},\n")

print(f"Formatted data has been written to {output_filename}")
