/**
A short SWI-Prolog program, simulating a fictional university that offers a mini-master in Informatics, worth 30 credits.
This program checks if a student has completed all required aspcredit for graduation.
There are two different tracks: Software Systems (ss) and Information Systems (is). Three faculties that offer courses: Informatics (inf), Economics (eco) and Law (law)

Graduation criteria are as follows:
SS student: 20 credits from inf courses, 10 credits from eco courses
IS student: 20 credits from inf, 5 credits from eco and 5 credits from law courses OR 20 credits from inf and 10 credits from eco courses

Courses offered by faculty (title,credits):
inf faculty:
Practical Artificial Intelligence (pai), 10
Theoretical Artificial Intelligence (tai), 5
Data Science (ds), 5
Communication Systems (cs), 5
Big Data Analytics (bda), 5
IT Security (its), 5
eco faculty:
Banking and Finance (bf), 5
Behavioral Economics (be), 5
Quantitative Finance (qf), 10
Organisation and Management (om), 5
Business Informatics (bi), 5
A primer in Entrepreneurship (pe), 5
law faculty:
Democracy (d), 10
Financial Law (fl), 5
Public Procedural Law (ppl), 2.5
European Institutes (ei), 2.5

Students inserted were alice, bob, carlos, daniela, philip
To check if a student has completed all requirements, use "pass(student_name)."
For more functions (like total current credits owned by student, or a list of all courses taken by student), check the comments in the sourcecode.
Example: coursesInf(philip,Y,H,Z). -> lists all courses from faculty inf taken by philip by title, faculty and credits, continue the list with spacebar

This was one of the exercises in the Practical Artifical Intelligence Lecture at University of Zurich UZH
Code by Philip Hofmann, github: Phhofm
*/

%!  input data

%!  input courses
course(pai,inf,10).
course(tai,inf,5).
course(ds,inf,5).
course(cs,inf,5).
course(bda,inf,5).
course(its,inf,5).
course(bf,eco,5).
course(be,eco,5).
course(qf,eco,10).
course(om,eco,5).
course(bi,eco,5).
course(pe,eco,5).
course(d,law,10).
course(fl,law,5).
course(ppl,law,2.5).
course(ei,law,2.5).

%!  input sample students
student(alice,ss).
student(bob,is).
student(carlos,ss).
student(daniela,is).
student(philip,is).

%!  assign courses taken to students
attend(alice,pai).
attend(alice,tai).
attend(alice,cs).
attend(alice,qf).
attend(bob,pai).
attend(bob,qf).
attend(bob,d).
attend(carlos,pai).
attend(carlos,tai).
attend(carlos,cs).
attend(carlos,qf).
attend(daniela,pai).
attend(daniela,tai).
attend(daniela,be).
attend(philip,pai).
attend(philip,cs).
attend(philip,bda).
attend(philip,its).
attend(philip,om).
attend(philip,bi).
attend(philip,pe).

%!  output courses for student. X is student name. Example: courses(alice,X). Continue list with spacebar.
courses(X,Y) :- attend(X,Y).

%!  get list of courses for student. traverse through list, count credit
%   for each course in a variable and the compare.
courses2(X,Y,H,Z) :- courses(X,Y), course(Y,H,Z).

%!  test if a course if from inf
courseInf(X) :- course(X,Y,_),Y=inf.

%!  outputs only the courses from inf for a student. Example
%  coursesInf(alice,Y,H,Z).
coursesInf(S,Y,H,Z) :- courses2(S,Y,H,Z),courseInf(Y).

%!  test if a course is from eco
courseEco(X) :- course(X,Y,_),Y=eco.

%!  outputs courses from eco for a student. See coursesInf
coursesEco(S,Y,H,Z) :- courses2(S,Y,H,Z),courseEco(Y).

%!  test if a course is from law
courseLaw(X) :- course(X,Y,_),Y=law.

%!  outputs courses from law for a student. See coursesInf
coursesLaw(S,Y,H,Z) :- courses2(S,Y,H,Z),courseLaw(Y).

%!  gives the sum of the list integers
sum([],0).
sum([X|List],Sum) :- sum(List,Sum1),Sum is X+Sum1.

%!  outputs the inf courses as a integer list
coursesInfList(S,Y,H,Z) :- findall(Z,(courses2(S,Y,H,Z),courseInf(Y)),Z).

%!  outputs the sum total credit of all inf courses of a student.
creditSumInf(S,E) :- coursesInfList(S,_,_,X),sum(X,E).

%!  outputs the eco courses as a integer list
coursesEcoList(S,Y,H,Z) :- findall(Z,(courses2(S,Y,H,Z),courseEco(Y)),Z).

%!  outputs the sum total credit of all eco courses of a student.
creditSumEco(S,E) :- coursesEcoList(S,_,_,X),sum(X,E).

%!  outputs the law courses as a integer list
coursesLawList(S,Y,H,Z) :- findall(Z,(courses2(S,Y,H,Z),courseLaw(Y)),Z).

%!  outputs the sum total credit of all law courses of a student.
creditSumLaw(S,E) :- coursesLawList(S,_,_,X),sum(X,E).

%!  test if a student passes, assumption : ss student.
passSS(X) :- creditSumInf(X,E), E>19, creditSumEco(X,Z), Z>9.

%!  test if a student passes, assumption : is student.
passIS(X) :- creditSumInf(X,E), E>19, creditSumEco(X,Z), Z>9 ; creditSumInf(X,E), E>19, creditSumEco(X,Z), Z>4, creditSumLaw(X,W), W>4.

%!  tests if student passes based on track.
pass(X) :- student(X,F), F=ss -> passSS(X); passIS(X).
