#Question:

'''
The academic office at the Hogwarts School of Witchcraft and Wizardry has compiled data about students' grades. The data is provided as text from standard input in three parts: information about courses, information about students and information about grades. Each part has a specific line format, described below..

    1. Information about courses
    2. Line format: Course Code~Course Name~Semester~Year~Instructor
    3. Information about students
    4. Line format: Roll Number~Full Name
    5. Information about grades
    6. Line format: Course Code~Semester~Year~Roll Number~Grade 

The possible grades are A, AB, B, BC, C, CD, D with corresponding grade points 10, 9, 8, 7, 6, 5 and 4. The grade point average of a student is the sum of his/her grade points divided by the number of courses. For instance, if a student has taken two courses with grades A and C, the grade point average is 8 = (10+6)÷2. If a student has not completed any courses, the grade point average is defined to be 0.

You may assume that the data is internally consistent. For every grade, there is a corresponding course code and roll number in the input data.

Each section of the input starts with a line containing a single keyword. The first section begins with a line containing Courses. The second section begins with a line containing Students. The third section begins with a line containing Grades. The end of the input is marked by a line containing EndOfInput.

Write a Python program to read the data as described above and print out a line listing the grade point average for each student in the following format:

Roll Number~Full Name~Grade Point Average

Your output should be sorted by Roll Number. The grade point average should be rounded off to 2 digits after the decimal point. Use the built-in function round().

Here is a sample input and its corresponding output.

Sample Input

Courses
TRAN~Transfiguration~1~2011-2012~Minerva McGonagall
CHAR~Charms~1~2011-2012~Filius Flitwick
Students
SLY2301~Hannah Abbott
SLY2302~Euan Abercrombie
SLY2303~Stewart Ackerley
SLY2304~Bertram Aubrey
SLY2305~Avery
SLY2306~Malcolm Baddock
SLY2307~Marcus Belby
SLY2308~Katie Bell
SLY2309~Sirius Orion Black
Grades
TRAN~1~2011-2012~SLY2301~AB
TRAN~1~2011-2012~SLY2302~B
TRAN~1~2011-2012~SLY2303~B
TRAN~1~2011-2012~SLY2305~A
TRAN~1~2011-2012~SLY2306~BC
TRAN~1~2011-2012~SLY2308~A
TRAN~1~2011-2012~SLY2309~AB
CHAR~1~2011-2012~SLY2301~A
CHAR~1~2011-2012~SLY2302~BC
CHAR~1~2011-2012~SLY2303~B
CHAR~1~2011-2012~SLY2305~BC
CHAR~1~2011-2012~SLY2306~C
CHAR~1~2011-2012~SLY2307~B
CHAR~1~2011-2012~SLY2308~AB
EndOfInput

Sample Output

SLY2301~Hannah Abbott~9.5
SLY2302~Euan Abercrombie~7.5
SLY2303~Stewart Ackerley~8.0
SLY2304~Bertram Aubrey~0
SLY2305~Avery~8.5
SLY2306~Malcolm Baddock~6.5
SLY2307~Marcus Belby~8.0
SLY2308~Katie Bell~9.5
SLY2309~Sirius Orion Black~9.0'''

#program
def grades(x):
    return {
        'A':10,
        'AB':9,
        'B':8,
        'BC':7,
        'C':6,
        'CD':5,
        'D':4
    }.get(x,0)

def count_ascii(s):
    sum = 0
    for i in range(len(s)):
        sum = sum + ord(s[i])
    return sum

def find_grades():
    lines = []
    while True:
        line = input()
        if line:
            lines.append(line)
            if line == 'EndOfInput':
                break
        else:
            break
    return find_grades1(lines)

def find_grades1(s):
    sorted_roll_dict = {}
    final_list = []

    students = find_students(s.index('Students'), s)
    grade = find_grade(s.index('Grades'), s)
    sorted_roll = list(students.keys())

    for i in range(len(sorted_roll)):
        sorted_roll_dict[sorted_roll[i]] = count_ascii(sorted_roll[i])
    sorted_roll_dict = sorted(sorted_roll_dict.items(), key=lambda x: x[0])
    for i in range(len(sorted_roll_dict)):
        if students.__contains__(sorted_roll_dict[i][0]) and grade.__contains__(sorted_roll_dict[i][0]):
            final_list.append('{}~{}~{}'.format(sorted_roll_dict[i][0], students[sorted_roll_dict[i][0]], grade[sorted_roll_dict[i][0]]))
        else:
            final_list.append('{}~{}~{}'.format(sorted_roll_dict[i][0], students[sorted_roll_dict[i][0]], 0))
    return '\n'.join(final_list)

def find_students(index, s):
    dict1 = {}
    for i in range(index+1, s.index('Grades')):
        dict1[s[i].split('~')[0]] = s[i].split('~')[1]
    return dict1

def find_grade(index, s):
    dic1 = {}
    repeated_rollnos = []
    for i in range(index+1, len(s)-1):
        repeated_rollnos.append(s[i].split('~')[-2])
        if dic1.__contains__(s[i].split('~')[-2]):
            dic1[s[i].split('~')[-2]] = (dic1[s[i].split('~')[-2]] +grades(s[i].split('~')[-1]))
        else:
            dic1[s[i].split('~')[-2]] = round(grades(s[i].split('~')[-1])/1, 2)

    roll_nos = list(dic1.keys())

    for j in range(len(roll_nos)):
        dic1[roll_nos[j]] = round(dic1[roll_nos[j]]/repeated_rollnos.count(roll_nos[j]), 2)

    return dic1