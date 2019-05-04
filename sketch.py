import pandas
import matplotlib.pyplot as plt

data = pandas.read_csv("out.csv")

plt.ylabel("running time")
plt.xlabel("N")

i = 0
for experiment in data["GSD"]:
    plt.plot(i, experiment, 'g^')
    i += 1
    
i = 0
for experiment in data["DaC"]:
    plt.plot(i, experiment, 'bs')
    i += 1

plt.show()