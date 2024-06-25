import csv

data_PRESERVE = [['Name', 'Score', 'Fairway Hits', 'C1 Reg', 'C2 Reg', 'C1 Putting', 'C2 Putting', 'OB'],
            ['Ricky Wysocki', 37, 0.85, 0.61, 0.83, 0.93, 0.36, 2],
            ['Calvin Heimburg', 32, 0.91, 0.67, 0.85, 0.81, 0.31, 1],
            ['Cole Redalen', 32, 0.76, 0.61, 0.74, 0.90, 30, 4],
            ['Eagle McMahon', 31, 0.85, 0.65, 0.80, 0.88, 0.09, 3],
            ['Garrett Gurthie', 29, 0.74, 0.57, 0.74, 0.88, 0.23, 3],
            ['James Proctor', 29, 0.94, 0.57, 0.83, 0.91, 0.24, 3],
            ['James Conrad', 28, 0.77, 0.43, 0.69, 1, 0.36, 4],
            ['Andrew Presenell', 28, 0.89, 0.52, 0.80, 93, 0.19, 0],
            ['Alden Harris', 28, 0.78, 0.60, 0.75, 0.90, 0.36, 6],
            ['Gannon Buhr', 27, 0.85, 0.56, 0.67, 0.78, 0.67, 2],
            ['Anthony Barela', 27, 0.71, 0.54, 0.72, 0.75, 0.36, 3]]

filename = 'Preserve.csv'
with open(filename, 'w', newline='') as csvfile:
    csvwriter = csv.writer(csvfile)
    csvwriter.writerows(data_PRESERVE)
    
print("CSV FILE created !")




