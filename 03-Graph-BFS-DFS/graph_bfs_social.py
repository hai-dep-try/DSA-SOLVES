from collections import deque
class SocialGraph:
    def __init__(self):
        # Tại sao dùng Dict mà không dùng List? 
        # Để tra cứu tên "Alice" nhanh hơn là index 0, 1, 2
        self.adj_list = {} 

    def add_user(self, user):
        if user not in self.adj_list:
            self.adj_list[user] = set()

    def add_friend(self, user1, user2):
        self.add_user(user1) #add user1
        self.add_user(user2) #add user2
        self.adj_list[user1].add(user2) #add user2 to set friend of user1 and dont worry abt repeat
        self.adj_list[user2].add(user1) #similary



    def get_shortest_path_bfs(self, start_node, target_node):
        # 0. Kiểm tra cơ bản: Nếu start hoặc target không tồn tại thì nghỉ khỏe
        if start_node not in self.adj_list or target_node not in self.adj_list:
            return -1
        
        # 1. Khởi tạo Queue và tập Visited
        # Queue lưu trữ một tuple: (tên_người, khoảng_cách_từ_start)
        queue = deque( [ (start_node, 0) ] ) 
        visited = {start_node} #dung set
        
        # 2. Bắt đầu vòng lặp
        while queue: # Chừng nào hàng đợi chưa rỗng
            current_node, dist = queue.popleft()
            if current_node == target_node:
                return dist
            for neighbor in self.adj_list[current_node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append([neighbor, dist + 1])
            
            # --- HẾT CODE CỦA BẠN ---

        return -1 # Nếu duyệt hết mà không thấy

fb = SocialGraph()
edges = [
    ('A', 'B'), ('B', 'C'), ('C', 'D'), ('D', 'E'), # Line: 4 bước
    ('A', 'F'), ('F', 'E'),                         # Shortcut: 2 bước
    ('B', 'H'), ('H', 'K')                          # Nhánh rẽ linh tinh
]

for u, v in edges:
    fb.add_friend(u, v)

# Kiểm tra kết quả
print("Tìm đường từ A đến E:")
steps = fb.get_shortest_path_bfs('A', 'E')

if steps == 2:
    print(f"✅ CHÍNH XÁC! Tìm thấy đường ngắn nhất là {steps} bước (qua F).")
else:
    print(f"❌ SAI RỒI. Kết quả ra {steps}, đáng lẽ phải là 2.")