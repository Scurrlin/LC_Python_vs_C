import pandas as pd
import matplotlib.pyplot as plt

file_path = 'Python&C_raw_data.xlsx'
excel_data = pd.ExcelFile(file_path)

runtime_data = pd.read_excel(
    excel_data,
    sheet_name='Runtime',
    header=None
)

memory_data = pd.read_excel(
    excel_data,
    sheet_name='Memory',
    header=None
)

def create_bar_graph(x, y1, y2, labels, title, y_label, filename, note, y_ticks, include_note):
    plt.figure(figsize=(14, 8))
    
    bar_width = 0.35
    index = range(len(x))
    
    plt.bar(index, y1, bar_width, label='Python', color='#3572A5')
    plt.bar([i + bar_width for i in index], y2, bar_width, label='C', color='#555555')

    plt.xlabel(labels['x_label'])
    plt.ylabel(y_label)
    plt.title(title)
    plt.xticks([i + bar_width / 2 for i in index], x, rotation=45, ha="right")
    plt.yticks(y_ticks)
    plt.legend(loc='upper right')
    
    plt.grid(axis='both', linestyle='--', linewidth=0.5, color='gray', alpha=0.7)

    plt.tight_layout(rect=[0, 0.05, 1, 1])
    if include_note:
        plt.figtext(0.5, 0.01, note, wrap=True, horizontalalignment='center', fontsize=8)
    
    plt.savefig(filename)
    plt.close()

problems = [39, 46, 78, '53*', 169, 240, 70, 198, '300*', '200*', 733, 994, '55*', 406, '452*', 33, 374, 704, 3, 438, 567, 56, 57, '912A*', '912B*', 94, 144, 230, '11*', '15*', 344]
python_runtime_values = [runtime_data.iat[i, 5] for i in range(3, 64, 2)]
c_runtime_values = [runtime_data.iat[i, 5] for i in range(4, 65, 2)]

create_bar_graph(problems, python_runtime_values, c_runtime_values, 
                 {'x_label': 'LeetCode Problem #'}, 
                 'Average Runtime (ms) by LeetCode Problem #', 
                 'Average Runtime (ms)', 
                 'avg_runtime_by_lc_problem.png', 
                 '*Runtime reduced by a factor of 10 to not skew data visualization',
                 [0, 25, 50, 75, 100, 125, 150, 175],
                 include_note=True)

algorithms = ['Backtracking', 'Divide & Conquer', 'Dynamic Programming', 'Graphs', 'Greedy', 'Searching', 'Sliding Window', 'Sorting', 'Trees', 'Two Pointers']
python_algo_runtime = [runtime_data.iat[i, 4] for i in [3, 9, 15, 21, 27, 33, 39, 45, 53, 59]]
c_algo_runtime = [runtime_data.iat[i, 4] for i in [4, 10, 16, 22, 28, 34, 40, 46, 54, 60]]

create_bar_graph(algorithms, python_algo_runtime, c_algo_runtime, 
                 {'x_label': 'Algorithm'}, 
                 'Average Runtime (ms) by Algorithm', 
                 'Average Runtime (ms)', 
                 'avg_runtime_by_algorithm.png', 
                 '',
                 [0, 20, 40, 60, 80, 100, 120],
                 include_note=False)

memory_problems = [39, 46, 78, 53, 169, 240, 70, 198, 300, 200, 733, 994, 55, 406, 452, 33, 374, 704, 3, 438, 567, 56, 57, '912A*', '912B', 94, 144, 230, 11, 15, 344]
python_memory_values = [memory_data.iat[i, 5] for i in range(3, 64, 2)]
c_memory_values = [memory_data.iat[i, 5] for i in range(4, 65, 2)]

create_bar_graph(memory_problems, python_memory_values, c_memory_values, 
                 {'x_label': 'LeetCode Problem #'}, 
                 'Average Memory (MB) by LeetCode Problem #', 
                 'Average Memory (MB)', 
                 'avg_memory_by_lc_problem.png', 
                 '*Memory reduced by a factor of 10 to not skew data visualization',
                 [0, 20, 40, 60, 80],
                 include_note=True)

memory_algo_python = [memory_data.iat[i, 4] for i in [3, 9, 15, 21, 27, 33, 39, 45, 53, 59]]
memory_algo_c = [memory_data.iat[i, 4] for i in [4, 10, 16, 22, 28, 34, 40, 46, 54, 60]]

create_bar_graph(algorithms, memory_algo_python, memory_algo_c, 
                 {'x_label': 'Algorithm'}, 
                 'Average Memory (MB) by Algorithm', 
                 'Average Memory (MB)', 
                 'avg_memory_by_algorithm.png', 
                 '',
                 [0, 10, 20, 30, 40, 50],
                 include_note=False)

print("Visualizations have been generated and saved successfully.")