# Write your MySQL query statement below
select p.product_name,e.year,e.price from Sales e
inner join Product p on e.product_id=p.product_id