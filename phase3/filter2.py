import sys
file = open(sys.argv[1],'r')

array = []
with open('mini_l_fixed.txt', 'a') as the_file:
	for line in file:
		if "printf" in line and "{" in line:
			left = line.find("{") + 1
			right = line.find("}")
			line = line[:left] + line[right:]
		the_file.write(line)