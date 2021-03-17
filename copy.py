
file_num = 6

f = open('テンプレ.cpp', 'r')
src = f.read()
f.close()

for i in range(1,file_num+1):
    filename = 'C++' + str(i) + '.cpp'
    f = open(filename, 'w')
    f.write(src)
    f.close()




