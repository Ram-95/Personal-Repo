SELECT
    *
FROM
    employees;

------------------------------------------------------------------------------------------------------

SELECT
    *
FROM
    students
    NATURAL JOIN friends
    NATURAL JOIN packages;

SELECT
    s.name
FROM
    ( students s
    JOIN packages p ON s.id = p.id
    JOIN friends f ON s.id = f.id
    JOIN packages p1 ON p1.id = f.friend_id )
WHERE
    p.salary < p1.salary
ORDER BY
    p1.salary;
--------------------------------------------------------------------------------------------------------------------------------------

SELECT
    c.company_code,
    c.founder,
    COUNT(DISTINCT lm.lead_manager_code),
    COUNT(DISTINCT sm.senior_manager_code),
    COUNT(DISTINCT m.manger_code),
    COUNT(DISTINCT e.employee_code)
FROM
    company c
    JOIN lead_manager lm ON lm.company_code = c.company_code
    JOIN senior_manager sm ON sm.lead_manager_code = lm.lead_manager_code
    JOIN manager m ON m.senior_manager_code = sm.senior_manager_code
    JOIN employee e ON e.manger_code = m.manger_code
GROUP BY (
    c.company_code,
    c.founder
)
ORDER BY
    c.company_code ASC;
--------------------------------------------------------------------------------------------------------------------------------------

SELECT
    *
FROM
    employees;

SELECT
    employee_id,
    first_name,
    last_name,
    salary,
    DENSE_RANK() OVER(
        ORDER BY
            salary DESC
    ) AS rank
FROM
    employees
ORDER BY
    rank;
    

select salary, department_id from employees ;