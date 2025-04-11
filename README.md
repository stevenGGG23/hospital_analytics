# hospital_analytics 

This C++ program simulates a simple hospital analytics system for tracking and reporting on treatments, billing, and departmental performance. It allows users to input treatment data for patients and analyze various healthcare-related metrics including insurance coverage, cost statistics, and departmental revenue.

📋 Features
Input Treatment Data: Record multiple procedures including cost, doctor, and patient information.

Insurance Coverage Report: Shows how many patients are covered under each insurance and their total billing.

Treatment Cost Analysis: Displays mean, median, standard deviation, and most expensive procedure.

Department Performance: Calculates revenue generated per department based on treatments performed.

Full Report: Generates all three types of reports at once.

Menu System: Easy navigation through different report options. 


<pre> <code>```text 
  
  ENTER TREATMENT DATA
====================
Available Patients:
1. John Doe (BlueCross)
2. Jane Smith (Medicare)
3. Alice Wong (Aetna)

Available Doctors:
101. Dr. Patel (Heart Center)
102. Dr. Garcia (Brain Health)
103. Dr. Chen (Bone Clinic)

Procedure: Angioplasty
Select patient ID: 1
Select doctor ID: 101
Enter cost ($): 2000
Enter duration (days): 3

Procedure: MRI
Select patient ID: 1
Select doctor ID: 101
Enter cost ($): 800
Enter duration (days): 2

Procedure: EKG
Select patient ID: 0
Invalid input! Enter 1, 2, or 3: 2
Select doctor ID: 102
Enter cost ($): 987
Enter duration (days): 1

Procedure: Hip Replacement
Select patient ID: 3
Select doctor ID: 103
Enter cost ($): 3240
Enter duration (days): 1

Procedure: CT Scan
Select patient ID: 100
Invalid input! Enter 1, 2, or 3: 2
Select doctor ID: 101
Enter cost ($): 300
Enter duration (days): 1

Procedure: Blood Test
Select patient ID: 1
Select doctor ID: 101
Enter cost ($): 50
Enter duration (days): 1

Procedure: Physical Therapy
Select patient ID: 3
Select doctor ID: 103
Enter cost ($): 100
Enter duration (days): 7

HOSPITAL ANALYTICS MENU
=======================
1. Insurance Coverage Report
2. Treatment Cost Analysis
3. Department Performance
4. Full Analysis Report
5. Re-enter Treatment Data
6. Exit

Select option: 1

INSURANCE COVERAGE REPORT
==========================
Aetna     : 1 patients (33.3%), Total billing: $3340.0  
BlueCross : 1 patients (33.3%), Total billing: $2850.0  
Medicare  : 1 patients (33.3%), Total billing: $1287.0

Select option: 2

TREATMENT STATISTICS
=====================
Mean cost:          $1068.1  
Median cost:        $800.0  
Standard deviation: $1084.2  
Most expensive:     $3240.0 (Hip Replacement for patient 3)

Select option: 3

DEPARTMENT PERFORMANCE
=======================
Bone Clinic:
  Total revenue:    $1002.0  
  Cases handled:    2  
  Avg revenue/case: $501.0  

Brain Health:
  Total revenue:    $296.1  
  Cases handled:    1  
  Avg revenue/case: $296.1  

Heart Center:
  Total revenue:    $945.0  
  Cases handled:    4  
  Avg revenue/case: $236.2

Select option: 4

INSURANCE COVERAGE REPORT
==========================
Aetna     : 1 patients (33.3%), Total billing: $3340.0  
BlueCross : 1 patients (33.3%), Total billing: $2850.0  
Medicare  : 1 patients (33.3%), Total billing: $1287.0

TREATMENT STATISTICS
=====================
Mean cost:          $1068.1  
Median cost:        $800.0  
Standard deviation: $1084.2  
Most expensive:     $3240.0 (Hip Replacement for patient 3)

DEPARTMENT PERFORMANCE
=======================
Bone Clinic:
  Total revenue:    $1002.0  
  Cases handled:    2  
  Avg revenue/case: $501.0  

Brain Health:
  Total revenue:    $296.1  
  Cases handled:    1  
  Avg revenue/case: $296.1  

Heart Center:
  Total revenue:    $945.0  
  Cases handled:    4  
  Avg revenue/case: $236.2

Select option: 6  
Exiting program...

  
  ```</code> </pre>
