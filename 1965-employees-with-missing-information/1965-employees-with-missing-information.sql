/* Write your T-SQL query statement below */
select employee_id from Employees union select employee_id from Salaries except select Employees.employee_id from Employees inner join Salaries on Employees.employee_id = Salaries.employee_id;
