file = open("puzzle_input.txt", "r")

sum_calib_val = 0
for line in file:
    for char in line:
        if char.isnumeric():
            fst_num = char
            break
    
    idx = 1
    while True:
        if line[-idx].isnumeric():
            snd_num = line[-idx]
            break
        idx += 1
    sum_calib_val += int(fst_num + snd_num)

file.close()
print(sum_calib_val)