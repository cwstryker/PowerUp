import os
import glob
import csv

result = [i for i in glob.glob('./*.csv') if not "-len" in i]

for file in result:
  output=''
  with open(file) as csvfile:
    readCSV = csv.reader(csvfile, delimiter=',')
    base=os.path.basename(file)
    filename = os.path.splitext(base)[0]
    with open(filename+'-len'+len(), "w+") as outfile:
      for row in readCSV:
        output+='{' + row[0] + ', '+ row[1] + ', ' + row[2] + '},\n'
      outfile.write(output.rstrip(',\n'))