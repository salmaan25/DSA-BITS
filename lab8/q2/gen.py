from random import randint

num_records = 20
f = open(str(num_records)+'.txt','w')
f.write(str(num_records)+'\r\n')
for _ in range(num_records):
	n = randint(0, 10000)
	f.write('tgrox\t'+str(n)+'\r\n')
f.close()
