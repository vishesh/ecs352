#!/usr/bin/python
# Generate the Lab File in HTML
# Vishesh Yadav

import os, glob, cgi, re

sources = glob.glob( '*.c')

print "Opening 'lab_file.htm' for writing"
lab_file = open("lab_file.htm", "w")

print "Starting to write on file"

lab_file.write("""
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">

<head>
<style type="text/css">
body{font-size: 90%;}
div.prog { page-break-after: always; }
</style>
<title>Data Structures Lab</title>

</head>

<body>
""")

tit = re.compile("[\s]+\* [a-zA-Z0-9]*")
aut = re.compile("[\s]+\* Vishesh Yadav*", re.IGNORECASE)

for program in sources:
    filename, ext = program.split(".")
    print "Generating for ", program
    current_source = open(program, "r")
    current_output = open(filename+".txt", "r")
    lab_file.write("<div class='prog'><pre>")
    for line in current_source:
        line = cgi.escape(line)
        if tit.match(line):
            if not aut.match(line):
               line = "<h2>" + line + "</h2>"
        lab_file.write(line)
    lab_file.write("</pre>")
    lab_file.write("<h5>Output</h5>")
    lab_file.write("<pre>")
    for line in current_output:
        lab_file.write(cgi.escape(line))
    lab_file.write("</pre></div>")

lab_file.write("""
</body>

</html>
""")

print "Completed writing file"
