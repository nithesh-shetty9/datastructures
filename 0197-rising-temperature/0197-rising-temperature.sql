# Write your MySQL query statement below
select t.id from Weather t
inner join Weather w on datediff(t.recordDate,w.recordDate)=1
where t.temperature>w.temperature;
