weekstr = '周一周二周三周四周五周六周日'
weekid = eval(input('请输入1-7：'))
pos = (weekid - 1) * 2
print(weekstr[pos:pos+2])
print(eval(input('请输入被除数：'))//eval(input('请输入除数')))