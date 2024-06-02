import sys
import matplotlib.pyplot as plt

if len(sys.argv) < 2:
    print("Usage: python data_plot.py <data_file_path>")
    sys.exit(1)
file_path = sys.argv[1]

index_list = []
value_list = []

with open(file_path, 'r') as file:
    for line in file:
        # 分割每行的index和value
        parts = line.strip().split(',')
        if len(parts) == 2:
            index = int(parts[0])
            value = float(parts[1])
            index_list.append(index)
            value_list.append(value)

# 绘制ECG信号图
plt.figure(figsize=(10, 5))  # 设置图形大小
plt.plot(index_list, value_list, label='ECG Signal')  # 绘制折线图
plt.title('ECG Signal Chart')  # 设置图表标题
plt.xlabel('Index')  # 设置x轴标签
plt.ylabel('Value')  # 设置y轴标签
plt.legend()  # 显示图例
plt.grid(True)  # 显示网格
# 保存图表为PNG文件
output_image_path = file_path.replace('.csv', '.png')  # 替换文件扩展名
plt.savefig(output_image_path)  # 保存图形
# 显示图形
plt.show()
