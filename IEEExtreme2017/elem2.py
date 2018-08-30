
f1 = open('out2.txt')
f2 = open('out3.txt')
for line in f1:
    line2 = f2.readline()
    print('M["{0}"] = "{1}"'.format(line.strip(), line2.strip()))
f1.close()
f2.close()