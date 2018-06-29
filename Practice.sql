select manager_id,employee_id,salary, dense_rank() over(partition by manager_id order by salary) as Rank 
from employees; -- To rank the acc to salary

select manager_id, max(salary) from employees group by manager_id;

select max(cast(ltrim(cost,'$') as integer )) as Max_Cost from cars2;


select instr('Bababar','b',1,2) from dual;

select replace('ram nanu', 'n', 'b') from dual;

create table cars_info as select * from cars2; -- create table from another existing table

select * from cars_info;

create table persons(Id varchar2(10) primary key, Name varchar(20) not null, Mobile number(10) check(length(mobile) = 10), 
Age integer check (age between 1 and 79)); -- All constraints


insert into persons values('P' || MY_SEQUENCE.NEXTVAL, '&name', &mobile, &age); -- dynamically entering values

select * from user_constraints where table_name = 'PERSONS'; --To know the constraints defined on a table

select substr(mobile,1,3)|| '-' || substr(mobile,4,3)||'-'|| substr(mobile,7,10) F_Mobile from persons; -- concatenating

select * from (select * from employees order by dbms_random.value) where rownum = 1; --To print a random row

select * from (select * from employees order by salary desc) where rownum <= 10; -- To know n max salaries

select ceil(dbms_random.value * 10) from dual; -- To generate random values << It generates between 1 and 10 >>

select * from 
(
select employee_id, first_name, last_name ,salary, dense_rank() over(order by salary desc) Rankings from employees
) 
where Rankings = '&Nth_max'; -- To find nth max salary. Replace desc with asc and you'll get the Min salaries

-----------------------------------------------------------------------------------------------------------------------------------
-- Triangles Type

create table triangles(side1 integer not null, side2 integer not null, side3 integer not null);

insert into triangles values(&side1, &side2, &side3);

select * from triangles;

desc triangles;

select triangle_id, side1,side2,side3, case
    when ((side1 = side2) and (side2 = side3)) then 'Equilateral'
    when(((side1 = side2) and (side2 != side3)) or ((side2 = side3) and (side3 != side1)) or ((side3 = side1) and (side2 != side3))) then 'Isosceles'
    else 'Scalene'
    end Type_Tri
from triangles;

alter table triangles add Triangle_id integer;

select * from triangles;

select my_sequence.nextval from dual;

update triangles set Triangle_id = my_sequence.nextval;

-----------------------------------------------------------------------------------------------------------------------------------
select * from (select triangle_id, rownum as r_no from triangles) where mod(r_no,2) = 0;

select * from employees;

select * from (select employee_id,first_name,last_name, rownum as num from employees) where mod(num,2) = 0; -- To select even rows

select * from (select employee_id,first_name,last_name, rownum as num from employees) where mod(num,2) = 1; -- To select odd rows

select * from triangles;

select * from (select employee_id,first_name,last_name, rownum as num from employees) where num ='&n'; -- To select nth record

select * from (select employee_id,first_name,last_name, rownum as num from employees) 
where num =(select max(rownum) from employees); -- To select Last row

select * from employees where rownum <= '&n'; -- To select first n records

select * from employees where rowid = (select max(rowid) from employees); -- To select last record

select E.*, rowid, rownum from employees E; -- To get all columns in addition to rowid and rownum




-------------------------------------------------------------------------------------------------------


declare
a integer := &n;
begin
    case  
        when (mod(a,2)=0) then dbms_output.put_line('Divisible by 2');
        when (mod(a,3)=0) then dbms_output.put_line('Divisible by 3');
        when (mod(a,5)=0) then dbms_output.put_line('Divisible by 5');
        else dbms_output.put_line('NOT Divisible by any no.');
    end case;

end;
/
----------------------------------------------------------------------------------------------
DECLARE
i integer := 0;

begin
    for i in reverse 1..10
    loop
    if i = 5 then
    continue;
    end if;
    dbms_output.put_line('Value of i is: ' || i);
    
    end loop;
end;
/




select distinct manager_id from employees order by 1;

select manager_id, count(*) from employees group by manager_id order by 1;

--- Table to store summarized data of managers
create table Managers_Summ(emp_id integer primary key, name varchar2(55), No_of_Reportees integer);

select * from managers_info;

Insert into MANAGERS_SUMM (emp_id, name, NO_OF_REPORTEES);


    select distinct E.employee_id, (E.first_name || ' ' ||  E.last_name) as Manager_Name, count(*) as Reportees 
    from employees E join employees F on E.employee_id = F.manager_id
    group by E.employee_id, (E.first_name|| ' ' || E.last_name)
    order by E.EMPLOYEE_ID;


select instr('rambabu','b',1,2) from dual;

select distinct manager_id, nvl2(manager_id,'Manager','CEO') from employees order by 2;

