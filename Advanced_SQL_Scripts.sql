SELECT
    e.*,
    ( e.salary * 0.10 ) + e.salary AS net_salary
FROM
    employees e;

SELECT
    round(AVG(nvl(tax_amount,0) ),2)
FROM
    sales;

/*
1. Create a virtual column named SALARY_RANGE in the table EMPLOYEES
with the below logic.
If salary is greater than 10000 then value should be displayed as ‘Good’ else
the value should be displayed as ‘Average’
*/

SELECT
    e.*,
    CASE
            WHEN e.salary > 10000 THEN 'GOOD'
            ELSE 'Average'
        END
    AS salary_range
FROM
    employees e;

/*
2. Create a default column named COMPANY in the table EMPLOYEES with
the default value ‘Udemy’
*/

ALTER TABLE employees ADD company VARCHAR2(20) DEFAULT 'Udemy';

SELECT
    *
FROM
    employees;

/*
4. Write a SQL statement to display the average of MANAGER_ID column in
the EMPLOYEES table. (Remember what you learnt when dealing with null
values)
*/

SELECT
    round(AVG(nvl(manager_id,0) ),3) AS avg_man
FROM
    employees;

------------------------------------------------------------------------------------------------------------------------------
--ANALYTICAL FUNCTIONS
------------------------------------------------------------------------------------------------------------------------------

SELECT
    s.*,
    savg.avg_data
FROM
    sales s,
    (
        SELECT
            round(AVG(nvl(total_amount,0) ),2) AS avg_data
        FROM
            sales
    ) savg;

SELECT
    s.*,
    savg.avg_data
FROM
    sales s,
    (
        SELECT
            sales_date,
            round(AVG(nvl(total_amount,0) ),2) AS avg_data
        FROM
            sales
        GROUP BY
            sales_date
    ) savg
WHERE
    s.sales_date = savg.sales_date;

SELECT
    s.sales_date,
    s.order_id,
    s.product_id,
    s.sales_amount,
    AVG(sales_amount) OVER(
        PARTITION BY order_id
    ) AS avg_sales_amt
FROM
    sales s
ORDER BY
    2;

/*  Average of a column partition by another column */

SELECT
    s.sales_date,
    s.order_id,
    s.product_id,
    s.sales_amount,
    round(AVG(sales_amount) OVER(),2) AS total_avg,
    round(AVG(sales_amount) OVER(
        PARTITION BY s.sales_date
    ),2) AS avg_sales_amt_day,
    round(AVG(sales_amount) OVER(
        PARTITION BY trunc(s.sales_date,'mon')
    ),2) AS avg_sales_amt_month
FROM
    sales s
ORDER BY
    1;

/* Cummulative Sum */

SELECT
    sales_date,
    order_id,
    product_id,
    sales_amount,
    SUM(sales_amount) OVER(
    ORDER BY
        sales_date,order_id,product_id
    ) AS cumm_sum
FROM
    sales;

/* Showing sales as a part of total sales */

SELECT
    trunc(sales_date,'mon') AS sales_month,
    SUM(total_amount) AS total_amount,
    round(RATIO_TO_REPORT(SUM(total_amount) ) OVER() * 100,2) AS ratio_percent
FROM
    sales
GROUP BY
    trunc(sales_date,'mon')
ORDER BY
    1;

/* Ranking */

SELECT
    *
FROM
    (
        SELECT
            trunc(s.sales_date,'mon') AS sales_month,
            sp.first_name,
            SUM(s.total_amount) AS total_amount,
            RANK() OVER(
                PARTITION BY trunc(s.sales_date,'mon')
                ORDER BY
                    SUM(s.total_amount) DESC        -- change desc to asc if you want the reverse
            ) AS sales_person_rank
        FROM
            sales s,
            salesperson sp
        WHERE
            s.salesperson_id = sp.salesperson_id
        GROUP BY
            trunc(s.sales_date,'mon'),
            sp.first_name
    )
WHERE
    sales_person_rank <= 3;


/*  N-Tile Function - Dividing the rows into groups called bands */

SELECT
    sp.first_name,
    SUM(total_amount) AS total_amount,
    NTILE(3) OVER(
        ORDER BY
            SUM(total_amount) DESC
    ) AS bucket
FROM
    sales s,
    salesperson sp
WHERE
    s.salesperson_id = sp.salesperson_id
GROUP BY
    sp.first_name;

SELECT
    employee_id,
    first_name,
    salary,
    NTILE(50) OVER(
        ORDER BY
            salary DESC
    ) AS band
FROM
    employees;
    
/*  LAG and LEAD to compare the current vs the previous and the next values */

SELECT
    trunc(sales_date,'mon') AS sales_month,
    SUM(total_amount) AS total_amount,
    LAG(SUM(total_amount),1) OVER(
        ORDER BY
            trunc(sales_date,'mon')
    ) AS prev_month,
    LEAD(SUM(total_amount),1) OVER(
        ORDER BY
            trunc(sales_date,'mon')
    ) AS next_month
FROM
    sales
GROUP BY
    trunc(sales_date,'mon');


/**  Calculated growth of sales amount across tiime **/

SELECT
    sales_month,
    total_amount,
    prev_month,
    round( ( (total_amount - prev_month) / prev_month) * 100,2) AS growth
FROM
    (
        SELECT
            trunc(sales_date,'mon') AS sales_month,
            SUM(total_amount) AS total_amount,
            LAG(SUM(total_amount),1) OVER(
                ORDER BY
                    trunc(sales_date,'mon')
            ) AS prev_month,
            LEAD(SUM(total_amount),1) OVER(
                ORDER BY
                    trunc(sales_date,'mon')
            ) AS next_month
        FROM
            sales
        GROUP BY
            trunc(sales_date,'mon')
    );

/************************ Analytical Functions Practice *****************************************/
/*
1) Write a query to find the average salary by department without using the GROUP BY function.
You have to use analytical function and do this.
*/

SELECT
    employee_id,
    first_name,
    last_name,
    salary,
    department_id,
    round(AVG(salary) OVER(
        PARTITION BY department_id
    ),2) AS avg_dept_salary
FROM
    employees
ORDER BY
    department_id;

/*
2) Write a query to display the following information (Order by JOB_ID)
? Employee ID
? Job ID
? Salary
? Department ID
? Average salary by Job ID
? Average salary by Department ID
? Average salary of all employees
*/

SELECT
    e.employee_id,
    e.job_id,
    e.salary,
    e.department_id,
    round(AVG(e.salary) OVER(
        PARTITION BY e.job_id
    ),2) AS avg_job_id,
    round(AVG(e.salary) OVER(
        PARTITION BY e.department_id
    ),2) AS avg_dept_id,
    round(AVG(e.salary) OVER(),2) AS avg_all_emp
FROM
    employees e;
    
/*
3) Write a query to display the following information (Order by JOB_ID)
? Employee ID
? Job ID
? Department ID
? Salary
? Average salary by Department ID
? Difference between employee salary and Average salary by Department ID
*/

SELECT
    avg_tbl.*,
    ( avg_tbl.salary - avg_tbl.avg_dept_id ) AS diff_sal_avg
FROM
    (
        SELECT
            e.employee_id,
            e.job_id,
            e.salary,
            e.department_id,
            round(AVG(e.salary) OVER(
                PARTITION BY e.department_id
            ),2) AS avg_dept_id
        FROM
            employees e
    ) avg_tbl;

/*
4) Write a query to display the following information (Order by JOB_ID)
? Job ID
? Department ID
? Number of managers by Job ID
? Number of managers by Department ID
? Total number of managers
*/

SELECT
    e.job_id,
    e.department_id,
    COUNT(manager_id) OVER(
        PARTITION BY e.job_id
    ) AS num_man_job,
    COUNT(manager_id) OVER(
        PARTITION BY e.department_id
    ) AS num_man_dept,
    COUNT(manager_id) OVER() AS total_managers
FROM
    employees e;
    
/*
5) Write a query to display the following information (Experiment with RANK, DENSE_RANK and ROW_NUMBER analytical functions)
? Employee ID
? Department ID
? Salary
? Salary Ranking
*/

SELECT
    e.employee_id,
    e.department_id,
    e.salary,
    DENSE_RANK() OVER(
        ORDER BY
            e.salary DESC
    ) AS sal_rank
FROM
    employees e;

/*
6) Write a query to display the following information
? Employee ID
? Department ID
? Salary
? Salary Ranking by Department ID
*/

SELECT
    e.employee_id,
    e.department_id,
    e.salary,
    DENSE_RANK() OVER(
        PARTITION BY e.department_id
        ORDER BY
            e.salary DESC
    ) AS sal_rank
FROM
    employees e;

/*
7) Write a query to display the following information
? Employee ID
? Department ID
? Salary
? Top Salary Ranking by Department ID
? Bottom Salary Ranking by Department ID
*/

SELECT
    e.employee_id,
    e.department_id,
    e.salary,
    DENSE_RANK() OVER(
        PARTITION BY e.department_id
        ORDER BY
            e.salary DESC
    ) AS top_sal_in_dept,
    DENSE_RANK() OVER(
        PARTITION BY e.department_id
        ORDER BY
            e.salary
    ) AS bottom_sal_in_dept
FROM
    employees e;
    

/*
8) Write a query to display the following information, but display only top 3 and bottom 3 salaries.
? Employee ID
? Department ID
? Salary
? Top Salary Ranking by Department ID
? Bottom Salary Ranking by Department ID
*/

SELECT
    emp.*
FROM
    (
        SELECT
            e.employee_id,
            e.department_id,
            e.salary,
            DENSE_RANK() OVER(
                PARTITION BY e.department_id
                ORDER BY
                    e.salary DESC
            ) AS top3_sal_in_dept,
            DENSE_RANK() OVER(
                PARTITION BY e.department_id
                ORDER BY
                    e.salary
            ) AS bottom3_sal_in_dept
        FROM
            employees e
    ) emp
WHERE
    emp.top3_sal_in_dept <= 3
    OR emp.bottom3_sal_in_dept <= 3;
    
/*
9) Write a query to display the following information for the Department ID 30
? Employee ID
? Salary
? Next lowest salary (You need to use LEAD)
? Previous highest salary (You need to use LAG)
*/

SELECT
    e.employee_id,
    e.salary,
    e.department_id,
    LEAD(e.salary,1,0) OVER(
        PARTITION BY e.department_id
        ORDER BY
            e.salary DESC NULLS LAST
    ) AS next_lowest,
    LAG(e.salary,1,0) OVER(
        PARTITION BY e.department_id
        ORDER BY
            e.salary DESC NULLS LAST
    ) AS prev_highest
FROM
    employees e
--where e.department_id = 30
ORDER BY
    e.department_id,
    e.salary DESC;