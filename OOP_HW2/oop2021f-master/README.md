Welcome to the course website of OOP 2021 fall. The source code we wrote in the class will be available here. You can check history tab on the top of this page to see the content of each week. Notably, the teaching materials and methods are credited to Prof. Yu Chin Cheng at CSIE, NTUT. For any inquires, please email shchen@ntut.edu.tw with title [物件導向程式設計]_姓名_學號_班級. Formal format is required in the email. You can find your [**Grades**](https://docs.google.com/spreadsheets/d/1dP1KPtEw2mkf2xmfuVnBfRT9bgkF2TV1E2GNmS0f9YI/edit?usp=sharing) here for each HW.

**After 10/12, we will continue staying online until further notice. _(UPDATED on 10/05)_**

### Week 6 10/29 - More about Copy constructor & Copy assignment (with BBPOS & IRS)

Suggesting reading : [PL C++](https://www.cplusplus.com/articles/y8hv0pDG/) & [Extract Methods for refactoring](https://refactoring.com/catalog/extractFunction.html)

- copy assignment
  - right associative w = u = v; => w = (u = v);
  - return by reference
  - the this pointer
  - automatically generated if not defined shallow copy not deep copy
- constructors are overloadable
  - default constructor: the constructor that takes no parameters
  - copy constructor: the constructor that takes an object of the same class
  - one is given by C++ when not defined: shallow copy not deep copy
  -other constructors are defined as needed (e.g., MathVector(int, double *))

Example



      class MyClass obj1, obj2;
      class MyClass obj3(obj1);     //Calls Copy Constructor
      class MyClass obj4 = obj1;    //Calls Copy Constructor
      obj1 = obj2;                  //Calls Copy Assignment Operator

### Week 6 10/25 - Passed by reference v.s. Passed by value with a pointer

[HW02](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f_hw) You're required to submit HW02 to your gitlab project and trigger Jenkins and shuold have blue light for both HW and TA jobs to get all points for HW02. 

- In today's class, we see the difference between passed by reference and passed by value with a pointer.
- Copy assignment.

### Week 5 10/22 - Addressof operator v.s. Reference

Suggesting reading : CH 10

- Syntax for computation, want to have
  - w = u + v
  - w = a * v
  - w = a * u + b * v
- What is this? It's a pointer
- The concept of reference
  - Avoid copy constructor when passing by reference
  - Must be initialized when declaring
- What is the difference of following operators?


      double *p, v; 
      p = &v; // & Addressof operator
      *p = 12; // * dereferencing operator
      
      int r; 
      int &xp = r; // reference

### Week 5 10/18 - Why copy constructor is not called when returning an object?

- [copy elision](https://en.wikipedia.org/wiki/Copy_elision#Return_value_optimization)
  - A compiler optimization to avoid unnecessary copying of objects.
  - [Common forms of copy elision](https://stackoverflow.com/questions/12953127/what-are-copy-elision-and-return-value-optimization/12953150#12953150)
- [using gdb](https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/551505/) to find out segmentation fault

### Week 4 10/15 - Looking back on the math vector problem with Class

Suggesting reading : CH 7 & [Class](http://www.cplusplus.com/doc/tutorial/classes/)

- Solve problem with MathVector class
  - two pieces of data wrapped together
  - new and delete operations
  - constructor
  - destructor
  - make wrapped members (data and behavior)
- Function overloading
- Copy constructor - may be called in the following cases: 
  1. When an object of the class is returned by value. 
  2. When an object of the class is passed (to a function) by value as an argument. 
  3. When an object is constructed based on another object of the same class. 
  4. When the compiler generates a temporary object.

### Week 4 10/11 - No Class

### Week 3 10/8 - Continue the math vector problem

Suggesting reading : [Slide](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP_Week_4.pdf) & CH 3

[HW01](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f_hw) You're required to submit HW01 to your gitlab project and trigger Jenkins and shuold have blue light for both HW and TA jobs to get all points for HW01. 

**Problem III** Let _u_, _v_ be n-dimensional vectors. Write a program to calculate add u to v to obtain _u_ + _v_

**Problem IV** Let _u_, _v_ be n-dimensional vectors and _a_, _b_ be real numbers. Write a program to calculate _a_ _u_ + _b_ _v_

- Handle exception
- Pointer
  - *a, a[], &a
- runtime model of program
  - data, text, stack, heap
- memory allocation/deallocation from heap
  - new operator: allocating space from heap
  - delete operator: de-allocating space from heap
  - memory leak: allocated space NOT de-allocated when it's done used

### Week 3 10/4 - Continue the math vector problem

Suggesting reading : [Slide](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP_Week_3.pdf)

**Problem II** Let _v_ be a n-dimensional vector and _a_ be a real number. Write a program to calculate its scalar multiplication _a_ _v_.

**C++ (version 11)**
- [function](http://www.cplusplus.com/doc/tutorial/functions/)
- C argument passing: ONLY call by value
- memory model of variables in C/C++
  - model of variable
  - model of an array

### Week 2 10/1 - The math vector problem

Suggesting reading : Make sure you read those links below & [Slide](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP_Makefile.pdf)

**Problem I** Let v a n-dimensional vector. Write a program to calculate its length | v |.

If you're not familiar with vector, read [here](https://en.wikipedia.org/wiki/Vector_space).

**Problem solving**

- understanding the problem
- devising a plan
- carrying out the plan
- looking back

**Engineering practices**

- write [makefile](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP_Makefile.pdf)
- Engineering: add test folder
- Engineering + programming: write first vector test for length
- Git useful scenarios
  - Add .gitignore file to bin folder to avoid uploading compiled files
  - clone a repo: git clone
  - get new result from repo: git pull
  - incorporate current work: add, commit, and push
  - [reset all changes after last commit in git](https://stackoverflow.com/questions/4630312/reset-all-changes-after-last-commit-in-git)

**C++ (version 11)**

- Precedence of Operator
- Enum v.s. Strong Enum (Class)
- How soruce code are compiled (with makefile)

### Week 2 9/27 - Getting started

Suggesting reading : following links & [Slide](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP_Week_2.pdf) & CH 2

In this semester, 3 things will be given to assist you in your future career.
- [How To Solve It](http://htsicpp.blogspot.com/2014/08/introducing-how-to-solve-it-cpp.html) (Proposed by George Pólya)
- C++ (version 11)
- Engineering practices (unit testing, [version control](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/2_More_Info_About_Git.pdf), make, incremental development, test driven development, pair programming, and mob programming, [using Linux cmds](https://ubuntu.com/tutorials/command-line-for-beginners#1-overview))

Reference
- Text book
- [cplusplus.com](https://www.cplusplus.com/)
- [googletest](https://github.com/google/googletest/blob/master/docs/primer.md)

We will solve a few problems together through the practices of "How To Solve It". 

**Problem** Ask users to input two vectors and give the inner product. We are requied tell the user whether to continue and stop.

      [1, 0] · [1, 1] = 1,
      [1, 1, 0] · [0, 1, 1] = 1, and
      [1, 0] · [1, 1, 0] => undefined.

**Our plan** [Inner product, round 1](http://htsicpp.blogspot.com/2014/08/inner-product-round-1.html)

**C++ (version 11)**

- Namespace
- [String Class](https://www.cplusplus.com/reference/string/string/?kw=string)

### Week 1 - Introduction & Environment 

Setup Suggesting reading : CH 1

[Slides of Introduction](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP_Week_1.pdf) / [Slides of HW00](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/HW00_OOP_Environment_Setup.pdf) / [Report template for HW00](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP_HW00_109000000.docx) _(UPDATED on 09/28)_

You're required to submit the report for part 1 of HW00 to i study. If you do not have a student account from NTUT. Please send your homework to shchen@ntut.edu.tw with title [物件導向程式設計]_姓名_學號_班級_HW00. Your file name shuold be "OOP_HW00_109000000.pdf".

Gitlab and Jenkins are now available for logging in. If you are 隨班附讀, please check your assigned id [here](https://docs.google.com/spreadsheets/d/1dP1KPtEw2mkf2xmfuVnBfRT9bgkF2TV1E2GNmS0f9YI/edit?usp=sharing). Please remeber to change your password right after logging in. _(UPDATED on 09/28)_
