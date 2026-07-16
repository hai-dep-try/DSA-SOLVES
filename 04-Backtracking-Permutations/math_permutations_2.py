class sinhvien:
    def __init__(self, ten, msv, scores):
        self.ten = ten
        self.msv = msv
        self.score = scores
    
    def addscore(self, *scores):
        # Accept either multiple numeric args, or a single list/tuple
        if len(scores) == 1 and isinstance(scores[0], (list, tuple)):
            self.score.extend(scores[0])
        else:
            self.score.extend(scores)
    
    def avg(self):
        if not self.score:
            return 0
        return sum(self.score) / len(self.score)
    
p1 = sinhvien("H", 2502, [0])
p1.addscore(6, 7, 8, 9)
print(p1.avg())