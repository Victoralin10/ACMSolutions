import sys

cs = "abcdefghijklmnopqrstuvwxyyz "
st = set()

for line in sys.stdin:
    line = line.lower()
    line = "".join([c for c in line if c in cs])
    for pal in line.split():
        if len(pal) > 0:
            st.add(pal)

for pal in st:
    print(pal)