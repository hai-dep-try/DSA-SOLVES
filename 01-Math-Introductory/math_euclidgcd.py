import math

# 1. Định nghĩa cấu trúc Node
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 2. Hàm hỗ trợ in cây (Dạng Text) để dễ nhìn
def print_tree(node, level=0, prefix="Gốc: "):
    if node is None:
        return
    print(" " * (level * 4) + prefix + str(node.val))
    if node.left:
        print_tree(node.left, level + 1, "L--- ")
    if node.right:
        print_tree(node.right, level + 1, "R--- ")

# 3. Class Giải thuật (Có gắn camera theo dõi)
class SolutionVisualizer:
    
    def balanceBST(self, root: TreeNode) -> TreeNode:
        if not root: return None
        
        print("\n=== BẮT ĐẦU: CÂY BAN ĐẦU ===")
        print_tree(root)

        # --- STEP 1: DUỖI THẲNG (VINE) ---
        print("\n[STEP 1] Tạo Vine (Duỗi thẳng cây thành dây)")
        vine_head = TreeNode(0)
        vine_head.right = root
        current = vine_head
        
        while current.right:
            if current.right.left:
                # Phát hiện gấp khúc -> Xoay phải
                self.right_rotate(current, current.right)
            else:
                current = current.right
        
        print("-> Đã duỗi xong! Hình dáng Vine:")
        print_tree(vine_head.right) # In dây ra xem

        # --- STEP 2: ĐẾM SỐ LƯỢNG NODE ---
        node_count = 0
        current = vine_head.right
        while current:
            node_count += 1
            current = current.right
        print(f"\n[STEP 2] Tổng số node đếm được: {node_count}")

        # --- STEP 3: TÁI CÂN BẰNG (FOLDING) ---
        print("\n[STEP 3] Bắt đầu gấp cây (Rebalance)")
        
        # Tính toán lõi hoàn hảo
        m = 2 ** math.floor(math.log2(node_count + 1)) - 1
        print(f"-> Kích thước lõi hoàn hảo (m) = {m}")
        print(f"-> Số node thừa cần xử lý trước = {node_count - m}")

        # Xử lý node thừa
        self.make_rotations(vine_head, node_count - m)
        print("-> Sau khi xử lý node thừa (Lớp đáy):")
        print_tree(vine_head.right)

        # Vòng lặp gấp đôi
        step = 1
        while m > 1:
            m //= 2
            print(f"\n-> Gấp lần thứ {step} (m={m}):")
            self.make_rotations(vine_head, m)
            print_tree(vine_head.right)
            step += 1

        balanced_root = vine_head.right
        vine_head = None
        return balanced_root

    # Hàm xoay phải (Right Rotate)
    def right_rotate(self, parent, node):
        tmp = node.left
        node.left = tmp.right
        tmp.right = node
        parent.right = tmp

    # Hàm xoay trái (Left Rotate)
    def left_rotate(self, parent, node):
        tmp = node.right
        node.right = tmp.left
        tmp.left = node
        parent.right = tmp

    # Hàm thực hiện loạt xoay trái
    def make_rotations(self, vine_head, count):
        current = vine_head
        for _ in range(count):
            tmp = current.right
            self.left_rotate(current, tmp)
            current = current.right

# --- CHẠY THỬ NGHIỆM ---
if __name__ == "__main__":
    # Tạo một cái cây xấu xí (Linked List: 10 -> 20 -> 30... -> 70)
    root = TreeNode(10)
    root.right = TreeNode(20)
    root.right.right = TreeNode(30)
    root.right.right.right = TreeNode(40)
    root.right.right.right.right = TreeNode(50)
    root.right.right.right.right.right = TreeNode(60)
    root.right.right.right.right.right.right = TreeNode(70)

    solver = SolutionVisualizer()
    new_root = solver.balanceBST(root)

    print("\n=== KẾT QUẢ CUỐI CÙNG ===")
    print_tree(new_root)