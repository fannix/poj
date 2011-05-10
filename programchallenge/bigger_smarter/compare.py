from subprocess import Popen
from subprocess import PIPE
import sys
import os

def execute(exe, input):
	p1 = Popen([exe], shell=True, stdin=PIPE, stdout=PIPE)
	p1.stdin.write(input)

	return p1.communicate()[0]

def random_input():
	import random

	num = random.randint(1, 1000)
	input = ""

	for i in range(num):
		input += str(random.randint(1, 10000))
		input += " "
		input += str(random.randint(1, 10000))
		input += '\n'

	return input

def check_sequence(input, output2):
	li = input.split('\n')
	
	li2 = output2.split()[1:]

	for i in range(len(li2)-1):
		ind1 = int(li2[i].strip()) - 1
		ind2 = int(li2[i+1].strip()) - 1

		weight1, iq1 = li[ind1].strip().split()
		weight2, iq2 = li[ind2].strip().split()

		if int(weight1) >= int(weight2) or int(iq1) <= int(iq2):
			print "sequence error"
			print input, output2
			exit()

if __name__ == "__main__":
	for i in range(10000):
		input = random_input()
		print len(input)
		output1 = execute("main.exe", input)
		output2 = execute("bigger_smarter.exe", input)

		len1 = output1.split()[0]
		len2 = output2.split()[0]

		if len1 != len2:
			print "error", len1, "!=", len2
			print input
			exit()

		check_sequence(input, output2)



