import sys
file = open(sys.argv[1],'r')

array = []
for line in file:
	array.append(line.split())

with open('output.txt', 'a') as the_file:
    #for x in array:
	#	if len(str(x[0])) < 3:
	#		the_file.write(x[0] + "\t" + "[" + x[0] + "]" "\n")
    for x in array:
		temp1 = str(x[0])
		temp2 =  str(x[1]) 
		temp = "\"" + temp1 + "\" \t" + "{printf(\"" + temp2 + "\");}\n"
		the_file.write(temp)
