CID=$(docker run --detach --rm -t --entrypoint bash luisferreira32/crunner)
docker cp . $CID:/home/runner/
docker exec $CID bash -c 'make compile build valrun RUNNER_ARGS="--ch anagram1 --sv solver1"'
docker stop $CID
