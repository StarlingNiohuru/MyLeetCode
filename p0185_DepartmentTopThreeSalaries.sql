SELECT Department.Name AS Department, E1.Name AS Employee, E1.Salary
FROM Department
JOIN Employee E1 ON Department.Id = E1.departmentId
LEFT JOIN Employee E2 ON E1.departmentId = E2.departmentId AND E1.Salary < E2.Salary
GROUP BY Department.Name, E1.Name
HAVING COUNT(DISTINCT(E2.Salary)) < 3
ORDER BY Department.Name, E1.Salary DESC;