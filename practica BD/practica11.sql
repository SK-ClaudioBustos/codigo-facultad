--10. Competiciones en las que participó el atleta con mayor cantidad de participaciones de la historia.
/*
select distinct Sport from Olimpiadas
where Name in (
	select Name from Olimpiadas
	group by Name
	HAVING COUNT(*) = (select MAX(cant_participaciones) from (
	select Name,COUNT(*) as cant_participaciones from Olimpiadas
	group by Name) as tablita))
*/

--11. Mostrar solo las participaciones en las que haya obtenido una medalla.
/*select Sport,Medal from Olimpiadas
where Name = (
	select Name from Olimpiadas
	group by Name
	HAVING COUNT(*) = (select MAX(cant_participaciones) from (
	select Name,COUNT(*) as cant_participaciones from Olimpiadas
	group by Name) as tablita))
group by Sport,Medal 
HAVING COUNT(*) = 1*/

--12. Promedio de edad de los atletas.
--select AVG(Age) as promedio_edad from Olimpiadas

--13. Promedio de edad de los atletas que ganaron medallas.
/*select AVG(Age) from (
	select Name,Age,COUNT(distinct Name) as cant from Olimpiadas
	where Medal is not NULL
	group by Name,Age) as tablita*/

--14. Promedio de edad de los atletas que ganaron medallas agrupados por sexo.
/*select Sex,AVG(Age) promedio_edad from (
select Name,Age,Sex,COUNT(distinct Name) as cant from Olimpiadas
	where Medal is not NULL
	group by Name,Age,Sex) as tablita
group by Sex*/

--15. Cantidad total de medallas repartidas por cada disciplina (sport).
/*select Sport,Medal,COUNT(*) as cantMedallas from Olimpiadas
where Medal is not NULL
group by Sport,Medal  
order by Sport*/

--16. Indicar nombre del país y cantidad de medallas obtenidas de los 3 países más ganadores.
/*select top 3 NOC,COUNT(*) as cantMedallas from Olimpiadas
where Medal is not NULL
group by NOC
order by COUNT(*) DESC*/

--17. Indicar nombre del país y cantidad de atletas, de los 10 países con mayor cantidad de participantes.
/*select top 10 NOC,COUNT(distinct Name) as cantParticipantes from Olimpiadas
group by NOC
order by COUNT(*) DESC*/

--18. Indicar nombre del país y cantidad de atletas, de los 10 países con mayor cantidad de participantes en la década del 80".
/*select top 10 NOC,COUNT(distinct Name) as cantParticipantes from Olimpiadas
where Anio >= 1980 and Anio < 1990
group by NOC
order by COUNT(*) DESC*/

--19. Atletas argentinos que participaron en 2004. Indicar nombre, edad, sexo, altura y peso, ordenado por medalla y por deporte.
/*select Name,Age,Sex,Height,Weight from Olimpiadas
where NOC = 'ARG' and Anio = 2004
order by Medal,Sport DESC*/

--20. Atletas argentinos que participaron en 2004 pero no en 2008.
/*select Name from Olimpiadas
where NOC = 'ARG' and Anio = 2004
EXCEPT
select Name from Olimpiadas
where NOC = 'ARG' and Anio = 2008*/

--21. Atletas argentinos que participaron en 2004 y en 2008.
/*select Name from Olimpiadas
where NOC = 'ARG' and Anio = 2004
INTERSECT
select Name from Olimpiadas
where NOC = 'ARG' and Anio = 2008*/