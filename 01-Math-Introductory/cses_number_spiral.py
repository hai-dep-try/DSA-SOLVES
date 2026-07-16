import numpy as np
import matplotlib.pyplot as plt

# 1. Khởi tạo dữ liệu
# Tạo lưới tọa độ x, y cho mặt đáy (hình vuông từ 0 đến 1)
x = np.linspace(0, 1, 100)
y = np.linspace(0, 1, 100)
X, Y = np.meshgrid(x, y)

# Tính độ cao Z cho từng khối
# Khối a: z = 4 - x - 2y
Z_a = 4 - X - 2*Y

# Khối b: z = 2 - x^2 - y^2
Z_b = 2 - X**2 - Y**2

# 2. Thiết lập đồ thị 3D
fig = plt.figure(figsize=(14, 6))

# --- Vẽ Khối a ---
ax1 = fig.add_subplot(121, projection='3d')
# Vẽ mặt cong phía trên
surf1 = ax1.plot_surface(X, Y, Z_a, cmap='viridis', alpha=0.8, edgecolor='none')
ax1.set_title('Khối a: $z = 4 - x - 2y$', fontsize=14)
ax1.set_xlabel('Trục X')
ax1.set_ylabel('Trục Y')
ax1.set_zlabel('Trục Z')
# Giới hạn trục để nhìn rõ hình dáng
ax1.set_xlim([0, 1])
ax1.set_ylim([0, 1])
ax1.set_zlim([0, 4])
fig.colorbar(surf1, ax=ax1, shrink=0.5, aspect=10)

# --- Vẽ Khối b ---
ax2 = fig.add_subplot(122, projection='3d')
# Vẽ mặt cong phía trên (paraboloid)
surf2 = ax2.plot_surface(X, Y, Z_b, cmap='plasma', alpha=0.8, edgecolor='none')
ax2.set_title('Khối b: $z = 2 - x^2 - y^2$', fontsize=14)
ax2.set_xlabel('Trục X')
ax2.set_ylabel('Trục Y')
ax2.set_zlabel('Trục Z')
# Giới hạn trục 
ax2.set_xlim([0, 1])
ax2.set_ylim([0, 1])
ax2.set_zlim([0, 2])
fig.colorbar(surf2, ax=ax2, shrink=0.5, aspect=10)

# 3. Hiển thị kết quả
plt.tight_layout()
plt.show()