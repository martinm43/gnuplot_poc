"""
Quick and dirty program to show how the True Hit formula works
in most of the Fire Emblem games. You can do this with factorials
but it's easier to just use Monte Carlo simulation.
"""

import random
from matplotlib import pyplot as plt

count = 0
runs = 100000
stored_real_odds = []

for printed_odds in range(1,100):
    count = 0 # start at zero.
    for i in range (1,runs):
        num1 = random.randint(0, 100)
        num2 = random.randint(0, 100)

        # Calculate the average
        average = (num1 + num2) / 2.0

        # Determine if the average is less than the printed odds
        if average < printed_odds:
            count += 1
    
    stored_real_odds.append([printed_odds,count/runs*100])

x_values = [item[0] for item in stored_real_odds]
y_values = [item[1] for item in stored_real_odds]

# Set up the plot
plt.figure()
plt.plot(x_values, y_values, marker='o', linestyle='-', color='r')  # Plotting data points

# Adding labels and title
plt.xlabel('Displayed Hit Odds')
plt.ylabel('Actual Hit Odds')
plt.title('True Hit In FE7 Onwards through at least FE13')

plt.xticks(range(0, 101, 10))
plt.yticks(range(0, 101, 10))

# Display grid
plt.grid(True)

# Save the plot as a PNG image
plt.savefig('plot_py.png')

# Show the plot
plt.show()



