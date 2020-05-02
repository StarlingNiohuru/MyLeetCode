SELECT Trips.Request_at AS 'Day', ROUND(COUNT(Status <> 'completed' OR NULL) / COUNT(*), 2) AS 'Cancellation Rate'
FROM Trips
JOIN Users ON Trips.Client_Id = Users.Users_Id AND Users.Banned = 'No'
WHERE Trips.Request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY Trips.Request_at;