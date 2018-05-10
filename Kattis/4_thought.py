from sets import Set
solutions = ["4"]
solutionsvalue = {}

for i in range(3):
	onetime = []
	for solution in solutions:
		onetime.append(solution + " * 4")
		onetime.append(solution + " + 4")
		onetime.append(solution + " - 4")
		onetime.append(solution + " / 4")
	solutions = onetime
liste = []
for solution in solutions:
	liste.append(eval(solution))
	solutionsvalue[int(eval(solution))] = solution
print(Set(sorted(liste)))
N = int(input())
for i in range(N):
	M = int(input())
	if M in solutionsvalue:
		print(solutionsvalue[M] + " = " + str(M))
			
	else:
		print('no solution')