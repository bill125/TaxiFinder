# -*- coding: UTF-8 -*- 
import json
import random
 
file_name = '../data/road_js.cnode'
file_out = '../data/road.cnode.json'
# nums = [3, 4, 5, 7, 1, 9]
# nums = {"name": "Mike", "age": 12}

with open(file_name) as file_object:
    contents = file_object.read()
print(len(contents))

nums = []
lines = contents.split('\n')
for line in lines:
    pos = line.split(' ')
    print(pos)
    x = float(pos[0])
    y = float(pos[1])
    if (random.random() > 0.9):
        nums.append([x, y])

with open(file_out, 'w') as file_obj:
    # '''写入json文件'''
    json.dump(nums, file_obj)
    # print("写入json文件：", nums)