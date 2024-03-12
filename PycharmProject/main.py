
# 字面量
# 字面量是指在代码中被写下来的固定值 被称为字面量
# 字面量
# 数字(Number) int float complex bool
# 字符串(Stting)  string
# 列表(List) 有序的可变序列
# 元组(Tuple) 有序的不可变序列
# 集合(set)   无序不重复集合
# 字典(Dictionary) 无序Key-Value集合 可无序纪录key-Value型的Python数据集合

#
# 666
# 13.14
# “黑马程序员”

# 单行注释 # 一个空格隔开
# 多行注释 一对三个双引号 """注释内容"""
"""
 注释内容
"""
print(666)
print(13.14)
print("黑马程序员")


# 变量 在程序运行时，能存储计算结果或能表示值的抽象概念 盒子
# 第一个变量
money=50
# 输出多份数据可以使用逗号隔开
print("钱包还有：",money)

# 买了一个冰淇淋 花费10元
money = money - 10
money -= 10
money += 1
print("钱包还有：",money)

# 数据类型
# 使用type()语句查看数据的类型
# 理解变量无类型而数据有类型的概念
print(type(money))
print(type("黑马程序员"))
# str是string的缩写
# 使用变量存储type()查询类型的结果
int_type=type(666)
string_type=type("黑马程序员")
print(int_type)
print(string_type)
# 变量有类型吗？
# 查看的是：变量存储的数据类型。 因为，变量无类型，但是它存储的数据有

# 数据类型转换 整数，浮点数之间转换
# 原则万物皆可转字符串 字符串转数字一定要保证字符串内容都是数字
# 将数字类型转换为字符串
num_str = str(11)
print(type(num_str))

# 将字符串转换为数字
str_num = int("505")
print(type(str_num))
# 将浮点数转换为int
float_int = int(1.00)
print(float_int)
# 将int转换为字符串
int_float =float(1)
print(int_float)

# 标识符
# 在py程序中我们可以给很多东西起名字,比如：
# 变量的名字
# 方法的名字
# 类的名字，等等
# 这些名字，我们把它统一称为标识符 用处来做内容的标识
# 所以标识符：
# 是用户在编程的时候使用的一系列名字，用于给变量，类，方法等命名
# 标识符内容的规定
# 只允许出现 英文 中文 数字 下划线 其他如何内容不允许出现 数字不可以开头
# 多个单词使用下划线分割 命名变量的英文字母应全部小写

# 运算符
# + 加
# — 减
# * 乘
# / 除
# // 取整除
# % 取余
# ** 指数 a**b
# += -= *= /= //= %= **=

# 字符串扩展

# 单引号定义法 name='黑马程序员'
# 双引号定义法 name="黑马程序员"
# 三引号定义法 name="""黑马程序员"""  三引号使用变量接收它就是字符串 否则就是多行注释

# 字符串拼接
# +号拼接 不能够让字符串和其他类型拼接

# 字符串格式化
name="黑马=程序员"
message="学IT就来%s" % name
message="学IT就来%s%s" % (name,"uu")
print(message)
# 通过占位的形式 完成数字和字符串的拼接
class_num = 57
avg_salary = 16781
message ="Py大数据学科，北京%s期，毕业平均工资：%s"%(class_num,avg_salary)
print(message)
# 数字可以用%s占位吗？ 可以会直接将数字类型转换为字符串

# 格式控制符

# %d
# %s
# %f

# 字符串格式的精度控制
# m控制宽度  默认使用空格补足
# .n控制小数点精度 会进行四舍五入
# %5d %5.2f
# 如果m比数字本身宽度还小 会发生什么事情
# m不会生效
# .n对小数部分做精度限制，同时会对小数部分做四舍五入

# 字符串格式化2
# 快速格式化字符串
# 通过语法: f“内容{变量}”的格式来快速格式化
name="传智播客"
set_up_year=2006
stock_price=19.99
print(f"我是{name},我成立于:{set_up_year},我今天的股票价格是:{stock_price}")
# 这种方式不理会类型
# 不做精度控制 适合对精度没有要求的时候快速的使用它

# 对表达式格式化
# 什么是表达式 一条具有明确执行结果的代码语句
# 又或者 常见的变量定义
# name = "张三"  age = 11+11
print("1*1的结果是：%d"%(1*1))
print(f"1*1的结果是：{1*1}")
print("字符串在Python的类型是：%s"% type('字符串'))
# 无需是使用变量进行数据存储的时候，可以直接格式化表达式，简化代码

# 数据输入
# input函数
# print("请告诉我你是谁？")
# name = input()
# print("你是：%s"%name)

# 默认当做字符串类型处理
# name = input("请告诉我你是谁：")
# print("你是：%s"%name)

# 如果需要是int 使用转换

# num =int(input())
# print(type(num))

# if elif else
# if 判断内容:
#    执行内容
#    执行内容
# elif 判断内容:
#    执行内容
#    执行内容
# else:
#    执行内容

# 循环
# while循环
#
# while 条件:
#     执行语句
#     执行语句
# 循环中短 continue break

# for循环

# 遍历字符串
name = "itheima"

for x in name:
      print(x)
# 同while循环不同 for循环是无法定义循环条件的 是一种遍历循环
# 理论上 py的for循环也无法构建无限循环 （被处理的数据集不可能无限大）
# for 临时变量 in 待处理数据集(序列):
#     执行语句

# range语句
# 语法1
# range(num)
# 获取一个从0开始，到num结束的数字序列(不含num本身)
# 语法2
# range(num1,num2)
# 获取一个从num1开始，到num2结束的数字序列(不含num2本身)
# range(num1,num2,step)
# 获取一个从num1开始，到num2结束的数字序列(不含num2本身)
# 数字之间的步长 以step为准(step默认为1)
# range(5,10,2) [5,7,9]

for x in range(10):
    print(x)

# for循环临时变量作用域
for i in range(5):
    print(i)
print(i)
# 规范上临时变量只应该在for循环内部生效
# 但实际上却是可以的

# 循环中短
# continue和break

# 函数
# 函数的定义
"""
def 函数名(传入参数):
    函数体
    return 返回值
"""
# 函数的参数插入

def add(x,y):
    return x+y

print(add(1,7))

# 形参 不可改变值
def mod(x):
    x=99

x=2
mod(2)
print(x)

# py函数的参数类型
# 传值
# 当参数类型为固定数据类型（如整数、浮点数、字符串、元组等）时，在函数内部直接修改形参的值不会影响实参。
# 传引用
# 但当参数类型为可变数据类型（如列表、字典、集合等）时，在函数内部使用下标或其他方式为其增加、删除元素或修改元素值时，修改后的结果是可以反映到函数之外的，即实参也会得到相应的修改。
# 函数返回值之 None类型
# 特殊字面量 None 类型: <class 'NoneType'>
# 在if判断上None等同于False

# 变量在函数中的作用域
# 局部变量和全局变量
# 局部变量: 定义在函数体内部的变量 即只在函数体内部生效
#    作用: 在函数内部，临时保存数据，即当函数调用完成后，销毁局部变量
# 全局变量
# 在函数体内，外都生效的变量

# 数据容器
# list(列表)
# list定义
# 字面量
# [元素1，元素2，元素3，...]
# 定义变量
# 变量名称 =[元素1，元素2，...]

name_list=['itheima','itcast','python']
print(name_list)
# 嵌套列表定义
# 通过下标获取列表中的元素 0,1,2,3
print(name_list[1])
# 反向索引
# (-n,-n-1,,,,-1)

# 列表的常用操作方法
# 1，查找某一元素下标
# 功能:查找指定元素在列表的下标，如果找不到，报错ValueError
# 语法: 列表.index(元素)
# index就是列表对象(变量)内置的方法(函数)

mylist=['itheima','itcast','python']
print(mylist.index('itheima'))
# print(mylist.index("国男"))

# 2.列表元素修改 直接使用[]

# 3.插入
# 语法: 列表.insert(插入下标,元素)

# 4.追加元素 (到列表尾部)
# 语法:列表.append(元素)

# 5.删除
# 语法1:del 列表[下标]
# 语法2:列表.pop(下标)
# 语法3:列表.remove(元素) 删除对应的匹配项

# 6.清空
# 语法:列表.clear()

# 7.统计列表中元素的数量
# 语法:列表.count(元素)

# 7.统计表长
# 语法:len(列表)


# 元组 内容定义以后不可修改
t1=(1,"Hello",True)
t2=()
t3=tuple()
t4=('hello',) # 定义一个元组要加,
# 嵌套元组
t5=((1,2,3),(4,5,6))
print(t5[1][2])
# 元组操作 index查找
t6=("传智教育","黑马程序员","Python","黑马程序员")
index=t6.index("黑马程序员")
print(index)

# 字符串的操作
