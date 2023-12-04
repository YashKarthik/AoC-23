f = open("./input4.txt").readlines();
t = []
for i in f:
    l = []
    for j in i.strip().split()[2:]:
        try:
            l.append(int(j))
        except:
            pass

    t.append(l)

ss = 0
for line in t:
    num_common = len(set(line[:5]).intersection(set(line[5:])))
    s = 0
    for i in range(num_common):
        s = 1 if s == 0 else s*2

    ss += s

print(ss)

#########################

dict = {i:1 for i in range(1, len(f) + 1)}
print(dict)

for i, row in enumerate(f, start=1):
    count = 0

    winning_numbers = row.split("|")[0].split(" ")[2:]
    hand = row.split("|")[1]

    winning_numbers = list(filter(lambda a: a != '', winning_numbers))

    for card in hand.split():
        if card in winning_numbers:
            count += 1

    for j in range(i + 1, i + count + 1):
        dict[j] = dict.get(j,0) + dict[i]

print(sum(dict.values()))
