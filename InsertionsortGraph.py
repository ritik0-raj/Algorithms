import matplotlib.pyplot as plt

# Input sizes and corresponding average times in nanoseconds
input_sizes = [
    1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000,
    11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000
]

average_times_ns = [
    569335, 1207448, 2618070, 4650126, 7218736, 10428125, 14000189, 18594240,
    23208925, 30718454, 35630044, 41165353, 50219065, 56219305, 64364419,
    72924348, 82467688, 91968751, 102581846, 113309218
]

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(input_sizes, average_times_ns, marker='o', color='blue', linestyle='-', linewidth=2, markersize=5)

plt.title("Insertion Sort: Input Size vs Average Time")
plt.xlabel("Input Size")
plt.ylabel("Average Time (ns)")
plt.grid(True, linestyle='--', alpha=0.7)

# Optional: show values on each point
for x, y in zip(input_sizes, average_times_ns):
    plt.text(x, y, f"{y}", fontsize=8, ha='right', va='bottom')

plt.tight_layout()
plt.show()