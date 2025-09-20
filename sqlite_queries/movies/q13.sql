SELECT DISTINCT p.name from stars s
JOIN people p on p.id = s.person_id
where p.name != 'Kevin Bacon' 
and movie_id IN(
    SELECT DISTINCT movie_id from stars s
    JOIN people p on p.id = s.person_id
    WHERE  p.name = 'Kevin Bacon' and birth = 1958
)