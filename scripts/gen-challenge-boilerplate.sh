#!/bin/sh

# check for required variable names
if [[ -z "${CHALLENGE_NAME}" ]]; then
  echo "CHALLENGE_NAME is a required env variable!"
  exit 1
fi
UPPER_CHALLENGE_NAME=${CHALLENGE_NAME^^}

if [[ -z "${CCC_DIR}" ]]; then
  echo "CCC_DIR is assumed to be $(pwd)"
  CCC_DIR_INTERNAL=$(pwd)
else
  CCC_DIR_INTERNAL=$CCC_DIR
fi

##### Create the stuff! #####

# 1. dirs
mkdir -p $CCC_DIR_INTERNAL/src/$CHALLENGE_NAME

# 2. challenge headers file
touch $CCC_DIR_INTERNAL/src/$CHALLENGE_NAME/$CHALLENGE_NAME.h
cat > $CCC_DIR_INTERNAL/src/$CHALLENGE_NAME/$CHALLENGE_NAME.h  << EOF
#ifndef ${UPPER_CHALLENGE_NAME}_H
#define ${UPPER_CHALLENGE_NAME}_H

/* Definition of common structs */
typedef struct
{
    void *input; // TODO your own input struct
} ${CHALLENGE_NAME^}Input;

/* and common macros */
#define ${UPPER_CHALLENGE_NAME: 0:2}_REPETITIONS 1
#define ${UPPER_CHALLENGE_NAME: 0:2}_INPUT_N 1
#define ${UPPER_CHALLENGE_NAME: 0:2}_SOLVER_N 1

/**
 * ===================== HELPER FUNCTIONS =====================
 * These are helper functions for the ${CHALLENGE_NAME} challenge
 */

/**
 * This function runs an ${CHALLENGE_NAME} challenge
 */
int ${CHALLENGE_NAME}_challenge_runner(int, const char *, clock_t *);

// TODO your own inputs for different verions of the challenges

#endif /* ${UPPER_CHALLENGE_NAME}_H */
EOF

# 3. challenge c file
touch $CCC_DIR_INTERNAL/src/$CHALLENGE_NAME/$CHALLENGE_NAME.c
cat > $CCC_DIR_INTERNAL/src/$CHALLENGE_NAME/$CHALLENGE_NAME.c  << EOF
// import external libs
#include <time.h>

// import your own headers
#include "${CHALLENGE_NAME}.h"
#include "solver1.h"

/*
 * Input mapping for ${CHALLENGE_NAME} challenges
 */
${CHALLENGE_NAME^}Input ${CHALLENGE_NAME: 0:2}_input_map[1] = {
    {NULL}
};

/*
 * Solver mapping for ${CHALLENGE_NAME} challenges
 */
const static struct
{
    const char *solver_name;
    char *(*solver)(char **, int, char *, int);
} ${CHALLENGE_NAME: 0:2}_solver_map[] = {
    {"solver1", ${CHALLENGE_NAME: 0:2}_solver1},
    // TODO add your solvers to the mapper
};


/**
 * ===================== HELPER FUNCTIONS =====================
 * These are helper functions for the ${CHALLENGE_NAME} challenge
 */

 /* ${CHALLENGE_NAME} challenge runner */
int ${CHALLENGE_NAME}_challenge_runner(int challenge_n, const char *solver, clock_t *timer)
{
    if (challenge_n > ${UPPER_CHALLENGE_NAME: 0:2}_INPUT_N)
    {
        printf("[WARNING] Failed to load input for challenge ${CHALLENGE_NAME}%d...\n", challenge_n);
        return 1;
    }
    challenge_n--; // indexing actually starts at zero ;)

    int error = 0;
    clock_t start_t, end_t;

    for (size_t i = 0; i < ${UPPER_CHALLENGE_NAME: 0:2}_SOLVER_N; i++)
    {
        if (strcmp(${CHALLENGE_NAME: 0:2}_solver_map[i].solver_name, solver) == 0)
        {
            /*
             * ===== IMPORTANT =====
             * We have to wrap the timer around our solver run to return in to main.
             * But give it a couple repetitions to get a nicer sum of running times.
             */

            // timer start
            start_t = clock();
            for (size_t j = 0; j < ${UPPER_CHALLENGE_NAME: 0:2}_REPETITIONS; j++)
            {
                // TODO place your own solver map with its signature here
                ${CHALLENGE_NAME: 0:2}_solver_map[i].solver()

            }
            end_t = clock();
            // timer end

            *timer = end_t - start_t;
            
            // TODO do your own result checker
            break;
        }

        if (i + 1 == ${UPPER_CHALLENGE_NAME: 0:2}_SOLVER_N)
        {
            printf("[WARNING] Solver %s is not mapped.\n", solver);
            error = 1;
        }
    }

    return error;
}
EOF

# 4. solver1 header file
touch $CCC_DIR_INTERNAL/src/$CHALLENGE_NAME/solver1.h
cat > $CCC_DIR_INTERNAL/src/$CHALLENGE_NAME/solver1.h  << EOF
#ifndef ${UPPER_CHALLENGE_NAME: 0:2}_SOLVER1_H
#define ${UPPER_CHALLENGE_NAME: 0:2}_SOLVER1_H

void ${CHALLENGE_NAME: 0:2}_solver1();

#endif
EOF

# 5. solver1 c file
touch $CCC_DIR_INTERNAL/src/$CHALLENGE_NAME/solver1.c
cat > $CCC_DIR_INTERNAL/src/$CHALLENGE_NAME/solver1.c  << EOF
// std lib imports - the only ones allowed!
#include <stdlib.h>

// import your own headers
#include "solver1.h"

// TODO your own implementation of the ${CHALLENGE_NAME: 0:2}_solver1
void ${CHALLENGE_NAME: 0:2}_solver1(){}

EOF

# 6. do own cmake list
touch $CCC_DIR_INTERNAL/src/$CHALLENGE_NAME/CMakeLists.txt
cat > $CCC_DIR_INTERNAL/src/$CHALLENGE_NAME/CMakeLists.txt  << EOF
cmake_minimum_required(VERSION 3.2)
project($CHALLENGE_NAME-challenge)

add_library($CHALLENGE_NAME STATIC 
    $CHALLENGE_NAME.c
    solver1.c
)

# TODO link whatever libraries your $CHALLENGE_NAME solver needs

EOF

# 7. append this challenge to the root CMakeLists.txt 
cat >>  $CCC_DIR_INTERNAL/src/CMakeLists.txt << EOF
# $CHALLENGE_NAME challenge
add_subdirectory($CHALLENGE_NAME)
target_link_libraries(${APP_EXE} $CHALLENGE_NAME)
include_directories($CHALLENGE_NAME)

EOF

# 8. do the tracker file
touch $CCC_DIR_INTERNAL/src/$CHALLENGE_NAME/$CHALLENGE_NAME.tracker 
cat > $CCC_DIR_INTERNAL/src/$CHALLENGE_NAME/$CHALLENGE_NAME.tracker << EOF
${CHALLENGE_NAME}1
EOF