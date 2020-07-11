select ifnull(   
(select distinct Salary 
from Employee
order by Salary desc
limit 1 offset 1),null) as SecondHighestSalary;
#重点掌握limit 和offset的使用
#同时也需要掌握判断为空