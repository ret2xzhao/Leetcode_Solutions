SELECT c.name, SUM(r.fare) [Sum Of Fare]
FROM CITIES c
    LEFT JOIN USERS u ON c.id = u.city_id 
    LEFT JOIN RIDES r ON u.id = r.user_id
GROUP BY c.name
ORDER BY SUM(r.fare) ASC;