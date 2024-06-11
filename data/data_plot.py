import sys
import matplotlib.pyplot as plt

if len(sys.argv) < 2:
    print("Usage: python data_plot.py <data_file_path>")
    sys.exit(1)
file_path = sys.argv[1]

index_list = []
value_list = []

# 打开文件读取内容
with open(file_path, 'r') as file:
    lines = file.readlines()
    for index,line in enumerate(lines[2:], start=1):
        # 去除行尾的换行符
        line = line.rstrip('\n')
        # 去除逗号和分号
        line = line.replace(',', '')
        if ';' not in line:
            index_list.append(index)
            value_list.append(float(line))
        else:
            line = line.replace(';', '')
            index_list.append(index)
            value_list.append(float(line))
            break

# 绘制ECG信号图
plt.figure(figsize=(10, 5))  # 设置图形大小
plt.plot(index_list, value_list, label='ECG Signal')  # 绘制折线图
plt.title('ECG Signal Chart')  # 设置图表标题
plt.xlabel('Index')  # 设置x轴标签
plt.ylabel('Value')  # 设置y轴标签
plt.legend()  # 显示图例
plt.grid(True)  # 显示网格
# 保存图表为PNG文件
output_image_path = file_path.replace('.coe', '.png')  # 替换文件扩展名
plt.savefig(output_image_path)  # 保存图形
# 显示图形
plt.show()
