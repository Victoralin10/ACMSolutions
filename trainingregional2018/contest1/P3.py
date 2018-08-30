import sys

def get_cases():
	casos = []
	ccaso = []
	for line in sys.stdin:
		line = line.strip()
		if line == "":
			if len(ccaso) > 0:
				casos.append(ccaso)
				ccaso = []
		else:
			ccaso.append(line)
	if len(ccaso) > 0:
		casos.append(ccaso)
	return casos

def solve_case(caso):
	digits = caso[0]
	mp = {}
	for i, c in enumerate(digits):
		mp[c] = i
	
	ans = []
	for i in range(1, len(caso)):
		suma = 0
		a = 0
		b = len(digits)
		for c in caso[i]:
			a = max(a, mp[c])
		a += 1

		pot = [1]*(b - a + 1)
		for j, c in enumerate(reversed(caso[i])):
			suma += mp[c]*sum(pot)
			for k in range(a, b + 1):
				pot[k-a] *= k
		ans.append(suma)
	return ans

casos = get_cases()
pri = True
for caso in casos:
	if not pri:
		print("")
	pri = False
	for x in solve_case(caso):
		print(x)
