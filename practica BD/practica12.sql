/*1. Consultar los nombres de los empleados que han atendido al cliente de apellido
Rodman, el listado debe incluir nombre completo del empleado y cargo.

select distinct empleados.first_name, empleados.last_name, empleados.job_title from employees as empleados inner join orders 
	on empleados.id = employee_id inner join customers as cliente on cliente.id = customer_id 
	where cliente.last_name =  'Rodman'
*/

/*2. Consultar los nombres de los clientes que hicieron compras en octubre del 2006.
select cliente.first_name from customers as cliente inner join orders on cliente.id = customer_id 
	--where YEAR(order_date) = 2006 and MONTH(order_date) = 10  
	--where order_date  >= '20061001'and order_date <='20061031' 
	where order_date Between '20061001' and '20061031'*/

/*3. Consultar por cada producto el total de unidades vendidas por mes, el listado debe
incluir nombre del producto, el mes y el total de unidades vendidas en ese mes.
select producto.product_name, MONTH(order_date) as mes ,SUM(quantity) as cantidad from products as producto 
	inner join order_details on producto.id =  product_id 
	inner join orders as orden on order_id = orden.id
	group by producto.product_name, MONTH(order_date)*/

/*4. Mostrar los nombres de los productos, su precio unitario y existencias, únicamente
para los de las categorías Cereal, Soups y Sauces. La lista debe mostrarse en orden
alfabético. 
select producto.product_name, producto.standard_cost,SUM(inventario_transacciones.quantity) as existencia from products as producto
	inner join inventory_transactions as inventario_transacciones on producto.id = inventario_transacciones.product_id
	where producto.category in ('Cereal','Soups','Sauces')
	group by producto.product_name, producto.standard_cost
	order by producto.product_name*/

/*5. Listar sin repeticiones las ciudades de origen de los clientes de la base de datos.
select distinct city as Ciudad from customers order by city*/

/*6. Listar cuántos productos existen por categoría, mostrar el nombre de la categoría.
select category, COUNT(*) as cantidad from products 
group by category */

/*7. ¿Cuál es el precio promedio de los productos de la categoría de los cereales?
select AVG(costo) from products
	where category = 'Cereal*/

/*8. Listar los clientes cuyo nombre empiece por A incluyendo los números de órdenes
que han hecho.
select cliente.first_name nombre_cliente, orden.id as numero_orden from customers as cliente 
	inner join orders as orden on cliente.id = customer_id
	where cliente.first_name LIKE 'a%'
	order by cliente.first_name*/

/*9. Listar los empleados que le hayan realizado ventas a los 10 primeros clientes
ordenados alfabéticamente.
select distinct empleado.first_name from employees as empleado 
	inner join orders as orden on empleado.id = orden.employee_id
	inner join (
		select distinct top 10 cli.first_name,cli.id from customers as cli 
		inner join orders as ord on cli.id = ord.customer_id
		order by first_name) as cliente 
	on customer_id = cliente.id*/

/*10. Ordenar de mayor a menor por su precio unitario los productos cuyo empaque
sean botellas (bottles). 
select producto.product_name,producto.standard_cost from products as producto
where producto.quantity_per_unit like '%bottles' 
order by producto.product_name,producto.standard_cost*/

/*11. Listar para cada proveedor las categorías de productos que suministra.
select proveedor.id, producto.category from suppliers as proveedor 
	inner join products as producto on proveedor.id = producto.supplier_ids
	group by proveedor.id,producto.category*/

/*12. Calcular el importe total de todos los artículos que hay en el almacén. El valor de lo
almacenado de un artículo se obtiene multiplicando la cantidad en stock por el
precio unitario del artículo. 
select producto.product_name, SUM(inventario_t.quantity)*producto.standard_cost as importe_total from products as producto
	inner join inventory_transactions as inventario_t on producto.id = inventario_t.product_id
	group by producto.product_name,producto.standard_cost*/


/*13. Consultar los nombres de los proveedores, ciudad, teléfono, nombre del producto,
precio y existencias, para aquellos cuyas existencias sean menores a 20 unidades. corregido

select proveedor.first_name, proveedor.city, proveedor.home_phone, producto.product_name, 
	producto.standard_cost, SUM(inventario.quantity) as existencia from suppliers as proveedor 
		inner join products as producto on proveedor.id = producto.supplier_ids
		inner join inventory_transactions as inventario on inventario.product_id = producto.id
		where inventario.quantity < 20 
		group by proveedor.first_name, proveedor.city, proveedor.home_phone, producto.product_name, 
	producto.standard_cost*/


/*14. Obtener el valor máximo y el valor mínimo de las cantidades en stock de los
artículos cuyo precio se encuentra entre 20 y 50 euros. Mostrar también el valor
medio de ambos, máximo y mínimo. 

select AVG(tabla.quantity) as valor_medio,MIN(tabla.quantity) as valor_minimo,MAX(tabla.quantity) as valor_maximo from(
		select producto.product_name, producto.standard_cost, SUM(inventario.quantity) as quantity from products as producto
		inner join inventory_transactions as inventario on producto.id = inventario.product_id 
		where producto.standard_cost between 20 and 50
		group by producto.product_name, producto.standard_cost) as tabla*/
		
/*15. Mostrar los códigos de los clientes que tienen más de un pedido que aún no ha
sido facturado (estado New). Junto al código y nombre de cada cliente debe
aparecer cuántos pedidos tiene de este tipo.

select tabla_clientes.id from (
select cliente.id,COUNT(*) as cantidad_pedidos from customers as cliente 
	inner join orders as orden on cliente.id = orden.customer_id
	inner join orders_status as estado on orden.status_id = estado.id
	where estado.status_name = 'New'
	group by cliente.id ) as tabla_clientes
	where tabla_clientes.cantidad_pedidos > 1 */

/*16. De los clientes cuyo código está entre el 10 y el 20, mostrar el número de facturas
que cada uno tiene con cada forma de pago.
select cliente.id,isnull(orden.payment_type,'sin forma de pago especificada') as forma_de_pago from customers as cliente 
	inner join orders as orden on cliente.id = orden.customer_id
	where cliente.id between 10 and 20
	order by cliente.id,orden.payment_type*/

/*17. Mostrar el código de los productos de los que se ha facturado más de 1000 euros
en total (en el conjunto de todas las facturas donde lo hayan comprado).
select producto.id, sum(pur_od.quantity*producto.standard_cost) from products as producto 
	inner join purchase_order_details as pur_od on producto.id = pur_od.product_id
	inner join purchase_orders as orden_compra on pur_od.purchase_order_id = orden_compra.id
	group by producto.id
	having sum(pur_od.quantity*producto.standard_cost) > 1000*/
	
	