#!/usr/bin/env python

import sys, os, subprocess, logging


if "RUNNER_BIN" not in os.environ:
    logging.error("RUNNER_BIN env variable not defined")
    sys.exit(1)

logging.basicConfig(format='[%(levelname)s] %(message)s',level=logging.INFO)

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
        logging.warning("Possible dots in path, will not attempt autotest for:\n  >> %s", line)
        continue
    if split_dot[-1] == '/':
        continue
    split_path = (split_dot[0]).split('/')
    if split_path[0] != 'src':
        logging.warning("Only changes on src/ are tested. Skipping:\n  >> %s", line)
        continue
    if len(split_path) < 3:
        logging.warning("Changes on main detected, autotest not prepared for this scenario.")
        continue

    filename = split_path[-1]
    challenge_name = split_path[1]

    if filename == challenge_name:
        logging.info("Challenge %s was modified, testing all solvers for all updated versions in %s.tracker.",challenge_name)
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
    
# make this do the checks
for challenge, solver_list in to_run.items():
    executable = os.getcwd()+os.getenv("RUNNER_BIN")
    for solver in solver_list:
        # WARNING: this might break in the future...
        with open('src/'+challenge_name+'/'+challenge_name+'.tracker') as f:
            challenge_ids = [line.strip() for line in f]

        for challenge_id in challenge_ids:
            logging.info("Running command, %s --ch %s --sv %s", executable, challenge_id, solver)
            p = subprocess.Popen([executable, "--ch", challenge_id, "--sv", solver], stdout=subprocess.PIPE)
            (out, err) = p.communicate()
            logging.info("Logs from the run\n>>>>>>>>\n%s<<<<<<<<", out.decode('utf-8'))
            if p.returncode:
                logging.error("Exiting with error from challenge %s with solver %s", challenge_id, solver)
                sys.exit(1)

sys.exit(0)