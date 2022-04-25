#!/usr/bin/env python

import sys, os, json

# pick up the file changes
data = sys.stdin.read()
lines = data.split('\n')

# pick up the challenges and solvers to run
to_run = {}
for line in lines:
    if line.strip() == "":
        continue

    split_dot = line.split(".")
    if len(split_dot) > 2:
        print("[WARNING] possible dots in path, will not attempt autotest for:\n  >> ", line)
        continue
    if split_dot[-1] == '/':
        continue
    split_path = (split_dot[0]).split('/')
    if split_path[0] != 'src':
        print("[INFO] only changes on src/ are tested. Skipping:\n  >> ", line)
        continue
    if len(split_path) < 3:
        print("[WARNING] changes on main detected, autotest not prepared for this scenario.")
        continue

    filename = split_path[-1]
    challenge_name = split_path[1]

    if filename == challenge_name:
        print("[INFO] challenge ",challenge_name," was modified, testing all solvers.")
        # WARNING: this might break in the future...
        for p in os.listdir('src/'+challenge_name):
            pfilename = p.split(".")[0]
            if "solver" in pfilename:
                if challenge_name not in to_run:
                    to_run[challenge_name] = []
                if pfilename not in to_run[challenge_name]:
                    to_run[challenge_name] += (pfilename,)
        continue

    if "solver" in filename:
        if challenge_name not in to_run:
            to_run[challenge_name] = []
        if filename not in to_run[challenge_name]:
            to_run[challenge_name] += (filename,)
    
    print("filename:", filename, "\n  challenge name:", challenge_name)

# return a nice json for jq to do it's magic
with open("run.json", "w") as f:
    json.dump(to_run, f)
