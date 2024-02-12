import re

def check_possible(limit_value, lst_vals):
    for val in lst_vals:
        if int(val) > limit_value:
            return True
    return False

file = open("puzzle_input.txt", "r")

sum_ID = 0
num_l = 0
for line in file:
    num_l += 1
    red_vals = re.findall(r'(\d+) red', line)
    if check_possible(12, red_vals):
        continue

    blue_vals = re.findall(r'(\d+) blue', line)
    if check_possible(14, blue_vals):
        continue

    green_vals = re.findall(r'(\d+) green', line)
    if check_possible(13, green_vals):
        continue
    
    sum_ID += num_l

print(sum_ID)