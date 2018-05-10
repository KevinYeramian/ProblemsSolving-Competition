
def solver(nbnb):
	dico = {}
	liste = []
	for _ in range(nbnb):
		s = input()
		liste.append(s)
	liste.sort(reverse=True)
	#print(liste)
	for i,s in enumerate(liste):
		s = str(s)
		dicoaux = dico
		flag = True
		#print(s)
		for letter in s:
			#print(letter)
			if letter in dicoaux.keys():
				dicoaux = dicoaux[letter]
			else:
				#print(letter)
				flag = False
				dicoaux[letter] = {}
				dicoaux = dicoaux[letter]
		if flag:
			if not s in liste[:i]:
				print("NO")
				return
	#print(dico)
	print("YES")
N = int(input())
for i in range(N):
	M = int(input())
	solver(M)