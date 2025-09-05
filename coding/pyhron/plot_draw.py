
import numpy as np
import matplotlib.pyplot as plt

# Constants for decay factors
decay_1min = np.exp(-5/60)
decay_5min = np.exp(-5/300)
decay_15min = np.exp(-5/900)

# Number of runnable processes
n_runnable = 3

# Time period (10 minutes, updated every 5 seconds)
time_period = 10 * 60 // 5

# Initialize load averages
load_1min = [0]
load_5min = [0]
load_15min = [0]

# Calculate load averages over time
for _ in range(time_period):
    load_1min.append(load_1min[-1] * decay_1min + n_runnable * (1 - decay_1min))
    load_5min.append(load_5min[-1] * decay_5min + n_runnable * (1 - decay_5min))
    load_15min.append(load_15min[-1] * decay_15min + n_runnable * (1 - decay_15min))

# Time axis (in minutes)
time_axis = np.arange(0, (time_period + 1) * 5, 5) / 60

# Plot the load averages
plt.figure(figsize=(10, 6))
plt.plot(time_axis, load_1min, label='1-minute load average')
plt.plot(time_axis, load_5min, label='5-minute load average')
plt.plot(time_axis, load_15min, label='15-minute load average')
plt.xlabel('Time (minutes)')
plt.ylabel('Load Average')
plt.title('Load Average Evolution Over Time with 3 Runnable Processes')
plt.legend()
plt.grid(True)
plt.show()
