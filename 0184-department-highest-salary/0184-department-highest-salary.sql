# Write your MySQL query statement below
select Department.name as Department,Employee.name as Employee,salary from
Employee inner join Department on Employee. departmentId=Department.id
where salary=(select max(e.salary)from Employee e
 WHERE Employee.departmentId = e.departmentId);
