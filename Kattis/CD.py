#from sets import Set


def solver():
	return
s = input().split(" ")
N = int(s[0])
M = int(s[1])

kevin = set()
quentin = set()
for _ in range(N):
	kevin.add(input())
for _ in range(M):
	quentin.add(input())
print(len(kevin & quentin))
#print(kevin)
#print(quentin)