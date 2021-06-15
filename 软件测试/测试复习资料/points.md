# Software Test Questions Answered by Points

------

## Introduction

### 1. Twelve Bugs:



### 2. Six Sources of Problems:



### 3. Percentage of Bugs Sources:

55 25 15 5  || 54 25 15 6

------

# Software Development Process

### 1. Seven Cyclic Steps of TDD:



### 2. Nine Steps of V-model:



### 3. Seven Steps of W-model (7+7):



### 4. Five Activities of H-model:



### 5. Nine Axioms of Software Testing:

plus with five supplementary principles of software testing



### 6. Three Classification Methods（分类方法） to Software Testing:

along with the tests method belong to the classification method. 2+4+6

### 7. Seven SQA Activities:



### 8. Eight Tasks or Responsiblities of Software Testing Team:



### 9. Basic Composition of Test Team (7):

Internal Auditor 

### 10. Ten Essential Qualities of Excellent Software Testing Engineer:



------

# Test Planning

### 1. Sixteen Components of a Test Plan:



### 2. Four Sentences Defining the Test  Use Case:

* 满足特定目的的测试数据、测试代码、测试规程的集合
* 发现软件缺陷的最小测试执行单元
* 有特殊的书写标准和基本原则
* 有明确的输入、输出

### 3. Three Components of Test Systems Architecture:

包含关系

------

# Methods for Designing Test Use Cases 

### 1. Six Roles(作用) of Test Use Cases:



### 2. Two Types of Dynamic White-box Testing:

* **ControlFlow-testing**
  * 逻辑分支覆盖法：
    * ？
    * ？
    * ？
    * ？
    * ？
  * 路径法：
    * ？
    * ？
* **DataFlow-Testing**

### 3. Five Steps for Basic Path Testing:



### 4. Three Testing Steps of White-box Testing:

*  选择逻辑覆盖标准
* 按照覆盖标准列出所有情况
* 设计测试用例    用最少的用例满足覆盖标准
* 验证、分析 运行结果与预期结果

### 5. Data Object (State) Categories (7):

**Defined** Created Initialized Killed Undefined Released **Used**(in a calculation or a predicate)   **DU**

### 6. Six Test Use Cases Design Techniques of Dynamic Black-box Testing:

EP BVA DT  ...

------

# Unit Testing

### 1. Five Contents of Unit Testing:

* 局部数据结构
* 出错处理
* 模块接口
* 独立路径
* 边界条件

### 2. Four Essential Elements of a Formal Code Review:

* Identify problems
* Follow rules
* Prepare
* Write a report

### 3. Two Forms of Informal Code Inspections:

* Peer reviews 同级审查
  * reviewers 审查人员：an informal small group of programmers and/or testers 
  * 参与者应该遵循上个问题中的4个步骤
* Walkthroughs 走查
  * 代码的作者把代码正式地展示给一个包括程序员 和/或 测试员的小组
  * 展示的时候一行一行代码的解释，reviewers听取解释、提出问题
  * 参与者应该遵循上个问题中的4个步骤

### 4. Seven Types of Errors in Code Review Checklist:

Computation errors Comparison errors Control flow errors Data reference errors Data declaration errors Subroutine parameter errors Input/Output errors

### 5. Four Concepts under xUnit Frame: (对应要会画JUnit框架的类图)



### 6. Five Processes of Unit Testing:

------

# Integration Testing

### 1. Six Integration Strategies:



### 2. Two Modes of Integration Testing:



### 3. Five Elements of Testing Environment:



------

## System Testing

### 1. The Purpose and Content of Functional Testing (12点):



### 2. Four Methods of Regression Testing:



### 3. Five Non-functional Tests:



### 4. Three Critical Steps of Performance Test and Bottleneck Analysis:



### 5. Four Steps of Using LoadRunner:



------

# Acceptance Test

### 1. Three Completion Criterion:



### 2. Seven Elements of User Interface:



### 3. Two Compatible Types: 



------

# Software Defect and Test Report

### 1. Nine Attributes among Software Defects:

缺陷标识（唯一）、缺陷类型、缺陷严重程度（4种）、缺陷优先级（3种）、缺陷产生可能性（1-100%）

缺陷状态(3种）、缺陷起源、缺陷来源、缺陷原因

### 2. Three Tools for Managing Software Defects:

Buggit Mantis Bugzilla

注：

- 测试用例管理工具：TestLink
- 单元测试工具：JUnit     Parasoft Jtest     Parasoft C++Test

### 3. Software Defect Life Cycle (A Picture)

测试后发现Bug，对Bug进行审查，审查通过则关闭，否则进行下一条；

有的Bugs解决不了，只能延期；

有的Bugs需要改需求、设计文档，改完后测试，回到第一条；

有的Bugs“打开”后发现表述不清，需要重新测试，如果表述清晰可再现，就修复，再回归测试，回到第一条；

### 4. Five Components of Software Defect Report:



### 5. Six Parts of Software Test Report:



### 6. Four Types of Software Defect（自加）:

* 完善性维护 50-66%
* 适应性维护 18-25%
* 改正性维护 17-21%
* 其他维护     4%

------

## 后记：

##### 	本文档是在考试前一天面向考试而做，基本记录了那些可以分条按要点（points）回答的问题，但这并不意味着本文档的考点是齐全的，很多不方便按要点作答的考点（概念、图等）本文档未提及。

##### 	由于考试无选择判断题，全靠理解与记忆，故而按要点式编写了本文档，方便记忆，本文档之外的考点基本通过理解就能掌握。

##### 	本文档所有题目来自老师最后的两个总复习pdf文件，大多数题未给出答案，鼓励自行背诵与默写。

##### 本文档不是最终版，as specifications are never final.

#### 														  2019.5.30