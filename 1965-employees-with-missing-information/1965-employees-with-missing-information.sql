/* Write your T-SQL query statement below */
-- select employee_id from Employees union select employee_id from Salaries except select Employees.employee_id from Employees inner join Salaries on Employees.employee_id = Salaries.employee_id;

select employee_id from Employees where employee_id not in(select employee_id from Salaries)
union
select employee_id from Salaries where employee_id not in (select employee_id from Employees)
order by employee_id;