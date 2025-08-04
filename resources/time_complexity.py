import numpy as np
import matplotlib.pyplot as plt

# Data range
n = np.arange(2, 101)

# Big O example: f(n) = n log n, upper bound g(n) = n^2 (showing f(n) = O(n^2))
f_big_o = n * np.log2(n)
upper_bound_big_o = n ** 2

plt.figure()
plt.scatter(n, f_big_o, label=r"$f(n) = n \log_2 n$ (data points)", s=10)
plt.plot(n, upper_bound_big_o, label=r"Upper bound $g(n) = n^2$", linewidth=1.5)
plt.title("Big O Notation: $f(n) = O(n^2)$")
plt.xlabel("n")
plt.ylabel("Time / Growth")
plt.legend()
plt.grid(True)

# Big Omega example: f(n) = n log n, lower bound h(n) = n (showing f(n) = Ω(n))
f_big_omega = n * np.log2(n)
lower_bound_big_omega = n

plt.figure()
plt.scatter(n, f_big_omega, label=r"$f(n) = n \log_2 n$ (data points)", s=10)
plt.plot(n, lower_bound_big_omega, label=r"Lower bound $h(n) = n$", linewidth=1.5)
plt.title("Big Omega Notation: $f(n) = \Omega(n)$")
plt.xlabel("n")
plt.ylabel("Time / Growth")
plt.legend()
plt.grid(True)

# Theta example: noisy f(n) around n log n, bounds 0.8*n log n and 1.2*n log n
base_theta = n * np.log2(n)
np.random.seed(42)
f_theta = base_theta * (1 + np.random.uniform(-0.15, 0.15, size=n.shape))
lower_theta = 0.8 * base_theta
upper_theta = 1.2 * base_theta

plt.figure()
plt.scatter(n, f_theta, label=r"Noisy $f(n) \approx n \log_2 n$", s=10)
plt.plot(n, lower_theta, label=r"Lower tight bound $0.8 \cdot n \log_2 n$", linewidth=1.5)
plt.plot(n, upper_theta, label=r"Upper tight bound $1.2 \cdot n \log_2 n$", linewidth=1.5)
plt.title("Theta Notation: $f(n) = \Theta(n \log n)$")
plt.xlabel("n")
plt.ylabel("Time / Growth")
plt.legend()
plt.grid(True)

plt.show()
