import matplotlib.pyplot as plt
import os

path = os.path.join(os.path.dirname(__file__), "percolation_probability.txt")
print(path)
data = open(path, "r").readlines()
x = []
y = []
for line in data:
    x.append(float(line.split()[0]))
    y.append(float(line.split()[1]))

plt.plot(x, y, "o-")
plt.xlabel("p")
plt.ylabel("P")
plt.title("Percolation Probability")
plt.show()
